#ifndef Spatial_SPPoint3D_h
#define Spatial_SPPoint3D_h

#include <Spatial/Structures.h>
#include <Spatial/SPProjectiveTransform3D.h>
#include <Spatial/SPAffineTransform3D.h>

// MARK: - Public API

/*!
 @abstract Creates a point with the specified coordinates.
 
 @param x The x coordinate.
 @param y The y coordinate.
 @param z The z coordinate.
 @returns A new point.
*/
SPATIAL_INLINE
SPPoint3D SPPoint3DMake(double x, double y, double z)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Creates a point with coordinates specified as a 3-element SIMD vector.
 
 @param xyz The source vector.
 @returns A new point.
*/
SPATIAL_INLINE
SPATIAL_OVERLOADABLE
SPPoint3D SPPoint3DMakeWithVector(simd_double3 xyz)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Creates a point with coordinates specified as a Spatial vector.
 
 @param xyz The source vector.
 @returns A new point.
*/
SPATIAL_INLINE
SPATIAL_OVERLOADABLE
SPPoint3D SPPoint3DMakeWithVector(SPVector3D xyz)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));


/*!
 @abstract Creates a point with coordinates specified as a dimensions of a size structure.
 
 @param size The source size.
 @returns A new point.
*/
SPATIAL_INLINE
SPPoint3D SPPoint3DMakeWithSize(SPSize3D size)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Returns a point that's rotated by the specified quaternion around the origin.
 
 @param point The source point.
 @param quaternion The quaternion that defines the rotation.
 @returns A point that's rotated by the specified rotation.
 @discussion This function is equivalent to calling @p SPPoint3DRotateByQuaternionAroundPoint with a zero vector for the pivot.
 */
SPATIAL_INLINE
SPPoint3D SPPoint3DRotateByQuaternion(SPPoint3D point, simd_quatd quaternion)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Returns a point that's rotated by the specified rotation around the origin.
 
 @param point The source point.
 @param rotation The rotation.
 @returns A point that's rotated by the specified rotation.
 @discussion This function is equivalent to calling @p SPPoint3DRotateAroundPoint with a zero vector
 for the pivot.
 */
SPATIAL_INLINE
SPPoint3D SPPoint3DRotate(SPPoint3D point, SPRotation3D rotation)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Returns a point that's rotated by a rotation around a specified pivot.
 
 @param point The source point.
 @param rotation The rotation.
 @param pivot The center of rotation.
 @returns A point that's rotated by the specified rotation.
 */
SPATIAL_INLINE
SPPoint3D SPPoint3DRotateAroundPoint(SPPoint3D point, SPRotation3D rotation, SPPoint3D pivot)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Returns a point that's rotated by a quaternion around a specified pivot.
 
 @param point The source point.
 @param quaternion The quaternion that defines the rotation.
 @param pivot The center of rotation.
 @returns A point that's rotated by the specified rotation.
 */
SPATIAL_INLINE
SPPoint3D SPPoint3DRotateByQuaternionAroundPoint(SPPoint3D point, simd_quatd quaternion, SPPoint3D pivot)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Returns a point with an origin that is offset from that of the source point.
 
 @param point The source point.
 @param offset A size structure that defines the offset.
 @returns A point that's offset by the @p width, @p height, and @p depth of the size.
*/
SPATIAL_INLINE
SPATIAL_OVERLOADABLE
SPPoint3D SPPoint3DTranslate(SPPoint3D point, SPSize3D offset)
__API_DEPRECATED("Use `SPVector3D` variant.",
                 macos(13.0, 13.0),
                 ios(16.0, 16.0),
                 watchos(9.0, 9.0),
                 tvos(16.0, 16.0));

/*!
 @abstract Returns a point with an origin that is offset from that of the source point.
 
 @param point The source point.
 @param offset A vector that defines the offset.
 @returns A point that's offset by the @p x, @p y, and @p z of the vector.
*/
SPATIAL_INLINE
SPATIAL_OVERLOADABLE
SPPoint3D SPPoint3DTranslate(SPPoint3D point, SPVector3D offset)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Returns the position of the entity's origin.
 
 @param point The source point.
 @returns For point structures, this function returns a point that's identical to the source point.
*/
SPATIAL_INLINE
SPPoint3D SPPoint3DGetOrigin(SPPoint3D point)
__API_DEPRECATED("This function is deprecated.",
                 macos(13.0, 13.0),
                 ios(16.0, 16.0),
                 watchos(9.0, 9.0),
                 tvos(16.0, 16.0));

/*!
 @abstract Returns the distance between the origins of two points.
 
 @param point The first point.
 @param other The second point.
 @returns The distance between the two points.
*/
SPATIAL_INLINE
double SPPoint3DDistanceToPoint(SPPoint3D point, SPPoint3D other)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Returns the rotation around @p (0,0,0)  from the first point to the second point.
 
 @param point The first point.
 @param other The second point.
 @returns A rotation structure that represents the rotation.
*/
SPATIAL_INLINE
SPRotation3D SPPoint3DRotationToPoint(SPPoint3D point, SPPoint3D other)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Returns the @p x, @p y, and @p z components of the point expressed as a simd vector.
 
 @param point The source point.
 @returns A vector that represents the point.
*/
SPATIAL_INLINE simd_double3 SPPoint3DGetVector(SPPoint3D point)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Returns a point that's transformed by the specified affine transform.
 
 @param point The source point.
 @param transform The affine transform that the function applies to the point.
 @returns The transformed point,
*/
SPATIAL_INLINE
SPPoint3D SPPoint3DApplyAffineTransform(SPPoint3D point,
                                        SPAffineTransform3D transform)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Returns a point that's transformed by the specified projective transform.
 
 @param point The source point.
 @param transform The projective transform that the function applies to the point.
 @returns The transformed point.
*/
SPATIAL_INLINE
SPPoint3D SPPoint3DApplyProjectiveTransform(SPPoint3D point,
                                            SPProjectiveTransform3D transform)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Returns a point that's transformed by the inverse of the specified affine transform.
 
 @param point The source point.
 @param transform The affine transform that the function unapplies to the point.
 @returns The transformed point.
*/
SPATIAL_INLINE
SPPoint3D SPPoint3DUnapplyAffineTransform(SPPoint3D point,
                                          SPAffineTransform3D transform)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Returns a point that's transformed by the inverse of the specified projective transform.
 
 @param point The source point.
 @param transform The projective transform that the function unapplies to the point.
 @returns The transformed point.
*/
SPATIAL_INLINE
SPPoint3D SPPoint3DUnapplyProjectiveTransform(SPPoint3D point,
                                              SPProjectiveTransform3D transform)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/// Returns @p true if both points are equal.
SPATIAL_INLINE
bool SPPoint3DEqualToPoint(SPPoint3D point1, SPPoint3D point2)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

// MARK: - Header inline implementations

SPATIAL_REFINED_FOR_SWIFT
simd_double3 SPPoint3DGetVector(SPPoint3D point) {
    return point.vector;
}

SPATIAL_REFINED_FOR_SWIFT
SPPoint3D SPPoint3DMake(double x, double y, double z) {
    return (SPPoint3D){ .x = x, .y = y, .z = z };
}

SPATIAL_REFINED_FOR_SWIFT
SPATIAL_OVERLOADABLE
SPPoint3D SPPoint3DMakeWithVector(simd_double3 xyz) {
    return (SPPoint3D){ .vector = xyz};
}

SPATIAL_REFINED_FOR_SWIFT
SPATIAL_OVERLOADABLE
SPPoint3D SPPoint3DMakeWithVector(SPVector3D xyz) {
    return (SPPoint3D){ .vector = xyz.vector};
}

SPATIAL_REFINED_FOR_SWIFT
SPPoint3D SPPoint3DMakeWithSize(SPSize3D size) {
    return (SPPoint3D){ .vector = size.vector};
}

SPATIAL_SWIFT_NAME(Point3D.rotated(self:by:))
SPPoint3D SPPoint3DRotate(SPPoint3D point, SPRotation3D rotation) {
    
    SPAffineTransform3D transform = SPAffineTransform3DMakeRotation(rotation);
    
    return SPPoint3DApplyAffineTransform(point, transform);
}

SPATIAL_SWIFT_NAME(Point3D.rotated(self:by:around:))
SPPoint3D SPPoint3DRotateAroundPoint(SPPoint3D point, SPRotation3D rotation, SPPoint3D pivot) {
    
    SPAffineTransform3D transform = SPAffineTransform3DMakeRotation(rotation);
    
    point = (SPPoint3D){ .vector = point.vector - pivot.vector } ;
    point = SPPoint3DApplyAffineTransform(point, transform);
    
    return (SPPoint3D){ .vector = point.vector + pivot.vector } ;
}

SPATIAL_SWIFT_NAME(Point3D.rotated(self:by:))
SPPoint3D SPPoint3DRotateByQuaternion(SPPoint3D point, simd_quatd quaternion) {
    
    SPRotation3D rotation = SPRotation3DMakeWithQuaternion(quaternion);
    
    
    return SPPoint3DRotate(point, rotation);
}

SPATIAL_SWIFT_NAME(Point3D.rotated(self:by:around:))
SPPoint3D SPPoint3DRotateByQuaternionAroundPoint(SPPoint3D point, simd_quatd quaternion, SPPoint3D pivot) {
    
    SPRotation3D rotation = SPRotation3DMakeWithQuaternion(quaternion);
    
    
    return SPPoint3DRotateAroundPoint(point, rotation, pivot);
}

SPATIAL_REFINED_FOR_SWIFT
SPATIAL_OVERLOADABLE
SPPoint3D SPPoint3DTranslate(SPPoint3D point, SPSize3D offset) {
    
    return (SPPoint3D) { .vector = point.vector + offset.vector};
}

SPATIAL_SWIFT_NAME(Point3D.translated(self:by:))
SPATIAL_OVERLOADABLE
SPPoint3D SPPoint3DTranslate(SPPoint3D point, SPVector3D offset) {
    
    return (SPPoint3D) { .vector = point.vector + offset.vector};
}

SPATIAL_SWIFT_NAME(Point3D.rotation(self:to:))
SPRotation3D SPPoint3DRotationToPoint(SPPoint3D point, SPPoint3D other) {
    
    simd_quatd quaternion = simd_quaternion(point.vector, other.vector);

    return (SPRotation3D) { .quaternion = quaternion };
}

SPATIAL_REFINED_FOR_SWIFT
SPPoint3D SPPoint3DGetOrigin(SPPoint3D point) {
    return point;
}

SPATIAL_SWIFT_NAME(Point3D.distance(self:to:))
double SPPoint3DDistanceToPoint(SPPoint3D point, SPPoint3D other) {
    return simd_distance(point.vector, other.vector);
}

SPATIAL_SWIFT_NAME(Point3D.unapplying(self:_:))
SPPoint3D SPPoint3DUnapplyAffineTransform(SPPoint3D point, SPAffineTransform3D transform) {
    SPAffineTransform3D invertedTransform = SPAffineTransform3DInverted(transform);
    
    return SPPoint3DApplyAffineTransform(point, invertedTransform);
}

SPATIAL_SWIFT_NAME(Point3D.unapplying(self:_:))
SPPoint3D SPPoint3DUnapplyProjectiveTransform(SPPoint3D point, SPProjectiveTransform3D transform) {
    SPProjectiveTransform3D invertedTransform = SPProjectiveTransform3DInverted(transform);
    
    return SPPoint3DApplyProjectiveTransform(point, invertedTransform);
}

SPATIAL_SWIFT_NAME(Point3D.applying(self:_:))
SPPoint3D SPPoint3DApplyAffineTransform(SPPoint3D point, SPAffineTransform3D transform) {
 
    simd_double4 rhs = simd_make_double4(point.vector, 1);
    
    simd_double3 transformed = simd_mul(transform.matrix, rhs).xyz;
    
    return (SPPoint3D){ .vector = transformed };
}

SPATIAL_SWIFT_NAME(Point3D.applying(self:_:))
SPPoint3D SPPoint3DApplyProjectiveTransform(SPPoint3D point, SPProjectiveTransform3D transform) {

    simd_double4 rhs = simd_make_double4(point.vector, 1);
    
    simd_double3 transformed = simd_mul(transform.matrix, rhs).xyz;
    
    return (SPPoint3D){ .vector = transformed };
}

SPATIAL_REFINED_FOR_SWIFT
bool SPPoint3DEqualToPoint(SPPoint3D point1, SPPoint3D point2) {
    return simd_equal(point1.vector, point2.vector);
}

// MARK: - Vector Methods

// MARK: - SPVector3DApplyAffineTransform

/*!
 @abstract Returns a vector that's transformed by the specified affine transform.
 
 @param vector The source vector.
 @param transform The affine transform that the function applies to the vector.
 @returns The transformed vector.
 */
SPATIAL_INLINE
SPVector3D SPVector3DApplyAffineTransform(SPVector3D vector,
                                          SPAffineTransform3D transform)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

SPATIAL_SWIFT_NAME(Vector3D.applying(self:_:))
SPVector3D SPVector3DApplyAffineTransform(SPVector3D vector,
                                          SPAffineTransform3D transform) {
    
    simd_double4 rhs = simd_make_double4(vector.vector, 0);
    
    simd_double3 transformed = simd_mul(transform.matrix, rhs).xyz;
    
    return (SPVector3D){ .vector = transformed };
}

// MARK: - SPVector3DApplyProjectiveTransform

/*!
 @abstract Returns a vector that's transformed by the specified projective transform.
 
 @param vector The source vector.
 @param transform The projective transform that the function applies to the vector.
 @returns The transformed vector.
 */
SPATIAL_INLINE
SPVector3D SPVector3DApplyProjectiveTransform(SPVector3D vector,
                                              SPProjectiveTransform3D transform)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

SPATIAL_SWIFT_NAME(Vector3D.applying(self:_:))
SPVector3D SPVector3DApplyProjectiveTransform(SPVector3D vector,
                                              SPProjectiveTransform3D transform) {
    
    simd_double4 rhs = simd_make_double4(vector.vector, 0);
    
    simd_double3 transformed = simd_mul(transform.matrix, rhs).xyz;
    
    return (SPVector3D){ .vector = transformed };
}

// MARK: - SPVector3DUnapplyAffineTransform

/*!
 @abstract Returns a vector that's transformed by the inverse of the specified affine transform.
 
 @param vector The source vector.
 @param transform The affine transform whose inverse is to be applied to the vector.
 @returns The transformed vector.
 */
SPATIAL_INLINE
SPVector3D SPVector3DUnapplyAffineTransform(SPVector3D vector,
                                            SPAffineTransform3D transform)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

SPATIAL_SWIFT_NAME(Vector3D.unapplying(self:_:))
SPVector3D SPVector3DUnapplyAffineTransform(SPVector3D vector,
                                            SPAffineTransform3D transform) {
    
    SPPoint3D p = (SPPoint3D){ .vector = vector.vector};
    p = SPPoint3DUnapplyAffineTransform(p, transform);
    
    return (SPVector3D){ .vector = p.vector};
}

// MARK: - SPVector3DUnapplyProjectiveTransform

/*!
 @abstract Returns a vector that's transformed by the inverse of the specified projective transform.
 
 @param vector The source vector.
 @param transform The projective transform whose inverse is to be applied to the vector.
 @returns The transformed vector.
 */
SPATIAL_INLINE
SPVector3D SPVector3DUnapplyProjectiveTransform(SPVector3D vector,
                                                SPProjectiveTransform3D transform)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

SPATIAL_SWIFT_NAME(Vector3D.unapplying(self:_:))
SPVector3D SPVector3DUnapplyProjectiveTransform(SPVector3D vector,
                                                SPProjectiveTransform3D transform) {
    
    SPPoint3D p = (SPPoint3D){ .vector = vector.vector};
    p = SPPoint3DUnapplyProjectiveTransform(p, transform);
    
    return (SPVector3D){ .vector = p.vector};
}

// MARK: - SPVector3DRotationToVector

/*!
 @abstract Returns the rotation around @p (0,0,0)  from the first vector to the second vector.
 
 @param vector The first vector.
 @param other The second vector.
 @returns A rotation structure that represents the rotation.
*/
SPATIAL_INLINE
SPRotation3D SPVector3DRotationToVector(SPVector3D vector, SPVector3D other)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

SPATIAL_SWIFT_NAME(Vector3D.rotation(self:to:))
SPRotation3D SPVector3DRotationToVector(SPVector3D vector, SPVector3D other) {
    
    SPPoint3D p0 = (SPPoint3D){ .vector = vector.vector};
    SPPoint3D p1 = (SPPoint3D){ .vector = other.vector};

    return SPPoint3DRotationToPoint(p0, p1);
}



// MARK: - SPVector3DScaleBySize

/*!
 @abstract Returns a vector with elements scaled by the specified size.
 
 @param vector The source vector.
 @param scale The scale value.
 @returns A vector that's scaled by the specified value.
*/
SPATIAL_INLINE
SPVector3D SPVector3DScaleBySize(SPVector3D vector, SPSize3D scale)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

SPATIAL_SWIFT_NAME(Vector3D.scaled(self:by:))
SPVector3D SPVector3DScaleBySize(SPVector3D vector, SPSize3D scale) {
    
    return (SPVector3D){ .vector = vector.vector * scale.vector };
}

// MARK: - SPVector3DScaleUniform

/*!
 @abstract Returns a vector with elements uniformly scaled by the specified value.
 
 @param vector The source vector.
 @param scale The scale value.
 @returns A vector that's uniformly scaled by the specified value.
*/
SPATIAL_INLINE
SPVector3D SPVector3DScaleUniform(SPVector3D vector, double scale)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

SPATIAL_SWIFT_NAME(Vector3D.uniformlyScaled(self:by:))
SPVector3D SPVector3DScaleUniform(SPVector3D vector, double scale) {
    
    return (SPVector3D){ .vector = vector.vector * scale };
}

// MARK: - SPVector3DRotate

/*!
 @abstract Returns a vector that's rotated by the specified rotation around the origin.
 
 @param vector The source vector.
 @param rotation The rotation.
 @returns A vector that's rotated by the specified rotation.
 */
SPATIAL_INLINE
SPVector3D SPVector3DRotate(SPVector3D vector, SPRotation3D rotation)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

SPATIAL_SWIFT_NAME(Vector3D.rotated(self:by:))
SPVector3D SPVector3DRotate(SPVector3D vector, SPRotation3D rotation) {
    
    SPAffineTransform3D transform = SPAffineTransform3DMakeRotation(rotation);
    
    return SPVector3DApplyAffineTransform(vector, transform);
}

// MARK: - SPVector3DRotateByQuaternion

/*!
 @abstract Returns a vector that's rotated by the specified quaternion around the origin.
 
 @param vector The source vector.
 @param quaternion The quaternion that defines the rotation.
 @returns A vector that's rotated by the specified quaternion.
 */
SPATIAL_INLINE
SPVector3D SPVector3DRotateByQuaternion(SPVector3D vector, simd_quatd quaternion)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

SPATIAL_SWIFT_NAME(Vector3D.rotated(self:by:))
SPVector3D SPVector3DRotateByQuaternion(SPVector3D vector, simd_quatd quaternion) {
    
    SPRotation3D rotation = SPRotation3DMakeWithQuaternion(quaternion);
    
    return SPVector3DRotate(vector, rotation);
}

#endif /* Spatial_SPPoint3D_h */
