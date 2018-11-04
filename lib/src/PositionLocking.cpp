#include "libcamera2d/PositionLocking.hpp"
#include <iostream>

namespace libcamera2d
{
  PositionLocking::PositionLocking(const Object1D& base) :
    _base(base)
  {
  }

  PositionLocking::~PositionLocking()
  {
  }

  Object1D PositionLocking::operator()(const Object1D& target) const
  {
    Object1D retval = _base;
    
    unsigned int offset = (_base.size() - target.size()) / 2;

    if (target.position() < offset)
      retval.position(0);
    else
      retval.position(target.position() - offset);


    return retval;
  }
}
