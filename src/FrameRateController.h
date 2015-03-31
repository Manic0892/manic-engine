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

namespace ManicEngine
{

class FrameRateController
{
  public:
    FrameRateController(int framerate);

    void FrameStart();
    void FrameEnd();

    double GetLastFrameTime();
    double GetFrameTime();

  private:
    int FrameRate;
    ms FrameTime;
    TimePoint StartTime;
    TimePoint EndTime;
    double TotalTime;
    ms LastFrameTime;
};

} // ManicEngine

#endif
