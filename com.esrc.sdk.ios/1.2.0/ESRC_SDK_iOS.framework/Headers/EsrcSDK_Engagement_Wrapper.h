//
//  EsrcSDK_Emotion_Wrapper.h
//  ESRC-SDK-iOS
//
//  Created by Hyunwoo Lee on 27/05/2021.
//  Copyright © 2021 ESRC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EsrcSDK_Engagement_Wrapper : NSObject

+ (bool) EsrcSDK_Engagement_Initialize;
+ (bool) EsrcSDK_Engagement_Release;
+ (int) EsrcSDK_Engagement_RecognizeFocusingInTimeDomain: (double) hr param2: (double *) emotionProbs;
+ (int) EsrcSDK_Engagement_RecognizeFocusingInFrequencyDomain: (double *) hrv param2: (double *) emotionProbs;
+ (int) EsrcSDK_Engagement_RecognizeEngagementInTimeDomain: (double) hr param2: (double *) emotionProbs;
+ (int) EsrcSDK_Engagement_RecognizeEngagementInFrequencyDomain: (double *) hrv param2: (double *) emotionProbs;

@end
