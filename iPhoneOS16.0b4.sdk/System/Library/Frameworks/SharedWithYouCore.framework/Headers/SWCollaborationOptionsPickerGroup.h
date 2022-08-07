//  Copyright (c) 2022 Apple. All rights reserved.

@class SWCollaborationOptionsGroup;

NS_ASSUME_NONNULL_BEGIN

/*!
     @class SWCollaborationOptionsPickerGroup
     @abstract represents a group of SWCollaborationOptions that should be grouped together as a picker list from which one option in the list can be selected at a time
     @discussion SWCollaborationOptionsPickerGroup is used as a picker view which allows the user to select only one of the SWCollaborationOptions at a time from each group.
 */
SW_EXTERN @interface SWCollaborationOptionsPickerGroup : SWCollaborationOptionsGroup

/*!
    @abstract The identifier of the selected option in the option group. Defaults to the first SWCollaboration option identifier.
 */
@property (nonatomic, strong, readwrite) NSString *selectedOptionIdentifier;

@end

NS_ASSUME_NONNULL_END
