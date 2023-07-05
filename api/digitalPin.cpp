#include <ArduinoAPI.h>
#include <digitalPin.hpp>

digitalPin::digitalPin(uint8_t pin)
: pin(pin)
{
    sat = digitalRead(pin);
}

digitalPin::digitalPin(const digitalPin& dig_pin)
: pin(dig_pin.pin), sat(dig_pin.sat) {}


PinStatus digitalPin::get()
{
    return digitalRead(pin);
}

void digitalPin::set(PinStatus sat)
{
    digitalWrite(pin, (PinStatus)sat);
}

digitalPin::operator bool()
{
    return get();
}

digitalPin::operator PinStatus()
{
    return get();
}

digitalPin digitalPin::operator=(uint8_t pin)
{
    return digitalPin(pin);
}

bool digitalPin::toggle()
{
    return digitalToggle(pin);
}

void digitalPin::PWMset(int val)
{
    analogWrite(pin, val);
}

void digitalPin::operator()(PinStatus v)
{
    set(v);
}