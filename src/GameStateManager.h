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

enum STATE_LIST { gsLevel, gsRestart, gsQuit };

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
    
    STATE_LIST GetPreviousState() const;
    STATE_LIST GetCurrentState() const;
    STATE_LIST GetNextState() const;
    
    void SetPreviousState(STATE_LIST state);
    void SetCurrentState(STATE_LIST state);
    void SetNextState(STATE_LIST state);
    
    State *Running;
    
  private:
    void SwitchToState(State *state);
    
    /* Previous, current, and next states */
    STATE_LIST Previous;
    STATE_LIST Current;
    STATE_LIST Next;
};

} // Manic_Engine

#endif
