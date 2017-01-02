#include "libcamera2d/ObjectDimension.hpp"

namespace libcamera2d
{

ObjectDimension::ObjectDimension(unsigned int size, unsigned int bound) :
  _position(0),
  _bound(bound),
  _size(size)
{
}

ObjectDimension::~ObjectDimension()
{
}

unsigned int ObjectDimension::position() const

{
  return _position;
}

void ObjectDimension::position(unsigned int value)
{
  _position = value;
  
  if((_position + _size) > _bound)
  {
    _position = _bound - _size;
  }
}

unsigned int ObjectDimension::bound() const

{
  return _bound;
}

void ObjectDimension::bound(unsigned int value)
{
  _bound = value;
  
  if((_position + _size) > _bound)
  {
    _position = _bound - _size;
  }

}

unsigned int ObjectDimension::size() const

{
  return _size;
}

void ObjectDimension::size(unsigned int value)
{
  _size = value;

  if((_position + _size) > _bound)
  {
    _position = _bound - _size;
  }
}

}
