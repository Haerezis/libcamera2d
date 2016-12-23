#include "libcamera2d/Camera.hpp"

namespace libcamera2d
{
Camera::Camera(unsigned int width, unsigned int height, unsigned int worldWidth,
               unsigned int worldHeight)
    : Object2D(width, height), _worldWidth(worldWidth), _worldHeight(worldHeight)
{
}

Camera::~Camera() {}

unsigned int Camera::worldHeight() const { return _worldHeight; }

void Camera::worldHeight(unsigned int height) { _worldHeight = height; }

unsigned int Camera::worldWidth() const { return _worldWidth; }

void Camera::worldWidth(unsigned int width) { _worldWidth = width; }
}
