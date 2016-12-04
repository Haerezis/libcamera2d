#include <exception>
#include <iostream>
#include <memory>
#include <string>

#include <SDL.h>

#include "Player.hpp"
#include "libcamera2d/Camera_staticOffsetFromTarget.hpp"
#include "tilemap_data.hpp"

class SdlException : public std::exception
{
 public:
  SdlException();
  SdlException(const std::string& m);
  virtual ~SdlException() throw();
  virtual const char* what() const throw();

 protected:
  std::string _msg;
};

SdlException::SdlException() : exception(), _msg(SDL_GetError()) {}

SdlException::SdlException(const std::string& m) : exception(), _msg(m) {}

SdlException::~SdlException() throw() {}

const char* SdlException::what() const throw() { return _msg.c_str(); }

//////////////////////////
//////////////////////////
//////////////////////////

class DemoSDL
{
 public:
  DemoSDL(unsigned int windowsWidth, unsigned int windowsHeight, unsigned int tileSize,
          Uint32 flags = 0);
  virtual ~DemoSDL();

  void draw();

  void handleEvent();
  void handleEventKeyDown(const SDL_KeyboardEvent& event);
  void handleKeyboardState();

  void updateCamera();

 protected:
  unsigned int _windowWidth;
  unsigned int _windowHeight;

  unsigned char** _tileMap;
  unsigned int _tileMapWidth;
  unsigned int _tileMapHeight;
  unsigned int _tileSize;

  unsigned int _playerPositionX;
  unsigned int _playerPositionY;
  unsigned int _playerSize;

  std::unique_ptr<libcamera2d::Camera_staticOffsetFromTarget> _camera;

  SDL_Window* _window;
  SDL_Renderer* _renderer;

  static const unsigned int _playerMoveIncrement;
};

const unsigned int DemoSDL::_playerMoveIncrement = 4;

DemoSDL::DemoSDL(unsigned int windowWidth, unsigned int windowHeight, unsigned int tileSize,
                 Uint32 flags)
    : _windowWidth(windowWidth),
      _windowHeight(windowHeight),
      _tileSize(tileSize),
      _playerPositionX(0),
      _playerPositionY(0),
      _playerSize(tileSize)
{
  if (SDL_Init(flags) != 0) throw SdlException();

  auto res = SDL_CreateWindowAndRenderer(_windowWidth, _windowHeight, SDL_WINDOW_SHOWN, &_window,
                                         &_renderer);

  if (res != 0) throw SdlException();

  _tileMapWidth = sizeof(tilemap_data) / sizeof(tilemap_data[0]);
  _tileMapHeight = sizeof(tilemap_data[0]) / sizeof(tilemap_data[0][0]);

  _tileMap = new unsigned char*[_tileMapWidth];
  for (unsigned int x = 0; x < _tileMapWidth; x++)
  {
    _tileMap[x] = new unsigned char[_tileMapHeight];
    for (unsigned int y = 0; y < _tileMapHeight; y++)
    {
      _tileMap[x][y] = tilemap_data[x][y];
    }
  }

  _camera.reset(new libcamera2d::Camera_staticOffsetFromTarget(
      (_windowWidth - _playerSize) / 2, (_windowHeight - _playerSize) / 2, _windowWidth,
      _windowHeight, _tileMapWidth * _tileSize, _tileMapHeight * _tileSize));

  updateCamera();
}

DemoSDL::~DemoSDL()
{
  SDL_DestroyWindow(_window);
  SDL_DestroyRenderer(_renderer);
  SDL_Quit();
}

void DemoSDL::draw()
{
  // Clear the window with a black background
  SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
  SDL_RenderClear(_renderer);

  SDL_Rect tile = {0, 0, static_cast<int>(_tileSize), static_cast<int>(_tileSize)};
  SDL_Rect player = {0, 0, static_cast<int>(_playerSize), static_cast<int>(_playerSize)};

  for (unsigned int x = 0; x < _tileMapWidth; x++)
  {
    for (unsigned int y = 0; y < _tileMapHeight; y++)
    {
      tile.x = x * _tileSize - _camera->x();
      tile.y = y * _tileSize - _camera->y();

      if (_tileMap[x][y] == 0)
      {
        SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
      }
      else
      {
        SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
      }

      SDL_RenderFillRect(_renderer, &tile);
    }
  }

  player.x = _playerPositionX - _camera->x();
  player.y = _playerPositionY - _camera->y();
  SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
  SDL_RenderFillRect(_renderer, &player);

  SDL_RenderPresent(_renderer);
}

void DemoSDL::handleEvent()
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_KEYDOWN:
        handleEventKeyDown(event.key);
        break;
      default:
        break;
    }
  }
}

void DemoSDL::handleEventKeyDown(const SDL_KeyboardEvent& event)
{
  switch (event.keysym.sym)
  {
    case SDLK_ESCAPE:
      SDL_Quit();
      exit(0);
      break;
    default:
      break;
  }
}

void DemoSDL::handleKeyboardState()
{
  const Uint8* state = SDL_GetKeyboardState(NULL);

  if (state[SDL_SCANCODE_DOWN])
  {
    _playerPositionY += DemoSDL::_playerMoveIncrement;
    if (_playerPositionY >= (_tileMapHeight * _tileSize - _playerSize))
    {
      _playerPositionY = _tileMapHeight * _tileSize - _playerSize;
    }
  }
  if (state[SDL_SCANCODE_UP])
  {
    if (_playerPositionY <= DemoSDL::_playerMoveIncrement)
    {
      _playerPositionY = 0;
    }
    else
    {
      _playerPositionY -= DemoSDL::_playerMoveIncrement;
    }
  }

  if (state[SDL_SCANCODE_RIGHT])
  {
    _playerPositionX += DemoSDL::_playerMoveIncrement;
    if (_playerPositionX >= (_tileMapWidth * _tileSize - _playerSize))
    {
      _playerPositionX = _tileMapWidth * _tileSize - _playerSize;
    }
  }
  if (state[SDL_SCANCODE_LEFT])
  {
    if (_playerPositionX <= DemoSDL::_playerMoveIncrement)
    {
      _playerPositionX = 0;
    }
    else
    {
      _playerPositionX -= DemoSDL::_playerMoveIncrement;
    }
  }
}

void DemoSDL::updateCamera() { _camera->update(_playerPositionX, _playerPositionY); }

int main(int argc, char** argv)
{
  try
  {
    const unsigned int fps = 60;
    const unsigned int frameDuration = 1000 / fps;
    unsigned int timeBefore = 0;

    DemoSDL sdl(480, 360, 32, SDL_INIT_VIDEO | SDL_INIT_TIMER);

    while (true)
    {
      timeBefore = SDL_GetTicks();

      sdl.handleEvent();
      sdl.handleKeyboardState();
      sdl.updateCamera();
      sdl.draw();

      SDL_Delay(frameDuration - std::min(frameDuration, (SDL_GetTicks() - timeBefore)));
    }

    return 0;
  }
  catch (const SdlException& err)
  {
    std::cerr << "Error while initializing SDL:  " << err.what() << std::endl;
  }

  return 1;
}
