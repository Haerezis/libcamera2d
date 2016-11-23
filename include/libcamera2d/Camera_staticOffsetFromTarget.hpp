#ifndef _LIBCAMERA2D_CAMERA__STATIC_OFFSET_FROM_PLAYER_HPP
#define _LIBCAMERA2D_CAMERA__STATIC_OFFSET_FROM_PLAYER_HPP

#include "libcamera2d/camera.hpp"

namespace libcamera2d
{
class Camera_staticOffsetFromTarget : public Camera
{
  public :
    Camera_staticOffsetFromTarget(
        unsigned int offsetX,
        unsigned int offsetY,
        unsigned int width,
        unsigned int height,
        unsigned int worldWidth,
        unsigned int worldHeight);

    virtual ~Camera_staticOffsetFromTarget();

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
