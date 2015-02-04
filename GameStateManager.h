/*!
  \file   GameStateManager.h
  \author Sean McGeer
  \date   1/29/15
  \brief
    Define the game state manager.
*/

enum STATE { Level_1, Level_2, Restart, Quit };

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
    enum STATE _Previous;
    enum STATE _Current;
    enum STATE _Next;
};
