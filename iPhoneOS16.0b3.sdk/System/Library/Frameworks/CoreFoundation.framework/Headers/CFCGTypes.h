/*	CFCGTypes.h
	Copyright (c) 1998-2021, Apple Inc. and the Swift project authors

	Portions Copyright (c) 2014-2021, Apple Inc. and the Swift project authors
	Licensed under Apache License v2.0 with Runtime Library Exception
	See http://swift.org/LICENSE.txt for license information
	See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
*/

#if !defined(__COREFOUNDATION_CFCGTYPES__)
#define __COREFOUNDATION_CFCGTYPES__ 1

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFAvailability.h>
#include <float.h>
#include <stdint.h>

#define CF_DEFINES_CG_TYPES

#if defined(__has_attribute) && __has_attribute(objc_boxable)
# define CF_BOXABLE __attribute__((objc_boxable))
#else
# define CF_BOXABLE
#endif

/* Definition of `CGFLOAT_TYPE', `CGFLOAT_IS_DOUBLE', `CGFLOAT_MIN', and
 *    `CGFLOAT_MAX'. */

 #if defined(__LP64__) && __LP64__
 # define CGFLOAT_TYPE double
 # define CGFLOAT_IS_DOUBLE 1
 # define CGFLOAT_MIN DBL_MIN
 # define CGFLOAT_MAX DBL_MAX
 # define CGFLOAT_EPSILON DBL_EPSILON
 #else
 # define CGFLOAT_TYPE float
 # define CGFLOAT_IS_DOUBLE 0
 # define CGFLOAT_MIN FLT_MIN
 # define CGFLOAT_MAX FLT_MAX
 # define CGFLOAT_EPSILON FLT_EPSILON
 #endif

/* Definition of the `CGFloat' type and `CGFLOAT_DEFINED'. */

typedef CGFLOAT_TYPE CGFloat;
#define CGFLOAT_DEFINED 1

/* Points. */
struct
CGPoint {
    CGFloat x;
    CGFloat y;
};
typedef struct CF_BOXABLE CGPoint CGPoint;

/* Sizes. */

struct CGSize {
    CGFloat width;
    CGFloat height;
};
typedef struct CF_BOXABLE CGSize CGSize;

/* Vectors. */

#define CGVECTOR_DEFINED 1

struct CGVector {
    CGFloat dx;
    CGFloat dy;
};
typedef struct CF_BOXABLE CGVector CGVector;

/* Rectangles. */

struct CGRect {
    CGPoint origin;
    CGSize size;
};
typedef struct CF_BOXABLE CGRect CGRect;

/* Rectangle edges. */

typedef CF_CLOSED_ENUM(uint32_t, CGRectEdge) {
    CGRectMinXEdge, CGRectMinYEdge, CGRectMaxXEdge, CGRectMaxYEdge
};

typedef struct CGAffineTransform CGAffineTransform;

struct CGAffineTransform {
    CGFloat a, b, c, d;
    CGFloat tx, ty;
};

#endif /* ! __COREFOUNDATION_CFCGTYPES__ */
