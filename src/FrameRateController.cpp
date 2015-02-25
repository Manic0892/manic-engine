

#include "FrameRateController.h"
#include <chrono>
#include <thread>

namespace Manic_Engine
{

FrameRateController::FrameRateController(int FrameRate)
{
  FrameRate_ = FrameRate;
  FrameTime_ = double(1 / FrameRate_);
  
  LastFrameTotalTime_ = 0;
}

void FrameRateController::FrameStart()
{
  StartTime_ = clock();
}

void FrameRateController::FrameEnd()
{
  TotalTime_ = 0;
  
  while (TotalTime_ < FrameTime_)
  {
    EndTime_ = clock();

    TotalTime_ = double((EndTime_ - StartTime_) * 1000 / CLOCKS_PER_SEC);
    
    std::this_thread::sleep_for(std::chrono::milliseconds(TotalTime_));
  }
}

double GetLastFrameTotalTime()
{
  return LastFrameTotalTime_;
}

} // Manic_Engine
