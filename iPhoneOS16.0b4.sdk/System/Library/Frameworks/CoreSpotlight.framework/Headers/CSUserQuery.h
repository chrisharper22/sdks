//
//  CSUserQuery.h
//  CoreSpotlight
//
//  Copyright © 2021 Apple. All rights reserved.
//

#import <CoreSpotlight/CSBase.h>
#import <CoreSpotlight/CoreSpotlight.h>

NS_ASSUME_NONNULL_BEGIN

/****************    User Query    ****************/

API_AVAILABLE(macos(10.13), ios(16.0)) CS_TVOS_UNAVAILABLE
@interface CSUserQueryContext : CSSearchQueryContext

+ (CSUserQueryContext *)userQueryContext;
+ (CSUserQueryContext *)userQueryContextWithCurrentSuggestion:(CSSuggestion * _Nullable)currentSuggestion;

@property (nonatomic, assign) NSInteger maxSuggestionCount;

@end

API_AVAILABLE(macos(10.13), ios(16.0)) CS_TVOS_UNAVAILABLE
@interface CSUserQuery : CSSearchQuery

- (instancetype)initWithUserQueryString:(NSString * _Nullable)userQueryString queryContext:(CSUserQueryContext *)queryContext NS_DESIGNATED_INITIALIZER;

// The query will update the count before each foundSuggestionsHandler invocation to reflect
// the number of suggestions found so far; if foundSuggestionsHandler is nil then the count will be zero.
@property (readonly) NSInteger foundSuggestionCount;

// The foundSuggestionsHandler may be invoked additional times as new suggestions are generated,
// but the value will always be a complete, ordered list. The query serializes all the foundSuggestionsHandler invocations. If no handler is set, suggestions will not be generated.
@property (nullable, copy) void (^foundSuggestionsHandler)(NSArray<CSSuggestion *> *suggestions);

- (void)start;
- (void)cancel;

@end

/****************    Top Hit Query    ****************/

API_AVAILABLE(macos(10.13), ios(16.0)) CS_TVOS_UNAVAILABLE
@interface CSTopHitQueryContext : CSUserQueryContext

+ (CSTopHitQueryContext *)topHitQueryContext;
+ (CSTopHitQueryContext *)topHitQueryContextWithCurrentSuggestion:(CSSuggestion * _Nullable)currentSuggestion;

@property (nonatomic, assign) NSInteger maxItemCount;

@end

API_AVAILABLE(macos(10.13), ios(16.0)) CS_TVOS_UNAVAILABLE
@interface CSTopHitQuery : CSUserQuery

- (instancetype)initWithUserQueryString:(NSString * _Nullable)userQueryString queryContext:(CSTopHitQueryContext *)queryContext NS_DESIGNATED_INITIALIZER;

@end
NS_ASSUME_NONNULL_END
