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

void Level::Load()
{
  std::cout << "Level Load" << std::endl;
}

void Level::Init()
{
  std::cout << "Level Init" << std::endl;
}

void Level::Update()
{
  std::cout << "Level Update" << std::endl;
}

void Level::Draw()
{
  std::cout << "Level Draw" << std::endl;
}

void Level::Free()
{
  std::cout << "Level Free" << std::endl;
}

void Level::Unload()
{
  std::cout << "Level Unload" << std::endl;
}

} // namespace States

} // namespace Manic_Engine
