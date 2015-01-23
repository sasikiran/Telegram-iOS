/*
 * This is the source code of Telegram for iOS v. 1.1
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Peter Iakovlev, 2013.
 */

#ifndef Telegraph_TGCommon_h
#define Telegraph_TGCommon_h

#import "ASCommon.h"

#import <UIKit/UIKit.h>

#define TGUseSocial true

#define TG_ENABLE_AUDIO_NOTES true

#define TGAssert(expr) assert(expr)

#define UIColorRGB(rgb) ([[UIColor alloc] initWithRed:(((rgb >> 16) & 0xff) / 255.0f) green:(((rgb >> 8) & 0xff) / 255.0f) blue:(((rgb) & 0xff) / 255.0f) alpha:1.0f])
#define UIColorRGBA(rgb,a) ([[UIColor alloc] initWithRed:(((rgb >> 16) & 0xff) / 255.0f) green:(((rgb >> 8) & 0xff) / 255.0f) blue:(((rgb) & 0xff) / 255.0f) alpha:a])

#define TGRestrictedToMainThread {if(![[NSThread currentThread] isMainThread]) TGLog(@"***** Warning: main thread-bound operation is running in background! *****");}


extern int TGLocalizedStaticVersion;
#define TGLocalizedStatic(s) ({ static int _localizedStringVersion = 0; static NSString *_localizedString = nil; if (_localizedString == nil || _localizedStringVersion != TGLocalizedStaticVersion) { _localizedString = TGLocalized(s); _localizedStringVersion = TGLocalizedStaticVersion; } _localizedString; })

#define TG_TIMESTAMP_DEFINE(s) CFAbsoluteTime tg_timestamp_##s = CFAbsoluteTimeGetCurrent(); int tg_timestamp_line_##s = __LINE__;
#define TG_TIMESTAMP_MEASURE(s) { CFAbsoluteTime tg_timestamp_current_time = CFAbsoluteTimeGetCurrent(); TGLog(@"%s %d-%d: %f ms", #s, tg_timestamp_line_##s, __LINE__, (tg_timestamp_current_time - tg_timestamp_##s) * 1000.0); tg_timestamp_##s = tg_timestamp_current_time; tg_timestamp_line_##s = __LINE__; }

#ifdef __cplusplus
extern "C" {
#endif
int cpuCoreCount();
int deviceMemorySize();
    
void TGSetLocalizationFromFile(NSString *filePath);
bool TGIsCustomLocalizationActive();
void TGResetLocalization();
NSString *TGLocalized(NSString *s);

bool TGObjectCompare(id obj1, id obj2);
bool TGStringCompare(NSString *s1, NSString *s2);
    
NSTimeInterval TGCurrentSystemTime();
    
NSString *TGStringMD5(NSString *string);
    
int iosMajorVersion();
int iosMinorVersion();
    
void printMemoryUsage(NSString *tag);
    
void TGDumpViews(UIView *view, NSString *indent);
    
NSString *TGEncodeText(NSString *string, int key);
    
inline void TGDispatchOnMainThread(dispatch_block_t block)
{
    if ([NSThread isMainThread])
        block();
    else
        dispatch_async(dispatch_get_main_queue(), block);
}

inline void TGDispatchAfter(double delay, dispatch_queue_t queue, dispatch_block_t block)
{
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)((delay) * NSEC_PER_SEC)), queue, block);
}
    
#ifdef __cplusplus
}
#endif

@interface NSNumber (IntegerTypes)

- (int32_t)int32Value;
- (int64_t)int64Value;

@end

#define CGFloor floorf

#import "TGAppearance.h"

#endif
