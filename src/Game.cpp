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
Game::Game(int framerate)
{
  FrameRate = framerate;

  GSM = new GameStateManager();
  FRC = new Manic_Engine::FrameRateController(FrameRate);
}

/*!
  Destroys a game object.  Cleans up the GameStateManager and
  FrameRateController instances.
*/
Game::~Game()
{
  delete GSM;
  delete FRC;
}

/*!
  Runs the game.

  \return
    An integer code to return to the OS.
*/
int Game::Run()
{
  std::cout << "Hello, world!  Framerate set to: " << FrameRate << std::endl;

  GSM->Update(); // Update the game state manager.

  // Basic game loop
  while (GSM->Current_ != QUIT)
  {
    if (GSM->Current_ == RESTART)
    {
      GSM->Current_ = GSM->Previous_;
      GSM->Next_ = GSM->Previous_;
    }
    else
    {
      GSM->Update();
      GSM->State_->Load();
    }

    GSM->State_->Init();

    while (GSM->Next_ == GSM->Current_)
    {
      FRC->FrameStart();

      GSM->State_->Update();
      GSM->State_->Draw();

      FRC->FrameEnd();
    }

    GSM->State_->Free();

    if (GSM->Next_ == RESTART)
    {
      GSM->Previous_ = GSM->Current_;
      GSM->Current_ = GSM->Next_;
    }
    else
      GSM->State_->Unload();

    // Update state indicators
    GSM->Previous_ = GSM->Current_;
    GSM->Current_ = GSM->Next_;
  }

  return 0;
}

} // namespace Manic_Engine
