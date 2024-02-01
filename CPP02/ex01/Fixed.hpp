#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
public:
    Fixed(void);
    Fixed(const int num_int);
    Fixed(const float num_float);
    Fixed(const Fixed &source);              // Copy constructor
    ~Fixed();                                // Destructor

    Fixed &operator=(const Fixed &rhs);      // Copy assignment operator

    float toFloat() const;                   // Convert to float
    int toInt() const;                       // Convert to int
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    // Friend function to overload the insertion operator
    friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
private:
    int _fixedValue;                          // Stores the fixed-point value
    static const int _fractionalBits = 8;     // Number of fractional bits
};

#endif
