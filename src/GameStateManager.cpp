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

namespace States
{
  State *level;
  void CreateStateObjects()
  {
    level = new Level();
  }
}

/*!
  Creates a new game state manager.
*/
GameStateManager::GameStateManager()
{
  Previous_ = LEVEL;
  Current_ = LEVEL;
  Next_ = LEVEL;

  States::CreateStateObjects();
}

void GameStateManager::Update()
{
  switch (Next_)
  {
    case LEVEL:
      State_ = States::level;
      break;
    default:
      break;
  }
}

GameStateManager::~GameStateManager()
{

}

} // namespace Manic_Engine
