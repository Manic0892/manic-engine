/*!
  \file   Level.cpp
  \author Sean McGeer
  \date   1/29/15
  \brief
    Implement the main game state manager.
*/

#include "Level.h"
#include <iostream>

namespace Manic_Engine
{

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
  std::cout << "Level Load" << std::endl;
}

/*!
  Initialize a new play session for a Level.
*/
void Level::Init()
{
  std::cout << "Level Init" << std::endl;
}

/*!
  This level's part of the update loop.
*/
void Level::Update()
{
  std::cout << "Level Update" << std::endl;
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
