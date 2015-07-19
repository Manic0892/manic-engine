/*!

\file   Entity.cpp
\author Sean McGeer
\date   6/1/15
\brief  Implements the class for a game entity.

*/

#include "Entity.h"
#include "Game.h"
#include "ComponentList.h"
#include "ComponentInclude.h"

namespace Manic_Engine
{

extern Game* Manic;

Entity::Entity()
{
  Components.resize(Components::INDICES_COMPONENT::icLast, 0);
  ComponentsFlag = Components::BITFIELD_COMPONENT::bcNone;
}

Entity::~Entity()
{
  for (std::vector<Components::Component *>::iterator it = Components.begin();
    it != Components.end(); ++it)
    if (*it) delete *it;
}

int Entity::GetComponentsFlag()
{
  return ComponentsFlag;
}

bool Entity::AddComponent(Components::INDICES_COMPONENT index)
{
  switch (index)
  {
    case (Components::INDICES_COMPONENT::icTransform) :
      Components.push_back(new Components::Transform);
      break;
  }

  return true;
}


} // Manic_Engine
