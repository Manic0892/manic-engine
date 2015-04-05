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

  \param framerate
    The framerate in FPS to set the game framerate to.
*/
Game::Game(int framerate)
{
  FrameRate = framerate;

  GSM = new GameStateManager();
  FRC = new FrameRateController(FrameRate);
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
  while (GSM->GetCurrentState() != gsQuit)
  {
    if (GSM->GetCurrentState() == gsRestart)
    {
      GSM->SetCurrentState(GSM->GetPreviousState());
      GSM->SetNextState(GSM->GetPreviousState());
    }
    else
    {
      GSM->Update();
      GSM->Running->Load();
    }

    GSM->Running->Init();

    while (GSM->GetNextState() == GSM->GetCurrentState())
    {
      FRC->FrameStart();

      GSM->Running->Update();
      GSM->Running->Draw();

      FRC->FrameEnd();
    }

    GSM->Running->Free();

    if (GSM->GetNextState() == gsRestart)
    {
      GSM->SetPreviousState(GSM->GetCurrentState());
      GSM->SetCurrentState(GSM->GetNextState());
    }
    else
      GSM->Running->Unload();

    // Update state indicators
    GSM->SetPreviousState(GSM->GetCurrentState());
    GSM->SetCurrentState(GSM->GetNextState());
  }

  return 0;
}

} // Manic_Engine
