//  Copyright (c) 2022 Apple. All rights reserved.

#import <SharedWithYouCore/SWAction.h>
#import <SharedWithYouCore/SWCollaborationMetadata.h>

NS_ASSUME_NONNULL_BEGIN

SW_EXTERN @interface SWStartCollaborationAction : SWAction <NSSecureCoding, NSCopying>

@property (nonatomic, readonly) SWCollaborationMetadata *collaborationMetadata;

- (void)fulfillUsingURL:(NSURL *)url collaborationIdentifier:(SWCollaborationIdentifier)collaborationIdentifier;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
