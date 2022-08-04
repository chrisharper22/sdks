//
//  BADownloaderExtension.h
//  BackgroundAssets
//
//  Copyright (c) 2022, Apple Inc.
//  All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BackgroundAssets/BackgroundAssets.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(tvos, watchos)
@protocol BADownloaderExtension <NSObject>

@optional

/// @brief This method is invoked when a containing application was installled.
- (void)applicationDidInstallWithMetadata:(BAApplicationExtensionInfo *)metadata
API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(tvos, watchos)
NS_SWIFT_NAME(applicationDidInstall(metadata:));

/// @brief This method is invoked when the containing application has been updated.
- (void)applicationDidUpdateWithMetadata:(BAApplicationExtensionInfo *)metadata
API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(tvos, watchos)
NS_SWIFT_NAME(applicationDidUpdate(metadata:));

/// @brief This method is invoked when a periodic timer invokes the plugin.
- (void)checkForUpdatesWithMetadata:(BAApplicationExtensionInfo *)metadata
API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(tvos, watchos)
NS_SWIFT_NAME(checkForUpdates(metadata:));

/// @brief A download is ready but needs to know if its permitted
- (void)receivedAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge
                               download:(BADownload *)download
                      completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition, NSURLCredential * _Nullable))completionHandler
API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(tvos, watchos);

/// @brief This method is called when a download, or multiple downloads fail but there is no currently BADownloadManager to handle the completion event.
/// @param failedDownload The download object that has failed.
- (void)backgroundDownloadDidFail:(BADownload *)failedDownload
API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(tvos, watchos);

/// @brief This method is called when a download has finished but there is no currently BADownloadManager to handle the completion event.
/// @param finishedDownload Download that has completed successfully.
/// @param fileURL A location to the file that has been downloaded. The caller must move or copy this file before this method exits scope or the file will be destroyed.
- (void)backgroundDownloadDidFinish:(BADownload *)finishedDownload
                            fileURL:(NSURL *)fileURL
API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(tvos, watchos);

/// @brief This method will be called shortly before the extension is terminated.
/// @discussion This method is called asyncronously from the other methods in the protocol. This method is invoked if all applicable
/// callbacks have been called and returned. This method is also invoked if the extension has run over it's alotted runtime and is now about to
/// be killed. This gives users a last changes to tidy up their state before process termination.
- (void)extensionWillTerminate
API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(tvos, watchos);

@end

NS_ASSUME_NONNULL_END
