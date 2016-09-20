#ifndef _LIBCAMERA2D_CAMERA_HPP
#define _LIBCAMERA2D_CAMERA_HPP

namespace libcamera2d
{
/**
 * The base class for all Camera class.
 */
class Camera
{
 public:
  /**
   * Basic constructor.
   */
  Camera();

  /**
   * Destructor.
   */
  virtual ~Camera();

  /**
   * Get the X axis origin of the camera.
   * \return the X axis origin of the camera.
   */
  unsigned int x() const;

  /**
   * Get the Y axis origin of the camera.
   * \return the Y axis origin of the camera.
   */
  unsigned int y() const;

  /**
   * Get the height (in pixels) of the image displayed by the camera
   * \return the height (in pixels) of the image displayed by the camera
   */
  unsigned int height() const;

  /**
   * Get the width (in pixels) of the image displayed by the camera
   * \return the width (in pixels) of the image displayed by the camera
   */
  unsigned int width() const;

  /**
   * Get the scale value of the camera.
   * \return The scale value of the camera.
   */
  float scale() const;

 protected:
  /**
   * The X-axis origin of the camera.
   */
  unsigned int _x;

  /**
   * The Y-axis origin of the camera.
   */
  unsigned int _y;

  /**
   * The height (in pixels) of the image displayed by the camera.
   */
  unsigned int _height;

  /**
   * The width (in pixels) of the image displayed by the camera.
   */
  unsigned int _width;

  /**
   * The scale of the image displayed by the camera.
   */
  float _scale;
};
}

#endif
