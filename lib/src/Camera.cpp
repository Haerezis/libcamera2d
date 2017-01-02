#include "libcamera2d/Camera.hpp"

namespace libcamera2d
{
Camera::Camera(unsigned int width, unsigned int height, unsigned int worldWidth,
               unsigned int worldHeight)
    : Object2D(width, height, worldWidth, worldHeight)
{
}

Camera::~Camera() {}
}
