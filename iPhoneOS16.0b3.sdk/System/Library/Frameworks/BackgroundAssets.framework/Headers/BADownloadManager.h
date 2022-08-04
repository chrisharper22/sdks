//
//  BADownloader.h
//  BackgroundAssets
//
//  Copyright (c) 2022, Apple Inc.
//  All rights reserved.
//

#import <BackgroundAssets/BackgroundAssets.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(tvos, watchos)
@protocol BADownloadManagerDelegate <NSObject>

@optional

/// @brief A download has started.
- (void)downloadDidBegin:(BADownload *)download;

/// @brief A download has paused.
- (void)downloadDidPause:(BADownload *)download;

/// @brief A download has made progress in bytes / total so far / total expected.
- (void)download:(BADownload *)download didWriteBytes:(int64_t)bytesWritten
                                    totalBytesWritten:(int64_t)totalBytesWritten
                            totalBytesExpectedToWrite:(int64_t)totalExpectedBytes;

/// @brief A download has tried to start but gotten a challenge quest.
- (void)download:(BADownload *)download didReceiveChallenge:(NSURLAuthenticationChallenge *)challenge
                                          completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential * _Nullable credential))completionHandler;

/// @brief A download has failed with a specific error.
- (void)download:(BADownload *)download failedWithError:(NSError *)error;

/// @brief Called when a download has been completed and the file has placed at it's destination path.
/// @param fileURL A location to the file that has been downloaded.
/// @discussion The caller should attempt to use the URL provided by the API so that the system will
/// properly purge the file as storage fills up on the device. Only move this file if it is critical that it should
/// never be purged. It is recommended to leave the file in /Library/Caches so that it stays purgeable.
- (void)download:(BADownload *)download finishedWithFileURL:(NSURL *)fileURL;

@end

API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(tvos, watchos)
@interface BADownloadManager : NSObject

- (instancetype)init
NS_UNAVAILABLE;
+ (instancetype)new
NS_UNAVAILABLE;

/// @brief Gets the singleton downloader object.
@property (class, readonly, strong) BADownloadManager *sharedManager
API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(tvos, watchos)
NS_SWIFT_NAME(shared);

/// @brief A object confroming to BADownloadManagerDelegate to get notified when actions occur.
@property (weak) id<BADownloadManagerDelegate> delegate
API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(tvos, watchos);

/// @brief Allows access to the set of downloads that are staged / pending for you application identifier.
/// @discussion Allows access to the set of downloads that your application identifier has staged /pending.
/// @param completionHandler A block to recieve the currently scheduled downloads. The block is called on the same queue as all the other completion blocks in the class.
- (void)fetchCurrentDownloadsWithCompletionHandler:(void(^)(NSArray<BADownload *> *downloads, NSError *_Nullable error))completionHandler
API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(tvos, watchos)
NS_SWIFT_NAME(currentDownloads(completionHandler:))
NS_SWIFT_ASYNC_NAME(currentDownloads());

/// @brief Schedules a download to be done at some point in the future.
/// @discussion Specifies a download to schedule at a priority to be downloaded some point in the future.
/// @param download A BADownload object representing a URL to be downloaded.
/// @param outError A NSError representing why the BADownload could not be scheduled.
/// @return YES if @c download was scheduled. NO and @c outError set if the download could not be scheduled.
- (BOOL)scheduleDownload:(BADownload *)download
                   error:(NSError* _Nullable __autoreleasing *)outError
API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(tvos, watchos);

/// @brief Acquires exclusive access to the BADownloadManager across the app and application extension.
/// @discussion Acquires exclusive access to the BADownloadManager across the app and application extension. This ensures that your extension and app
/// do not perform operations at the same time. Both the extension and app must use this API to ensure exclusive access.
/// @param performHandler A block that will be executed once exclusive control is acquired.
/// If an error is non-nil then a problem occured acquiring exclusive access.
- (void)performWithExclusiveControl:(void (^)(NSError *_Nullable error))performHandler
API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(tvos, watchos)
NS_SWIFT_NAME(withExclusiveControl(_:))
NS_SWIFT_DISABLE_ASYNC;

/// @brief Acquires exclusive access to the BADownloadManager across the app and application extension.
/// @discussion Acquires exclusive access to the BADownloadManager across the app and application extension. This ensures that your extension and app
/// do not perform operations at the same time. Both the extension and app must use this API to ensure exclusive access.
/// @param date A date by which you want exclusive control acquired. If you pass +[NSDate date], control will attempt to be acquired and if it can not be, it will fail instantly.
/// @param performHandler A block that will be executed once exclusive control is acquired.
/// If an error is non-nil then a problem occured acquiring exclusive access.
- (void)performWithExclusiveControlBeforeDate:(NSDate *)date
                                   completion:(void (^)(BOOL acquiredLock, NSError *_Nullable error))performHandler
API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(tvos, watchos)
NS_SWIFT_NAME(withExclusiveControl(beforeDate:_:))
NS_SWIFT_DISABLE_ASYNC;

/// @brief Attempts to schedule a BADownload in foreground mode.
/// @discussion Attempts to schedule a BADownload in foreground mode. This download will start (if it has not been started) immediately regrardlesss of battery or
/// network status. The download will remain in this foreground until the download manager is disconnected. This API only functions if the download manager is created in
/// the application and not the download extension. If this API is called from the download extension, NO will be returned along with a NSError with the settings
/// BAErrorDomain : BAErrorCodeCallFromExtensionNotAllowed. If this API is called from a app while it is in the background, NO will be returned along with a NSError
/// with the settings BAErrorDomain : BAErrorCodeCallFromInactiveProcessNotAllowed.
- (BOOL)startForegroundDownload:(BADownload *)download
                          error:(NSError* _Nullable __autoreleasing *)outError
API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(tvos, watchos);

/// @brief Cancels a download.
/// @discussion Attempts to cancel a BADownload. If the download has not been schduled or has already completed, NO is returned along with a NSError set
/// to BAErrorDomain : BAErrorCodeDownloadNotScheduled.
/// @return YES if the download is canceled. NO if the download could not be canceled, @c error will be set with a reason why.
- (BOOL)cancelDownload:(BADownload *)download
                 error:(NSError **)error
API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(tvos, watchos);

@end

NS_ASSUME_NONNULL_END
