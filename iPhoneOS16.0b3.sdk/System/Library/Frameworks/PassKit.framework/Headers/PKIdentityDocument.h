#if !__has_include(<PassKitCore/PKIdentityDocument.h>) || PK_USE_PUBLIC_PASSKIT
//
//  PKIdentityDocument.h
//  PassKit
//
//  Copyright © 2022 Apple, Inc. All rights reserved.
//


#import <Foundation/Foundation.h>

@class PKIdentityDocumentRawElements;

NS_ASSUME_NONNULL_BEGIN

/// Represents the response of a request for an identity document.
API_AVAILABLE(ios(16.0)) API_UNAVAILABLE(macos, watchos, tvos)
@interface PKIdentityDocument: NSObject

/// An encrypted data blob containing the requested document information and associated metadata.
/// This is encrypted to the public key on-file with the Developer portal for the calling app, and should
/// be passed to the server holding the corresponding private key for decryption.
/// This data is not intended to be read on-device.
@property (nonatomic, readonly) NSData *encryptedData;

/// The unsigned, unencrypted representation of the elements in the response, as specified by the issuer.
/// When element values are returned, they match the corresponding element values within encryptedData, but
/// do not possess an issuer signature. They can be used locally for use cases that do not require the
/// authenticity guarantees provided by the issuer signature, but should never be used in situations that
/// require trusted information.
@property (nonatomic, readonly, nullable) PKIdentityDocumentRawElements *rawElements;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END


#else
#import <PassKitCore/PKIdentityDocument.h>
#endif
