#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
public:
    Fixed();                      // Default constructor
    Fixed(const int num_int);     // Constructor from integer
    Fixed(const float num_float); // Constructor from float
    Fixed(const Fixed &source);   // Copy constructor
    ~Fixed();

    Fixed &operator=(const Fixed &rhs);
    bool operator>(const Fixed &rhs) const;
    bool operator<(const Fixed &rhs) const;
    bool operator==(const Fixed &rhs) const;
    bool operator!=(const Fixed &rhs) const;
    bool operator>=(const Fixed &rhs) const;
    bool operator<=(const Fixed &rhs) const;
    Fixed operator+(const Fixed &rhs) const;
    Fixed operator-(const Fixed &rhs) const;
    Fixed operator*(const Fixed &rhs) const;
    Fixed operator/(const Fixed &rhs) const;
    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

    float toFloat() const;
    int toInt() const;
    int getRawBits(void) const;
    void setRawBits(int const raw);

    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

    friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

private:
    int _fixedValue;
    static const int _fractionalBits = 8;
};

#endif
