/*!

\file   Component.h
\author Sean McGeer
\date   6/1/15
\brief  Defines a class for a game object component.  All components should
inherit from this class.

*/

#ifndef COMPONENT_H
#define COMPONENT_H

#include "ComponentList.h"
#include <string>

namespace Manic_Engine
{

namespace Components
{

class Component
{
  public:
    Component(char* name, BITFIELD_COMPONENT id);
    ~Component();

    virtual void Init()   = 0;
    virtual void Update() = 0;

  protected:
    /*! The name of this component */
    std::string const Name;
    BITFIELD_COMPONENT const ID;
};

}

}

#endif
