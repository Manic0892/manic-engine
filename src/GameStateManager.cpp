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
  Previous_ = Level;
  Current_ = Level;
  Next_ = Level;
}

void GameStateManager::Update()
{
  switch (Next_)
  {
    case Level:
      break;
    default:
      break;
  }
}

GameStateManager::~GameStateManager()
{
  
}
