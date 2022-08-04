#if !__has_include(<PassKitCore/PKIdentityDocumentIssuingAuthority.h>) || PK_USE_PUBLIC_PASSKIT
//
//  PKIdentityDocumentIssuingAuthority.h
//  PassKit
//
//  Copyright © 2022 Apple, Inc. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Represents a document's issuing authority in a PKIdentityDocument.
API_AVAILABLE(ios(16.0)) API_UNAVAILABLE(macos, watchos, tvos)
NS_SWIFT_NAME(PKIdentityDocument.IssuingAuthority)
@interface PKIdentityDocumentIssuingAuthority: NSObject

/// The name of the issuing authority of the document.
@property (nonatomic, readonly, nullable) NSString *name;

/// The country subdivision code of the jurisdiction that issued the document.
@property (nonatomic, readonly, nullable) NSString *jurisdiction;

/// The ISO 3166-1 alpha-2 country code of the country that issued the document.
@property (nonatomic, readonly, nullable) NSString *ISOCountryCode;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END


#else
#import <PassKitCore/PKIdentityDocumentIssuingAuthority.h>
#endif
