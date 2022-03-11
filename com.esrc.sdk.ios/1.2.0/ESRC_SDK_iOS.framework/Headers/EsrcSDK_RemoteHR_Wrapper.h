//
//  EsrcSDK_RemoteHR_Wrapper.h
//  ESRC-SDK-iOS
//
//  Created by Hyunwoo Lee on 27/05/2021.
//  Copyright © 2021 ESRC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIkit/UIkit.h>

@interface EsrcSDK_RemoteHR_Wrapper : NSObject

+ (bool) EsrcSDK_RemoteHR_Initialize;
+ (bool) EsrcSDK_RemoteHR_Release;
+ (double) EsrcSDK_RemoteHR_Feed: (UIImage *) face param2: (double *) progressRatio;

@end
