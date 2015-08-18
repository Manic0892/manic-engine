/*!

\file   Transform.h
\author Sean McGeer
\date   6/2/15
\brief  Defines the transform component.

*/

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Component.h"

namespace Manic_Engine
{

namespace Components
{

/*!

\class Transform

\brief A definition of a transform component.  Inherits from Component.

*/

class Transform : public Component
{

public:
  Transform();
  ~Transform();

  void Init();
  void Init(int position);
  void Update();

private:
  int Position;

};

} // Components

} // Manic_Engine

#endif