#if !__has_include(<PassKitCore/PKIdentityDocumentRawElements.h>) || PK_USE_PUBLIC_PASSKIT
//
//  PKIdentityDocumentRawElements.h
//  PassKit
//
//  Copyright © 2022 Apple, Inc. All rights reserved.
//


#import <Foundation/Foundation.h>

@class CNPostalAddress;
@class PKIdentityDocumentIssuingAuthority;
@class PKIdentityDocumentAgeThreshold;

NS_ASSUME_NONNULL_BEGIN

/// Represents the response elements in a PKIdentityDocument.
/// Only properties that correspond to elements that were requested and
/// are present in the underlying identity document will be set.
API_AVAILABLE(ios(16.0)) API_UNAVAILABLE(macos, watchos, tvos)
NS_SWIFT_NAME(PKIdentityDocument.RawElements)
@interface PKIdentityDocumentRawElements: NSObject

/// The name of the document holder.
@property (nonatomic, readonly, nullable) NSPersonNameComponents *name;

/// The address of the document holder.
@property (nonatomic, readonly, nullable) CNPostalAddress *address;

/// The issuing authority that issued the document.
@property (nonatomic, readonly, nullable) PKIdentityDocumentIssuingAuthority *issuingAuthority;

/// The issue date of the document.
@property (nonatomic, readonly, nullable) NSDateComponents *documentIssueDate;

/// The expiration date of the document.
@property (nonatomic, readonly, nullable) NSDateComponents *documentExpirationDate;

/// The number identifying the document, as specified by its issuing authority.
@property (nonatomic, readonly, nullable) NSString *documentNumber;

/// The age (in years) of the document holder.
@property (nonatomic, readonly, nullable) NSNumber *age NS_REFINED_FOR_SWIFT;

/// An age threshold indicating whether the document holder is at least a requested age.
@property (nonatomic, readonly, nullable) PKIdentityDocumentAgeThreshold *ageThreshold;

/// The date of birth of the document holder.
@property (nonatomic, readonly, nullable) NSDateComponents *dateOfBirth;

/// The portrait of the document holder.
@property (nonatomic, readonly, nullable) NSData *portraitImageData;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END


#else
#import <PassKitCore/PKIdentityDocumentRawElements.h>
#endif
