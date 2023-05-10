//
// Created by 97250 on 14/04/2023.
//

#ifndef FRACTION_FRACTION_HPP
#define FRACTION_FRACTION_HPP

#include <stdexcept>

namespace ariel {
    class Fraction {
    private:
        int _numerator;
        int _denominator;

        int gcd(int num1, int num2);

        std::pair<int, int> abs_max_min(int num1, int num2);

        Fraction float_to_fraction(double floating_point);

        void reduce_fraction();

        void increment();

        void decrement();


    public:
        explicit Fraction(const int numerator = 1, int denominator = 1) : _numerator(numerator),
                                                                          _denominator(denominator) {
            if (denominator == 0) {
                throw std::invalid_argument("The denominator can not be zero\n");
            }
            reduce_fraction();
        }


        explicit Fraction(const double floating_point) : Fraction(float_to_fraction(floating_point)) {
        }

        int getNumerator() const;

        int getDenominator() const;

        Fraction &operator++();

        Fraction operator++(int);

        Fraction &operator--();

        Fraction operator--(int);

        Fraction operator+(const Fraction &rhs) const;

        Fraction operator+(double rhs) const;

        friend Fraction operator+(double lhs, const Fraction &rhs);

        Fraction operator-(const Fraction &rhs) const;

        Fraction operator-(double rhs) const;

        friend Fraction operator-(double lhs, const Fraction &rhs);

        Fraction operator*(const Fraction &rhs) const;

        Fraction operator*(double rhs) const;

        friend Fraction operator*(double lhs, const Fraction &rhs);

        Fraction operator/(const Fraction &rhs) const;

        Fraction operator/(double rhs) const;

        friend Fraction operator/(double lhs, const Fraction &rhs);

        bool operator==(const Fraction &rhs) const;

        bool operator==(double rhs) const;

        friend bool operator==(double lhs, const Fraction &rhs);

        bool operator<(const Fraction &rhs) const;

        bool operator<(double rhs) const;

        friend bool operator<(double lhs, const Fraction &rhs);

        bool operator>(const Fraction &rhs) const;

        bool operator>(double rhs) const;

        friend bool operator>(double lhs, const Fraction &rhs);

        bool operator<=(const Fraction &rhs) const;

        bool operator<=(double rhs) const;

        friend bool operator<=(double lhs, const Fraction &rhs);

        bool operator>=(const Fraction &rhs) const;

        bool operator>=(double rhs) const;

        friend bool operator>=(double , const Fraction &);

        friend std::ostream &operator<<(std::ostream &output_stream, const Fraction &fraction);

        friend std::istream &operator>>(std::istream &input_stream, Fraction &fraction);
    };
}

#endif //FRACTION_FRACTION_HPP