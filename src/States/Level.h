/*!
  \file   Level.h
  \author Sean McGeer
  \date   2/5/15
  \brief
    Define the main Level object.
*/

#include "State.h"

namespace Manic_Engine
{

namespace States
{

/*!
  \class Level

  \brief
    A definition of a basic level.  Inherits from State.
*/
class Level : public State
{
  public:
    Level();
    ~Level();

    void Load();
    void Init();
    void Update();
    void Draw();
    void Free();
    void Unload();

  private:
    int Health = 3;
    int Lives = 2;
};

} // namespace States

} // namespace Manic_Engine
