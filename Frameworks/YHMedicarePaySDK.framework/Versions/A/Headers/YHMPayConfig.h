//
//  YHMPayConfig.h
//  YHMedicarePaySDK
//
//  Created by Jagtu on 2018/8/7.
//

#import <YHOnePaySDK/YHOnePayConfig.h>

@interface YHMPayConfig : YHOnePayConfig

/**
 * 应用appId
 */
@property(nonatomic,copy)NSString *appId;

/**
 * 应用密钥
 */
@property(nonatomic,copy)NSString *appSecret;

/**
 * 单家医院
 */
@property(nonatomic,assign)BOOL isAloneMedical;

/**
 * 机构名称
 */
@property(nonatomic,copy)NSString *medicalName;

/**
 * 商户所属渠道类型，请修改为对应的渠道
 *  01 窗口
 *  02 自助机
 *  03 网站
 *  04 手机app
 *  05 微信公众号
 *  06 银医通
 *  07 微信小程序
 *  08 支付宝服务窗
 *  09 药店
 *  14 市民卡app
 *  15 i厦门app
 *  31 美丽厦门微信公众号
 */
@property(nonatomic,copy)NSString * appChannelType;


//@property(nonatomic,strong)NSString *isWjw;//1表示多家医院，0单医院，默认为1.
/**
 初始化设置
 
 @param appId 应用ID与应用的bundleIdentifier对应
 @param appSecret 应用密钥
 @param appChannelType 所属渠道类型
 @param platformHost 平台地址
 */
+(YHMPayConfig *)initWithAPPID:(NSString *)appId appSecret:(NSString *)appSecret channelType:(NSString *)appChannelType platformHost:(NSString *)platformHost;

+(YHMPayConfig *)initWithAPPID:(NSString *)appId appSecret:(NSString *)appSecret channelType:(NSString *)appChannelType platformHost:(NSString *)platformHost medicalName:(NSString *)hospName;

@end
