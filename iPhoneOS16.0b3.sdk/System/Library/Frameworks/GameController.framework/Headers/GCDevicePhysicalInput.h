//  
//  GCDevicePhysicalInput.h
//  GameController
//
//  Copyright © 2021 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <GameController/GCDevicePhysicalInputState.h>
#import <GameController/GCDevicePhysicalInputStateDiff.h>

@protocol GCDevice;

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(macos(13.0), ios(16.0), tvos(16.0))
@protocol GCDevicePhysicalInput <GCDevicePhysicalInputState>

/**
 The device that this profile is mapping input from.
 */
@property (weak, readonly) id<GCDevice> device;

#pragma mark Immediate Input

/**
 Set this block if you want to be notified when a value on a element changed.
 If multiple elements have changed this block will be called for each element
 that changed.
 
 The block is called on the \c handlerQueue configured on the \c device.
 
 @note
 IMPORTANT: It is possible for the value(s) of \c element to change (again)
 between when your handler is scheduled for execution and when it actually
 executes.  This may cause your application to "miss" changes to the element.
 If your application needs to track every element state change - as opposed to
 just the latest element state - use the methods under "Buffered Input".
 
 @param element
 The element that has been modified.
 */
@property (copy, nullable) void (^elementValueDidChangeHandler)(__kindof id<GCPhysicalInputElement> element);

/**
 Polls the current state vector of the physical input and saves it to a new
 instance.
 
 If your application is heavily multithreaded this may also be useful to
 guarantee atomicity of input handling as a snapshot will not change based on
 further device input once it is taken.
 
 @return An input state with the duplicated state vector of the current input.
 */
- (__kindof id<GCDevicePhysicalInputState>)capture;

#pragma mark Buffered Input

/**
 Set this block to be notified when a new input state is available.  Your
 handler should repeatedly call \c -nextInputState until it returns \c nil to
 drain the pending input states from the queue.
 */
@property (copy, nullable) void (^inputStateAvailableHandler)(void);

/**
 The maximum number of input states to buffer.  If your application does not
 drain the pending input states queue before this limit is reached, older input
 states will be discarded - resulting in your application "missing" input state
 changes.
 
 The default value is \c one (no buffering).  Smaller values are ignored.  A
 value of \c 20 should be more than enough to ensure no input state changes
 are missed.
 */
@property (readwrite) NSInteger inputStateQueueDepth;

/**
 Pop the next pending input state from the queue.  This method returns \c nil
 when there are no more input states pending.
 */
- (nullable __kindof id<GCDevicePhysicalInputState, GCDevicePhysicalInputStateDiff>)nextInputState;

@end

NS_ASSUME_NONNULL_END
