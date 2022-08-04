//  Copyright (c) 2022 Apple. All rights reserved.

#import <SharedWithYouCore/SWDefines.h>

@class SWCollaborationOption;

NS_ASSUME_NONNULL_BEGIN

/*!
    @abstract String identifier used to initialize a UTType to represent the type of the array of SWCollaborationOptionsGroups when registering to and reading from the NSItemProvider
 */
SW_EXTERN NSString * const UTCollaborationOptionsTypeIdentifier;

/*!
     @class SWCollaborationOptionsGroup
     @abstract represents a group of SWCollaborationOptions that should be grouped together and displayed in the same section in the CSCollaborationOptionsView
     @discussion SWCollaborationOptionsGroups group together options which represent the ways which the document can be shared and indicates a section of CSCollaborationOptionsView. A SWCollaborationOptionsGroup with one option indicates a switch.
 */
SW_EXTERN @interface SWCollaborationOptionsGroup : NSObject <NSCopying, NSSecureCoding>

/*!
    @abstract Localized string used to title the section
 */
@property (nonatomic, copy) NSString *title;
/*!
    @abstract Unique identifier
 */
@property (nonatomic, copy, readonly) NSString *identifier;

/*!
    @abstract Localized string to describe or provide additional information on the group of options
 */
@property (nonatomic, copy) NSString *footer;

/*!
    @abstract SWCollaborationOptions to be displayed in the section
 */
@property (nonatomic, copy) NSArray<SWCollaborationOption *> *options;


/*!
     @abstract Initializes group of options which will be displayed as one section in CSCollaborationOptionsView
     @param identifier unique identifier for the SWCollaborationOptionGroup
     @param options SWCollaborationOptions to display in the section
*/
- (instancetype)initWithIdentifier:(NSString *)identifier options:(NSArray<SWCollaborationOption *> *)options NS_DESIGNATED_INITIALIZER;

/*!
     @abstract Creates group of options which will be displayed as one section in CSCollaborationOptionsView
     @param identifier unique identifier for the SWCollaborationOptionGroup
     @param options SWCollaborationOptions to display in the section
*/
+ (SWCollaborationOptionsGroup *)optionsGroupWithIdentifier:(NSString *)identifier options:(NSArray<SWCollaborationOption *> *)options;

- (instancetype)init NS_UNAVAILABLE;

@end


NS_ASSUME_NONNULL_END
