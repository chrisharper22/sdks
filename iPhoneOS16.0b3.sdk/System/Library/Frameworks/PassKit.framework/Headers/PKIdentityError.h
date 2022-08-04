#if !__has_include(<PassKitCore/PKIdentityError.h>) || PK_USE_PUBLIC_PASSKIT
//
//  PKIdentityError.h
//  PassKit
//
//  Copyright © 2022 Apple, Inc. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Error domain for identity errors.
extern NSErrorDomain const PKIdentityErrorDomain API_AVAILABLE(ios(16.0)) API_UNAVAILABLE(macos, watchos, tvos);

/// Identity error codes.
typedef NS_ERROR_ENUM(PKIdentityErrorDomain, PKIdentityError) {
    /// Catch-all for all errors without a specific error code.
    PKIdentityErrorUnknown = 1,

    /// Returned if the app is not entitled to call an API.
    PKIdentityErrorNotEntitled = 2,

    /// Returned if the sheet was cancelled.
    PKIdentityErrorCancelled = 3,

    /// Returned if a request cannot be processed because
    /// the network is not available.
    PKIdentityErrorNetworkUnavailable = 4,

    /// Returned if no supported elements were requested.
    PKIdentityErrorNoElementsRequested = 5,

    /// Returned if a request is made but another request is already
    /// in progress.
    PKIdentityErrorRequestAlreadyInProgress = 6,

    /// Returned if the caller-supplied nonce is too large or otherwise unsuitable.
    PKIdentityErrorInvalidNonce = 7,

    /// Returned if an element requested by the caller is invalid.
    PKIdentityErrorInvalidElement = 8,

    /// Returned if the merchant ID used in a request is invalid
    PKIdentityErrorInvalidMerchantID = 9,
    
    /// Returned if the request originates from an unsupported device
    PKIdentityErrorNotSupported = 10
} API_AVAILABLE(ios(16.0)) API_UNAVAILABLE(macos, watchos, tvos);

NS_ASSUME_NONNULL_END


#else
#import <PassKitCore/PKIdentityError.h>
#endif
