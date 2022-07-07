# ArduinoCore-API

[![Unit Tests](https://github.com/arduino/ArduinoCore-API/workflows/Unit%20Tests/badge.svg)](https://github.com/arduino/ArduinoCore-API/actions?workflow=Unit+Tests)
[![codecov](https://codecov.io/gh/arduino/ArduinoCore-API/branch/master/graph/badge.svg)](https://codecov.io/gh/arduino/ArduinoCore-API)
[![Spell Check status](https://github.com/arduino/ArduinoCore-API/actions/workflows/spell-check.yml/badge.svg)](https://github.com/arduino/ArduinoCore-API/actions/workflows/spell-check.yml)

This repository hosts the hardware independent layer of Arduino core.

All Arduino official cores are being ported to the new structure so they take advantage of this single repo.

Including this repo in your existing Arduino core will allow the language to grow and include new features.
For backwards compatibility, every revision of this repo will increase the `ARDUINO_API_VERSION` define.

Some cores have been ported to the new structure, for example:
* megaAVR (https://github.com/arduino/ArduinoCore-megaAVR) 
* nRF52-mbedos (https://github.com/arduino/ArduinoCore-nRF528x-mbedos)
* classic AVR (https://github.com/arduino/ArduinoCore-avr/tree/api) 
* SAMD (https://github.com/arduino/ArduinoCore-samd)

These repositories **don't** contain the needed `api` subfolder; to "complete" the core you need to copy or symlink the `api` folder from this repo to the target's `cores/arduino` folder.

### Porting tips

In the future, core APIs will be updated independently from the core, so all the compatible cores will seamlessly adopt new features.
This requires support from all the IDEs, so in the meantime we suggest to release the core by copying a snapshot of this `api` folder.

The most elegant and effective solution is to develop the core with `api` symlinked and produce the distributable archive by telling `tar` to follow symlinks. 
Example command:
```
tar --exclude='*.git*' -cjhvf $yourcore-$version.tar.bz2 $yourcore/
```
