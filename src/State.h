/*!
  \file   State.h
  \author Sean McGeer
  \date   2/5/15
  \brief
    Define the layout of a state.
*/

/*!
  \class State
  \brief  
    The basic framework for a state which will be run by the game loop.
*/
struct State
{
  public:
    State();
    ~State();
    
    //Game loop functions
    void Load();
    void Init();
    void Update();
    void Draw();
    void Free();
    void Unload();
};
