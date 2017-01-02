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
    Object2D(width, height, tilemap.tilesize() * tilemap.width(), tilemap.tilesize() * tilemap.height()),
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
  const unsigned int oldX = x();
  
  x(((x() + _horizontalVelocity + width()) >= worldWidth()) ? worldWidth() - width() : x() + _horizontalVelocity);
  
  bool hitSomething = false;
  for(unsigned int x = ((oldX + width()) / tilesize); (x <= ((this->x() + width() - 1) / tilesize)) && !hitSomething; x++)
  {
    for(unsigned int y = this->y() / tilesize; (y <= ((this->y() + height() -1) / tilesize)) && !hitSomething; y++)
    {
      hitSomething |= _tilemap->at(x, y) != 0;
      if(hitSomething)
      {
        this->x(x * tilesize - width());
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
  const unsigned int oldX = x();

  x((x() < std::fabs(_horizontalVelocity)) ? 0 : x() + _horizontalVelocity);

  bool hitSomething = false;
  for(unsigned int x = (this->x() / tilesize); (x <= (oldX / tilesize)) && !hitSomething; x++)
  {
    for(unsigned int y = this->y() / tilesize; (y <= ((this->y() + height() -1) / tilesize)) && !hitSomething; y++)
    {
      hitSomething |= _tilemap->at(x, y) != 0;
      if(hitSomething)
      {
        this->x((x + 1) * tilesize);
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
  const unsigned int oldY = y();

  y((y() < std::fabs(_verticalVelocity)) ? 0 : y() + _verticalVelocity);

  bool hitSomething = false;
  for(unsigned int y = (this->y() / tilesize) ; (y <= (oldY / tilesize)) && !hitSomething; y++)
  {
    for(unsigned int x = this->x() / tilesize; (x <= ((this->x() + width() -1) / tilesize)) && !hitSomething; x++)
    {
      hitSomething |= _tilemap->at(x, y) != 0;
      if(hitSomething)
      {
        this->y((y + 1) * tilesize);
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
  unsigned int oldY = y();

  y(((y() + _verticalVelocity + height()) > worldHeight()) ? worldHeight() - height() : y() + _verticalVelocity);
  
  bool hitSomething = false;
  for(unsigned int y = ((oldY + height()) / tilesize); (y <= ((this->y() + height() - 1) / tilesize)) && !hitSomething; y++)
  {
    for(unsigned int x = this->x() / tilesize; (x <= ((this->x() + width() -1) / tilesize)) && !hitSomething; x++)
    {
      hitSomething |= _tilemap->at(x, y) != 0;
      if(hitSomething)
      {
        this->y(y * tilesize - height());
      }
    }
  }
}

bool Player::_isTouchingBottomTile()
{
  const unsigned int tilesize = _tilemap->tilesize();
  unsigned int y = (this->y() + height() + 1) / tilesize;
  bool isTouching = false;
  
  //If we are on the bottomest line of the tilemap, we consider that we are touching a tile.
  isTouching = this->y() >= (_tilemap->height() - 1) * tilesize;

  for(unsigned int x = this->x() / tilesize; (x <= ((this->x() + width() - 1) / tilesize)) && !isTouching; x++)
  {
    isTouching |= _tilemap->at(x, y) != 0;
  }

  return isTouching;
}

bool Player::_isTouchingTopTile()
{
  const unsigned int tilesize = _tilemap->tilesize();
  unsigned int y = (this->y() - 1) / tilesize;
  bool isTouching = false;
  
  //If we are on the toppest position of the tilemap, we consider that we are touching a tile.
  isTouching = this->y() == 0;

  for(unsigned int x = this->x() / tilesize; (x <= ((this->x() + width() - 1) / tilesize)) && !isTouching; x++)
  {
    isTouching |= _tilemap->at(x, y) != 0;
  }

  return isTouching;
}

bool Player::_isTouchingLeftTile()
{
  return false;
  const unsigned int tilesize = _tilemap->tilesize();
  unsigned int x = (this->x() + width() + 1) / tilesize;
  bool isTouching = false;
  
  isTouching = this->x() == 0;

  for(unsigned int y = this->y() / tilesize; (y <= ((this->y() + height() - 1) / tilesize)) && !isTouching; y++)
  {
    isTouching |= _tilemap->at(x, y) != 0;
  }

  return isTouching;
}

bool Player::_isTouchingRightTile()
{
  return false;
  const unsigned int tilesize = _tilemap->tilesize();
  unsigned int x = (this->x() + width() + 1) / tilesize;
  bool isTouching = false;

  isTouching = this->x() >= (_tilemap->width() - 1) * tilesize;

  for(unsigned int y = this->y() / tilesize; (y <= ((this->y() + height() - 1) / tilesize)) && !isTouching; y++)
  {
    isTouching |= _tilemap->at(x, y) != 0;
  }

  return isTouching;
}
