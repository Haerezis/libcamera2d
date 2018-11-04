#include "libcamera2d/Object1D.hpp"

namespace libcamera2d {

Object1D::Object1D(unsigned int size, unsigned int bound) :
  _position(0),
  _bound(bound),
  _size(size) {
}

Object1D::~Object1D() {
}

unsigned int Object1D::position() const {
  return _position;
}

void Object1D::position(unsigned int value) {
  _position = value;
  
  if((_position + _size) > _bound)
  {
    _position = _bound - _size;
  }
}

unsigned int Object1D::bound() const {
  return _bound;
}

void Object1D::bound(unsigned int value) {
  _bound = value;
  
  if((_position + _size) > _bound)
  {
    _position = _bound - _size;
  }

}

unsigned int Object1D::size() const {
  return _size;
}

void Object1D::size(unsigned int value) {
  _size = value;

  if((_position + _size) > _bound)
  {
    _position = _bound - _size;
  }
}

}
