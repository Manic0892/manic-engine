/*!
  \file   State.cpp
  \author Sean McGeer
  \date   2/9/15
  \brief
    Implement the state object.
*/

#include "State.h"
#include <iostream>

namespace Manic_Engine
{

State::State()
{
  Name = "";
}

State::State(std::string name) : Name(name)
{

}

std::string State::GetName() const
{
  return Name;
}

void State::SetName(std::string name)
{
  Name = name;
}

} // namespace Manic_Engine
