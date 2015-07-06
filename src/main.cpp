/*!

\file   main.cpp
\author Sean McGeer
\date   1/29/15
\brief  Instantiate the main game object.

*/

#include "Game.h"
#include <stdlib.h>

#define FRAMERATE 1

namespace ME = Manic_Engine;

int main()
{
  ME::Game gameObject(FRAMERATE);

  gameObject.Run();

  return 0;
}
