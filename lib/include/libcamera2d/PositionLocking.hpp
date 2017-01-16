#ifndef _LIBCAMERA2D_ALGORITHM_POSITION_LOCKING__HPP
#define _LIBCAMERA2D_ALGORITHM_POSITION_LOCKING__HPP

#include "libcamera2d/ObjectDimension.hpp"
#include "libcamera2d/ObjectDimensionGenerator.hpp"

namespace libcamera2d
{

class PositionLocking : ObjectDimensionGenerator
{
  public:
  PositionLocking(const ObjectDimension& base);
  ~PositionLocking();

  ObjectDimension operator()(const ObjectDimension& target) const;

  protected:
  unsigned int _windowSize;

  unsigned int _worldSize;
};

}


#endif
