//
//  RDLiveSDK.h
//  RDLiveSDK
//
//  Created by Wuxiaoxia on 16/5/15.
//  Copyright © 2016年 北京锐动天地信息技术有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class RDLiveSDK;
#pragma mark - RDLiveErrorCode 具体初始化锐动直播SDK错误码
typedef NS_ENUM(NSInteger, RDLiveErrorCode) {
    /*!
     传入的APPKEY为空
     */
    RDLIVE_PARA_APPKEY_NULL = 10000,
    
    /*!
     传入的SECRETKEY为空
     */
    RDLIVE_PARA_SECRETKEY_NULL,
    
    /*!
     传入的VIDEOSIZE(分辨率)为空
     */
    RDLIVE_PARA_LIVE_VIDEOSIZE_NULL,
    
    /*!
     传入的FPS(帧率)错误
     */
    RDLIVE_PARA_LIVE_FPS_INVALID,
    
    /*!
     传入的BPS(码率)为空
     */
    RDLIVE_PARA_LIVE_BPS_NULL,
    
    /*!
     传入的URL(直播地址)为空
     */
    RDLIVE_PARA_PLAYER_URL_NULL,
    
    /*!
     服务器连接异常
     */
    RDLIVE_CLIENT_INVALID,
    
    /*!
     服务已到期
     */
    RDLIVE_SERVICES_EXPIRED,
    
    /*!
     开始直播接口选择错误
     */
    RDLIVE_LIVE_INTERFACE_ERROR
};

typedef NS_ENUM(NSInteger, RDLiveAuthorizationType)
{
    RDLive_AT_URL,          //0:基础功能
    RDLive_AT_UID,          //1:云服务
    RDLive_AT_URL_OR_UID,   //2:基础功能、云服务均可
    RDLive_AT_INVALID       //3:服务已到期
};

#pragma mark - RDRtmpPublish
typedef NS_ENUM(NSInteger, RDRtmpPublishState)
{
    RDRtmpPublishStateNone,             //0
    RDRtmpPublishStateCameraStarted,    //1
    RDRtmpPublishStateStarting,         //2
    RDRtmpPublishStateStarted,          //3
    RDRtmpPublishStatePaused,           //4
    RDRtmpPublishStateEnded,            //5
    RDRtmpPublishStateError             //6
};

typedef NS_ENUM(NSInteger, RDRtmpPublishCameraState)
{
    RDRtmpPublishCameraStateFront,
    RDRtmpPublishCameraStateBack
};

typedef NS_ENUM(NSInteger, RDRtmpPublishAspectMode)
{
    RDRtmpPublishAspectModeFit,
    RDRtmpPublishAspectModeFill
};

typedef NS_ENUM(NSInteger, RDRtmpPublishFilterType) {
    RDRtmpPublishFilterNormal,         // 原始
    RDRtmpPublishFilterBeauty,         // 美颜
    RDRtmpPublishFilterGray,           // 黑白
    RDRtmpPublishFilterInvertColors,   // 反转颜色
    RDRtmpPublishFilterSepia,          // 褐色
    RDRtmpPublishFilterFisheye,        // 鱼眼
    RDRtmpPublishFilterGlow,           // 辉光
    RDRtmpPublishFilterYouGe,          // 优格
    RDRtmpPublishFilterLanSeShiKe,     // 蓝色时刻
    RDRtmpPublishFilterLengYan,        // 冷艳
    RDRtmpPublishFilterNuanYangYang,   // 暖洋洋
    RDRtmpPublishFilterGuTongSe        // 古铜色
};

@protocol RDRtmpPublishDelegate <NSObject>
@required

/**
 *  推送状态回调
 *
 *  @param rtmpState 推送状态
 */
- (void) RDRtmpPublishConnectionStatusChanged: (RDRtmpPublishState) liveState;
@optional

/**
 *  摄像头已添加回调
 */
- (void) RDRtmpPublishDidAddCameraSource:(RDLiveSDK *)rdLiveSDK;

/**
 *  检查自动调节码率模式回调
 */
- (void) RDRtmpPublishDetectedThroughput: (NSInteger) throughputInBytesPerSecond;
- (void) RDRtmpPublishDetectedThroughput: (NSInteger) throughputInBytesPerSecond videoRate:(NSInteger) rate;

@end

#pragma mark - RDRDRTMPPlayer
typedef enum {
    RDRTMPPlayerScalingModeAspectFit,
    RDRTMPPlayerScalingModeAspectFill,
    RDRTMPPlayerScalingModeFill
} RDRTMPPlayerScalingMode;

typedef enum {
    kRDRTMPPlayerStateNone = 0,                   // 0
    kRDRTMPPlayerStateConnecting,                 // 1
    kRDRTMPPlayerStateConnected,                  // 2
    kRDRTMPPlayerStateConnectionFailed,           // 3
    kRDRTMPPlayerStateGotStreamDuration,          // 4
    kRDRTMPPlayerStateGotAudioStreamInfo,         // 5
    kRDRTMPPlayerStateGotVideoStreamInfo,         // 6
    kRDRTMPPlayerStateInitialLoading,             // 7
    kRDRTMPPlayerStateReadyToPlay,                // 8
    kRDRTMPPlayerStateBuffering,                  // 9
    kRDRTMPPlayerStatePlaying,                    // 10
    kRDRTMPPlayerStatePlayed,                     // 11
    kRDRTMPPlayerStatePaused,                     // 12
    kRDRTMPPlayerStateStoppedByUser,              // 13
    kRDRTMPPlayerStateStoppedWithError,           // 14
    kRDRTMPPlayerStatePacketLoading,              // 15
    kRDRTMPPlayerStatePacketLoaded                // 16
} RDRTMPPlayerState;

typedef enum {
    kRDRTMPPlayerErrorNone = 0,                   // 0
    kRDRTMPPlayerErrorUnsupportedProtocol,        // 1
    kRDRTMPPlayerErrorStreamURLParseError,        // 2
    kRDRTMPPlayerErrorOpenStream,                 // 3
    kRDRTMPPlayerErrorStreamInfoNotFound,         // 4
    kRDRTMPPlayerErrorStreamsNotAvailable,        // 5
    kRDRTMPPlayerErrorStreamDurationNotFound,     // 6
    kRDRTMPPlayerErrorAudioStreamNotFound,        // 7
    kRDRTMPPlayerErrorVideoStreamNotFound,        // 8
    kRDRTMPPlayerErrorAudioCodecNotFound,         // 9
    kRDRTMPPlayerErrorVideoCodecNotFound,         // 10
    kRDRTMPPlayerErrorAudioCodecNotOpened,        // 11
    kRDRTMPPlayerErrorUnsupportedAudioFormat,     // 12
    kRDRTMPPlayerErrorAudioStreamAlreadyOpened,   // 13
    kRDRTMPPlayerErrorVideoCodecNotOpened,        // 14
    kRDRTMPPlayerErrorAudioAllocateMemory,        // 15
    kRDRTMPPlayerErrorVideoAllocateMemory,        // 16
    kRDRTMPPlayerErrorStreamReadError,            // 17
    kRDRTMPPlayerErrorStreamEOFError,             // 18
    kRDRTMPPlayerErroSetupScaler                  // 19
} RDRTMPPlayerError;

@protocol RDRTMPPlayerDelegate <NSObject>

@optional

- (void)RDRTMPPlayerStateChanged:(RDRTMPPlayerState)state errorCode:(RDRTMPPlayerError)errCode player:(id)player;

@end

@interface RDLiveSDK : NSObject

/**
 *  初始化RDLiveSDK，此方法在使用RDLiveSDK时在主线程中调用。
 *
 *  @param appKey                   在锐动SDK官网(http://www.rdsdk.com/ )中注册的应用Key。
 *  @param secretKey                在锐动SDK官网(http://www.rdsdk.com/ )中注册的应用秘钥。
 *  @param successBlock             初始化成功的回调［authType：在锐动SDK官网申请的服务类型］
 *  @param errorBlock               初始化失败的回调［error：初始化失败的错误码］
 */
- (instancetype) initWithAPPKey:(NSString *)appKey
                   andSecretKey:(NSString *)secretKey
                        success:(void (^)(RDLiveAuthorizationType authType))successBlock
                          error:(void (^)(NSError *error))errorBlock;

@property (nonatomic, readonly) RDLiveAuthorizationType authType;

#pragma mark - RDRtmpPushlish
/**
 *  摄像头视图
 */
@property (nonatomic, strong, readonly) UIView *cameraView;

/**
 *  分辨率(默认：720*1280）
 */
@property (nonatomic, assign) CGSize            videoSize;

/**
 *  码率(默认：600k）
 */
@property (nonatomic, assign) int               bitrate;

/**
 *  帧率(1-30)
 */
@property (nonatomic, assign) int               fps;

/**
 *  手动设置摄像头方向
 */
@property (nonatomic,assign) UIDeviceOrientation deviceOrientation;

/**
 *  设置前后置摄像头; Default is RDRtmpPublishCameraStateBack
 */
@property (nonatomic, assign) RDRtmpPublishCameraState cameraState;

/**
 *  是否锁死方向
 */
@property (nonatomic, assign) BOOL          orientationLocked;

/**
 *  是否开启闪光灯
 */
@property (nonatomic, assign) BOOL          torch;

/**
 *  视频缩放系数; Default is 1.0f
 */
@property (nonatomic, assign) float         videoZoomFactor;

/**
 *  麦克风音量; Default is 1.0f
 */
@property (nonatomic, assign) float         micGain;

/**
 *  焦距调整; (0,0) is top-left, (1,1) is bottom-right
 */
@property (nonatomic, assign) CGPoint       focusPointOfInterest;

/**
 *  曝光量调整
 */
@property (nonatomic, assign) CGPoint       exposurePointOfInterest;

/**
 *  是否自动调焦
 */
@property (nonatomic, assign) BOOL          continuousAutofocus;

/**
 *  是否自动调节曝光度
 */
@property (nonatomic, assign) BOOL          continuousExposure;

/**
 *  是否根据用户网络自动调节码率; Default is off
 */
@property (nonatomic, assign) BOOL          useAdaptiveBitrate;

/**
 *  摄像头适应模式, Default is RDRtmpPublishAspectModeFit
 */
@property (nonatomic, assign) RDRtmpPublishAspectMode  aspectMode;

/**
 *  直播状态
 */
@property (nonatomic, readonly) RDRtmpPublishState liveState;

/**
 *  摄像头滤镜,Default is RDRtmpPublishFilterBeauty
 */
@property (nonatomic, assign) RDRtmpPublishFilterType      filter;

/**
 *  直播委托协议
 */
@property (nonatomic, assign) id<RDRtmpPublishDelegate> rtmpPublishDelegate;

/**
 *  直播之前准备，用于设置直播参数。
 *  @param  videoSize               分辨率
 *  @param  fps                     帧率(1-30)
 *  @param  bps                     码率
 *  @param  useInterfaceOrientation 是否根据设备方向调节摄像头方向
 *  @param  cameraState             设置前后置摄像头
 *  @param  aspectMode              摄像头适应模式
 */
- (void) preparePublishWithVideoSize:(CGSize)videoSize
                           frameRate:(int)fps
                             bitrate:(int)bps
             useInterfaceOrientation:(BOOL)useInterfaceOrientation
                         cameraState:(RDRtmpPublishCameraState) cameraState
                          aspectMode:(RDRtmpPublishAspectMode) aspectMode;

/**
 *  在锐动SDK官网申请的服务类型是基础服务RDLive_AT_URL或RDLive_AT_URL_OR_UID时，才可使用此接口直播
 *  开始直播,推送摄像头到rtmp
 *
 *  @param rtmpUrl      rtmp服务器地址
 *  @param streamKey    rtmp流名称
 *  @param errorBlock   开始直播失败的回调［status：开始直播失败的错误码］
 */
- (void) startPublishWithUrl:(NSString *)rtmpUrl
                andStreamKey:(NSString *)streamKey
                     success:(void (^)())successBlock
                       error:(void (^)(RDLiveErrorCode status))errorBlock;

/**
 *  在锐动SDK官网申请的服务类型是云服务RDLive_AT_UID或RDLive_AT_URL_OR_UID时，才可使用此接口直播
 *  开始直播
 *
 *  @param userID       用户ID
 *  @param errorBlock   开始直播失败的回调［error：开始直播失败的错误码］
 */
- (void) startPublishWithUid:(NSString *)userID
                    andTitle:(NSString *)title
                     success:(void (^)())successBlock
                       error:(void (^)(NSError *error))errorBlock;

/**
 *  结束直播
 */
- (void) endPublish;

/**
 *  美颜滤镜的美丽程度（1-5）,Default is 4
 */
- (void)setPublishBeautyFilterWithLevel:(NSInteger)level;

/**
 *  添加水印
 *
 *  @param image 水印图片
 *  @param rect  图片区域
 */
- (void) addPublishPixelBufferSource: (UIImage*) image
                     withRect: (CGRect) rect;

/**
 *  获取直播截屏
 */
- (UIImage *) getPublishScreenshot;

#pragma mark - RDRTMPPlayer
/**
 *  播放器预览视图
 */
@property (nonatomic, readonly) UIView *playerView;

/**
 *  播放视频地址
 */
@property (nonatomic, retain) NSString *contentRtmpURLStr;

/**
 *  播放器适应模式
 */
@property (nonatomic, assign) RDRTMPPlayerScalingMode playerScalingMode;

/**
 *  播放委托协议
 */
@property (nonatomic, assign) id<RDRTMPPlayerDelegate> rtmpPlayerDelegate;

/*
 *  获取用户直播详细信息
 *  @param successBlock 获取用户直播详细信息成功的回调 [liveInfoDic:获取到的用户直播详细信息]
 *                      title:直播标题
 *                      description：直播描述
 *                      thumbnailUrl：缩略图地址
 *                      liveRtmpUrl：直播rtmp地址
 *                      liveStatus：直播状态:0准备好，1废弃/出错，2直播中，3流断开，4直播结束
 *  @param errorBlock   获取用户直播详细信息失败的回调 error：获取用户直播详细信息失败的错误码］
 */
- (void)getLiveInfoWithUid:(NSString *)userID
                   success:(void (^)(NSDictionary *liveInfoDic))successBlock
                    error:(void (^)(NSError *error))errorBlock;

/**
 *  播放
 */
- (void)play;

/**
 *  停止  ：如果没有开始播放，或者播放器出错，不需要调用此接口。
 */
- (void)stop;

/**
 *  设置播放器是否静音
 */
- (void)setMute:(BOOL)value;

/**
 *  获取播放视频缩略图
 */
- (UIImage *)rtmpPlayerSnapshot;

@end
