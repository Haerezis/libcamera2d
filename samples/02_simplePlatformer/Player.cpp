#include "Player.hpp"

Player::Player(
    unsigned int width,
    unsigned int height,
    unsigned int worldWidth,
    unsigned int worldHeight) :
  Object2D(width, height), _worldWidth(worldWidth), _worldHeight(worldHeight)
{}

Player::~Player() {}

unsigned int Player::worldWidth() const
{
  return _worldWidth;
}

void Player::worldWidth(unsigned int value)
{
  _worldWidth = value;
}

unsigned int Player::worldHeight() const
{
  return _worldHeight;
}

void Player::worldHeight(unsigned int value)
{
  _worldHeight = value;
}

void Player::moveHorizontal(float value)
{
}

void Player::moveVertical(float value)
{
}
