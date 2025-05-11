#include <SDL.h>

const int SCREEN_WIDTH {640};
const int SCREEN_HEIGHT {480};

int main(int argc, char* argv[])
{
  SDL_Window* window = nullptr;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    SDL_Log("Failed to initialize SDL, ERROR: %s\n", SDL_GetError());
  }
  else
  {
    window = SDL_CreateWindow("Crown Engine!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (!window)
    {
      SDL_Log("Failed to create SDL window, ERROR: %s\n", SDL_GetError());
    }

    SDL_Event event;
    bool running {true};

    while (running)
    {
      while (SDL_PollEvent(&event))
      {
        if (event.type == SDL_QUIT) running = false;
      }
    }
  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
