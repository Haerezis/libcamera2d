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
   * \param[in] width The initial width of the camera.
   * \param[in] height The initial height of the camera.
   * \param[in] worldWidth The width of the world in which the camera is moving. 0 means no maximum width.
   * \param[in] worldHeight The width of the height in which the camera is moving. 0 means no maximum height.
   */
  Camera(unsigned int width,
     unsigned int height,
     unsigned int worldWidth,
     unsigned int worldHeight);

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
   * Get the height (in pixels) of the image displayed by the camera.
   * \return the height (in pixels) of the image displayed by the camera.
   */
  unsigned int height() const;

  /**
   * Get the width (in pixels) of the image displayed by the camera.
   * \return the width (in pixels) of the image displayed by the camera.
   */
  unsigned int width() const;

  /**
   * Get the height (in pixels) of the world in which the camera is moving.
   * \return The height (in pixels) of the world in which the camera is moving.
   */
  unsigned int worldHeight() const;

  /**
   * Set the height (in pixels) of the world in which the camera is moving.
   * \param[in] The height (in pixels) of the world in which the camera is moving.
   */
  void worldHeight(unsigned int height);

  /**
   * Get the width (in pixels) of the world in which the camera is moving.
   * \return The width (in pixels) of the world in which the camera is moving.
   */
  unsigned int worldWidth() const;

  /**
   * Set the width (in pixels) of the world in which the camera is moving.
   * \param[in] The width (in pixels) of the world in which the camera is moving.
   */
  void worldWidth(unsigned int width);

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
   * The height (in pixels) of the world in which the camera is moving.
   * If 0, the world doesn't have any Y axis bound.
   */
  unsigned int _worldHeight;

  /**
   * The width (in pixels) of the world in which the camera is moving.
   * If 0, the world doesn't have any X axis bound.
   */
  unsigned int _worldWidth;
};
}

#endif
