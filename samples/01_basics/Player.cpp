#include "Player.hpp"

Player::Player(unsigned int width, unsigned int height, unsigned int worldWidth,
               unsigned int worldHeight) :
    Object2D(width, height, worldWidth, worldHeight)
{
}

Player::~Player() {}

void Player::moveHorizontal(float value)
{
  if (value < 0.0f) //LEFT
  {
    if (x() <= Player::_horizontalMoveIncrement)
    {
      x(0);
    }
    else
    {
      x(x() - Player::_horizontalMoveIncrement);
    }
  }
  else if (value > 0.0f) //RIGHT
  {
    x(x() + Player::_horizontalMoveIncrement);
  }
}

void Player::moveVertical(float value)
{
  if (value < 0.0f) //UP
  {
    if (y() <= Player::_verticalMoveIncrement)
    {
      y(0);
    }
    else
    {
      y(y() - Player::_verticalMoveIncrement);
    }
  }
  else if (value > 0.0f) //DOWN
  {
    y(y() + Player::_verticalMoveIncrement);
  }
}
