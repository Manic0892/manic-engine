/*!
  \file   GameObjectComponent.h
  \author Sean McGeer
  \date   6/1/15
  \brief
    Defines a class for a game object component.  All components should inherit
    from this class.
*/

#include <"GameObjectComponentList.h">

namespace Manic_Engine
{

namespace Components
{

class GameObjectComponent
{
  public:
    GameObjectComponent();
    ~GameObjectComponent();

    virtual void Init()   = 0;
    virtual void Update() = 0;

  private:
    /*! The name of this component */
    std::string const Name;
    int const ID = bcUndefined;
};

}

}