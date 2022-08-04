//
//  SWUpdateCollaborationParticipantsAction.h
//  SharedWithYouCore
//
//  Created by Devin Clary on 3/23/22.
//

#import <Foundation/Foundation.h>

#import <SharedWithYouCore/SWAction.h>
#import <SharedWithYouCore/SWCollaborationMetadata.h>
#import <SharedWithYouCore/SWPersonIdentity.h>

NS_ASSUME_NONNULL_BEGIN

@interface SWUpdateCollaborationParticipantsAction : SWAction <NSSecureCoding, NSCopying>

@property (nonatomic, readonly) SWCollaborationMetadata *collaborationMetadata;

@property (nonatomic, readonly) NSArray<SWPersonIdentity *> *addedIdentities;

@property (nonatomic, readonly) NSArray<SWPersonIdentity *> *removedIdentities;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
