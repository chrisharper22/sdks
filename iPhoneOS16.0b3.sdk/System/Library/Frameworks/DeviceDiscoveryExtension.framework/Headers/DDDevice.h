// Copyright (C) 2021-2022 Apple Inc. All Rights Reserved.

#ifndef DEVICE_DISCOVERY_EXTENSION_INDIRECT_INCLUDES
#error "Please #import <DeviceDiscoveryExtension/DeviceDiscoveryExtension.h> instead of this file directly."
#endif

#pragma once

#import <DeviceDiscoveryExtension/DDCommon.h>
#import <Foundation/Foundation.h>
#import <Network/Network.h>
#import <UniformTypeIdentifiers/UniformTypeIdentifiers.h>

NS_ASSUME_NONNULL_BEGIN

#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------------------------------------------------------
///	@defgroup	Supported Protocols
typedef NSString * DDDeviceProtocolString NS_STRING_ENUM;

API_AVAILABLE( ios( 16.0 ) )
DD_EXTERN DDDeviceProtocolString const DDDeviceProtocolStringInvalid;

API_AVAILABLE( ios( 16.0 ) )
DD_EXTERN DDDeviceProtocolString const DDDeviceProtocolStringDIAL NS_SWIFT_NAME(DDDeviceProtocolString.dial);

//---------------------------------------------------------------------------------------------------------------------------

typedef NS_ENUM( NSInteger, DDDeviceProtocol )
 {
	DDDeviceProtocolInvalid											= 0,	/// Invalid protocol.
	DDDeviceProtocolDIAL NS_SWIFT_NAME(DDDeviceProtocol.dial)		= 1,	/// DIAL protocol.
 };

/// Converts a device protocol type to a string for logging, etc.
DD_EXTERN
API_AVAILABLE( ios( 16.0 ) )
NSString * DDDeviceProtocolToString( DDDeviceProtocol inValue );

//---------------------------------------------------------------------------------------------------------------------------
/// Category of the device.
typedef NS_ENUM( NSInteger, DDDeviceCategory )
{
	DDDeviceCategoryHiFiSpeaker NS_SWIFT_NAME(hifiSpeaker)					= 0,	/// Hi-Fi speaker.
	DDDeviceCategoryHiFiSpeakerMultiple NS_SWIFT_NAME(hifiSpeakerMultiple)	= 1,	/// Multiple Hi-Fi speakers.
	DDDeviceCategoryTVWithMediaBox NS_SWIFT_NAME(tvWithMediaBox)			= 2,	/// TV with MediaBox.
	DDDeviceCategoryTV NS_SWIFT_NAME(tv)									= 3,	/// TV.
	DDDeviceCategoryLaptopComputer NS_SWIFT_NAME(laptopComputer)			= 4,	/// Laptop computer.
	DDDeviceCategoryDesktopComputer NS_SWIFT_NAME(desktopComputer)			= 5,	/// Desktop computer.
} NS_SWIFT_NAME(DDDevice.Category);

/// Converts a device category to a string for logging, etc.
DD_EXTERN
API_AVAILABLE( ios( 16.0 ) )
NSString * DDDeviceCategoryToString( DDDeviceCategory inValue );

//===========================================================================================================================
/// State of the device.
typedef NS_ENUM( NSInteger, DDDeviceState )
{
	DDDeviceStateInvalid		= 0,  /// Invalid/unapproved state.
	DDDeviceStateActivating		= 10, /// Selected by the user.
	DDDeviceStateActivated		= 20, /// Authorized and connected.
	DDDeviceStateAuthorized		= 25, /// Authorized by the user.
	DDDeviceStateInvalidating	= 30, /// Invalidating state.
};

/// Converts a device state to a string for logging, etc.
DD_EXTERN
API_AVAILABLE( ios( 16.0 ) )
NSString * DDDeviceStateToString( DDDeviceState inValue );

//===========================================================================================================================
/// DeviceDiscoveryExtension device.
DD_EXTERN
API_AVAILABLE( ios( 16.0 ) )
@interface DDDevice : NSObject

- (instancetype) init NS_UNAVAILABLE;

/// Initializes a DD device with display name, category, protocol type, and identifier.
- (instancetype) initWithDisplayName:(NSString *) displayName category:(DDDeviceCategory) category
	protocolType:(UTType *) protocolType identifier:(NSString *) identifier NS_DESIGNATED_INITIALIZER;

/// Identifier to communicate with the device via Bluetooth.
@property (readwrite, strong, nullable, nonatomic) NSUUID *bluetoothIdentifier;

/// Category of the device.
@property (readwrite, assign, nonatomic) DDDeviceCategory category;

/// Name of the device. Should be suitable for displaying to a user.
@property (readwrite, copy, nonatomic) NSString *displayName;

/// Identifier of the device.
@property (readwrite, copy, nonatomic) NSString *identifier;

/// Endpoint to communicate with the device via networking.
@property (readwrite, dd_os_ownership, nullable, nonatomic) nw_endpoint_t networkEndpoint
	NS_REFINED_FOR_SWIFT;

/// Protocol of the device.
@property (readwrite, assign, nonatomic) DDDeviceProtocol protocol;

/// Uniform Type for the protocol.
@property (readwrite, strong, nonatomic) UTType *protocolType;

/// State of the device.
@property (readwrite, assign, nonatomic) DDDeviceState state;

/// TXT record of the device.
@property (readwrite, copy, nullable, nonatomic) NSData *txtRecordData
	NS_REFINED_FOR_SWIFT;

/// URL used for SSDP connection.
/// The URL must have a valid hostname, no query parameters, and a maximum size of 100 bytes.
@property (readwrite, copy, nonatomic) NSURL *url;

@end

#ifdef __cplusplus
}
#endif

NS_ASSUME_NONNULL_END
