# ESRC SDK for iOS

[![Platform](https://img.shields.io/badge/platform-iOS-orange.svg)](https://github.com/esrc-official/ESRC-SDK-iOS)
[![Languages](https://img.shields.io/badge/language-Objective--C%20%7C%20Swift-orange.svg)](https://github.com/esrc-official/ESRC-SDK-iOS)
[![Commercial License](https://img.shields.io/badge/License-Commercial-brightgreen.svg)](https://github.com/esrc-official/ESRC-SDK-iOS/blob/master/LICENSE.md)

## Table of contents

  1. [About ESRC SDK](#about-esrc-sdk)
  1. [Install ESRC SDK](#install-esrc-sdk)
  1. [Making your first recognition](#making-your-first-recognition)

<br />

## About ESRC SDK

Through our **ESRC SDK** for iOS, you can efficiently integrate real-time recognition of facial expression, heart response and emotions into your mobile app. This and other pages in the Getting Started provide the ESRC SDK’s structure and installation steps, then goes through the preliminary steps of implementing the ESRC SDK in your own project.

### Requirements

The minimum requirements to use our iOS sample are:

- iOS 9.0 or later <br />
- Swift 4 or later, Objective-C <br />
- Xcode 9 or later, macOS Sierra or later <br />

### Key functions

|Function|Description|
|---|---|
|Face Detection| Detect a single face using a front camera on mobile. |
|Facial Landmark Detection| Detect x and y coordinates of 68 facial landmarks in 2D space from the detected face. |
|Facial Action Unit Analysis| Extract centroid, area, theta and R distance of each 39 facial action unit from the detected 68 facial landmarks based on Facial Action Coding System determined by Paul Ekman. |
|Facial Expression Recognition| Recognize 7 facial expressions consist of neutral, happiness, sad-ness, surprise, anger, disgust and fear based on 6 basic emotions. |
|Heart Rate Estimation| Estimate heart rate from facial color variations and head move-ments caused by heartbeat using Remote Photoplethysmography and Ballistocardiography. |
|Heart Rate Variability Analysis| Extract 19 variables of heart rate variability reflecting autonomic nervous system activity from the accumulated heart rates. |
|Engagement Recognition| Recognize engagement level from balance of autonomic nervous system by heart rate variability analysis. |

### Try the sample app

Our sample app has the core features of the ESRC SDK. Download the app from our [GitHub repository](https://github.com/esrc-official/ESRC-iOS) to get an idea of what you can build with the actual SDK and start building in your project.

> Note: The fastest way to see our ESRC SDK in action is to build your app on top of our sample app. Make sure to change the application ID of the sample app to your own.


## Install ESRC SDK

This page provides a step-by-step guide that demonstrates how to build and configure an in-app face and bio-analysis using the ESRC SDK.

### Step 1: Download and install the ESRC SDK

Installing the ESRC SDK is simple if you're familiar with using external frameowkrs. First, download the ESRC SDK `.framework` file from our [GitHub repository](https://github.com/esrc-official/ESRC-SDK-iOS). Copy the downloaded framework file into your project directory. Go to `General` tab of your Xcode Project Navigator, and scroll down to `Frameworks, Libraries, and Embedded Content` menu. Click the + button, choose Add other... drop down menu, and select Add files... option. From the file navigator, select the framework that you've previously downloaded. Select `Embed & Sign` option in the Embed menu of the selected framework.

### Step 2: Download and install the assets

Download the `assets` file from our [GitHub repository](https://github.com/esrc-official/ESRC-SDK-iOS/tree/master/assets). Copy the downloaded assets file into your project directory. Go to `Build Phases` tab of your Xcode Project Navigator, and scroll down to `Copy Bundle Resourses` menu. Click the + button, choose select the assets file that you've previously downloaded. 

### Step 3: Grant system permission to the ESRC SDK

The ESRC SDK requires system permission. This permission allow the ESRC SDK to use a camera. Go to `Info` tab of your Xcode Project Navigator, and scroll down to `Custom iOS Target Properties` menu. Click the + button, choose select `Privacy - Camera Usage Description`option.  

### Step 4: Use the ESRC SDK in Swift

You can use all classes and methods just with the following one import statement, without a bridging header file in Swift.

```swift
import ESRC_SDK_iOS
```

## Making your first recognition

The ESRC SDK simplifies vision features into an effortless and straightforward process. To recognize your facial expression, heart response and emotion, do the following steps:

This page provides a step-by-step guide that demonstrates how to build and configure an in-app face and bio-analysis using ESRC SDK. License key can be received by requesting by the email: **esrc@esrc.co.kr**.

### Step 1: Initialize the ESRC SDK

Initialization binds the ESRC SDK to iOS, thereby allowing it to use a camera in your mobile. To the `initWithApplicationId()` method, pass the **App ID** of your ESRC application to initialize the ESRC SDK and the **ESRCLicenseHandler** to received callback for validation of the App ID.

```swift
ESRC.initWithApplicationId(appId: APP_ID, licenseHandler:  ESRCLicenseHandler() {
    
    func onValidatedLicense() {
        …
    }
    
    func onInvalidatedLicense() {
        …
    }
})
```

> Note: The `ESRC.initWithApplicationId()` method must be called once across your iOS app. It is recommended to initialize the ESRC SDK in the `viewDidAppear()` method of the Application instance.

### Step 2: Start the ESRC SDK

Start the ESRC SDK to recognize your facial expression, heart response and emotion. To the `start()` method, pass the `ENABLE_HRV` parameter for whether to analyze HRV and the `ESRCHandler` to handle the results. You should implement the callback method of `ESRCHandler` interface. So, you can receive the results of face, facial landmark, facial expression, heart rate, heart rate variability and engagement. Please refer to **[sample app](https://github.com/esrc-official/ESRC-iOS)**.

```swift
ESRC.start(enableHRV: ENABLE_HRV, handler: ESRCHandler() {
    func onDetectedFace(face: ESRCFace) {
        // The face is detected.
        // Through the “face” parameter of the onDetectedFace() callback method,
        // you can get the location of the face from the result object
        // that ESRC SDK has passed to the onDetectedFace().
        …
    }
    
    // Please implement other callback method of ESRCHandler interface.
    func onNotDetectedFace() { … }
    func onDetectedFacialLandmark(facialLandmark: ESRCFacialLandmark) { … }
    func onAnalyzedFacialActionUnit(facialActionUnit: ESRCFacialActionUnit) { … }
    func onRecognizedFacialExpression(facialExpression: ESRCFacialExpression) { … }
    func didChangedProgressRatioOnRemoteHR(progressRatio: Double) { … }
    func onEstimatedRemoteHR(remoteHR: ESRCRemoteHR) { … }
    func didChangedProgressRatioOnHRV(progressRatio: Double) { … }
    func onAnalyzedHRV(hrv: ESRCHRV) { … }
    func onRecognizedEngagement(engagement: ESRCEngagement) { … }
});
```

### Step 3: Feed the ESRC SDK

Feed `UIImage` on the ESRC SDK. To the `feed()` method, pass the `UIImage` image received using a camera in real-time. Please do it at 10 fps.

```swift
ESRC.feed(frame: frame)
```

### Step 4: Stop the ESRC SDK

When your app is not use the camera or destroyed, stop the ESRC SDK.

```swift
ESRC.stop()
```
