# sdks
Patched sdks that include private framework tbds. 

This repository contains patched iOS SDKs containing private symbols. These were removed from official SDKs starting in Xcode 7.3 and the iOS 9.3 SDK.
Additionlly, these SDKs have the `allowed-clients` field removed from each text-based stub library (.tbd) for you.

To use with Theos, [download this repo](https://github.com/chrisharper22/sdks/archive/main.zip), extract, and copy whichever SDKs you desire into $THEOS/sdks/.
