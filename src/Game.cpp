/*!
  \file   Game.cpp
  \author Sean McGeer
  \date   1/29/15
  \brief
    Implement the main Game object.
*/

#include <iostream>           // cout, endl
#include "Game.h"             // Game
#include "GameStateManager.h" // GameStateManager

namespace Manic_Engine
{

/*!
  Creates a new game object.
  
  \param FrameRate
    The framerate in FPS to set the game framerate to.
*/
Game::Game(int FrameRate)
{
  FrameRate_ = FrameRate;
  
  GSM_ = new GameStateManager();
}

Game::~Game()
{
  
}

/*!
  Runs the game.
  
  \return
    An integer code to return to the OS.
*/
int Game::Run()
{
  std::cout << "Hello, world!  Framerate set to: " << FrameRate_ << std::endl;
  
  while (true)
  {
    std::cout << "Here" << std::endl;
    
    GSM_->pState_->Load();
    
    std::cout << "Here" << std::endl;
  }
  
  return 0;
}

} // namespace Manic_Engine
