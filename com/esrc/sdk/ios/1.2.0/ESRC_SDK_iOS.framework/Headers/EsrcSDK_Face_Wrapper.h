//
//  EsrcCV_Face_Wrapper.h
//  ESRC-SDK-iOS
//
//  Created by Hyunwoo Lee on 27/05/2021.
//  Copyright © 2021 ESRC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIkit/UIkit.h>

@interface EsrcSDK_Face_Wrapper : NSObject

+ (bool) EsrcSDK_Face_Initialize: (NSString *) protoPath param2: (NSString *) caffePath;
+ (bool) EsrcSDK_Face_Release;
+ (UIImage *) EsrcSDK_Face_Feed: (UIImage *) frame param2: (int *) roi param3: (bool *) isDetect;
+ (void) EsrcSDK_Face_Feed: (UIImage *) frame param2: (UIImage **) faceFrame param3: (int *) face param3: (UIImage **) squareFrame param4: (int *) square param5: (bool *) isDetect;

@end
