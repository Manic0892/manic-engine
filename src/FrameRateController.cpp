

#include "FrameRateController.h"
#include <chrono>
#include <thread>
#include <iostream>

namespace Manic_Engine
{

FrameRateController::FrameRateController(int FrameRate)
{
  FrameRate_ = FrameRate;
  FrameTime_ = ms( 1000 / FrameRate_ );
  
  LastFrameTime_ = ms(0);
}

void FrameRateController::FrameStart()
{
  StartTime_ = Time::now();
}

void FrameRateController::FrameEnd()
{
  ms currentFrameTime = ms(0);
  
  while (currentFrameTime < FrameTime_)
  {
    EndTime_ = Time::now();
    
    currentFrameTime = std::chrono::duration_cast<ms>(EndTime_ - StartTime_);
    
    std::this_thread::sleep_for(currentFrameTime);
  }
  
  LastFrameTime_ = currentFrameTime;
  TotalTime_ += currentFrameTime.count();
}

double FrameRateController::GetFrameTime()
{
  return FrameTime_.count();
}

double FrameRateController::GetLastFrameTime()
{
  return LastFrameTime_.count();
}

} // Manic_Engine
