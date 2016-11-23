#include "libcamera2d/Camera.hpp"

namespace libcamera2d
{

Camera::Camera(unsigned int width,
     unsigned int height,
     unsigned int worldWidth,
     unsigned int worldHeight) :
       _x(0), _y(0),
       _width(width),
       _height(height),
       _worldWidth(worldWidth),
       _worldHeight(worldHeight)
{}

Camera::~Camera() {}

unsigned int Camera::x() const
{
  return _x;
}

unsigned int Camera::y() const
{
  return _y;
}

unsigned int Camera::height() const
{
  return _height;
}

unsigned int Camera::width() const
{
  return _width;
}

unsigned int Camera::worldHeight() const
{
  return _worldHeight;
}

void Camera::worldHeight(unsigned int height)
{
  _worldHeight = height;
}

unsigned int Camera::worldWidth() const
{
  return _worldWidth;
}

void Camera::worldWidth(unsigned int width)
{
  _worldWidth = width;
}

}
