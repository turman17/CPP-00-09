#include "Fixed.hpp"

// Fixed::Fixed(){
//     this->fixed_point_integer = 0;
// }


Fixed::Fixed()
    : _fixedPointInteger(0)
{
    std::cout << "Default constructor called\n";
}

int Fixed::getFixedPointInteger() const
{
    std::cout << "Copy assignment operator called \n";
    return _fixedPointInteger;
}

Fixed &Fixed::operator=(Fixed const &toAsign){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &toAsign)
        this->setRawBits(toAsign.getRawBits());
    return *this;
}

Fixed::Fixed(Fixed const& toCopy)
    : _fixedPointInteger(toCopy.getFixedPointInteger())
{
    std::cout << "Copy constructor called\n";
}

int Fixed::getRawBits() const{
    std::cout << "getRawBits member function called\n";
    return this->_fixedPointInteger;
}

void Fixed::setRawBits(int const raw){
    _fixedPointInteger = raw;
}

Fixed::~Fixed(){
    std::cout << "Destructor called\n";
}
