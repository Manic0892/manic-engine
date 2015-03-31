/*!
  \file   Game.cpp
  \author Sean McGeer
  \date   1/29/15
  \brief
    Implements a frame rate controller.
*/

#include "FrameRateController.h"
#include <chrono>
#include <thread>

namespace ManicEngine
{

/*!
  \brief
    Construct a new FrameRateController.

  \param framerate
    An integer framerate (frames per second).
*/
FrameRateController::FrameRateController(int framerate)
{
  FrameRate = framerate;
  FrameTime = ms( 1000 / FrameRate );

  LastFrameTime = ms(0);
}

void FrameRateController::FrameStart()
{
  StartTime = Time::now();
}

void FrameRateController::FrameEnd()
{
  ms currentFrameTime = ms(0);

  while (currentFrameTime < FrameTime)
  {
    EndTime = Time::now();

    currentFrameTime = std::chrono::duration_cast<ms>(EndTime - StartTime);

    std::this_thread::sleep_for(currentFrameTime);
  }

  LastFrameTime = currentFrameTime;
  TotalTime += currentFrameTime.count();
}

double FrameRateController::GetFrameTime()
{
  return FrameTime.count();
}

double FrameRateController::GetLastFrameTime()
{
  return LastFrameTime.count();
}

} // Manic_Engine
