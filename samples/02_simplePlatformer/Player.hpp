#ifndef __LIBCAMERA2D_01_BASICS_PLAYER__HPP
#define __LIBCAMERA2D_01_BASICS_PLAYER__HPP

#include "libcamera2d/Object2D.hpp"

class Player : public libcamera2d::Object2D
{
 public:
  Player(unsigned int width, unsigned int height, unsigned int worldWidth = 0,
         unsigned int worldHeight = 0);

  ~Player();

  unsigned int worldWidth() const;

  void worldWidth(unsigned int value);

  unsigned int worldHeight() const;

  void worldHeight(unsigned int value);

  void moveHorizontal(float value);

  void moveVertical(float value);

 protected:
  unsigned int _worldWidth;

  unsigned int _worldHeight;

  int _horizontalVelocity;

  int _verticalVelocity;

  static const int _maxHorizontalVelocity = 4;

  static const int _maxVerticalVelocity = 4;

  static const unsigned int _horizontalAcceleration = 4;
  static const unsigned int _verticalAcceleration = 4;
};

#endif
