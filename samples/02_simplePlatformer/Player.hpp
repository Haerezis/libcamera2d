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

  void moveRight(float value);

  void moveLeft(float value);

  void jump();

  void updatePosition();

 protected:
  void _applyFallAcceleration();

  void _applyHorizontalFrictionAcceleration();

  void _moveRight();

  void _moveLeft();

  void _moveUp();

  void _moveDown();

  bool _isTouchingBottomTile();

  bool _isTouchingTopTile();
  
  bool _isTouchingLeftTile();
  
  bool _isTouchingRightTile();

  //This is a pointer because it should be mutable at runtime, so it cannot be a reference,
  //but we don't want to copy it when changing it (a tilemap can have a big memory footprint)
  const Tilemap * _tilemap;

  float _horizontalVelocity;

  float _verticalVelocity;

  static const float _maxHorizontalVelocity;

  static const float _maxVerticalVelocity;

  static const float _horizontalAcceleration;
  static const float _jumpVelocity;
  static const float _fallAcceleration;
  static const float _horizontalFrictionAccelerationCoefficient;
};

#endif
