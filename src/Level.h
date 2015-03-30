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

class Level : public State
{
  public:
    Level();
    void Load();
    void Init();
    void Update();
    void Draw();
    void Free();
    void Unload();
};

} // namespace States

} // namespace Manic_Engine
