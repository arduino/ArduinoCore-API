#pragma once
#ifndef DIG_PIN_H
#define DIG_PIN_H
#include <stdint.h>

/*enum class PIN_SAT : bool
{
    pHIGH = 1,
    pLOW = 0
};*/

class digitalPin
{
private:
    uint8_t pin;
    bool sat;
    void operator()(int av);
public:
    digitalPin(uint8_t pin);
    digitalPin(const digitalPin& dig_pin);

    __inline digitalPin(){}
    void set(bool sat);
    int get();
    bool toggle();
    void PWMset(int val);

    void operator()(bool v);
    
    digitalPin operator=(uint8_t pin);
    operator bool();
    operator int();
    

    __inline ~digitalPin(){}
};



#endif
