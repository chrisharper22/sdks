//  Copyright (c) 2022 Apple. All rights reserved.

#import <Foundation/Foundation.h>
#import <SharedWithYouCore/SWCollaborationActionHandler.h>
#import <SharedWithYouCore/SWDefines.h>
#import <SharedWithYouCore/SWAction.h>

NS_ASSUME_NONNULL_BEGIN

SW_EXTERN @interface SWCollaborationCoordinator : NSObject

@property (class, nonatomic, strong, readonly) SWCollaborationCoordinator *sharedCoordinator;
@property (nonatomic, weak, readwrite) id<SWCollaborationActionHandler> actionHandler;

@end

NS_ASSUME_NONNULL_END
