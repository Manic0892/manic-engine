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
  State *Level;
  void CreateStateObjects()
  {
    Level = new State(&(Level_Functions::Load),
                      &(Level_Functions::Init),
                      &(Level_Functions::Update),
                      &(Level_Functions::Draw),
                      &(Level_Functions::Free),
                      &(Level_Functions::Unload));
  }
}

/*!
  Creates a new game state manager.
*/
GameStateManager::GameStateManager()
{
  Previous_State_ = Level_State;
  Current_State_ = Level_State;
  Next_State_ = Level_State;
  
  States::CreateStateObjects();
}

void GameStateManager::Update()
{
  switch (Next_State_)
  {
    case Level_State:
      pState_ = States::Level;
      break;
    default:
      break;
  }
}

GameStateManager::~GameStateManager()
{
  
}

} // namespace Manic_Engine
