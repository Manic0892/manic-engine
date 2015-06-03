/*!

\file   Level.cpp
\author Sean McGeer
\date   1/29/15
\brief  Implement the main game state manager.

*/

#include "Level.h"
#include "Game.h"
#include <iostream>

namespace Manic_Engine
{

extern Game* Manic;

namespace States
{

/*!
  Creates a new Level object.
*/
Level::Level()
{
  SetName("Level");
  std::cout << "Constructed " << GetName() << std::endl;
}

/*!
  Destroys a Level object.
*/
Level::~Level()
{
}

/*!
  Loads the assets for a Level.
*/
void Level::Load()
{
  Lives = 2;
  std::cout << "Level Load." << std::endl;
}

/*!
  Initialize a new play session for a Level.
*/
void Level::Init()
{
  Health = 3;
  std::cout << "Level Init." << std::endl;
}

/*!
  This level's part of the update loop.
*/
void Level::Update()
{
  --Health;
  std::cout << "Level Update.  Health = " << Health << ", Lives = " << Lives
    << std::endl;

  if (Health <= 0)
  {
    --Lives;
    if (Lives <= 0)
      Manic->GSM->SetNextState(gsQuit);
    else
      Manic->GSM->SetNextState(gsRestart);
  }
}

/*!
  This level's part of the draw loop.
*/
void Level::Draw()
{
  std::cout << "Level Draw" << std::endl;
}

/*!
  De-initializes this level.
*/
void Level::Free()
{
  std::cout << "Level Free" << std::endl;
}

/*!
  Unloads all the assets for a level.
*/
void Level::Unload()
{
  std::cout << "Level Unload" << std::endl;
}

} // States

} // Manic_Engine
