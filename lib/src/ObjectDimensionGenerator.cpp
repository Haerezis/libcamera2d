#include "libcamera2d/ObjectDimensionGenerator.hpp"

namespace libcamera2d
{
  ObjectDimensionGenerator::ObjectDimensionGenerator(const ObjectDimension& baseObjectDimension) :
    _base(baseObjectDimension)
  {
  }

  ObjectDimensionGenerator::~ObjectDimensionGenerator()
  {
  }

  const ObjectDimension& ObjectDimensionGenerator::baseObjectDimension() const
  {
    return _base;
  }

  void ObjectDimensionGenerator::baseObjectDimension(const ObjectDimension& value)
  {
    _base = value;
  }
}
