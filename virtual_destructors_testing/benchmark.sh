#!/bin/bash

FQBNS=(
    arduino-git:renesas_portenta_main:unor4wifi
    # arduino-git:mbed:envie_m7
    # arduino-git:avr:uno
    # arduino-git:samd:mkrwifi1010
    # arduino-git:mbed:opta
)

branches=(
    master
    virtual-destructors
)

for branch in "${branches[@]}"; do
    git checkout $branch
    for fqbn in $"${FQBNS[@]}"; do
        echo "compiling for " $fqbn.$branch
        # arduino-cli compile -b $fqbn | tee $fqbn.$branch.log
        arduino-cli compile -b $fqbn --build-property "compiler.cpp.extra_flags=\"-fdump-record-layouts\""
        # /home/agilardoni/.arduino15/packages/arduino/tools/arm-none-eabi-gcc/7-2017q4/bin/arm-none-eabi-size -A /tmp/arduino/sketches/97A7C8915D2115841AF9E1023FFD9539/virtual_destructors_testing.ino.elf | tee $fqbn.$branch.size.log
    done
done
