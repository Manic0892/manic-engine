

#include "FrameRateController.h"
#include <chrono>
#include <thread>

namespace Manic_Engine
{

FrameRateController::FrameRateController(int FrameRate)
{
  FrameRate_ = FrameRate;
  FrameTime_ = double(1 / FrameRate_);
  
  LastFrameTime_ = 0;
}

void FrameRateController::FrameStart()
{
  StartTime_ = Time::now();
}

void FrameRateController::FrameEnd()
{
  using std::chrono::duration;
  using std::chrono::duration_cast;
  
   EndTime_ = Time::now();

  duration<double> currentFrameTime = duration_cast<duration<double>>(EndTime_ - StartTime_);
  
  while (currentFrameTime < FrameTime_)
  {
    EndTime_ = Time::now();

    currentFrameTime = duration_cast<duration<double>>(EndTime_ - StartTime_);
    
    duration<double> sleepTime = FrameTime_ - currentFrameTime.count();
    
    std::this_thread::sleep_for(sleepTime);
  }
  
  LastFrameTime_ = currentFrameTime;
}

double FrameRateController::GetLastFrameTime()
{
  return LastFrameTime_;
}

} // Manic_Engine
