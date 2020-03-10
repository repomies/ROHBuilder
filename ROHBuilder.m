//
//  ROHBuilder.m
//
//  Created by Janne Käki on 27/02/15.
//  Copyright (c) 2015 Janne Käki. All rights reserved.
//

#import "ROHBuilder.h"

@interface ROHBuilder ()

    @property (nonatomic) ROHBuilder *parent;
    @property (nonatomic, copy) id (^initBlock)(ROHBuilder *builder);
    @property (nonatomic, copy) void (^editBlock)(id object);

@end

@implementation ROHBuilder

+ (instancetype)builderWithInitBlock:(id (^)(ROHBuilder *builder))initBlock
                           editBlock:(void (^)(id object))editBlock
{
    return [self builderWithParent:nil initBlock:initBlock editBlock:editBlock];
}

+ (instancetype)builderWithParent:(ROHBuilder *)parent
                        initBlock:(id (^)(ROHBuilder *builder))initBlock
                        editBlock:(void (^)(id object))editBlock
{
    ROHBuilder *builder = [self new];
    builder.parent = parent;
    builder.initBlock = initBlock;
    builder.editBlock = editBlock;
    return builder;
}

- (instancetype)with:(void (^)(id object))block
{
    return [self.class builderWithParent:self
                               initBlock:^id (ROHBuilder *builder) {
                                   
                                   return [builder.parent build];
                                   
                               } editBlock:block];
}

- (id)build
{
    return [self buildWith:nil];
}

- (id)buildWith:(void (^)(id object))block
{
    id object = self.initBlock ? self.initBlock(self) : nil;
    if (self.editBlock) self.editBlock(object);
    if (block) block(object);
    return object;
}

@end

////////////////////////////////////////////////////////////////////////////////

@interface NSObject (ROHBuilderCast)

    + (instancetype)roh_cast:(id)object;

@end

@implementation NSObject (ROHBuilderCast)

+ (instancetype)roh_cast:(id)object
{
    return [object isKindOfClass:self] ? object : nil;
}

@end

////////////////////////////////////////////////////////////////////////////////

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wincomplete-implementation"

@implementation ROHArrayBuilder
@end

@implementation ROHAttributedStringBuilder
@end

@implementation ROHDictionaryBuilder
@end

@implementation ROHParagraphStyleBuilder
@end

@implementation ROHStringBuilder
@end

@implementation ROHURLRequestBuilder
@end

@implementation ROHViewBuilder
@end

@implementation ROHActivityIndicatorViewBuilder
@end

@implementation ROHButtonBuilder
@end

@implementation ROHCollectionViewBuilder
@end

@implementation ROHImageViewBuilder
@end

@implementation ROHLabelBuilder
@end

@implementation ROHRefreshControlBuilder
@end

@implementation ROHScrollViewBuilder
@end

@implementation ROHSegmentedControlBuilder
@end

@implementation ROHSliderBuilder
@end

@implementation ROHStepperBuilder
@end

@implementation ROHSwitchBuilder
@end

@implementation ROHTableViewBuilder
@end

@implementation ROHTableViewCellBuilder
@end

@implementation ROHTextFieldBuilder
@end

@implementation ROHTextViewBuilder
@end

@implementation ROHWebViewBuilder
@end

@implementation ROHGradientLayerBuilder
@end

////////////////////////////////////////////////////////////////////////////////

@implementation NSObject (ROHBuilder)

+ (ROHBuilder *)roh_with:(void (^)(id object))block
{
    return [ROHBuilder builderWithInitBlock:^id (ROHBuilder *builder) {
        return [self new];  // Returns a ridiculously useless NSObject instance, just for the kicks
    } editBlock:block];
}

+ (id)roh_buildWith:(void (^)(id object))block
{
    ROHBuilder *builder = [self roh_with:block];
    return builder.build;
}

@end

@implementation NSArray (ROHBuilder)

+ (ROHArrayBuilder *)roh_with:(void (^)(NSMutableArray *))block
{
    return [ROHArrayBuilder builderWithInitBlock:^id (ROHBuilder *builder) {
        return [NSMutableArray new];
    } editBlock:block];
}

@end

@implementation NSAttributedString (ROHBuilder)

+ (ROHAttributedStringBuilder *)roh_with:(void (^)(NSMutableAttributedString *))block
{
    return [ROHAttributedStringBuilder builderWithInitBlock:^id (ROHBuilder *builder) {
        return [NSMutableAttributedString new];
    } editBlock:block];
}

@end

@implementation NSDictionary (ROHBuilder)

+ (ROHDictionaryBuilder *)roh_with:(void (^)(NSMutableDictionary *))block
{
    return [ROHDictionaryBuilder builderWithInitBlock:^id (ROHBuilder *builder) {
        return [NSMutableDictionary new];
    } editBlock:block];
}

@end

@implementation NSParagraphStyle (ROHBuilder)

+ (ROHParagraphStyleBuilder *)roh_with:(void (^)(NSMutableParagraphStyle *))block
{
    return [ROHParagraphStyleBuilder builderWithInitBlock:^id (ROHBuilder *builder) {
        return [NSMutableParagraphStyle new];
    } editBlock:block];
}

@end

@implementation NSString (ROHBuilder)

+ (ROHStringBuilder *)roh_with:(void (^)(NSMutableString *))block
{
    return [ROHStringBuilder builderWithInitBlock:^id (ROHBuilder *builder) {
        return [NSMutableString new];
    } editBlock:block];
}

@end

@implementation NSURLRequest (ROHBuilder)

+ (ROHURLRequestBuilder *)roh_with:(void (^)(NSMutableURLRequest *))block
{
    return [ROHURLRequestBuilder builderWithInitBlock:^id (ROHBuilder *builder) {
        return [NSMutableURLRequest new];
    } editBlock:block];
}

@end

@implementation UIView (ROHBuilder)

+ (ROHViewBuilder *)roh_with:(void (^)(UIView *))block
{
    return [ROHViewBuilder builderWithInitBlock:^id (ROHBuilder *builder) {
        return [self new];
    } editBlock:block];
}

@end

@implementation UIActivityIndicatorView (ROHBuilder)

+ (ROHActivityIndicatorViewBuilder *)roh_with:(void (^)(UIActivityIndicatorView *))block
{
    return [ROHActivityIndicatorViewBuilder builderWithInitBlock:^id (ROHBuilder *builder) {
        return [self new];
    } editBlock:block];
}

@end

@implementation UIButton (ROHBuilder)

+ (ROHButtonBuilder *)roh_with:(void (^)(UIButton *))block
{
    return [ROHButtonBuilder builderWithInitBlock:^id (ROHBuilder *builder) {
        return [UIButton buttonWithType:UIButtonTypeSystem];
    } editBlock:block];
}

@end

@implementation UICollectionView (ROHBuilder)

+ (ROHCollectionViewBuilder *)roh_with:(void (^)(UICollectionView *))block
{
    return [ROHCollectionViewBuilder builderWithInitBlock:^id (ROHBuilder *builder) {
        return [[UICollectionView alloc] initWithFrame:CGRectZero collectionViewLayout:[UICollectionViewFlowLayout new]];
    } editBlock:block];
}

@end

@implementation UIImageView (ROHBuilder)

+ (ROHImageViewBuilder *)roh_with:(void (^)(UIImageView *))block
{
    return [ROHImageViewBuilder builderWithInitBlock:^id (ROHBuilder *builder) {
        return [self new];
    } editBlock:block];
}

@end

@implementation UILabel (ROHBuilder)

+ (ROHLabelBuilder *)roh_with:(void (^)(UILabel *))block
{
    return [ROHLabelBuilder builderWithInitBlock:^id (ROHBuilder *builder) {
        return [self new];
    } editBlock:block];
}

@end

@implementation UIRefreshControl (ROHBuilder)

+ (ROHRefreshControlBuilder *)roh_with:(void (^)(UIRefreshControl *))block
{
    return [ROHRefreshControlBuilder builderWithInitBlock:^id (ROHBuilder *builder) {
        return [self new];
    } editBlock:block];
}

@end

@implementation UIScrollView (ROHBuilder)

+ (ROHScrollViewBuilder *)roh_with:(void (^)(UIScrollView *))block
{
    return [ROHScrollViewBuilder builderWithInitBlock:^id (ROHBuilder *builder) {
        return [self new];
    } editBlock:block];
}

@end

@implementation UISegmentedControl (ROHBuilder)

+ (ROHSegmentedControlBuilder *)roh_with:(void (^)(UISegmentedControl *))block
{
    return [ROHSegmentedControlBuilder builderWithInitBlock:^id (ROHBuilder *builder) {
        return [self new];
    } editBlock:block];
}

@end

@implementation UISlider (ROHBuilder)

+ (ROHSliderBuilder *)roh_with:(void (^)(UISlider *))block
{
    return [ROHSliderBuilder builderWithInitBlock:^id (ROHBuilder *builder) {
        return [self new];
    } editBlock:block];
}

@end

@implementation UIStepper (ROHBuilder)

+ (ROHStepperBuilder *)roh_with:(void (^)(UIStepper *))block
{
    return [ROHStepperBuilder builderWithInitBlock:^id (ROHBuilder *builder) {
        return [self new];
    } editBlock:block];
}

@end

@implementation UISwitch (ROHBuilder)

+ (ROHSwitchBuilder *)roh_with:(void (^)(UISwitch *))block
{
    return [ROHSwitchBuilder builderWithInitBlock:^id (ROHBuilder *builder) {
        return [self new];
    } editBlock:block];
}

@end

@implementation UITableView (ROHBuilder)

+ (ROHTableViewBuilder *)roh_with:(void (^)(UITableView *))block
{
    return [ROHTableViewBuilder builderWithInitBlock:^id (ROHBuilder *builder) {
        return [self new];
    } editBlock:block];
}

@end

@implementation UITableViewCell (ROHBuilder)

+ (ROHTableViewCellBuilder *)roh_with:(void (^)(UITableViewCell *))block
{
    return [ROHTableViewCellBuilder builderWithInitBlock:^id (ROHBuilder *builder) {
        return [self new];
    } editBlock:block];
}

@end

@implementation UITextField (ROHBuilder)

+ (ROHTextFieldBuilder *)roh_with:(void (^)(UITextField *))block
{
    return [ROHTextFieldBuilder builderWithInitBlock:^id (ROHBuilder *builder) {
        return [self new];
    } editBlock:block];
}

@end

@implementation UITextView (ROHBuilder)

+ (ROHTextViewBuilder *)roh_with:(void (^)(UITextView *))block
{
    return [ROHTextViewBuilder builderWithInitBlock:^id (ROHBuilder *builder) {
        return [self new];
    } editBlock:block];
}

@end

@implementation CAGradientLayer (ROHBuilder)

+ (ROHGradientLayerBuilder *)roh_with:(void (^)(CAGradientLayer *))block
{
    return [ROHGradientLayerBuilder builderWithInitBlock:^id (ROHBuilder *builder) {
        return [self new];
    } editBlock:block];
}

@end

#pragma clang diagnostic pop
