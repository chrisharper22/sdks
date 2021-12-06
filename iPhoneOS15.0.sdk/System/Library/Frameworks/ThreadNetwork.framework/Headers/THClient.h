//
//  THClient.h
//  CoreThreadRadio
//
//  Created by Venkat Manepalli on 10/26/20.
//  Copyright © 2020 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ThreadNetwork/THCredentials.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(15.0))

@interface THClient : NSObject

/*
 * @function init
 *
 * @discussion
 * Initialize instance of THClient
 *
 * @parameter
 * no parameters
 */

- (instancetype)init;

/*
 * @function retrieveAllCredentials
 *
 * @discussion
 * Retrieve All Credentials, stored by the client
 *
 * @parameter
 * completion : Callback function to recieve all credentials
 *
 */
- (void)retrieveAllCredentials:(void (^)(NSSet<THCredentials*>* _Nullable credentials, NSError* _Nullable error))completion API_AVAILABLE(ios(15.0)) NS_SWIFT_ASYNC_NAME(allCredentials());

/*
 * @function deleteActiveDataSetRecordForBorderAgent
 *
 * @discussion
 * Delete Credentials For The given Border Agent identifier, stored by the client
 *
 * @parameter
 * borderAgentID : Thread Network Border Agent Identifier
 * @parameter
 * completion : Callback function to return the status of the delete operation
 *
 */
- (void)deleteCredentialsForBorderAgent:(NSData *)borderAgentID completion:(void (^)(NSError* _Nullable error))completion API_AVAILABLE(ios(15.0));

/*
 * @function retrieveCredentialsForBorderAgent
 *
 * @discussion
 * Retrieve Credentials For The given Thread Border Agent identifier, stored by the client
 *
 * @parameter
 * completion : Callback function to recieve the matching active dataset record
 *
 */
- (void)retrieveCredentialsForBorderAgent:(NSData *)borderAgentID completion:( void (^)(THCredentials* _Nullable credentials, NSError* _Nullable error))completion API_AVAILABLE(ios(15.0)) NS_SWIFT_ASYNC_NAME(credentials(forBorderAgentID:));

/*
 * @function storeCredentialsForBorderAgent
 *
 * @discussion
 * Store the Credentials Record
 *
 * @parameters
 * borderAgent              : Border Agent Identifier
 * activeOperationalDataSet : byte array of active operational dataset
 * completion               : Callback function to return the status of the store operation
 *
 */

- (void)storeCredentialsForBorderAgent:(NSData *)borderAgentID
              activeOperationalDataSet:(NSData *)activeOperationalDataSet
                            completion:(void (^)(NSError* _Nullable error))completion API_AVAILABLE(ios(15.0));

/*
 * @function retrievePreferredCredentials
 *
 * @discussion
 * Retrieve Preferred Thread Network Credentials.
 * Invoking this API will result into UI Alert prompt seeking user's permission to access the credentials
 *
 * @parameter
 * completion : Callback function to recieve preferred network active dataset record
 *
 */
- (void)retrievePreferredCredentials:(void (^)(THCredentials* _Nullable credentials, NSError* _Nullable error))completion API_AVAILABLE(ios(15.0)) NS_SWIFT_ASYNC_NAME(preferredCredentials());

/*
 * @function retrieveActiveDataSetRecordForExtendedPANID
 *
 * @discussion
 * Retrieve Credentials For The given Extedend-PAN Id
 * Invoking this API will result into UI Alert prompt seeking user's permission to access the credentials
 *
 * @parameter
 * extendedPANID    : Extended PAN Id identifying the thread network
 * completion       : Callback function to recieve the matching active dataset record
 *
 */
- (void)retrieveCredentialsForExtendedPANID:(NSData *)extendedPANID completion:( void (^)(THCredentials* _Nullable credentials, NSError* _Nullable error))completion API_AVAILABLE(ios(15.0)) NS_SWIFT_ASYNC_NAME(credentials(forExtendedPANID:));
@end

NS_ASSUME_NONNULL_END
