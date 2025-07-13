#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(int const n);
		Fixed(float const n);
		Fixed(Fixed const &src);
		~Fixed();

		Fixed&	operator=(Fixed const &rhs);
		Fixed	operator+(Fixed const &rhs);
		Fixed	operator-(Fixed const &rhs);
		Fixed	operator*(Fixed const &rhs);
		Fixed	operator/(Fixed const &rhs);

		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		bool	operator>(Fixed const &rhs);
		bool	operator<(Fixed const &rhs);
		bool	operator<=(Fixed const &rhs);
		bool	operator>=(Fixed const &rhs);
		bool	operator==(Fixed const &rhs);
		bool	operator!=(Fixed const &rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;		
		int		toInt(void) const;

		static	Fixed min(Fixed const &a, Fixed const &b);
		static	Fixed min(Fixed &a, Fixed &b);

		static	Fixed max(Fixed &a, Fixed &b);
		static	Fixed max(Fixed const &a, Fixed const &b);

	private:
		int					_RawBits;
		static int const	_IndComma = 8;
};

std::ostream &	operator<<(std::ostream& o, Fixed const & i);

#endif