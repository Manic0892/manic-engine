/*!
  \file   Level.h
  \author Sean McGeer
  \date   2/5/15
  \brief
    Define the main Level object.
*/

#include "State.h"

namespace Manic_Engine
{

namespace Level_Functions
{
  
  void Load();
  void Init();
  void Update();
  void Draw();
  void Free();
  void Unload();
  
} // namespace Level_Functions

//namespace States
//{
//  
//  State *Level;
//  
//} // namespace States

} // namespace Manic_Engine
