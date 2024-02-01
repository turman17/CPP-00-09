#include "Fixed.hpp"

Fixed::Fixed() : _fixedValue(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int num_int) {
    _fixedValue = num_int << _fractionalBits;
    std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float num_float) {
    _fixedValue = roundf(num_float * (1 << _fractionalBits));
    std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &source) : _fixedValue(source._fixedValue) {
    std::cout << "Copy constructor called\n";
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called\n";
    if (this != &rhs) {
        this->_fixedValue = rhs._fixedValue;
    }
    return *this;
}

int Fixed::getRawBits() const {
    return this->_fixedValue;
}

void Fixed::setRawBits(int const raw) {
    _fixedValue = raw;
}

float Fixed::toFloat() const {
    return static_cast<float>(_fixedValue) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
    return _fixedValue >> _fractionalBits;
}

// Implementations for comparison operators
bool Fixed::operator>(const Fixed &rhs) const {
    return this->_fixedValue > rhs._fixedValue;
}
// ... Implement other comparison operators in a similar manner ...

// Implementations for arithmetic operators
Fixed Fixed::operator+(const Fixed &rhs) const {
    return Fixed(this->toFloat() + rhs.toFloat());
}
// ... Implement -, *, / operators in a similar manner ...

// Implementations for increment/decrement operators
Fixed &Fixed::operator++() {
    this->_fixedValue++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;
}
// ... Implement -- operators in a similar manner ...

// Implementations for static methods
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

// Implementation for the stream insertion operator
std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}
