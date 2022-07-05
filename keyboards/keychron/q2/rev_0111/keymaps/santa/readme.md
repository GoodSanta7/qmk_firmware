# Santa's Keychron Q2 keymap v1.0.0

Migration of mkillewald Q1 keymaps to Q2.

## Features
* On macOS, F3 opens Mission Control and F4 opens Launchpad without needing to configure shortcuts in System Preferences.
* RGB lighting turns off when the computer sleeps.
* Caps Lock RGB indicator
  * the Caps Lock key will light when Caps Lock is enabled with the following options
    * `#define CAPS_LOCK_INDICATOR_COLOR [color]` in `config.h` to set the backlight color used for the indicator when Caps Lock is enabled. (default: red)
    * `Fn+Z` will toggle lighting the TAB key when Caps Lock is enabled. This is useful with non backlit keycaps. (default: on)
    * `Fn+X` will toggle lighting all the alpha keys when Caps Lock is enabled. (default: on)
* Dynamic Fn layer RGB indicator
  * When the Fn key is held down, any keys defined on the Fn layer in this firmware or in VIA will be highlighted with the following options:
    * `#define FN_LAYER_COLOR [color]` in `config.h` to set a static color for defined keys (default: orange).
    * `Fn+C` will toggle turning off RGB for keys with no definition. (default: RGB on)
    * `Fn+V` will toggle lighting the defined Fn layer keys with the static color set with `FN_LAYER_COLOR`. (default: static color on)
* RGB must be toggled on for all indicators to function. If you do not want an RGB mode active but still want the indicators, toggle RGB on and turn the brightness all the way off. The indicators will remain at full brightness.

## Problems
* VIA is **NOT** supported. Enabling VIA will somehow crash the keyboard.
* The settings cannot be saved, that is, when a cable is disconnected and connected again to the keyboard, previous settings on the Caps Lock and Fn layer will be lost. This is due to the fact that EEPROM is not officially [supported](https://github.com/Keychron/qmk_firmware/pull/35#issuecomment-1140593458) for Q2 now. Keychron has its work-around in its own [branch](https://github.com/Keychron/qmk_firmware/tree/playground/keyboards/keychron/q2).
