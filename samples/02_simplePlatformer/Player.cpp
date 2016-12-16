#include "Player.hpp"

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

void Player::moveHorizontal(float value)
{
  /*
  if (value < 0.0f) //LEFT
  {
    if (_x <= Player::_horizontalMoveIncrement)
    {
      _x = 0;
    }
    else
    {
      _x -= Player::_horizontalMoveIncrement;
    }
  }
  else if (value > 0.0f) //RIGHT
  {
    _x += Player::_horizontalMoveIncrement;

    if (_x >= (_worldWidth - _width))
    {
      _x = _worldWidth - _width;
    }
  }
  */
}

void Player::moveVertical(float value)
{
  /*
  if (value < 0.0f) //UP
  {
    if (_y <= Player::_verticalMoveIncrement)
    {
      _y = 0;
    }
    else
    {
      _y -= Player::_verticalMoveIncrement;
    }
  }
  else if (value > 0.0f) //DOWN
  {
    _y += Player::_verticalMoveIncrement;
    if (_y >= (_worldHeight - _height))
    {
      _y = _worldHeight - _height;
    }
  }
  */
}
