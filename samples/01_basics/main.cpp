#include <exception>
#include <iostream>
#include <memory>
#include <string>

#include <SDL.h>

#include "Player.hpp"
#include "libcamera2d/Camera_positionLocking.hpp"
#include "tilemap_data.hpp"
#include "Tilemap.hpp"
#include "SdlException.hpp"

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
  
  Tilemap _tileMap;

  Player _player;

  std::unique_ptr<libcamera2d::Camera_positionLocking> _camera;

  SDL_Window* _window;
  SDL_Renderer* _renderer;
};

DemoSDL::DemoSDL(unsigned int windowWidth, unsigned int windowHeight, unsigned int tileSize,
                 Uint32 flags)
    : _windowWidth(windowWidth),
      _windowHeight(windowHeight),
      _tileMap(
          sizeof(tilemap_data) / sizeof(tilemap_data[0]),
          sizeof(tilemap_data[0]) / sizeof(tilemap_data[0][0]),
          tileSize),
      _player(tileSize / 4, tileSize / 4)
{
  if (SDL_Init(flags) != 0) throw SdlException();

  auto res = SDL_CreateWindowAndRenderer(_windowWidth, _windowHeight, SDL_WINDOW_SHOWN, &_window,
                                         &_renderer);

  if (res != 0) throw SdlException();

  for (unsigned int x = 0; x < _tileMap.width(); x++)
  {
    for (unsigned int y = 0; y < _tileMap.height(); y++)
    {
      _tileMap.at(x, y) = tilemap_data[x][y];
    }
  }

  _camera.reset(new libcamera2d::Camera_positionLocking(
      (_windowWidth - _player.width()) / 2, (_windowHeight - _player.height()) / 2, _windowWidth,
      _windowHeight, _tileMap.width() * _tileMap.tilesize(), _tileMap.height() * _tileMap.tilesize()));

  _player.worldWidth(_tileMap.width() * _tileMap.tilesize());
  _player.worldHeight(_tileMap.height() * _tileMap.tilesize());

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

  SDL_Rect tile = {0, 0, static_cast<int>(_tileMap.tilesize()), static_cast<int>(_tileMap.tilesize())};
  SDL_Rect player = {0, 0, static_cast<int>(_player.width()), static_cast<int>(_player.height())};

  for (unsigned int x = 0; x < _tileMap.width(); x++)
  {
    for (unsigned int y = 0; y < _tileMap.height(); y++)
    {
      tile.x = x * _tileMap.tilesize() - _camera->x();
      tile.y = y * _tileMap.tilesize() - _camera->y();

      if (_tileMap.at(x, y) == 0)
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

  player.x = _player.x() - _camera->x();
  player.y = _player.y() - _camera->y();
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

  if (state[SDL_SCANCODE_UP])
  {
    _player.moveVertical(-1.0f);
  }
  if (state[SDL_SCANCODE_DOWN])
  {
    _player.moveVertical(1.0f);
  }

  if (state[SDL_SCANCODE_LEFT])
  {
    _player.moveHorizontal(-1.0f);
  }
  if (state[SDL_SCANCODE_RIGHT])
  {
    _player.moveHorizontal(1.0f);
  }
}

void DemoSDL::updateCamera()
{
  _camera->update(_player.x(), _player.y());
}

int main()
{
  try
  {
    const unsigned int fps = 60;
    const unsigned int frameDuration = 1000 / fps;
    unsigned int timeBefore = 0;

    DemoSDL sdl(640, 480, 64, SDL_INIT_VIDEO | SDL_INIT_TIMER);

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
