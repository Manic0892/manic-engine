/*!

\file   Entity.h
\author Sean McGeer
\date   6/1/15
\brief  Defines a class for a basic game object, with various paramaters
affecting gameplay.

*/

#include <vector>
#include "Component.h"

namespace Manic_Engine
{

class Entity
{
  public:
    Entity();
    ~Entity();
  
  protected:
    std::vector<Component *> Components;
    BITFIELD_COMPONENT ComponentsFlag;
};

}
