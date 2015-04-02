/*!
  \file   FrameRateController.h
  \author Sean McGeer
  \date   2/24/15
  \brief
    Define the FrameRateController class.
*/

#ifndef FRAMERATECONTROLLER_H
#define FRAMERATECONTROLLER_H

#include <chrono>

typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::high_resolution_clock::time_point TimePoint;
typedef std::chrono::milliseconds ms;

namespace Manic_Engine
{

/*!
  \class FrameRateController
  
  \brief
    Controls the framerate.  Registers the beginning of a frame, and then
    will sleep once it receives a call to FrameEnd until the appropriate amount
    of time to spend on each frame has passed.
*/
class FrameRateController
{
  public:
    FrameRateController(int framerate);

    void FrameStart();
    void FrameEnd();

    double GetLastFrameTime();
    double GetFrameTime();

  private:
    /*! The frames per second.                          */
    int FrameRate;
    /*! The time of each frame -- 1 / FrameRate.        */
    ms FrameTime;
    /*! The start time of the current frame.            */
    TimePoint StartTime;
    /*! The end time of the current frame.              */
    TimePoint EndTime;
    /*! The total time the game's been running, in ms.  */
    unsigned long long TotalTime;
    /*! The time of the last frame, in ms.              */
    ms LastFrameTime;
};

} // Manic_Engine

#endif
