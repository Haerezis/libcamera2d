#include "Tilemap.hpp"

#include <stdexcept>

Tilemap::Tilemap(unsigned int width, unsigned int height) :
  _width(width),
  _height(height),
  _data(width * height, 0)
{
}

Tilemap::~Tilemap() {}

unsigned char& Tilemap::operator()(unsigned int x, unsigned int y)
{
  if ((y * _width + x) >= _data.size())
    throw std::out_of_range("Out of range access to the tilemap");

  return _data[y * _width + x];
}
