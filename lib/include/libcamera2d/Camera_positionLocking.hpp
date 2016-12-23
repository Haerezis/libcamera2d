#ifndef _LIBCAMERA2D_CAMERA__POSITION_LOCKING_HPP
#define _LIBCAMERA2D_CAMERA__POSITION_LOCKING_HPP

#include "libcamera2d/Camera.hpp"

namespace libcamera2d
{
/**
 * Camera which have its position locked to the target position with on offset.
 * This camera also implement an edge-snapping mecanism that stop the camera from moving in
 * a direction when it reach an edge of the world.
 */
class Camera_positionLocking : public Camera
{
 public:
  Camera_positionLocking(unsigned int offsetX, unsigned int offsetY, unsigned int width,
                                unsigned int height, unsigned int worldWidth,
                                unsigned int worldHeight);

  /**
   * Destructor.
   */
  virtual ~Camera_positionLocking();

  /**
  * Update the camera properties (position, size, etc..) based on the target position.
  * \param[in] targetX X-axis position of the target.
  * \param[in] targetX Y-axis position of the target.
  */
  void update(unsigned int targetX, unsigned int targetY);

 protected:
  /**
  * X axis offset between the camera origin position and the target position;
  */
  unsigned int _offsetX;

  /**
  * Y axis offset between the camera origin position and the target position;
  */
  unsigned int _offsetY;
};
}

#endif
