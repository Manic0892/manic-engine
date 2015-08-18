/*!

\file   State.h
\author Sean McGeer
\date   2/5/15
\brief  Define the layout of a state.

*/

#include <string>
#include <vector>
#include "Entity.h"

#ifndef STATE_H
#define STATE_H

namespace Manic_Engine
{

/*!
  \class State
  \brief
    The basic framework for a state which will be run by the game loop.
*/
class State
{
  public:
    State();
    State(std::string name);
    virtual ~State();

    virtual void Load()   = 0;
    virtual void Init()   = 0;
    virtual void Update() = 0;
    virtual void Draw()   = 0;
    virtual void Free()   = 0;
    virtual void Unload() = 0;

    std::string GetName() const;
    void SetName(const std::string name);

    void AddEntity(Entity entityToAdd);

  private:
    /*! The name of this state. */
    std::string Name;
    /*! The vector of all objects loaded by this state. */
    std::vector<Entity> Entities;
};

} // namespace Manic_Engine

#endif
