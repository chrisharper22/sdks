// Copyright (C) 2021-2022 Apple Inc. All Rights Reserved.

#ifndef DEVICE_DISCOVERY_EXTENSION_INDIRECT_INCLUDES
#error "Please #import <DeviceDiscoveryExtension/DeviceDiscoveryExtension.h> instead of this file directly."
#endif

#pragma once

#import <DeviceDiscoveryExtension/DDCommon.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#ifdef __cplusplus
extern "C" {
#endif

@class DDDevice;
@class DDEvent;

//===========================================================================================================================
/// Type of event.
typedef NS_ENUM( NSInteger, DDEventType )
{
	DDEventTypeUnknown					= 0,	/// Unknown event. Placeholder for initializing event types.
	DDEventTypeDeviceFound				= 40,	/// [DDDeviceEvent] Device found.
	DDEventTypeDeviceLost				= 41,	/// [DDDeviceEvent] Device lost.
	DDEventTypeDeviceChanged			= 42,	/// [DDDeviceEvent] Device changed.
	DDEventTypeDevicesPresentChanged	= 50,	/// [DDDeviceEvent] Device changed.
};

/// Converts an event to a string for logging, etc.
DD_EXTERN
API_AVAILABLE( ios( 16.0 ) )
NSString * DDEventTypeToString( DDEventType inValue );

/// Invoked when an event occurs.
typedef void ( ^DDEventHandler )( DDEvent *inEvent );

//===========================================================================================================================
/// Event for status and other updates.
DD_EXTERN
@interface DDEvent : NSObject

/// Type of event. Type may indicate the subclass of DAEvent to provide additional properties.
@property (readonly, assign, nonatomic) DDEventType eventType;

@end

//===========================================================================================================================

/// Device-related event (e.g. found, lost).
DD_EXTERN
API_AVAILABLE( ios( 16.0 ) )
@interface DDDeviceEvent : DDEvent

/// Initializes a device event.
- (instancetype) initWithEventType:(DDEventType) type device:(DDDevice *) device;

/// Device found or lost.
@property (readonly, strong, nonatomic) DDDevice *device;

@end

//===========================================================================================================================
/// Reports the one or more devices are present changes.
DD_EXTERN
API_AVAILABLE( ios( 16.0 ) )
@interface DDEventDevicesPresent : DDEvent

/// One or more devices are present.
@property (readonly, assign, nonatomic) BOOL devicesPresent;

@end

#ifdef __cplusplus
}
#endif

NS_ASSUME_NONNULL_END
