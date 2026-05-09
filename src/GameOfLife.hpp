#pragma once

#include <SDL2/SDL.h>

#include "GameOfLifeBoard.hpp"

namespace gol
{

inline constexpr int         DEFAULT_CELL_SIZE    = 20;
inline constexpr const char* DEFAULT_WINDOW_TITLE = "Game Of Life";

class GameOfLife
{
  public:
    GameOfLife(int width, int height);
    ~GameOfLife() = default;

    int  Run();
    void Tick();

  private:
    bool            m_ShouldRun     = false;
    SDL_Event       m_SDLEvent      = {};
    SDL_Window*     m_SDLWindow     = nullptr;
    SDL_Renderer*   m_SDLRenderer   = nullptr;
    int             m_SDLWindowWidth;
    int             m_SDLWindowHeight;
    int             m_FrameCount    = 0;
    GameOfLifeBoard m_Board;

    int CreateSDLWindow();
    int CreateSDLRenderer();

    int FillBackgroundColor();
    int HandleSDLEvent();

    int DrawGrid();
    int DrawCells();
};

} // namespace gol