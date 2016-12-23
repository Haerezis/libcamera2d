#include "libcamera2d/Camera_positionLocking.hpp"

namespace libcamera2d
{
Camera_positionLocking::Camera_positionLocking(
    unsigned int offsetX, unsigned int offsetY, unsigned int width, unsigned int height,
    unsigned int worldWidth, unsigned int worldHeight)
    : Camera(width, height, worldWidth, worldHeight), _offsetX(offsetX), _offsetY(offsetY)
{
}

Camera_positionLocking::~Camera_positionLocking() {}

void Camera_positionLocking::update(unsigned int targetX, unsigned int targetY)
{
  if (targetX < _offsetX)
    _x = 0;
  else if (((targetX - _offsetX) + _width) > _worldWidth)
    _x = _worldWidth - _width;
  else
    _x = targetX - _offsetX;

  if (targetY < _offsetY)
    _y = 0;
  else if (((targetY - _offsetY) + _height) > _worldHeight)
    _y = _worldHeight - _height;
  else
    _y = targetY - _offsetY;
}
}
