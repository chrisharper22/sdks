//  Copyright (c) 2022 Apple. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @protocol SWHighlightEvent
 @abstract A protocol defining an activity that can be posted in response to a user action on some content.
 */
@protocol SWHighlightEvent <NSObject, NSSecureCoding, NSCopying>

@required
@property (nonatomic, readonly, copy) NSURL *highlightURL;

@end

NS_ASSUME_NONNULL_END
