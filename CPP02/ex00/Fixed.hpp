#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include "iostream"

class Fixed{
public:
    Fixed();
    Fixed(Fixed const &toCopy);

    Fixed &operator=(Fixed const &toAssign);
    ~Fixed();
    int getFixedPointInteger(void) const;
    int getRawBits( void ) const;
    void setRawBits( int const raw );
private:
    int _fixedPointInteger;
    static const int fractional_bits;
};

#endif