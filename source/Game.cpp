#include "Game.h"

#include <SDL.h>
#include <glad/glad.h>

#include <iostream>

Game::Game()
  : m_window(nullptr)
  , m_screen_width(640)
  , m_screen_height(480)
  , m_state(GameState::PLAY)
{
  if (!init())
  {
    std::cerr << "Game failed to initialize!\n";
    
    return;
  }
}

Game::~Game()
{
  SDL_DestroyWindow(m_window);
  SDL_Quit();

  std::cout << "Game ended!\n";
}

bool Game::init()
{
  bool valid {true};

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
  {
    SDL_Log("Failed to initialize SDL! ERROR: %s\n", SDL_GetError());
    
    valid = false;
  }

  m_window = SDL_CreateWindow("Crown Engine!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              m_screen_width, m_screen_height, SDL_WINDOW_OPENGL);
  if (!m_window)
  {
    SDL_Log("Failed to create SDL window! ERROR: %s\n", SDL_GetError());

    valid = false;
  }

  SDL_GLContext gl_context {SDL_GL_CreateContext(m_window)};

  if (!gl_context)
  {
    SDL_Log("Failed to create SDL OpenGL context! ERROR: %s\n", SDL_GetError());

    valid = false;
  }

  if (!gladLoadGLLoader(SDL_GL_GetProcAddress))
  {
    SDL_Log("Failed to load SDL OpenGL functions! ERROR: %s\n", SDL_GetError());

    valid = false;
  }
  else
  {
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  }

  return valid;
}

void Game::update()
{
  while (m_state != GameState::QUIT)
  {
    handleEvent();
    handleRendering();
  }
}

void Game::handleEvent()
{
  SDL_Event event { };

  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_QUIT:
        m_state = GameState::QUIT;
      break;

      case SDL_MOUSEMOTION:
        std::cout << event.motion.x << ", " << event.motion.y << '\n';
      break;
    }
  }
}

void Game::handleRendering()
{
  glClearDepth(1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glEnableClientState(GL_COLOR_ARRAY);

  glBegin(GL_TRIANGLES);
  glColor3f(1.0f, 0.5f, 0.5f);
  glVertex2f(-0.5f, -0.5f);
  glVertex2f( 0.0f,  0.5f);
  glVertex2f( 0.5f, -0.5f);
  glEnd();

  SDL_GL_SwapWindow(m_window);
  SDL_GL_SetSwapInterval(1);
}

void Game::run()
{
  update();
}
