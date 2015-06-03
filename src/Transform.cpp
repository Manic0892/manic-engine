/*!

\file   Transform.cpp
\author Sean McGeer
\date   6/2/15
\brief  Implements the transform component.

*/

#include "Transform.h"

namespace Manic_Engine
{

namespace Components
{

Transform::Transform() : Component("Transform", bcTransform) {}

Transform::~Transform()
{

}

void Transform::Init(int position)
{
  Position = position;
}

void Transform::Update()
{
  ++Position;
}

}

}
