#include "Player.hpp"

#include <cmath>
#include <iostream>

const float Player::_horizontalAcceleration = 4.0f;
const float Player::_jumpVelocity = 15.0f;
const float Player::_gravityAcceleration = 0.7f;
const float Player::_horizontalFrictionAccelerationCoefficient = 0.9f;

const float Player::_maxHorizontalVelocity = 4.0f;
const float Player::_maxVerticalVelocity = 20.0f;

Player::Player(unsigned int width, unsigned int height, const Tilemap& tilemap) :
    Object2D(width, height),
    _tilemap(&tilemap),
    _horizontalVelocity(0),
    _verticalVelocity(0)
{
}

Player::~Player() {}

void Player::tilemap(const Tilemap& tilemap)
{
  _tilemap = &tilemap;
}

void Player::moveRight(float value)
{
  if(value > 1.0f) value = 1.0f;
  if(value < 0.0f)
  {
    moveLeft(value);
    return;
  }
  
  _horizontalVelocity += value * _horizontalAcceleration;
  if(_horizontalVelocity > _maxHorizontalVelocity) _horizontalVelocity = _maxHorizontalVelocity;
}

void Player::moveLeft(float value)
{
  if(value > 1.0f) value = 1.0f;
  if(value < 0.0f)
  {
    moveRight(value);
    return;
  }
  
  _horizontalVelocity -= value * _horizontalAcceleration;
  if(_horizontalVelocity < (-_maxHorizontalVelocity)) _horizontalVelocity = -_maxHorizontalVelocity;
}

void Player::jump()
{

  if(_isGrounded())
  {
    _verticalVelocity = -_jumpVelocity;
    if(_verticalVelocity < (-_maxVerticalVelocity)) _verticalVelocity = -_maxVerticalVelocity;
  }
}

void Player::_applyGravityAcceleration()
{
  _verticalVelocity += _gravityAcceleration;
  if(_verticalVelocity > _maxVerticalVelocity) _verticalVelocity = _maxVerticalVelocity;
}
  
void Player::_applyHorizontalFrictionAcceleration()
{
  _horizontalVelocity *= _horizontalFrictionAccelerationCoefficient;
  if(_horizontalVelocity < 0.01f) _horizontalVelocity = 0.0f;
}

void Player::updatePosition()
{
  _moveLeft();
  _moveRight();
  _moveUp();
  _moveDown();

  _applyGravityAcceleration();
  _applyHorizontalFrictionAcceleration();
}

void Player::_moveRight()
{
  if(_horizontalVelocity <= 0.0f)
  {
    return;
  }

  const unsigned int tilesize = _tilemap->tilesize();
  const unsigned int worldWidth = _tilemap->width() * tilesize;
  const unsigned int oldX = _x;
  
  _x = ((_x + _horizontalVelocity + _width) >= worldWidth) ? worldWidth - _width : _x + _horizontalVelocity;
  
  bool hitSomething = false;
  for(unsigned int x = ((oldX + _width) / tilesize); (x <= ((_x + _width - 1) / tilesize)) && !hitSomething; x++)
  {
    for(unsigned int y = _y / tilesize; (y <= ((_y + _height -1) / tilesize)) && !hitSomething; y++)
    {
      hitSomething |= _tilemap->at(x, y) != 0;
      if(hitSomething)
      {
        _x = x * tilesize - _width;
      }
    }
  }
}

void Player::_moveLeft()
{
  if(_horizontalVelocity >= 0.0f)
  {
    return;
  }

  const unsigned int tilesize = _tilemap->tilesize();
  const unsigned int oldX = _x;

  _x = (_x < (-_horizontalVelocity)) ? 0 : _x + _horizontalVelocity;

  bool hitSomething = false;
  for(unsigned int x = (oldX / tilesize); (x >= (_x / tilesize)) && !hitSomething; x--)
  {
    for(unsigned int y = _y / tilesize; (y <= ((_y + _height -1) / tilesize)) && !hitSomething; y++)
    {
      hitSomething |= _tilemap->at(x, y) != 0;
      if(hitSomething)
      {
        _x = (x + 1) * tilesize;
      }
    }
  }

}

void Player::_moveUp()
{
  if(_verticalVelocity >= 0.0f)
  {
    return;
  }
  
  const unsigned int tilesize = _tilemap->tilesize();
  const unsigned int oldY = _y;

  _y = (_y < (-_verticalVelocity)) ? 0 : _y + _verticalVelocity;

  bool hitSomething = false;
  for(unsigned int y = (_y / tilesize) ; (y <= (oldY / tilesize)) && !hitSomething; y++)
  {
    for(unsigned int x = _x / tilesize; (x <= ((_x + _width -1) / tilesize)) && !hitSomething; x++)
    {
      hitSomething |= _tilemap->at(x, y) != 0;
      if(hitSomething)
      {
        _y = (y + 1) * tilesize;
      }
    }
  }
}

void Player::_moveDown()
{
  if(_verticalVelocity <= 0.0f)
  {
    return;
  }

  const unsigned int tilesize = _tilemap->tilesize();
  const unsigned int worldHeight = _tilemap->height() * tilesize;
  unsigned int oldY = _y;

  _y = ((_y + _verticalVelocity + _height) > worldHeight) ? worldHeight - _height : _y + _verticalVelocity;
  
  bool hitSomething = false;
  for(unsigned int y = ((oldY + _height) / tilesize); (y <= ((_y + _height - 1) / tilesize)) && !hitSomething; y++)
  {
    for(unsigned int x = _x / tilesize; (x <= ((_x + _width -1) / tilesize)) && !hitSomething; x++)
    {
      hitSomething |= _tilemap->at(x, y) != 0;
      if(hitSomething)
      {
        _y = y * tilesize - _height;
      }
    }
  }
}

bool Player::_isGrounded()
{
  const unsigned int tilesize = _tilemap->tilesize();
  unsigned int y = (_y + _height + 1) / tilesize;
  bool standOnSomething = false;

  for(unsigned int x = _x / tilesize; (x <= ((_x + _width -1) / tilesize)) && !standOnSomething; x++)
  {
    standOnSomething |= _tilemap->at(x, y) != 0;
  }

  return standOnSomething;
}
