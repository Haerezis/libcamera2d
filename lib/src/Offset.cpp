#include "libcamera2d/Offset.hpp"
#include <cmath>

namespace libcamera2d
{
  Offset::Offset(int offset) : _offset(offset)
  {
  }

  Offset::~Offset()
  {
  }
  
  ObjectDimension Offset::operator()(const ObjectDimension& camera) const
  {
    ObjectDimension retval = camera;

    if((_offset < 0) && (retval.position() < std::abs(_offset)))
    {
      retval.position(0);
    }
    else
    {
      retval.position(retval.position() + _offset);
    }
    
    return retval;
  }
}
