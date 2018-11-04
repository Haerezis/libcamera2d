#include "libcamera2d/Object2D.hpp"

namespace libcamera2d
{
Object2D::Object2D(
    unsigned int width, unsigned int height,
    unsigned int worldWidth, unsigned int worldHeight) :
  _horizontalDimension(width, worldWidth), _verticalDimension(height, worldHeight)
{
}

Object2D::~Object2D() {}

unsigned int Object2D::x() const { return _horizontalDimension.position(); }

void Object2D::x(unsigned int value) { _horizontalDimension.position(value); }

unsigned int Object2D::y() const { return _verticalDimension.position(); }

void Object2D::y(unsigned int value) { _verticalDimension.position(value); }

unsigned int Object2D::height() const { return _verticalDimension.size(); }

void Object2D::height(unsigned int value) { _verticalDimension.size(value); }

unsigned int Object2D::width() const { return _horizontalDimension.size(); }

void Object2D::width(unsigned int value) { _horizontalDimension.size(value); }

unsigned int Object2D::worldHeight() const { return _verticalDimension.bound(); }

void Object2D::worldHeight(unsigned int height) { _verticalDimension.bound(height); }

unsigned int Object2D::worldWidth() const { return _horizontalDimension.bound(); }

void Object2D::worldWidth(unsigned int width) { _horizontalDimension.bound(width); }

const Object1D& Object2D::horizontalDimension() const
{
  return _horizontalDimension;
}

void Object2D::horizontalDimension(const Object1D& value)
{
  _horizontalDimension = value;
}

const Object1D& Object2D::verticalDimension() const
{
  return _verticalDimension;
}

void Object2D::verticalDimension(const Object1D& value)
{
  _verticalDimension = value;
}

}
