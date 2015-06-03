/*!

\file   Game.h
\author Sean McGeer
\date   1/29/15
\brief  Define the main Game object.

*/

#include "GameStateManager.h"
#include "FrameRateController.h"

namespace Manic_Engine
{

/*!
  \class Game

  \brief
    The game class implements a game object which loads all other modules and
    handles the main running of the game.
*/
class Game
{
  public:
    Game(int FrameRate);
    ~Game();
    void Run();

    /*! This game's game state manager.     */
    GameStateManager *GSM;
    /*! This game's frame rate controller.  */
    FrameRateController *FRC;

  private:
    /*! The frames per second.              */
    int FrameRate;
};

} // Manic_Engine
