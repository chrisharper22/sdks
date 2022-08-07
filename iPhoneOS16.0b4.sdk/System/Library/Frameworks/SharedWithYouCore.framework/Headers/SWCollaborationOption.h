//  Copyright (c) 2022 Apple. All rights reserved.

#import <Foundation/Foundation.h>
#import <SharedWithYouCore/SWDefines.h>

NS_ASSUME_NONNULL_BEGIN
/*!
     @class SWCollaborationOption
     @abstract Represents a collaboration option which determines how the document should be shared
     @discussion SWCollaborationOptions represents the different permissions the document can be shared with in the CSCollaborationOptionsView
 */
SW_EXTERN @interface SWCollaborationOption : NSObject <NSCopying, NSSecureCoding>

/*!
    @abstract Localized string displayed as text to represent the option in the CSCollaborationOptionsView
 */
@property (nonatomic, copy) NSString *title;

/*!
    @abstract Unique identifier
 */
@property (nonatomic, copy, readonly) NSString *identifier;

/*!
    @abstract Localized string that describes the option in the CSCollaborationOptionsView
 */
@property (nonatomic, copy) NSString *subtitle;

/*!
    @abstract A bool representing the currently selected/switched on option item. This property should only be manually set on the option for switches.
 */
@property (nonatomic, assign, getter=isSelected) BOOL selected; // defaults to NO

/*!
    @abstract Array of option identifiers that must already be selected in order for the option to be interactable
 */
@property (nonatomic, copy) NSArray<NSString *> *requiredOptionsIdentifiers;

/*!
     @abstract Designated initializer to initialize a new collaboration option with the given title string and unique identifier
     @param title localized string displayed as text to represent the option in the CSCollaborationOptionsView
     @param identifier The unique identifier for the option
*/
- (instancetype)initWithTitle:(NSString *)title identifier:(NSString *)identifier NS_DESIGNATED_INITIALIZER NS_SWIFT_UNAVAILABLE("Use SWCollaborationOption.init(title:identifier:subtitle:selected:requiredOptionsIdentifiers:) instead");

- (nullable instancetype)initWithCoder:(NSCoder *)coder;
- (instancetype)init NS_UNAVAILABLE;

/*!
     @abstract Creates a new collaboration option with the given title string and unique identifier
     @param title localized string displayed as text to represent the option in the CSCollaborationOptionsView
     @param identifier the unique identifier for the option
*/
+ (SWCollaborationOption *)optionWithTitle:(NSString *)title identifier:(NSString *)identifier;

@end

NS_ASSUME_NONNULL_END
