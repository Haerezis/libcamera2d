#include "libcamera2d/PositionLocking.hpp"
#include <iostream>

namespace libcamera2d
{
  PositionLocking::PositionLocking(const ObjectDimension& base) :
    ObjectDimensionGenerator(base)
  {
  }

  PositionLocking::~PositionLocking()
  {
  }

  ObjectDimension PositionLocking::operator()(const ObjectDimension& target) const
  {
    ObjectDimension retval = _base;
    
    unsigned int offset = (_base.size() - target.size()) / 2;

    if (target.position() < offset)
      retval.position(0);
    else
      retval.position(target.position() - offset);


    return retval;
  }
}
