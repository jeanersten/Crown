#pragma once

#include <SDL.h>

enum class GameState
{
  PLAY,
  QUIT
};

class Game
{
private:
  SDL_Window* m_window;
  int m_screen_width;
  int m_screen_height;

  GameState m_state;

  bool init();
  void update();

  void handleEvent();
  void handleRendering();

public:
  Game();
  ~Game();

  void run();
};
