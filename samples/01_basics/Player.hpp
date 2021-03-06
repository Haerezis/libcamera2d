#ifndef __LIBCAMERA2D_SIMPLE_PLATEFORMER_PLAYER__HPP
#define __LIBCAMERA2D_SIMPLE_PLATEFORMER_PLAYER__HPP

#include "libcamera2d/Object2D.hpp"

class Player : public libcamera2d::Object2D
{
 public:
  Player(unsigned int width, unsigned int height, unsigned int worldWidth = 0,
         unsigned int worldHeight = 0);

  ~Player();

  void moveHorizontal(float value);

  void moveVertical(float value);

 protected:
  static const unsigned int _horizontalMoveIncrement = 4;
  static const unsigned int _verticalMoveIncrement = 4;
};

#endif
