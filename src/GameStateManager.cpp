/*!
  \file   GameStateManager.cpp
  \author Sean McGeer
  \date   1/29/15
  \brief
    Implement the main game state manager.
*/

#include "GameStateManager.h" // GameStateManager
#include "State.h"
#include "Level.h"

namespace Manic_Engine
{

/*!
  Creates a new game state manager.
*/
GameStateManager::GameStateManager()
{
  Previous = gsLevel;
  Current = gsLevel;
  Next = gsLevel;
}

/*!
  Default destructor.
*/
GameStateManager::~GameStateManager()
{
  delete Running;
}

/*!
  Updates the game state manager.
*/
void GameStateManager::Update()
{
  switch (Next)
  {
    case gsLevel:
      delete Running;
      Running = new States::Level();
      break;
    default:
      break;
  }
}

/*!
  Get the previous state.

  \return
    A STATE_LIST denoting the previous state.
*/
STATE_LIST GameStateManager::GetPreviousState() const
{
  return Previous;
}

/*!
  Get the current state.

  \return
    A STATE_LIST denoting the current state.
*/
STATE_LIST GameStateManager::GetCurrentState() const
{
  return Current;
}

/*!
  Get the next state.

  \return
    A STATE_LIST denoting the next state.
*/
STATE_LIST GameStateManager::GetNextState() const
{
  return Next;
}

/*!
  Set the previous state.

  \param state
    The state to set as the new previous state.
*/
void GameStateManager::SetPreviousState(STATE_LIST state)
{
  Previous = state;
}

/*!
  Set the current state.

  \param state
    The state to set as the new current state.
*/
void GameStateManager::SetCurrentState(STATE_LIST state)
{
  Current = state;
}

/*!
  Set the next state.

  \param state
    The state to set as the new next state.
*/
void GameStateManager::SetNextState(STATE_LIST state)
{
  Next = state;
}

} // Manic_Engine
