/*!

\file   State.cpp
\author Sean McGeer
\date   2/9/15
\brief  Implement the state object.

*/

#include "State.h"

namespace Manic_Engine
{

/*!
  Constructor for a new State object.
*/
State::State()
{
  Name = "";
}

/*!
  Constructor for a new State object.
  
  \param name
    The name for the new state.
*/
State::State(std::string name) : Name(name)
{

}

/*!
  Destructor for a State object.
*/
State::~State()
{

}

/*!
  Returns the name of the given state.
  
  \return
    The name, which is a standard string object.
*/
std::string State::GetName() const
{
  return Name;
}

/*!
  Set the name of a state.
  
  \param name
    The name, which is a standard string object.
*/
void State::SetName(std::string name)
{
  Name = name;
}

} // namespace Manic_Engine
