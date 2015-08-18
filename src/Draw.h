/*!

\file   Draw.h
\author Sean McGeer
\date   8/18/15
\brief  Defines the draw component.

*/

#ifndef DRAW_H
#define DRAW_H

#include "Component.h"

namespace Manic_Engine
{

namespace Components
{
  
/*!

\class Draw

\brief A definition of a draw component.  Inherits from Component.

*/

class Draw : public Component
{

public:
  Draw();
  ~Draw();

  void Init();
  void Update();

private:
  int Color;

};

} // Components

} // Manic_Engine

#endif