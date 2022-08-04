#if !__has_include(<PassKitCore/PKIdentityDocumentAgeThreshold.h>) || PK_USE_PUBLIC_PASSKIT
//
//  PKIdentityDocumentAgeThreshold.h
//  PassKit
//
//  Copyright © 2022 Apple, Inc. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Represents an age threshold in a PKIdentityDocument, which
/// indicates whether the document holder's age is at least
/// a certain age threshold in years.
API_AVAILABLE(ios(16.0)) API_UNAVAILABLE(macos, watchos, tvos)
NS_SWIFT_NAME(PKIdentityDocument.AgeThreshold)
@interface PKIdentityDocumentAgeThreshold: NSObject

/// The age threshold in years requested in the originating request.
@property (nonatomic, readonly) NSInteger years;

/// True if the document holder's age is >= years, false otherwise.
@property (nonatomic, readonly, getter=isAtLeastYearsOld) BOOL atLeastYearsOld;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END


#else
#import <PassKitCore/PKIdentityDocumentAgeThreshold.h>
#endif
