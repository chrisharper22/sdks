#ifndef SPVector3D_h
#define SPVector3D_h

#include <Spatial/Structures.h>
#include <Spatial/SPPoint3D.h>

// MARK: - SPVector3DMake

/*!
 @abstract Creates a point with the specified coordinates.
 
 @param x The first element of the vector.
 @param y The second element of the vector.
 @param z The third element of the vector.
 @returns A new vector.
 */
SPATIAL_INLINE
SPVector3D SPVector3DMake(double x, double y, double z)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

SPATIAL_REFINED_FOR_SWIFT
SPVector3D SPVector3DMake(double x, double y, double z) {
    return (SPVector3D){ .x = x, .y = y, .z = z };
}

// MARK: - SPVector3DMakeWithVector

/*!
 @abstract Creates a vector with elements specified as a 3-element SIMD vector.
 
 @param xyz The source simd vector.
 @returns A new vector.
 */
SPATIAL_INLINE
SPVector3D SPVector3DMakeWithVector(simd_double3 xyz)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

SPATIAL_REFINED_FOR_SWIFT
SPVector3D SPVector3DMakeWithVector(simd_double3 xyz) {
    return (SPVector3D){ .vector = xyz};
}

// MARK: - SPPoint3DMakeWithRotationAxis

/*!
 @abstract Creates a vector with elements specified as dimensions of a rotation axis structure.
 
 @param axis The source rotation axis.
 @returns A new vector.
 */
SPATIAL_INLINE
SPVector3D SPVector3DMakeWithRotationAxis(SPRotationAxis3D axis)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

SPATIAL_REFINED_FOR_SWIFT
SPVector3D SPVector3DMakeWithRotationAxis(SPRotationAxis3D axis) {
    return (SPVector3D){ .vector = axis.vector };
}

// MARK: - SPPoint3DMakeWithSize

/*!
 @abstract Creates a vector with elements specified as dimensions of a size structure.
 
 @param size The source size.
 @returns A new vector.
 */
SPATIAL_INLINE
SPVector3D SPVector3DMakeWithSize(SPSize3D size)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

SPATIAL_REFINED_FOR_SWIFT
SPVector3D SPVector3DMakeWithSize(SPSize3D size) {
    return (SPVector3D){ .vector = size.vector };
}

// MARK: - SPPoint3DMakeWithPoint

/*!
 @abstract Creates a vector with elements specified a coordinates of a point structure.
 
 @param point The source point.
 @returns A new vector.
 */
SPATIAL_INLINE
SPVector3D SPVector3DMakeWithPoint(SPPoint3D point)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

SPATIAL_REFINED_FOR_SWIFT
SPVector3D SPVector3DMakeWithPoint(SPPoint3D point) {
    return (SPVector3D){ .vector = point.vector};
}

// MARK: - SPVector3DEqualToPoint

/// Returns @p true if both points are equal.
SPATIAL_INLINE
bool SPVector3DEqualToVector(SPVector3D vector1, SPVector3D vector2)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

SPATIAL_REFINED_FOR_SWIFT
bool SPVector3DEqualToVector(SPVector3D vector1, SPVector3D vector2) {
    return simd_equal(vector1.vector, vector2.vector);
}

// MARK: - SPVector3DScaleBy

/*!
 @abstract Returns a vector with elements scaled by the specified values.
 
 @param vector The source vector.
 @param x The scale value for the @p x element.
 @param y The scale value for the @p y element.
 @param z The scale value for the @p z element.
 @returns A vector that's scaled by the specified values.
*/
SPATIAL_INLINE
SPVector3D SPVector3DScaleBy(SPVector3D vector, double x, double y, double z)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

SPATIAL_REFINED_FOR_SWIFT
SPVector3D SPVector3DScaleBy(SPVector3D vector, double x, double y, double z) {
    
    return (SPVector3D){ .vector = vector.vector * simd_make_double3(x, y, z)};
}

// MARK: - shear

/*!
 @abstract Returns a vector that's sheared over an axis by shear factors for the other two axes.
 
 @param vector The source vector.
 @param shearAxis The shear axis.
 @param shearFactor0 The first shear factor.
 @param shearFactor1 The second shear factor.
 @returns The transformed vector.
 @discussion
 When the shear axis is @p x , @p shearFactor0 is the @p y shear factor and @p shearFactor0 is the @p z shear factor.
 
 When the shear axis is @p y , @p shearFactor0 is the @p x  shear factor and @p shearFactor0 is the @p z shear factor.
 
 When the shear axis is @p z , @p shearFactor0 is the @p x  shear factor and @p shearFactor0 is the @p y shear factor.
 */
SPATIAL_INLINE
SPVector3D SPVector3DShear(SPVector3D vector,
                           enum SPAxis shearAxis,
                           double shearFactor0,
                           double shearFactor1)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

SPATIAL_REFINED_FOR_SWIFT
SPVector3D SPVector3DShear(SPVector3D vector,
                           enum SPAxis shearAxis,
                           double shearFactor0,
                           double shearFactor1) {
    
    SPAffineTransform3D shearTransform = SPAffineTransform3DMakeShear(shearAxis,
                                                                      shearFactor0,
                                                                      shearFactor1);
    
    return SPVector3DApplyAffineTransform(vector, shearTransform);
}

#endif /* SPVector3D_h */
