////////////////////////////////////////////////////////////////////////////////
/*!
\file:    main.cpp
\author:  Sean McGeer
\date:    1/29/15
\brief:
  Instantiate the main game object.
*/
////////////////////////////////////////////////////////////////////////////////

#include "Game.h"
#include <getopt.h>
#include <stdlib.h>

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
  
  Game gameObject(framerate);
  
  return gameObject.Run();
}
