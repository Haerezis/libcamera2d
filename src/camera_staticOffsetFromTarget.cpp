#include "libcamera2d/camera_staticOffsetFromTarget.hpp"

namespace libcamera2d
{
Camera_staticOffsetFromTarget::Camera_staticOffsetFromTarget(
    unsigned int offsetX,
    unsigned int offsetY,
    unsigned int width,
    unsigned int height,
    unsigned int worldWidth,
    unsigned int worldHeight) :
      Camera(width, height, worldWidth, worldHeight),
      _offsetX(offsetX),
      _offsetY(offsetY)
{
}

Camera_staticOffsetFromTarget::~Camera_staticOffsetFromTarget()
{}

void Camera_staticOffsetFromTarget::update(unsigned int targetX, unsigned int targetY)
{
  if(targetX < _offsetX)
    _x = 0;
  else if(((targetX - _offsetX) + _width) > _worldWidth)
    _x = _worldWidth - _width;
  else
    _x = targetX - _offsetX;

  if(targetY < _offsetY)
    _y = 0;
  else if(((targetY - _offsetY) + _height) > _worldHeight)
    _y = _worldHeight - _height;
  else
    _y = targetY - _offsetY;
}

}
