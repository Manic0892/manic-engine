/*!
  \file   FrameRateController.h
  \author Sean McGeer
  \date   2/24/15
  \brief
    Define the FrameRateController class.
*/

#ifndef FRAMERATECONTROLLER_H
#define FRAMERATECONTROLLER_H

#include <ctime>

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
    clock_t StartTime_;
    clock_t EndTime_;
    double TotalTime_;
    double LastFrameTotalTime_;
}

} // Manic_Engine

#endif
