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

STATE_LIST GameStateManager::GetPreviousState() const
{
  return Previous;
}

STATE_LIST GameStateManager::GetCurrentState() const
{
  return Current;
}

STATE_LIST GameStateManager::GetNextState() const
{
  return Next;
}

void GameStateManager::SetPreviousState(STATE_LIST state)
{
  Previous = state;
}

void GameStateManager::SetCurrentState(STATE_LIST state)
{
  Current = state;
}

void GameStateManager::SetNextState(STATE_LIST state)
{
  Next = state;
}

} // Manic_Engine
