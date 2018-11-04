#ifndef _LIBCAMERA2D_OBJECT_1D_HPP
#define _LIBCAMERA2D_OBJECT_1D_HPP


namespace libcamera2d
{
/**
 * A class representing all the basic spatial informations of a Object
 * in a specific dimension.
 * In clear, this object represent of the 1D infos of a dimentional object.
 */
class Object1D
{
  public:
  /**
   * Basic constructor.
   * \param[in] size the size of the object in the dimension represented by this object.
   * \param[in] bound the bound for the position of the object in the dimension represented by this object.
   */
  Object1D(unsigned int size, unsigned int bound);

  /**
   * Destructor.
   */
  virtual ~Object1D();
  
  /**
   * Get the position (in pixel) of the object's origin in this dimension.
   * The origin of the object correspond to the top-left point of the object.
   *
   * \return The position(origin) of the object.
   */
  unsigned int position() const;

  /**
   * Set the position (in pixel) of the object's origin in this dimension.
   * The origin of the object correspond to the top-left point of the object.
   *
   * \param[in] value the value to set as position (in pixel).
   */
  void position(unsigned int value);

  /**
   * Get the bound (in pixel) of the object in this dimension.
   * The object cannot be positionned to a point after this bound (also taking into account its size).
   *
   * \return The bound (in pixel) of the object.
   */
  unsigned int bound() const;

  /**
   * Set the bound (in pixel) of the object in this dimension.
   * The object cannot be positionned to a point after this bound (also taking into account its size).
   *
   * \param[in] value the value to set as bound (in pixel).
   */
  void bound(unsigned int value);

  /**
   * Get the size (in pixel) of the object in this dimension.
   *
   * \return The position (in pixel) of the object.
   */
  unsigned int size() const;

  /**
   * Set the size (in pixel) of the object in this dimension.
   *
   * \param[in] value the value to set as size (in pixel).
   */
  void size(unsigned int value);

  protected:

  /**
   * The position of the object in this dimension (in pixel).
   */
  unsigned int _position;
  
  /**
   * The bound for the position of the object in this dimension (in pixel).
   * It is the maximum value (_position + _size) can take.
   */
  unsigned int _bound;

  /**
   * The size (in pixel) of the object in this dimension.
   */
  unsigned int _size;
};

}

#endif
