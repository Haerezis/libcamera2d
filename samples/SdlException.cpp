#include "SdlException.hpp"

#include <SDL.h>

SdlException::SdlException() : exception(), _msg(SDL_GetError())
{}

SdlException::SdlException(const std::string& m) : exception(), _msg(m)
{}

SdlException::~SdlException()
{}

const char* SdlException::what() const noexcept
{
  return _msg.c_str();
}
