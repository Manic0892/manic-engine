/*!
  \file   GameStateManager.cpp
  \author Sean McGeer
  \date   1/29/15
  \brief
    Implement the main game state manager.
*/

#include "GameStateManager.h" // GameStateManager

/*!
  Creates a new game state manager.
*/
GameStateManager::GameStateManager()
{
  _Previous = Level_1;
  _Current = Level_1;
  _Next = Level_1;
}

GameStateManager::~GameStateManager()
{
  
}
