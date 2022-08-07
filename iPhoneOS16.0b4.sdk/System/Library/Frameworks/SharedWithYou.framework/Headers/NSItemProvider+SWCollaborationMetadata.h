//  Copyright (c) 2022 Apple. All rights reserved.

#import <Foundation/Foundation.h>
#import <SharedWithYouCore/SWDefines.h>
#import <SharedWithYouCore/SWCollaborationMetadata.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(16.0), macos(13.0)) API_UNAVAILABLE(watchos, tvos)
SW_EXTERN @interface SWCollaborationMetadata (NSItemProvider) <NSItemProviderReading, NSItemProviderWriting>

@end

NS_ASSUME_NONNULL_END

SW_EXTERN NSString * const SWCollaborationMetadataTypeIdentifier;
