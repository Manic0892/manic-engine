#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "System.h"

namespace Manic_Engine
{

namespace Systems
{

class Graphics : public System
{
  public:
    Graphics(Components::BITFIELD_COMPONENT id);
    void Update();
};

} // Systems

} // Manic_Engine

#endif