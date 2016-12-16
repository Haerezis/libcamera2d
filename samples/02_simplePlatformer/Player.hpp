#ifndef __LIBCAMERA2D_01_BASICS_PLAYER__HPP
#define __LIBCAMERA2D_01_BASICS_PLAYER__HPP

#include <memory>

#include "libcamera2d/Object2D.hpp"
#include "Tilemap.hpp"

class Player : public libcamera2d::Object2D
{
 public:
  Player(unsigned int width,
      unsigned int height,
      const Tilemap& tilemap);

  ~Player();

  void tilemap(const Tilemap& tilemap);

  void moveHorizontal(float value);

  void moveVertical(float value);

 protected:
  //This is a pointer because it should be mutable, so it can't be a reference,
  //but we don't want to copy it when changing it (a tilemap can have a big memory footprint)
  const Tilemap * _tilemap;

  int _horizontalVelocity;

  int _verticalVelocity;

  static const int _maxHorizontalVelocity = 4;

  static const int _maxVerticalVelocity = 4;

  static const unsigned int _horizontalAcceleration = 4;
  static const unsigned int _verticalAcceleration = 4;
};

#endif
