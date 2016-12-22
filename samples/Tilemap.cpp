#include "Tilemap.hpp"

#include <stdexcept>

Tilemap::Tilemap(unsigned int width, unsigned int height, unsigned int tilesize) :
  _width(width),
  _height(height),
  _tilesize(tilesize),
  _data(width * height, 0)
{
}

Tilemap::~Tilemap() {}

unsigned char& Tilemap::at(unsigned int x, unsigned int y)
{
  if ((y * _width + x) >= _data.size())
    throw std::out_of_range("Out of range access to the tilemap");

  return _data[y * _width + x];
}

unsigned char Tilemap::at(unsigned int x, unsigned int y) const
{
  if ((y * _width + x) >= _data.size())
    throw std::out_of_range("Out of range access to the tilemap");

  return _data[y * _width + x];
}


unsigned int Tilemap::width() const
{
  return _width;
}

unsigned int Tilemap::height() const
{
  return _height;
}

unsigned int Tilemap::tilesize() const
{
  return _tilesize;
}

void Tilemap::tilesize(unsigned int value)
{
  _tilesize = value;
}

void Tilemap::reset(unsigned int width, unsigned int height)
{
  _data.clear();

  _width = width;
  _height = height;
  _data.resize(_width * _height, 0);
}
