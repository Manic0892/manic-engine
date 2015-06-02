/*!

\file   Component.h
\author Sean McGeer
\date   6/1/15
\brief  Defines a class for a game object component.  All components should
inherit from this class.

*/

#include "Component.h"

namespace Manic_Engine
{

namespace Components
{

Component::Component(char* name = "Default", BITFIELD_COMPONENT
  id = bcUndefined) : Name(name), ID(id) {}

Component::~Component()
{

}

}

}
