#include "Player.hpp"

Player::Player(unsigned int width, unsigned int height, unsigned int worldWidth,
               unsigned int worldHeight) :
    Object2D(width, height),
    _worldWidth(worldWidth),
    _worldHeight(worldHeight)
{
}

Player::~Player() {}

unsigned int Player::worldWidth() const { return _worldWidth; }

void Player::worldWidth(unsigned int value) { _worldWidth = value; }

unsigned int Player::worldHeight() const { return _worldHeight; }

void Player::worldHeight(unsigned int value) { _worldHeight = value; }

void Player::moveHorizontal(float value)
{
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
}

void Player::moveVertical(float value)
{
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
}
