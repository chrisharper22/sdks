//  Copyright (c) 2022 Apple. All rights reserved.

#import <Foundation/Foundation.h>
#import <SharedWithYouCore/SWDefines.h>
#import <SharedWithYouCore/SWCollaborationMetadata.h>

NS_ASSUME_NONNULL_BEGIN

SW_EXTERN @interface SWCollaborationMetadata (NSItemProvider) <NSItemProviderReading, NSItemProviderWriting>

@end

NS_ASSUME_NONNULL_END

SW_EXTERN NSString * const SWCollaborationMetadataTypeIdentifier;
