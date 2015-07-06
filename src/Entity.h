/*!

\file   Entity.h
\author Sean McGeer
\date   6/1/15
\brief  Defines a class for a basic game object, with various paramaters
affecting gameplay.

*/

#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "Component.h"
#include "ComponentList.h"

namespace Manic_Engine
{

class Entity
{
  public:
    Entity();
    ~Entity();
    int GetComponentsFlag();
    bool AddComponent(Components::INDICES_COMPONENT index);
  
  protected:
    std::vector<Components::Component *> Components;
    Components::BITFIELD_COMPONENT ComponentsFlag;
};

}

#endif