FclBlowfish
===========

An Objective-C Blowfish Implementation


  * Supports EBC and CBC mode
  * Supports padding RFC and Zero padding
  * Works compatible with PHP's Mcrypt
  * Originally coded for iOS SDK. It may work also for OS X SDK

> You easily find out how to use the library.
  * Import it.
  * Create an instance.
  * Set IV and Key then call prepare
  * Do encryption or decryption

  **Feel free to contribute**

# How to Use
## Encrypt
```objc
FclBlowfish *bf = [[FclBlowfish alloc] init];
bf.Key = @"37501370571307510";
bf.IV = @"asdf";
[bf prepare];
NSLog(@"encrypt %@", [bf encrypt:@"Hi there" withMode:modeCBC withPadding:paddingRFC]);
```
## Decrypt
```objc
bf = [[FclBlowfish alloc] init];
bf.Key = @"37501370571307510";
bf.IV = @"asdf";
[bf prepare];    NSLog(@"encrypt %@", [bf decrypt:[bf encrypt:@"Hi there" withMode:modeCBC withPadding:paddingRFC] withMode:modeCBC withPadding:paddingRFC]);
```
### Properties
Property | Description | Restrictions | Suggestions
-------- | ----------- | ------------ | -----------
***Key*** | This is the cryption key use it as salt | Must use 1 byte characters | You can use md5 hashed text in hexadecimal format it will be 256 bit size then you can add extra 24 characters(192 bit) to reach 448 bit
***IV*** | This is the initialization vector | No restricton | You need to implement an algrotihm for storing this in final crypted text. Simply you can add base64 encoded iv to end of crypted text. So your server(decryptor) can extract it from the text and use it for decryption. You must do this in order to use unique IV for all crypted text.

# To-Do(s)

# Developed By

  * Can Tecim(Original Author) - <can.tecim@gmail.com>
  
# License

    Copyright 2013 Can Tecim
    
    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at
    
        http://www.apache.org/licenses/LICENSE-2.0
    
    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
