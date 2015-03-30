/*!
  \file   State.h
  \author Sean McGeer
  \date   2/5/15
  \brief
    Define the layout of a state.
*/

#ifndef STATE_H
#define STATE_H

namespace Manic_Engine
{

/*!
  \class State
  \brief
    The basic framework for a state which will be run by the game loop.
*/
class State
{
  public:
    State();
    ~State();

    virtual void Load()   = 0;
    virtual void Init()   = 0;
    virtual void Update() = 0;
    virtual void Draw()   = 0;
    virtual void Free()   = 0;
    virtual void Unload() = 0;
};

} // namespace Manic_Engine

#endif
