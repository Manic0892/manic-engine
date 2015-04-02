/*!
  \file   FrameRateController.cpp
  \author Sean McGeer
  \date   2/24/15
  \brief
    Implements a frame rate controller.
*/

#include "FrameRateController.h"
#include <chrono>                 // Time functions
#include <thread>                 // sleep_for

namespace Manic_Engine
{

/*!
  \brief
    Construct a new FrameRateController.

  \param framerate
    An integer framerate (frames per second).
*/
FrameRateController::FrameRateController(int framerate)
{
  FrameRate = framerate;              // Set the FrameRate
  FrameTime = ms( 1000 / FrameRate ); // Calculate the frame time in ms

  LastFrameTime = ms(0);              // Initialize the last frame time
}

/*!
  \brief
    Record the time for a new frame.
*/
void FrameRateController::FrameStart()
{
  StartTime = Time::now();
}

/*!
  \brief
    Record a frame end.
*/
void FrameRateController::FrameEnd()
{
  ms currentFrameTime = ms(0);          // Set the current time the frame's been
                                        // running to zero.

  while (currentFrameTime < FrameTime)
  {
    EndTime = Time::now();              // Record the ending time for the frame.

    // Recalculate the current time the frame's been running.
    currentFrameTime = std::chrono::duration_cast<ms>(EndTime - StartTime);

    // Sleep for the remaining amount of time
    std::this_thread::sleep_for(FrameTime - currentFrameTime);
  }

  LastFrameTime = currentFrameTime; // Set the LastFrameTime for later reference
  TotalTime += currentFrameTime.count(); // Increment TotalTime count
}

/*!
  \brief
    Get the frame time.

  \return
    A double representing the frame time.
*/
double FrameRateController::GetFrameTime()
{
  return FrameTime.count();
}

/*!
  \brief
    Get the most recent actual frame time.

  \return
    A double representing the most recent frame time.
*/
double FrameRateController::GetLastFrameTime()
{
  return LastFrameTime.count();
}

} // Manic_Engine
