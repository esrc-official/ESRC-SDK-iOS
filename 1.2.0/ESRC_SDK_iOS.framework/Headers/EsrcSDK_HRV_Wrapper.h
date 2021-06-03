//
//  EsrcSDK_HRV_Wrapper.h
//  ESRC-SDK-iOS
//
//  Created by Hyunwoo Lee on 27/05/2021.
//  Copyright © 2021 ESRC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EsrcSDK_HRV_Wrapper : NSObject

+ (bool) EsrcSDK_HRV_Initialize;
+ (bool) EsrcSDK_HRV_Release;
+ (void) EsrcSDK_HRV_Feed: (double) hr param2: (double *) hrv param3: (double *) progressRatio;

@end
