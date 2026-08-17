#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = num << this->bits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(num * (1 << this->bits));
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		value = obj.value;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat() const
{
	return static_cast<float>(this->value) / (1 << this->bits);
}

int Fixed::toInt() const
{
	return this->value >> this->bits;
}

Fixed& Fixed::min(Fixed& obj1, Fixed& obj2)
{
	if (obj1 < obj2)
		return obj1;
	else
		return obj2;
}

const Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2)
{
	if (obj1 < obj2)
		return obj1;
	else
		return obj2;
}

Fixed& Fixed::max(Fixed& obj1, Fixed& obj2)
{
	if (obj1 > obj2)
		return obj1;
	else
		return obj2;
}
const Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2)
{
	if (obj1 > obj2)
		return obj1;
	else
		return obj2;
}

bool Fixed::operator>(const Fixed& obj) const
{
	return this->value > obj.value;
}

bool Fixed::operator<(const Fixed& obj) const
{
	return this->value < obj.value;
}

bool Fixed::operator>=(const Fixed &obj) const
{
	return this->value >= obj.value;
}

bool Fixed::operator<=(const Fixed &obj) const
{
	return this->value <= obj.value;
}

bool Fixed::operator==(const Fixed &obj) const
{
	return this->value == obj.value;
}

bool Fixed::operator!=(const Fixed &obj) const
{
	return this->value != obj.value;
}

Fixed Fixed::operator+(const Fixed &obj) const
{
	Fixed nobj;
	nobj.setRawBits(this->value + obj.value);
	return nobj;
}

Fixed Fixed::operator-(const Fixed &obj) const
{
	Fixed nobj;
	nobj.setRawBits(this->value - obj.value);
	return nobj;
}

Fixed Fixed::operator*(const Fixed &obj) const
{
	Fixed nobj;
	nobj.setRawBits((this->value * obj.value) >> this->bits);
	return nobj;
}

Fixed Fixed::operator/(const Fixed &obj) const
{
	Fixed nobj;
	nobj.setRawBits((this->value << this->bits) / obj.value);
	return nobj;
}

Fixed& Fixed::operator++(void)
{
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed nobj = *this;
	this->value++;
	return nobj;
}

Fixed& Fixed::operator--(void)
{
	this->value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed nobj = *this;
	this->value--;
	return nobj;
}

std::ostream& operator<<(std::ostream& os, Fixed const &obj)
{
	os << obj.toFloat();
	return os;
}
