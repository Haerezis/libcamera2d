#include "libcamera2d/camera.hpp"

namespace libcamera2d
{
Camera::Camera() : _x(0), _y(0), _height(720), _width(1280), _scale(0) {}
Camera::~Camera() {}
unsigned int Camera::x() const { return _x; }
unsigned int Camera::y() const { return _y; }
unsigned int Camera::height() const { return _height; }
unsigned int Camera::width() const { return _width; }
float Camera::scale() const { return _scale; }
}
