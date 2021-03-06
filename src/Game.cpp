/*!

\file   Game.cpp
\author Sean McGeer
\date   1/29/15
\brief  Implement the main Game object.

*/

#include <iostream>           // cout, endl
#include "Game.h"             // Game
#include "GameStateManager.h" // GameStateManager

namespace Manic_Engine
{
Game* Manic;
/*!
  Creates a new game object.

  \param framerate
    The framerate in FPS to set the game framerate to.
*/
Game::Game(int framerate)
{
  Manic = this;
  FrameRate = framerate;

  GSM = new GameStateManager();
  FRC = new FrameRateController(FrameRate);
  Graphics = new Systems::Graphics();
}

/*!
  Destroys a game object.  Cleans up the GameStateManager and
  FrameRateController instances.
*/
Game::~Game()
{
  delete GSM;
  delete FRC;
  delete Graphics;
}

/*!
  Runs the game.

  \return
    An integer code to return to the OS.
*/
void Game::Run()
{
  std::cout << "Hello, world!  Framerate set to: " << FrameRate << std::endl;

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
}

} // Manic_Engine
