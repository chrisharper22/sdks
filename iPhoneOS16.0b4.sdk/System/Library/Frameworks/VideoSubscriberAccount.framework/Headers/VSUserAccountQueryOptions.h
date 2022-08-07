//
//  VSUserAccountQueryOptions.h
//  VideoSubscriberAccountFramework
//
//  Created by Nik Harris on 2/28/22.
//  Copyright © 2022 Apple Inc. All rights reserved.
//

typedef NS_OPTIONS(NSInteger, VSUserAccountQueryOptions) {
    VSUserAccountQueryOptionNone = 0,  // default
    VSUserAccountQueryOptionAllDevices // return VSUserAccounts also registered on other devices in the users iCloud account
};

