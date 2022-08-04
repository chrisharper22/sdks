#ifndef Spatial_SPAngle_h
#define Spatial_SPAngle_h

#include <Spatial/Structures.h>
#include <math.h>

// MARK: - Public API

/*!
 @abstract Returns an angle with the value specified in degrees.
 
 @param degrees The angle in degrees.
 @returns A new angle structure.
*/
SPATIAL_INLINE
SPAngle SPAngleMakeWithDegrees(double degrees)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Returns an angle with the value specified in radians.
 
 @param radians The angle in radians.
 @returns A new angle structure.
 */
SPATIAL_INLINE
SPAngle SPAngleMakeWithRadians(double radians)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Returns the angle in degrees.
 
 @param angle The source angle.
 @returns The angle in degrees.
 */
SPATIAL_INLINE
double SPAngleGetDegrees(SPAngle angle)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/// Returns @p true if both rotation angles are equal.
SPATIAL_INLINE
bool SPAngleEqualToAngle(SPAngle angle1, SPAngle angle2)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

// MARK: - Header inline implementations

SPATIAL_SWIFT_NAME(Angle2D.init(degrees:))
SPAngle SPAngleMakeWithDegrees(double degrees) {
  return (SPAngle){ .radians = degrees / 180 * M_PI };
}

SPATIAL_SWIFT_NAME(Angle2D.init(radians:))
SPAngle SPAngleMakeWithRadians(double radians) {
  return (SPAngle){ .radians = radians };
}

SPATIAL_SWIFT_NAME(getter:Angle2D.degrees(self:))
double SPAngleGetDegrees(SPAngle angle) {
  return angle.radians * 180 / M_PI;
}

SPATIAL_REFINED_FOR_SWIFT
bool SPAngleEqualToAngle(SPAngle angle1, SPAngle angle2) {
    return angle1.radians == angle2.radians;
}
#endif /* Spatial_SPAngle_h */
