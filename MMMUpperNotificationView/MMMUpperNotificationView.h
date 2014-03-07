// MMMUpperNotificationView.h
//
// Copyright (c) 2014 Muukii (http://www.muukii.me)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

NS_INLINE BOOL
__OSVersionNumberAtLeast_iOS_7_0() {
    return (floor(NSFoundationVersionNumber) > NSFoundationVersionNumber_iOS_6_1);
}
#define OSVersionNumberAtLeast_iOS_7_0 (__OSVersionNumberAtLeast_iOS_7_0())

#import <UIKit/UIKit.h>

typedef void(^TapHandler)();

@interface MMMUpperNotificationView : UIView
@property (nonatomic, retain) UIImageView *imageView;
@property (nonatomic, retain) UILabel *messageLabel;
@property (nonatomic, copy) NSString *message;
@property (nonatomic, copy) UIImage *image;

@property (nonatomic, copy) UIColor *backgroundViewColor;
@property (nonatomic, copy) UIColor *messageTextColor;

- (void)configureView; // Super Call When Override.
- (void)configureColor; // Please, Override this method when make subclass.
- (void)setTapHandler:(TapHandler)tapHandler;
- (TapHandler)tapHandler;

+ (instancetype)notification;
+ (instancetype)notificationWithMessage:(NSString *)message image:(UIImage *)image;
+ (instancetype)notificationWithMessage:(NSString *)message image:(UIImage *)image tapHandler:(TapHandler)tapHandler;

- (instancetype)initNotification;
- (instancetype)initWithMessage:(NSString *)message image:(UIImage *)image;
- (instancetype)initWithMessage:(NSString *)message image:(UIImage *)image tapHandler:(TapHandler)tapHandler;
- (void)show;
@end


@interface MMMUpperNotificationCautionView : MMMUpperNotificationView

@end

@interface MMMUpperNotificationSuccessView : MMMUpperNotificationView

@end

@interface MMMUpperNotificationFaiureView : MMMUpperNotificationView

@end
