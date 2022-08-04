//  Copyright (c) 2022 Apple. All rights reserved.

#import <Foundation/Foundation.h>
#import <SharedWithYouCore/SWDefines.h>

NS_ASSUME_NONNULL_BEGIN

SW_EXTERN
@interface SWAction : NSObject <NSCopying, NSSecureCoding>

@property (nonatomic, readonly) NSUUID *uuid;
@property (nonatomic, readonly, getter=isComplete) BOOL complete;

- (void)fulfill;
- (void)fail;

@end

NS_ASSUME_NONNULL_END
