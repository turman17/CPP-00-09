#include "Fixed.hpp"

Fixed::Fixed()
    : _fixedValue(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int num_int){
    _fixedValue = num_int << _fractionalBits;
    std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float num_float){
    _fixedValue = roundf(num_float * (1 << _fractionalBits));
    std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &source){
    std::cout << "Copy constructor called\n";   
    *this = source;
}

int Fixed::getRawBits(void) const {
    return _fixedValue;
}

Fixed &Fixed::operator=(const Fixed &rhs){
    std::cout << "Copy assignment operator called\n";
    if(this != &rhs)
        this->setRawBits(rhs.getRawBits());
    return *this;
}

void Fixed::setRawBits(int const raw){
    _fixedValue = raw;
}

Fixed::~Fixed(){
    std::cout << "Destructor called\n";
}

float Fixed::toFloat() const {
    return static_cast<float>(_fixedValue) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
    return _fixedValue >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}