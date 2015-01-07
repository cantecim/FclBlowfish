//
//  FclBlowfish.h
//  Class Development Environment
//
//  Created by Can on 8/8/13.
//  Copyright (c) 2013 Can. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum FclBlowfishMode
{
    modeEBC,    // electronic-code-book
    modeCBC     // cipher-block-chaining
} FclBlowfishMode;

typedef enum FclBlowfishPadding
{
    paddingRFC,
    paddingZero
} FclBlowfishPadding;

@interface FclBlowfish : NSObject {
    FclBlowfishMode mode;
    FclBlowfishPadding padding;
    unsigned short int N, blockSize;
    
    @private
    SInt32 P[16 + 2];
    SInt32 S[4][256];
}
@property(nonatomic, retain) NSString *Key; // Maximum 448 Bits, will be encoded using ASCII
@property(nonatomic, retain) NSString *IV;  // 8 Byte ASCII

- (NSString *)encrypt:(NSString *)plain withMode:(FclBlowfishMode)pMode
          withPadding:(FclBlowfishPadding)pPadding;
- (NSString *)decrypt:(NSString *)crypted withMode:(FclBlowfishMode)pMode
          withPadding:(FclBlowfishPadding)pPadding;
- (void)prepare;
- (NSString *)pad:(NSString *)plain;
- (NSString *)removePad:(NSString *)plain;
- (void)encipher:(SInt32 *)xl xr:(SInt32 *)xr;
- (void)decipher:(SInt32 *)xl xr:(SInt32 *)xr;
- (SInt32)F:(SInt32)v;

@end

static inline void FclSwap(SInt32 *l, SInt32 *r) {
    *l ^= *r;
    *r ^= *l;
    *l ^= *r;
}