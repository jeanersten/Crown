#pragma once

#include <glad/glad.h>

class Sprite
{
private:
  float m_x, m_y;
  float m_width, m_height;

  GLuint m_vboID;

public:
  Sprite(float x, float y, float width, float height);
  ~Sprite();

  void setup();
  void draw();
};
