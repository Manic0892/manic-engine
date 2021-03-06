#ifndef SYSTEM_H
#define SYSTEM_H

#include "Component.h"
#include "ComponentList.h"

namespace Manic_Engine
{

namespace Systems
{

class System
{
  public:
    System(Components::BITFIELD_COMPONENT id);
    virtual void Update() = 0;

  private:
    Components::BITFIELD_COMPONENT const ComponentID;
};

} // Systems

} // Manic_Engine


#endif