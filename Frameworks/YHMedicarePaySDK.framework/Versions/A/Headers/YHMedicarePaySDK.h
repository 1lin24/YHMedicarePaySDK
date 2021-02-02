//
//  YHMedicarePaySDK.h
//  YHMedicarePaySDK（YHMPaySDK）
//
//  Created by Jagtu on 2018/4/27.
//  Copyright © 2018年 yh. All rights reserved.
//
//  Version 1.0.9.2  by Jagtu  2018/11/21
//  Version 1.1.9.1  by Jagtu  2020/07/09
//

// In this header, you should import all the public headers of your framework using statements like #import <YHMedicarePaySDK/PublicHeader.h>


#import <UIKit/UIKit.h>
//config
#import <YHMedicarePaySDK/YHMPayConfig.h>
#import <YHMedicarePaySDK/YHMPColor.h>
#import <YHMedicarePaySDK/YHMPConstant.h>

/**
 * 单例模式
 * 注：请确保对应用户已实名认证！
 */
@interface YHMedicarePaySDK : NSObject

/**
 *  发起医保结算
 *  ->选择医院 ->选择待结算处方列表 ->确认处方（处方详情） ->结算收银台（完成自费支付） ->结算完成
 *
 *  @param token     用户令牌
 *  @param completionBlock 结算结果回调Block。
 *  注：结算成功后，商户服务端也会收到异步通知。最终结算成功请根据服务端异步通知为准。
 */
+ (void)settleWithToken:(NSString *)token
             completion:(YHMPPayCompletionBlock)completionBlock;

/**
 *  查询已结算记录
 *  ->展示已结算记录列表页
 *
 *  @param token     用户令牌
 *  @param completionBlock 失败回调Block。主要处理token过期等错误
 */
+ (void)querySettledRecodeWithToken:(NSString *)token
                         completion:(YHMPPayCompletionBlock)completionBlock;


/**
 *  处理App消息推送
 *  处理包括待结算处方消息、结算成功消息(如自行展示结算结果则不展示)
 *  消息来源：->移动医保支付平台 ->商户服务端 ->商户APP ->SDK
 *
 *  @param token     用户令牌
 *  @param ylzSDKParams  消息参数
 *  @return 是否处理，YES表示SDK处理该消息并在处理完成时回调block，NO则商户APP自行处理
 */
+ (BOOL)processNotification:(NSDictionary *)ylzSDKParams
                  withToken:(NSString *)token;


/**
 *  处理第三方app支付完成后跳回商户app携带的支付结果Url
 *
 *  @param token     用户令牌
 *  @param openURL        支付结果url
 *  @param completionBlock  支付结果回调Block（商户app已被系统kill掉，才会回调此block）
 *  注：如果商户app已被系统kill掉，则支付失败时打开待结算处方页面，其它情况打开结算记录页面
 */
+ (void)processOrderWithToken:(NSString *)token
                      openURL:(NSURL *)openURL
                   completion:(YHMPPayCompletionBlock)completionBlock;


/**
 *  退出
 *  注：清除内存缓存里的用户信息！
 */
+ (void)logout;


/**
 *  查询待结算
 *  ->展示已结算记录列表页
 *
 *  @param token     用户令牌
 *  @param completionBlock 失败回调Block。主要处理token过期等错误
 */
+ (void)queryUnSettledRecodeWithToken:(NSString *)token
                         completion:(YHMPPayCompletionBlock)completionBlock;

@end

