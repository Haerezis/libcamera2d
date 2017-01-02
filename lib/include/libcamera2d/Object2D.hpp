#ifndef _LIBCAMERA2D_OBJECT2D_HPP
#define _LIBCAMERA2D_OBJECT2D_HPP

#include "libcamera2d/ObjectDimension.hpp"

namespace libcamera2d
{
/**
 * The base class for 2D objects.
 */
class Object2D
{
 public:
  /**
   * Basic constructor.
   * \param[in] width The initial width of the object.
   * \param[in] height The initial height of the object.
   * \param[in] worldWidth The width of the world in which the object is moving. 0 means no maximum
   * width.
   * \param[in] worldHeight The width of the height in which the object is moving. 0 means no
   * maximum height.
   */
  Object2D(unsigned int width, unsigned int height, unsigned int worldWidth,
         unsigned int worldHeight);

  /**
   * Destructor.
   */
  ~Object2D();

  /**
   * Get the X axis origin of the object.
   * \return the X axis origin of the object.
   */
  unsigned int x() const;

  /**
   * Set the X axis origin of the object.
   */
  void x(unsigned int value);

  /**
   * Get the Y axis origin of the object.
   * \return the Y axis origin of the object.
   */
  unsigned int y() const;

  /**
   * Set the Y axis origin of the object.
   */
  void y(unsigned int value);

  /**
   * Get the height (in pixels) of the object.
   * \return the height (in pixels) of the object.
   */
  unsigned int height() const;

  /**
   * Set the height (in pixels) of the object.
   */
  void height(unsigned int value);

  /**
   * Get the width (in pixels) of the image displayed by the object.
   * \return the width (in pixels) of the image displayed by the object.
   */
  unsigned int width() const;

  /**
   * Set the width (in pixels) of the object.
   */
  void width(unsigned int value);

  /**
   * Get the height (in pixels) of the world in which the object is moving.
   * \return The height (in pixels) of the world in which the object is moving.
   */
  unsigned int worldHeight() const;

  /**
   * Set the height (in pixels) of the world in which the object is moving.
   * \param[in] The height (in pixels) of the world in which the object is moving.
   */
  void worldHeight(unsigned int height);

  /**
   * Get the width (in pixels) of the world in which the object is moving.
   * \return The width (in pixels) of the world in which the object is moving.
   */
  unsigned int worldWidth() const;

  /**
   * Set the width (in pixels) of the world in which the object is moving.
   * \param[in] The width (in pixels) of the world in which the object is moving.
   */
  void worldWidth(unsigned int width);

 protected:
  ObjectDimension _horizontalDimension;
  
  ObjectDimension _verticalDimension;

};
}

#endif
