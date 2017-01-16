#ifndef _LIBCAMERA2D_OBJECT_DIMENSION_GENERATOR_HPP
#define _LIBCAMERA2D_OBJECT_DIMENSION_GENERATOR_HPP

#include "libcamera2d/ObjectDimension.hpp"

namespace libcamera2d
{

class ObjectDimensionGenerator
{
 public:
  ObjectDimensionGenerator(const ObjectDimension& baseObjectDimension);
  virtual ~ObjectDimensionGenerator();

  const ObjectDimension& baseObjectDimension() const;
  void baseObjectDimension(const ObjectDimension& value);

 protected:
  ObjectDimension _base;
};  
    
}   
    
#endif
