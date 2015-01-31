////////////////////////////////////////////////////////////////////////////////
/*!
\file:    Game.h
\author:  Sean McGeer
\date:    1/29/15
\brief:
  Implement the main Game object.
*/
////////////////////////////////////////////////////////////////////////////////

#include "Game.h"
#include <iostream>

Game::Game(int FrameRate)
{
  FrameRate_ = FrameRate;
}

Game::~Game()
{
  
}

int Game::Run()
{
  std::cout << "Hello, world!  Framerate set to: " << FrameRate_ << std::endl;
  return 0;
}
