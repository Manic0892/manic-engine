#ifndef COMPONENTLIST_H
#define COMPONENTLIST_H

namespace Manic_Engine
{

namespace Components
{

enum INDICES_COMPONENT
{
  icTransform,
  icDraw,
  icLast
};

enum BITFIELD_COMPONENT
{
  bcUndefined       = -1,
  bcNone            =  0,
  
  bcTransform       =  1,
  bcDraw            =  1 <<  1
};

}

}

#endif