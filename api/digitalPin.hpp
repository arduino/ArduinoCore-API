#pragma once
#ifndef DIG_PIN_H
#define DIG_PIN_H
#include <stdint.h>

class digitalPin
{
private:
    uint8_t pin;
    bool sat;
    //void operator()(int av);
public:
    digitalPin(uint8_t pin);
    digitalPin(const digitalPin& dig_pin);

    __inline digitalPin(){}
    void set(PinStatus sat);
    PinStatus get();
    bool toggle();
    void PWMset(int val);

    void operator()(PinStatus v);
    
    digitalPin operator=(uint8_t pin);
    operator bool();
    operator PinStatus();
    

    __inline ~digitalPin(){}
};



#endif
