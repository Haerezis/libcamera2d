#ifndef __LIBCAMERA2D_SIMPLE_PLATEFORMER_PLAYER__HPP
#define __LIBCAMERA2D_SIMPLE_PLATEFORMER_PLAYER__HPP

#include "libcamera2d/Object2D.hpp"

class Player : public libcamera2d::Object2D
{
 public:
  Player(
      unsigned int width,
      unsigned int height,
      unsigned int worldWidth = 0,
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
};

#endif
