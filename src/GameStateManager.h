/*!
  \file   GameStateManager.h
  \author Sean McGeer
  \date   1/29/15
  \brief
    Define the game state manager.
*/

enum STATE_LIST { Level, Restart, Quit };

/*!
  \class GameStateManager
  \brief  
    The game state manager handles the switching of states and contains pointers
    to the currently loaded level for use in the game loop.
*/
class GameStateManager
{
  public:
    GameStateManager();
    ~GameStateManager();
    
    void Update();
  
  private:
    /* Pervious, current, and next states */
    enum STATE_LIST Previous_;
    enum STATE_LIST Current_;
    enum STATE_LIST Next_;
};
