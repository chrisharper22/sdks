//
//  MTLFXTemporalScaler.h
//  MetalFX
//
//  Copyright (c) 2021-2022 Apple Inc. All rights reserved.
//

#import <Metal/Metal.h>
#import <simd/simd.h>
#import <CoreGraphics/CoreGraphics.h>

typedef NS_ENUM(NSUInteger, MTLFXTemporalScalerVersion) {
    MTLFXTemporalScalerVersion_v1 = 0,
    MTLFXTemporalScalerVersion_End,
} API_AVAILABLE(macos(13.0), ios(16.0));

// Forward declaration.
@protocol MTLFXTemporalScaler;

API_AVAILABLE(macos(13.0), ios(16.0))
@interface MTLFXTemporalScalerDescriptor : NSObject

// These properties must be set to the respective Metal pixel formats for each texture that will be used with the scaler.
@property MTLPixelFormat colorTextureFormat;
@property MTLPixelFormat depthTextureFormat;
@property MTLPixelFormat motionTextureFormat;
@property MTLPixelFormat outputTextureFormat;

@property NSUInteger inputWidth;
@property NSUInteger inputHeight;
@property NSUInteger outputWidth;
@property NSUInteger outputHeight;

// Dynamic Resolution properties
// Set enableInputContentProperties to NO to indicate not using dynamic resolution
// Scale value represents output resolution / input content resolution for either
// width or height dimension. It's assumed that aspect ratio of input/output is
// always the same. 
@property BOOL enableInputContentProperties;
@property float inputContentMinScale;
@property float inputContentMaxScale;

@property enum MTLFXTemporalScalerVersion version;

// The following method is used to instantiate the effect encoder for a given
// Metal device.
- (id <MTLFXTemporalScaler>)newTemporalScalerWithDevice:(id<MTLDevice>)device;

@end

// This is the object that gets created from the descriptor
API_AVAILABLE(macos(13.0), ios(16.0))
@protocol MTLFXTemporalScaler <NSObject>

// Properties return the minimum required MTLTextureUsage bits required
@property (nonatomic, readonly) MTLTextureUsage colorTextureUsage;
@property (nonatomic, readonly) MTLTextureUsage depthTextureUsage;
@property (nonatomic, readonly) MTLTextureUsage motionTextureUsage;
@property (nonatomic, readonly) MTLTextureUsage outputTextureUsage;

// Dynamic Resolution property
@property (nonatomic) NSUInteger inputContentWidth;
@property (nonatomic) NSUInteger inputContentHeight;

// These would be all of the "state" needed that is allowed to change on a frame by
// frame basis.   We don't care about the textures assigned except that they must
// match the originally specified dimensions and pixel formats.
@property (nonatomic, retain) id<MTLTexture> colorTexture;
@property (nonatomic, retain) id<MTLTexture> depthTexture;
@property (nonatomic, retain) id<MTLTexture> motionTexture;
@property (nonatomic, retain) id<MTLTexture> outputTexture;

// The jitter offset property indicates the pixel offset to sample in order to
// return to the frame's reference frame.
@property (nonatomic) CGPoint jitterOffset;

// Scale factor to be applied to motion vectors to convert to pixel/fragment
// coordinates in the input data.  The expectation for a 1.0 scale factor is
// that each pixel's motion vector will point to where that pixel was in the
// prior frame.  Assuming standard Metal device coordinates (0,0 is upper left
// in the framebuffer), the motion vectors for an object that moved down and
// to the right in the framebuffer texture by 10 pixels would be -10,-10.
@property (nonatomic) CGPoint motionVectorScale;

// Reset.  Set to true when history is invalid (scene cut, etc.)
@property (nonatomic) BOOL reset;

// Set whether the depth buffer uses reversed depth or not. Defaults to YES.
@property (nonatomic) BOOL reversedDepth;

// Read-only immutable properties of effect
@property (nonatomic, readonly) MTLPixelFormat colorTextureFormat;
@property (nonatomic, readonly) MTLPixelFormat depthTextureFormat;
@property (nonatomic, readonly) MTLPixelFormat motionTextureFormat;
@property (nonatomic, readonly) MTLPixelFormat outputTextureFormat;
@property (nonatomic, readonly) NSUInteger inputWidth;
@property (nonatomic, readonly) NSUInteger inputHeight;
@property (nonatomic, readonly) NSUInteger outputWidth;
@property (nonatomic, readonly) NSUInteger outputHeight;
@property (nonatomic, readonly) float inputContentMinScale;
@property (nonatomic, readonly) float inputContentMaxScale;

// Property for synchronization when using untracked resources
@property (nonatomic, retain) id<MTLFence> fence;

// Method to encode the effect to a command buffer
- (void)encodeToCommandBuffer:(id<MTLCommandBuffer>)commandBuffer;

@end
