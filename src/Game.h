/*!
  \file   Game.h
  \author Sean McGeer
  \date   1/29/15
  \brief
    Define the main Game object.
*/

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
    int Run();
  
  private:
    int FrameRate_;
};

} // namespace Manic_Engine
