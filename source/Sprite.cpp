#include "Sprite.h"

#include <glad/glad.h>

Sprite::Sprite(float x, float y, float width, float height)
  : m_x(x)
  , m_y(y)
  , m_width(width)
  , m_height(height)
  , m_vboID(0)
{}

Sprite::~Sprite()
{
  if (m_vboID != 0)
  {
    glDeleteBuffers(1, &m_vboID);
  }
}

void Sprite::setup()
{
  if (m_vboID == 0)
  {
    glGenBuffers(1, &m_vboID);
  }

  GLfloat vertex_data[12];

  vertex_data[0] = m_x + m_width;
  vertex_data[1] = m_y + m_height;

  vertex_data[2] = m_x;
  vertex_data[3] = m_y + m_height;

  vertex_data[4] = m_x;
  vertex_data[5] = m_y;

  vertex_data[6] = m_x;
  vertex_data[7] = m_y;

  vertex_data[8] = m_x + m_width;
  vertex_data[9] = m_y;

  vertex_data[10] = m_x + m_width;
  vertex_data[11] = m_y + m_height;

  glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 12, vertex_data, GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::draw()
{
  glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
  glDrawArrays(GL_TRIANGLES, 0, 6);
  glDisableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}
