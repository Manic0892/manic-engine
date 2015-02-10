/*!
  \file   GameStateManager.cpp
  \author Sean McGeer
  \date   1/29/15
  \brief
    Implement the main game state manager.
*/

#include "State.h"
#include "Level.h"
#include <iostream>

namespace Manic_Engine
{
  
namespace Level_Functions
{
  void Load()
  {
    std::cout << "Level Load" << std::endl;
  }
  
  void Init()
  {
    std::cout << "Level Init" << std::endl;
  }
  
  void Update()
  {
    std::cout << "Level Update" << std::endl;
  }
  
  void Draw()
  {
    std::cout << "Level Draw" << std::endl;
  }
  
  void Free()
  {
    std::cout << "Level Free" << std::endl;
  }
  
  void Unload()
  {
    std::cout << "Level Unload" << std::endl;
  }
} // namespace Level

//namespace States
//{
  void FunctionShit()
  {
    // Create the new Level state.
    States::Level = new State(&(Level_Functions::Load),
                              &(Level_Functions::Init),
                              &(Level_Functions::Update),
                              &(Level_Functions::Draw),
                              &(Level_Functions::Free),
                              &(Level_Functions::Unload));
  }
//} // namespace States

} // namespace Manic_Engine
