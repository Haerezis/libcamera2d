#ifndef _LIBCAMERA2D_SAMPLES_TILEMAP_HPP
#define _LIBCAMERA2D_SAMPLES_TILEMAP_HPP

#include <vector>

class Tilemap
{
  public:
    Tilemap(unsigned int width = 0, unsigned int height = 0, unsigned int tilesize = 0);

    virtual ~Tilemap();

    unsigned char& operator()(unsigned int x, unsigned int y);

    unsigned int width() const;
    
    unsigned int height() const;

    unsigned int tilesize() const;

    void tilesize(unsigned int value);

    void reset(unsigned int width, unsigned int height);

  protected:

    std::vector<unsigned char> _data;

    unsigned int _width;

    unsigned int _height;

    unsigned int _tilesize;
};

#endif
