//
//  EsrcCV_FacialLandmark_Wrapper.h
//  ESRC-SDK-iOS
//
//  Created by Hyunwoo Lee on 27/05/2021.
//  Copyright © 2021 ESRC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIkit/UIkit.h>

@interface EsrcSDK_FacialLandmark_Wrapper : NSObject

+ (bool) EsrcSDK_FacialLandmark_Initialize: (NSString *) tflitePath;
+ (bool) EsrcSDK_FacialLandmark_Release;
+ (void) EsrcSDK_FacialLandmark_Feed: (UIImage *) face param2: (float *) facialLandmark;

@end
