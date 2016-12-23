#ifndef _LIBCAMERA2D_OBJECT2D_HPP
#define _LIBCAMERA2D_OBJECT2D_HPP

namespace libcamera2d
{
/**
 * The base class for all Camera class.
 */
class Object2D
{
 public:
  /**
   * Basic constructor.
   * \param[in] width The initial width of the object.
   * \param[in] height The initial height of the object.
   */
  Object2D(unsigned int width, unsigned int height);

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

 protected:
  /**
   * The X-axis origin of the object.
   */
  unsigned int _x;

  /**
   * The Y-axis origin of the object.
   */
  unsigned int _y;

  /**
   * The width of the object.
   */
  unsigned int _width;

  /**
   * The height of the object.
   */
  unsigned int _height;

};
}

#endif
