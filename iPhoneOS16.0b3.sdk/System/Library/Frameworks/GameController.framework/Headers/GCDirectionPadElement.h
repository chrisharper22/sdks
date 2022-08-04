//  
//  GCDirectionPadElement.h
//  GameController
//
//  Copyright © 2021 Apple Inc. All rights reserved.
//

#import <GameController/GCPhysicalInputElement.h>
#import <GameController/GCLinearInput.h>
#import <GameController/GCAxisInput.h>
#import <GameController/GCPressedStateInput.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(macos(13.0), ios(16.0), tvos(16.0))
@protocol GCDirectionPadElement <GCPhysicalInputElement>

/** The horizontal/x-component of the dpad input. */
@property (readonly) id<GCAxisInput> xAxis;
/** The vertical/y-component of the dpad input. */
@property (readonly) id<GCAxisInput> yAxis;

/** The positive y-component of the dpad input. */
@property (readonly) id<GCLinearInput, GCPressedStateInput> up;
/** The negative y-component of the dpad input. */
@property (readonly) id<GCLinearInput, GCPressedStateInput> down;
/** The negative x-component of the dpad input. */
@property (readonly) id<GCLinearInput, GCPressedStateInput> left;
/** The positive x-component of the dpad input. */
@property (readonly) id<GCLinearInput, GCPressedStateInput> right;

@end

NS_ASSUME_NONNULL_END
