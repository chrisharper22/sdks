/*	NSLock.h
	Copyright (c) 1994-2019, Apple Inc. All rights reserved.
*/

#import <Foundation/NSObject.h>

@class NSDate;

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

@protocol NSLocking

- (void)lock;
- (void)unlock;

@end

NS_SWIFT_SENDABLE // Locks are inherently Sendable by definition
@interface NSLock : NSObject <NSLocking>

- (BOOL)tryLock;
- (BOOL)lockBeforeDate:(NSDate *)limit;

@property (nullable, copy) NSString *name API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0));

@end

NS_SWIFT_SENDABLE // Locks are inherently Sendable by definition
@interface NSConditionLock : NSObject <NSLocking>

- (instancetype)initWithCondition:(NSInteger)condition NS_DESIGNATED_INITIALIZER;

@property (readonly) NSInteger condition;
- (void)lockWhenCondition:(NSInteger)condition;
- (BOOL)tryLock;
- (BOOL)tryLockWhenCondition:(NSInteger)condition;
- (void)unlockWithCondition:(NSInteger)condition;
- (BOOL)lockBeforeDate:(NSDate *)limit;
- (BOOL)lockWhenCondition:(NSInteger)condition beforeDate:(NSDate *)limit;

@property (nullable, copy) NSString *name API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0));

@end

NS_SWIFT_SENDABLE // Locks are inherently Sendable by definition
@interface NSRecursiveLock : NSObject <NSLocking>

- (BOOL)tryLock;
- (BOOL)lockBeforeDate:(NSDate *)limit;

@property (nullable, copy) NSString *name API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0));

@end


NS_SWIFT_SENDABLE // Locks are inherently Sendable by definition
API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0))
@interface NSCondition : NSObject <NSLocking>

- (void)wait;
- (BOOL)waitUntilDate:(NSDate *)limit;
- (void)signal;
- (void)broadcast;

@property (nullable, copy) NSString *name API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0));

@end

NS_HEADER_AUDIT_END(nullability, sendability)
