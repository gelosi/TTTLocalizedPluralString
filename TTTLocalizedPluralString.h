// TTTLocalizedPluralString.h
//
// Copyright (c) 2011 Mattt Thompson (http://mattt.me)
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

#import <Foundation/Foundation.h>


extern NSString * const kTTTZeroPluralRule;
extern NSString * const kTTTOnePluralRule;
extern NSString * const kTTTTwoPluralRule;
extern NSString * const kTTTFewPluralRule;
extern NSString * const kTTTManyPluralRule;
extern NSString * const kTTTOtherPluralRule;

extern NSString * TTTLocalizedPluralStringKeyForCountAndSingularNoun(NSUInteger count, NSString *singular);
extern NSString * TTTLocalizedPluralStringKeyForCountAndSingularNounForLanguage(NSUInteger count, NSString *singular, NSString *languageCode);

#define TTTLocalizedPluralString(count, singular, comment) \
[[NSBundle mainBundle] localizedStringForKey:TTTLocalizedPluralStringKeyForCountAndSingularNoun(count, singular) value:singular table:nil]

#define TTTLocalizedPluralStringForLanguage(count, singular, languageCode) \
[[NSBundle mainBundle] localizedStringForKey:TTTLocalizedPluralStringKeyForCountAndSingularNounForLanguage(count, singular, languageCode) value:singular table:nil]

#define TTTLocalizedPluralStringFromTable(count, singular, tbl, comment) \
[[NSBundle mainBundle] localizedStringForKey:TTTLocalizedPluralStringKeyForCountAndSingularNoun(count, singular) value:singular table:(tbl)]

#define TTTLocalizedPluralStringFromTableInBundle(count, singular, tbl, bundle, comment) \
[bundle localizedStringForKey:TTTLocalizedPluralStringKeyForCountAndSingularNoun(count, singular) value:singular table:(tbl)]

#define TTTLocalizedPluralStringWithDefaultValue(count, singular, tbl, bundle, val, comment) \
[bundle localizedStringForKey:TTTLocalizedPluralStringKeyForCountAndSingularNoun(count, singular) value:(val) table:(tbl)]
