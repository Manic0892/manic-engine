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
typedef std::chrono::duration<double> sec;

namespace Manic_Engine
{

class FrameRateController
{
  public:
    FrameRateController(int FrameRate);
    
    void FrameStart();
    void FrameEnd();
    
    double GetLastFrameTime();
  
  private:
    int FrameRate_;
    double FrameTime_;
    TimePoint StartTime_;
    TimePoint EndTime_;
    int TotalTime_;
    double LastFrameTime_;
};

} // Manic_Engine

#endif
