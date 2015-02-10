/*!
  \file   State.cpp
  \author Sean McGeer
  \date   2/9/15
  \brief
    Implement the state object.
*/

#include "State.h"

namespace Manic_Engine
{

/*!
  \class State
  \brief  
    The basic framework for a state which will be run by the game loop.
*/
State::State()
{
  //No defined behavior yet.
}

State::State(void (*pLoad)(void),
             void (*pInit)(void),
             void (*pUpdate)(void),
             void (*pDraw)(void),
             void (*pFree)(void),
             void (*pUnload)(void))
{
  Load = pLoad;
  Init = pInit;
  Update = pUpdate;
  Draw = pDraw;
  Free = pFree;
  Unload = pUnload;
}

} // namespace Manic_Engine
