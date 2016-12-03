#include "libcamera2d/Object2D.hpp"

namespace libcamera2d
{

Object2D::Object2D(unsigned int width, unsigned int height) :
       _x(0), _y(0),
       _width(width),
       _height(height)
{}

Object2D::~Object2D()
{}

unsigned int Object2D::x() const
{
  return _x;
}

void Object2D::x(unsigned int value)
{
  _x = value;
}

unsigned int Object2D::y() const
{
  return _y;
}

void Object2D::y(unsigned int value)
{
  _y = value;
}

unsigned int Object2D::height() const
{
  return _height;
}

void Object2D::height(unsigned int value)
{
  _height = value;
}

unsigned int Object2D::width() const
{
  return _width;
}

void Object2D::width(unsigned int value)
{
  _width = value;
}

}
