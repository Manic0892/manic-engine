/*!

\file   main.cpp
\author Sean McGeer
\date   1/29/15
\brief  Instantiate the main game object.

*/

#include "Engine/Game.h"
#include <getopt.h>
#include <stdlib.h>

namespace ME = Manic_Engine;

int main(int argc, char **argv)
{
  int framerate = 60;
  int opt;

  while ((opt = getopt(argc, argv, "f:")) != -1)
  {
     switch (opt)
     {
      case 'f':
        framerate = atoi(optarg);
        break;
     }
  }

  ME::Game gameObject(framerate);

  gameObject.Run();

  return 0;
}
