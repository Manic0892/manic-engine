/*!
  \file   State.cpp
  \author Sean McGeer
  \date   2/9/15
  \brief
    Implement the state object.
*/

#include "State.h"
#include <iostream>

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
  pLoad_ = pLoad;
  pInit_ = pInit;
  pUpdate_ = pUpdate;
  pDraw_ = pDraw;
  pFree_ = pFree;
  pUnload_ = pUnload;
}

void State::Load()
{
  pLoad_();
}
void State::Init()
{
  pInit_();
}
void State::Update()
{
  pUpdate_();
}
void State::Draw()
{
  pDraw_();
}
void State::Free()
{
  pFree_();
}
void State::Unload()
{
  pUnload_();
}

} // namespace Manic_Engine
