/*!
  \file   GameStateManager.h
  \author Sean McGeer
  \date   1/29/15
  \brief
    Define the game state manager.
*/

enum STATE { Level, Restart, Quit };

/*!
  \class GameStateManager
  \brief  
    The game state manager handles the switching of states and contains pointers
    to the currently loaded level for use in the game loop.
*/
class GameStateManager
{
  public:
    GameStateManager(int FrameRate);
    ~GameStateManager();
  
  private:
    /* Pervious, current, and next states */
    enum STATE Previous_;
    enum STATE Current_;
    enum STATE Next_;
};
