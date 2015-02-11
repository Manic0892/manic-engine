/*!
  \file   GameStateManager.h
  \author Sean McGeer
  \date   1/29/15
  \brief
    Define the game state manager.
*/

#include "State.h"

#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

namespace Manic_Engine
{

enum STATE_LIST { Level_State, Restart_State, Quit_State };

/*!
  \class GameStateManager
  \brief  
    The game state manager handles the switching of states and contains pointers
    to the currently loaded level for use in the game loop.
*/
class GameStateManager
{
  public:
    GameStateManager();
    ~GameStateManager();
    
    void Update();
    
    State *pState_;
  
  private:
    /* Pervious, current, and next states */
    enum STATE_LIST Previous_State_;
    enum STATE_LIST Current_State_;
    enum STATE_LIST Next_State_;
};

} // namespace Manic_Engine

#endif
