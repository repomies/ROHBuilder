//
//  ROHBuilder.h
//
//  Created by Janne Käki on 27/02/15.
//  Copyright (c) 2015 Janne Käki. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface ROHBuilder : NSObject

+ (instancetype)builderWithInitBlock:(id (^)(ROHBuilder *builder))initBlock
                           editBlock:(void (^)(id object))editBlock;

- (instancetype)with:(void (^)(id object))block;

- (id)build;
- (id)buildWith:(void (^)(id object))block;

@end

////////////////////////////////////////////////////////////////////////////////

@interface ROHArrayBuilder : ROHBuilder
- (instancetype)with:(void (^)(NSMutableArray *array))block;
- (NSArray *)build;
- (NSArray *)buildWith:(void (^)(NSMutableArray *array))block;
@end

@interface ROHAttributedStringBuilder : ROHBuilder
- (instancetype)with:(void (^)(NSMutableAttributedString *string))block;
- (NSAttributedString *)build;
- (NSAttributedString *)buildWith:(void (^)(NSMutableAttributedString *string))block;
@end

@interface ROHDictionaryBuilder : ROHBuilder
- (instancetype)with:(void (^)(NSMutableDictionary *dictionary))block;
- (NSDictionary *)build;
- (NSDictionary *)buildWith:(void (^)(NSMutableDictionary *dictionary))block;
@end

@interface ROHParagraphStyleBuilder : ROHBuilder
- (instancetype)with:(void (^)(NSMutableParagraphStyle *style))block;
- (NSParagraphStyle *)build;
- (NSParagraphStyle *)buildWith:(void (^)(NSMutableParagraphStyle *style))block;
@end

@interface ROHStringBuilder : ROHBuilder
- (instancetype)with:(void (^)(NSMutableString *string))block;
- (NSString *)build;
- (NSString *)buildWith:(void (^)(NSMutableString *string))block;
@end

@interface ROHURLRequestBuilder : ROHBuilder
- (instancetype)with:(void (^)(NSMutableURLRequest *request))block;
- (NSURLRequest *)build;
- (NSURLRequest *)buildWith:(void (^)(NSMutableURLRequest *request))block;
@end

@interface ROHViewBuilder : ROHBuilder
- (instancetype)with:(void (^)(UIView *view))block;
- (UIView *)build;
- (UIView *)buildWith:(void (^)(UIView *view))block;
@end

@interface ROHActivityIndicatorViewBuilder : ROHViewBuilder
- (instancetype)with:(void (^)(UIView *activityIndicatorView))block;
- (UIActivityIndicatorView *)build;
- (UIActivityIndicatorView *)buildWith:(void (^)(UIActivityIndicatorView *activityIndicatorView))block;
@end

@interface ROHButtonBuilder : ROHViewBuilder
- (instancetype)with:(void (^)(UIButton *button))block;
- (UIButton *)build;
- (UIButton *)buildWith:(void (^)(UIButton *button))block;
@end

@interface ROHCollectionViewBuilder : ROHViewBuilder
- (instancetype)with:(void (^)(UICollectionView *collectionView))block;
- (UICollectionView *)build;
- (UICollectionView *)buildWith:(void (^)(UICollectionView *collectionView))block;
@end

@interface ROHImageViewBuilder : ROHViewBuilder
- (instancetype)with:(void (^)(UIImageView *imageView))block;
- (UIImageView *)build;
- (UIImageView *)buildWith:(void (^)(UIImageView *imageView))block;
@end

@interface ROHLabelBuilder : ROHViewBuilder
- (instancetype)with:(void (^)(UILabel *label))block;
- (UILabel *)build;
- (UILabel *)buildWith:(void (^)(UILabel *label))block;
@end

@interface ROHRefreshControlBuilder : ROHViewBuilder
- (instancetype)with:(void (^)(UIRefreshControl *refreshControl))block;
- (UIRefreshControl *)build;
- (UIRefreshControl *)buildWith:(void (^)(UIRefreshControl *refreshControl))block;
@end

@interface ROHScrollViewBuilder : ROHViewBuilder
- (instancetype)with:(void (^)(UIScrollView *scrollView))block;
- (UIScrollView *)build;
- (UIScrollView *)buildWith:(void (^)(UIScrollView *scrollView))block;
@end

@interface ROHSegmentedControlBuilder : ROHViewBuilder
- (instancetype)with:(void (^)(UISegmentedControl *segmentedControl))block;
- (UISegmentedControl *)build;
- (UISegmentedControl *)buildWith:(void (^)(UISegmentedControl *segmentedControl))block;
@end

@interface ROHSliderBuilder : ROHViewBuilder
- (instancetype)with:(void (^)(UISlider *slider))block;
- (UISlider *)build;
- (UISlider *)buildWith:(void (^)(UISlider *slider))block;
@end

@interface ROHStepperBuilder : ROHViewBuilder
- (instancetype)with:(void (^)(UIStepper *stepper))block;
- (UIStepper *)build;
- (UIStepper *)buildWith:(void (^)(UIStepper *stepper))block;
@end

@interface ROHSwitchBuilder : ROHViewBuilder
- (instancetype)with:(void (^)(UISwitch *switchView))block;
- (UISwitch *)build;
- (UISwitch *)buildWith:(void (^)(UISwitch *switchView))block;
@end

@interface ROHTableViewBuilder : ROHViewBuilder
- (instancetype)with:(void (^)(UITableView *tableView))block;
- (UITableView *)build;
- (UITableView *)buildWith:(void (^)(UITableView *tableView))block;
@end

@interface ROHTableViewCellBuilder : ROHViewBuilder
- (instancetype)with:(void (^)(UITableViewCell *cell))block;
- (UITableViewCell *)build;
- (UITableViewCell *)buildWith:(void (^)(UITableViewCell *cell))block;
@end

@interface ROHTextFieldBuilder : ROHViewBuilder
- (instancetype)with:(void (^)(UITextField *textField))block;
- (UITextField *)build;
- (UITextField *)buildWith:(void (^)(UITextField *textField))block;
@end

@interface ROHTextViewBuilder : ROHViewBuilder
- (instancetype)with:(void (^)(UITextView *textView))block;
- (UITextView *)build;
- (UITextView *)buildWith:(void (^)(UITextView *))block;
@end

@interface ROHWebViewBuilder : ROHViewBuilder
- (instancetype)with:(void (^)(UIWebView *webView))block;
- (UIWebView *)build;
- (UIWebView *)buildWith:(void (^)(UIWebView *webView))block;
@end

@interface ROHGradientLayerBuilder : ROHBuilder
- (instancetype)with:(void (^)(CAGradientLayer *layer))block;
- (CAGradientLayer *)build;
- (CAGradientLayer *)buildWith:(void (^)(CAGradientLayer *layer))block;
@end

////////////////////////////////////////////////////////////////////////////////

@interface NSObject (ROHBuilder)
+ (ROHBuilder *)roh_with:(void (^)(id object))block;
+ (id)roh_buildWith:(void (^)(id object))block;
@end

@interface NSArray (ROHBuilder)
+ (ROHArrayBuilder *)roh_with:(void (^)(NSMutableArray *array))block;
+ (instancetype)roh_buildWith:(void (^)(NSMutableArray *array))block;
@end

@interface NSAttributedString (ROHBuilder)
+ (ROHAttributedStringBuilder *)roh_with:(void (^)(NSMutableAttributedString *string))block;
+ (instancetype)roh_buildWith:(void (^)(NSMutableAttributedString *string))block;
@end

@interface NSDictionary (ROHBuilder)
+ (ROHDictionaryBuilder *)roh_with:(void (^)(NSMutableDictionary *dictionary))block;
+ (instancetype)roh_buildWith:(void (^)(NSMutableDictionary *dictionary))block;
@end

@interface NSParagraphStyle (ROHBuilder)
+ (ROHParagraphStyleBuilder *)roh_with:(void (^)(NSMutableParagraphStyle *style))block;
+ (instancetype)roh_buildWith:(void (^)(NSMutableParagraphStyle *style))block;
@end

@interface NSString (ROHBuilder)
+ (ROHStringBuilder *)roh_with:(void (^)(NSMutableString *string))block;
+ (instancetype)roh_buildWith:(void (^)(NSMutableString *string))block;
@end

@interface NSURLRequest (ROHBuilder)
+ (ROHURLRequestBuilder *)roh_with:(void (^)(NSMutableURLRequest *request))block;
+ (instancetype)roh_buildWith:(void (^)(NSMutableURLRequest *request))block;
@end

@interface UIView (ROHBuilder)
+ (ROHViewBuilder *)roh_with:(void (^)(UIView *view))block;
+ (instancetype)roh_buildWith:(void (^)(UIView *view))block;
@end

@interface UIButton (ROHBuilder)
+ (ROHButtonBuilder *)roh_with:(void (^)(UIButton *button))block;
+ (instancetype)roh_buildWith:(void (^)(UIButton *button))block;
@end

@interface UIActivityIndicatorView (ROHBuilder)
+ (ROHActivityIndicatorViewBuilder *)roh_with:(void (^)(UIActivityIndicatorView *activityIndicatorView))block;
+ (instancetype)roh_buildWith:(void (^)(UIActivityIndicatorView *activityIndicatorView))block;
@end

@interface UICollectionView (ROHBuilder)
+ (ROHCollectionViewBuilder *)roh_with:(void (^)(UICollectionView *collectionView))block;
+ (instancetype)roh_buildWith:(void (^)(UICollectionView *collectionView))block;
@end

@interface UIImageView (ROHBuilder)
+ (ROHImageViewBuilder *)roh_with:(void (^)(UIImageView *imageView))block;
+ (instancetype)roh_buildWith:(void (^)(UIImageView *imageView))block;
@end

@interface UILabel (ROHBuilder)
+ (ROHLabelBuilder *)roh_with:(void (^)(UILabel *label))block;
+ (instancetype)roh_buildWith:(void (^)(UILabel *label))block;
@end

@interface UIRefreshControl (ROHBuilder)
+ (ROHRefreshControlBuilder *)roh_with:(void (^)(UIRefreshControl *refreshControl))block;
+ (instancetype)roh_buildWith:(void (^)(UIRefreshControl *refreshControl))block;
@end

@interface UIScrollView (ROHBuilder)
+ (ROHScrollViewBuilder *)roh_with:(void (^)(UIScrollView *scrollView))block;
+ (instancetype)roh_buildWith:(void (^)(UIScrollView *scrollView))block;
@end

@interface UISegmentedControl (ROHBuilder)
+ (ROHSegmentedControlBuilder *)roh_with:(void (^)(UISegmentedControl *segmentedControl))block;
+ (instancetype)roh_buildWith:(void (^)(UISegmentedControl *segmentedControl))block;
@end

@interface UISlider (ROHBuilder)
+ (ROHSliderBuilder *)roh_with:(void (^)(UISlider *slider))block;
+ (instancetype)roh_buildWith:(void (^)(UISlider *slider))block;
@end

@interface UIStepper (ROHBuilder)
+ (ROHStepperBuilder *)roh_with:(void (^)(UIStepper *stepper))block;
+ (instancetype)roh_buildWith:(void (^)(UIStepper *stepper))block;
@end

@interface UISwitch (ROHBuilder)
+ (ROHSwitchBuilder *)roh_with:(void (^)(UISwitch *switchView))block;
+ (instancetype)roh_buildWith:(void (^)(UISwitch *switchView))block;
@end

@interface UITableView (ROHBuilder)
+ (ROHTableViewBuilder *)roh_with:(void (^)(UITableView *tableView))block;
+ (instancetype)roh_buildWith:(void (^)(UITableView *tableView))block;
@end

@interface UITableViewCell (ROHBuilder)
+ (ROHTableViewCellBuilder *)roh_with:(void (^)(UITableViewCell *cell))block;
+ (instancetype)roh_buildWith:(void (^)(UITableViewCell *cell))block;
@end

@interface UITextField (ROHBuilder)
+ (ROHTextFieldBuilder *)roh_with:(void (^)(UITextField *textField))block;
+ (instancetype)roh_buildWith:(void (^)(UITextField *textField))block;
@end

@interface UITextView (ROHBuilder)
+ (ROHTextViewBuilder *)roh_with:(void (^)(UITextView *textView))block;
+ (instancetype)roh_buildWith:(void (^)(UITextView *textView))block;
@end

@interface UIWebView (ROHBuilder)
+ (ROHWebViewBuilder *)roh_with:(void (^)(UIWebView *webView))block;
+ (instancetype)roh_buildWith:(void (^)(UIWebView *webView))block;
@end

@interface CAGradientLayer (ROHBuilder)
+ (ROHGradientLayerBuilder *)roh_with:(void (^)(CAGradientLayer *layer))block;
+ (instancetype)roh_buildWith:(void (^)(CAGradientLayer *layer))block;
@end
