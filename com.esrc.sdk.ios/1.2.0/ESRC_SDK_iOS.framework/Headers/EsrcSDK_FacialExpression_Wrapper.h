//
//  EsrcCV_FacialExpression_Wrapper.h
//  ESRC-SDK-iOS
//
//  Created by Hyunwoo Lee on 27/05/2021.
//  Copyright © 2021 ESRC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIkit/UIkit.h>

@interface EsrcSDK_FacialExpression_Wrapper : NSObject

+ (bool) EsrcSDK_FacialExpression_Initialize: (NSString *) tflitePath;
+ (bool) EsrcSDK_FacialExpression_Release;
+ (int) EsrcSDK_FacialExpression_Feed: (UIImage *) face param2: (float *) emotionProbs;
+ (int) EsrcSDK_FacialEpression_GetResult: (float *) emotionProbs;

@end
