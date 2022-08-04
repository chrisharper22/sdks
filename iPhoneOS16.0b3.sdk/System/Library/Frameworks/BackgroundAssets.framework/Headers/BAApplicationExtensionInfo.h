//
//  BAApplicationExtensionInfo.h
//  BackgroundAssets
//
//  Copyright (c) 2022, Apple Inc.
//  All rights reserved.
//

#import <BackgroundAssets/BackgroundAssets.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(tvos, watchos)
@interface BAApplicationExtensionInfo : NSObject <NSSecureCoding>

/// @brief The application identifer that this code is being called to handle.
@property (readonly) NSString               *applicationIdentifier;

/// @brief The date the extension's periodic check was invoked.
@property (readonly, nullable) NSDate       *lastPeriodicCheckTime;

/// @brief The date the last time that appliction launched and checked in to check for downloads.
@property (readonly, nullable) NSDate       *lastApplicationLaunchTime;

/// @brief The download size is currently restricted. This is most likely because the application has not been launched yet.
@property (readonly) BOOL                   downloadSizeRestricted;

@end

NS_ASSUME_NONNULL_END
