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
    State(void (*pLoad)(void),
          void (*pInit)(void),
          void (*pUpdate)(void),
          void (*pDraw)(void),
          void (*pFree)(void),
          void (*pUnload)(void));
    ~State();
    
    void Load();
    void Init();
    void Update();
    void Draw();
    void Free();
    void Unload();
  
  private:
    //Game loop function pointers
    void (*pLoad_)(void);
    void (*pInit_)(void);
    void (*pUpdate_)(void);
    void (*pDraw_)(void);
    void (*pFree_)(void);
    void (*pUnload_)(void);
};

} // namespace Manic_Engine

#endif
