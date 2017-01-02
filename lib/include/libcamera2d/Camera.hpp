#ifndef _LIBCAMERA2D_CAMERA_HPP
#define _LIBCAMERA2D_CAMERA_HPP

#include "libcamera2d/Object2D.hpp"

namespace libcamera2d
{
/**
 * The base class for all Camera class.
 */
class Camera : public Object2D
{
 public:
  /**
   * Basic constructor.
   * \param[in] width The initial width of the camera.
   * \param[in] height The initial height of the camera.
   * \param[in] worldWidth The width of the world in which the camera is moving. 0 means no maximum
   * width.
   * \param[in] worldHeight The width of the height in which the camera is moving. 0 means no
   * maximum height.
   */
  Camera(unsigned int width, unsigned int height, unsigned int worldWidth,
         unsigned int worldHeight);

  /**
   * Destructor.
   */
  virtual ~Camera();
};
}

#endif
