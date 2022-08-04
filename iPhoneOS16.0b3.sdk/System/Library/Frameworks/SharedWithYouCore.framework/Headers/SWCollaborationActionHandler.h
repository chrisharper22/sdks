//  Copyright (c) 2022 Apple. All rights reserved.

#import <Foundation/Foundation.h>
#import <SharedWithYouCore/SWDefines.h>
#import <SharedWithYouCore/SWAction.h>

@class SWCollaborationCoordinator;
@class SWStartCollaborationAction;
@class SWUpdateCollaborationParticipantsAction;

NS_ASSUME_NONNULL_BEGIN

@protocol SWCollaborationActionHandler <NSObject>
- (void)collaborationCoordinator:(SWCollaborationCoordinator *)coordinator handleStartCollaborationAction:(SWStartCollaborationAction *)action;
- (void)collaborationCoordinator:(SWCollaborationCoordinator *)coordinator handleUpdateCollaborationParticipantsAction:(SWUpdateCollaborationParticipantsAction *)action;
@end

NS_ASSUME_NONNULL_END
