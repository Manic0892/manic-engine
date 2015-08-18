#include "System.h"

namespace Manic_Engine
{

namespace Systems
{

System::System(Components::BITFIELD_COMPONENT id = Components::BITFIELD_COMPONENT::bcUndefined) : ComponentID(id) {};

} // Systems

} // Manic_Engine