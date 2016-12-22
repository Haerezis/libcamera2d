#include "Player.hpp"

#include <cmath>
#include <iostream>

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

  const unsigned int tilesize = _tilemap->tilesize();
  const unsigned int worldWidth = _tilemap->width() * tilesize;
  const unsigned int oldX = _x;

  _horizontalVelocity += _horizontalAcceleration;
  if(_horizontalVelocity > _maxHorizontalVelocity) _horizontalVelocity = _maxHorizontalVelocity;
  
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

void Player::moveLeft(float value)
{
  if(value > 1.0f) value = 1.0f;
  if(value < 0.0f)
  {
    moveRight(value);
    return;
  }

  const unsigned int tilesize = _tilemap->tilesize();
  const unsigned int worldWidth = _tilemap->width() * _tilemap->tilesize();
  const unsigned int oldX = _x;

  _horizontalVelocity -= _horizontalAcceleration;
  if(_horizontalVelocity < (-_maxHorizontalVelocity)) _horizontalVelocity = -_maxHorizontalVelocity;

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

void Player::moveUp(float value)
{
  if(value > 1.0f) value = 1.0f;
  if(value < 0.0f)
  {
    moveDown(value);
    return;
  }
  
  const unsigned int tilesize = _tilemap->tilesize();
  const unsigned int worldHeight = _tilemap->height() * _tilemap->tilesize();
  const unsigned int oldY = _y;

  _verticalVelocity -= _verticalAcceleration;
  if(_verticalVelocity < (-_maxHorizontalVelocity)) _verticalVelocity = -_maxHorizontalVelocity;

  _y = (_y < (-_verticalVelocity)) ? 0 : _y + _verticalVelocity;

  bool hitSomething = false;
  for(unsigned int y = (oldY / tilesize); (y >= (_y / tilesize)) && !hitSomething; y--)
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

void Player::moveDown(float value)
{
  if(value > 1.0f) value = 1.0f;
  if(value < 0.0f)
  {
    moveUp(value);
    return;
  }

  const unsigned int tilesize = _tilemap->tilesize();
  const unsigned int worldHeight = _tilemap->height() * tilesize;
  unsigned int oldY = _y;

  _verticalVelocity += _verticalAcceleration;
  if(_verticalVelocity > _maxHorizontalVelocity) _verticalVelocity = _maxHorizontalVelocity;
  
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
