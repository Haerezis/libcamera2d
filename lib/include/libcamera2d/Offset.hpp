#ifndef _LIBCAMERA2D_ALGORITHM_OFFSET__HPP
#define _LIBCAMERA2D_ALGORITHM_OFFSET__HPP

#include "libcamera2d/ObjectDimension.hpp"

namespace libcamera2d
{

class Offset
{
  public:
  Offset(int offset);
  ~Offset();

  ObjectDimension operator()(const ObjectDimension& camera) const;

  protected:
  int _offset;
};

}

#endif
