//
//  MLPredictionOptions.h
//  CoreML
//
//  Copyright © 2017 Apple Inc. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <CoreML/MLExport.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 * MLPredictionOptions
 *
 * An object to hold options / controls / parameters of how
 * model prediction is performed
 */
API_AVAILABLE(macos(10.13), ios(11.0), watchos(4.0), tvos(11.0))
ML_EXPORT
@interface MLPredictionOptions : NSObject

/// Set to YES to force computation to be on the CPU only
@property (readwrite, nonatomic) BOOL usesCPUOnly API_DEPRECATED_WITH_REPLACEMENT("Use -[MLModelConfiguration computeUnits] instead.", macos(10.13, 12.0), ios(11.0, 15.0), tvos(11.0, 15.0), watchos(4.0, 8.0));

@end

NS_ASSUME_NONNULL_END

