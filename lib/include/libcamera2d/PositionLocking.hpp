#ifndef _LIBCAMERA2D_ALGORITHM_POSITION_LOCKING__HPP
#define _LIBCAMERA2D_ALGORITHM_POSITION_LOCKING__HPP

#include "libcamera2d/Object1D.hpp"

namespace libcamera2d
{

class PositionLocking
{
  public:
  PositionLocking(const Object1D& base);
  ~PositionLocking();

  Object1D operator()(const Object1D& target) const;

  protected:
  Object1D _base;
};

}


#endif
