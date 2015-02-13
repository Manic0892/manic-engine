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

enum STATE_LIST { LEVEL, RESTART, QUIT };

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
    
    State *State_;
    
    /* Pervious, current, and next states */
    STATE_LIST Previous_;
    STATE_LIST Current_;
    STATE_LIST Next_;
};

} // namespace Manic_Engine

#endif
