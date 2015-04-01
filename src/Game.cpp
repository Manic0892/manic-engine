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
  FRC_ = new ManicEngine::FrameRateController(FrameRate);
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

  GSM_->Update();

  while (GSM_->Current_ != QUIT)
  {
    if (GSM_->Current_ == RESTART)
    {
      GSM_->Current_ = GSM_->Previous_;
      GSM_->Next_ = GSM_->Previous_;
    }
    else
    {
      GSM_->Update();
      GSM_->State_->Load();
    }

    GSM_->State_->Init();

    while (GSM_->Next_ == GSM_->Current_)
    {
      FRC_->FrameStart();

      GSM_->State_->Update();
      GSM_->State_->Draw();

      FRC_->FrameEnd();
    }

    GSM_->State_->Free();

    if (GSM_->Next_ == RESTART)
    {
      GSM_->Previous_ = GSM_->Current_;
      GSM_->Current_ = GSM_->Next_;
    }
    else
      GSM_->State_->Unload();

    // Update state indicators
    GSM_->Previous_ = GSM_->Current_;
    GSM_->Current_ = GSM_->Next_;
  }

  return 0;
}

} // namespace Manic_Engine
