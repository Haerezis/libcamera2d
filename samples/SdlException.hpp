#ifndef _LIBCAMERA2D_SAMPLE_SDLEXCEPTION__HPP
#define _LIBCAMERA2D_SAMPLE_SDLEXCEPTION__HPP

#include <exception>
#include <string>

class SdlException : public std::exception
{
 public:
  SdlException();
  SdlException(const std::string& m);
  virtual ~SdlException();
  virtual const char* what() const noexcept;

 protected:
  std::string _msg;
};


#endif
