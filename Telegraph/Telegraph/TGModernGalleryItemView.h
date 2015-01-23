/*
 * This is the source code of Telegram for iOS v. 1.1
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Peter Iakovlev, 2013.
 */

#import <UIKit/UIKit.h>

#import "TGModernGalleryItem.h"

@class TGModernGalleryItemView;
@protocol TGModernGalleryDefaultFooterView;
@protocol TGModernGalleryDefaultFooterAccessoryView;

@protocol TGModernGalleryItemViewDelegate <NSObject>

- (void)itemViewIsReadyForScheduledDismiss:(TGModernGalleryItemView *)itemView;
- (void)itemViewDidRequestInterfaceShowHide:(TGModernGalleryItemView *)itemView;

@end

@interface TGModernGalleryItemView : UIView

@property (nonatomic, weak) id<TGModernGalleryItemViewDelegate> delegate;

@property (nonatomic) NSUInteger index;
@property (nonatomic, strong) id<TGModernGalleryItem> item;
@property (nonatomic, strong) UIView<TGModernGalleryDefaultFooterView> *defaultFooterView;
@property (nonatomic, strong) UIView<TGModernGalleryDefaultFooterAccessoryView> *defaultFooterAccessoryLeftView;
@property (nonatomic, strong) UIView<TGModernGalleryDefaultFooterAccessoryView> *defaultFooterAccessoryRightView;

- (void)setItem:(id<TGModernGalleryItem>)item synchronously:(bool)synchronously;

- (void)prepareForRecycle;
- (void)prepareForReuse;
- (void)setIsVisible:(bool)isVisible;
- (void)setIsCurrent:(bool)isCurrent;

- (UIView *)headerView;
- (UIView *)footerView;

- (UIView *)transitionView;
- (CGRect)transitionViewContentRect;

- (bool)dismissControllerNowOrSchedule;

@end
