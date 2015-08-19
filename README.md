# TTTLocalizedPluralString
## NSLocalizedString with a Count Argument

> As of iOS 7 and Mac OS X 10.9 Mavericks, Foundation has the ability to specify localized strings according to pluralization and grammar rules. You can find more information about it in the [Localized Property List File](https://developer.apple.com/library/mac/releasenotes/Foundation/RN-Foundation/#//apple_ref/doc/uid/TP30000742-CH2-SW56) section of the Foundation release notes.

## Why the hell did I clone the repo?

`TTTLocalizedPluralString` has great logics for different locale plural rules. But it does one extra thing - always formats the sting with given `count` argument. And always like `%d`. If you need to keep localized string with something like "You have %@ banana(s) left." - good luck with it. And this clone is exactly for that - it uses brilliance of TTTLocalizedPluralString idea, and let's you to format your strings yourself as you want.

use my repo in your project:
```
pod 'TTTLocalizedPluralString', :tag => '0.0.11', :git => 'https://github.com/gelosi/TTTLocalizedPluralString.git'
```

## a bit about `NSLocalizedString` macro

`NSLocalizedString` and its related macros make localizing Mac and iOS applications relatively straight-forward and simple. It falls down, however, when having to deal with strings whose conjugations change based on a dynamic count value. In such cases, you may have seen code like this:

``` objective-c
if (count == 1) {
  return NSLocalizedString(@"1 Person", nil);
} else {
  return [NSString stringWithFormat:NSLocalizedString(@"%d People", nil), count];
}
```

While this works alright for English, you run into problems when targeting other locales. Consider some examples as described in the [Unicode Language Plural Rules](http://unicode.org/repos/cldr-tmp/trunk/diff/supplemental/language_plural_rules.html):

* Many Asian languages, like Japanese, Korean, Thai, and Simplified Chinese, do not have plural forms of nouns
* Arabic has several plural forms, including rules for zero, one, two, as well as few, many, and other, which are determined using a rather complicated base 10 divmod operation to determine the parity.

Fortunately, `TTTLocalizedPluralString` figures all of this out for you. You can use it just as you would `NSLocalizedString`, only in this case, you also have an argument for count. Here is the example from before, this time using `TTTLocalizedPluralString`.

``` objective-c
// assume in Localized.strings file you have sometihng like:
// "Person#one" = "%d Person";
// "Person#two" = "%d Persons";
// "Person#other" = "%d Person";
NSString *localizedFormat = TTTLocalizedPluralString(count, @"Person", nil);
return [NSString string withFormat: localizedFormat, count];
```

This macro points to a function that determines the plural rule for the current locale, and then does an `NSBundle` localized string lookup for the corresponding value. In this case, `en.lproj/Localizable.strings` would have two keys for this: `Person#one` and `Person#other`. Other localizations would only require the keys used by that language (e.g. 1 for Japanese, and 6 for Arabic).

Here is the full list of plural rules:

* `zero`
* `one`
* `two`
* `few`
* `many`
* `other`

## Supported Locales

- Arabic (`ar`)
- Catalan (`ca`)
- Chinese (Simplified) (`zh-Hans`)
- Chinese (Traditional) (`zh-Hant`)
- Croatian (`cr`)
- Czech (`cs`)
- Danish (`da`)
- Dutch (`nl`)
- English (`en`)
- German (`de`)
- Finish (`fi`)
- Greek (`el`)
- French (`fr`)
- Hebrew (`he`)
- Hungarian (`hu`)
- Indonesian (`id`)
- Italian (`it`)
- Japanese (`ja`)
- Korean (`ko`)
- Latvian (`lv`)
- Malay (`ms`)
- Norwegian Bokmål (`nb`)
- Norwegian Nynorsk (`nn`)
- Polish (`pl`)
- Portuguese (`pt`)
- Romanian (`ro`)
- Russian (`ru`)
- Spanish (`es`)
- Slovak (`sk`)
- Swedish (`sv`)
- Thai (`th`)
- Turkish (`tr`)
- Ukrainian (`uk`)
- Vietnamese (`vi`)

---

## Contact

Mattt Thompson

- http://github.com/mattt
- http://twitter.com/mattt
- m@mattt.me

## License

TTTLocalizedPluralString is available under the MIT license. See the LICENSE file for more info.
