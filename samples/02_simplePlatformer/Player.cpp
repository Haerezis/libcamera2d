#include "Player.hpp"

#include <cmath>
#include <iostream>

const float Player::_horizontalAcceleration = 5.0f;
const float Player::_jumpVelocity = 15.0f;
const float Player::_fallAcceleration = 0.7f;
const float Player::_horizontalFrictionAccelerationCoefficient = 0.8f;

const float Player::_maxHorizontalVelocity = 7.0f;
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
  if(std::fabs(_horizontalVelocity) > _maxHorizontalVelocity) _horizontalVelocity = -_maxHorizontalVelocity;
}

void Player::jump()
{

  if(_isTouchingBottomTile())
  {
    _verticalVelocity = -_jumpVelocity;
    if(std::fabs(_verticalVelocity) >_maxVerticalVelocity) _verticalVelocity = -_maxVerticalVelocity;
  }
}

void Player::_applyFallAcceleration()
{
  _verticalVelocity += _fallAcceleration;
  if(_verticalVelocity > _maxVerticalVelocity) _verticalVelocity = _maxVerticalVelocity;
}
  
void Player::_applyHorizontalFrictionAcceleration()
{
  //_horizontalVelocity = 0;
  _horizontalVelocity *= _horizontalFrictionAccelerationCoefficient;
  if(std::fabs(_horizontalVelocity) < 1.0f) _horizontalVelocity = 0.0f;
}

void Player::updatePosition()
{
  _moveLeft();
  _moveRight();
  _moveUp();
  _moveDown();

  //If we touch a tile on the bottop or top of the player, we reset vertical velocity to avoid to "hover"
  if((_isTouchingTopTile() && (_verticalVelocity < 0.0f)) || (_isTouchingBottomTile() && (_verticalVelocity > 0.0f)))
  {
    _verticalVelocity *= 0.2f;
  }
  //If we touch a tile on the left or right of the player, we reset horizontal velocity
  if(_isTouchingLeftTile() || _isTouchingRightTile())
  if((_isTouchingLeftTile() && (_horizontalVelocity < 0.0f)) || (_isTouchingRightTile() && (_horizontalVelocity > 0.0f)))
  {
    _horizontalVelocity *= 0.2f;
  }

  if(!_isTouchingBottomTile())
  {
    _applyFallAcceleration();
  }
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

  _x = (_x < std::fabs(_horizontalVelocity)) ? 0 : _x + _horizontalVelocity;

  bool hitSomething = false;
  for(unsigned int x = (_x / tilesize); (x <= (oldX / tilesize)) && !hitSomething; x++)
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

  _y = (_y < std::fabs(_verticalVelocity)) ? 0 : _y + _verticalVelocity;

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

bool Player::_isTouchingBottomTile()
{
  const unsigned int tilesize = _tilemap->tilesize();
  unsigned int y = (_y + _height + 1) / tilesize;
  bool isTouching = false;
  
  //If we are on the bottomest line of the tilemap, we consider that we are touching a tile.
  isTouching = _y >= (_tilemap->height() - 1) * tilesize;

  for(unsigned int x = _x / tilesize; (x <= ((_x + _width - 1) / tilesize)) && !isTouching; x++)
  {
    isTouching |= _tilemap->at(x, y) != 0;
  }

  return isTouching;
}

bool Player::_isTouchingTopTile()
{
  const unsigned int tilesize = _tilemap->tilesize();
  unsigned int y = (_y - 1) / tilesize;
  bool isTouching = false;
  
  //If we are on the toppest position of the tilemap, we consider that we are touching a tile.
  isTouching = _y == 0;

  for(unsigned int x = _x / tilesize; (x <= ((_x + _width - 1) / tilesize)) && !isTouching; x++)
  {
    isTouching |= _tilemap->at(x, y) != 0;
  }

  return isTouching;
}

bool Player::_isTouchingLeftTile()
{
  return false;
  const unsigned int tilesize = _tilemap->tilesize();
  unsigned int x = (_x + _width + 1) / tilesize;
  bool isTouching = false;
  
  isTouching = _x == 0;

  for(unsigned int y = _y / tilesize; (y <= ((_y + _height - 1) / tilesize)) && !isTouching; y++)
  {
    isTouching |= _tilemap->at(x, y) != 0;
  }

  return isTouching;
}

bool Player::_isTouchingRightTile()
{
  return false;
  const unsigned int tilesize = _tilemap->tilesize();
  unsigned int x = (_x + _width + 1) / tilesize;
  bool isTouching = false;

  isTouching = _x >= (_tilemap->width() - 1) * tilesize;

  for(unsigned int y = _y / tilesize; (y <= ((_y + _height - 1) / tilesize)) && !isTouching; y++)
  {
    isTouching |= _tilemap->at(x, y) != 0;
  }

  return isTouching;
}
