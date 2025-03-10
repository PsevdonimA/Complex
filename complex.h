#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:
    Complex();
    Complex(double _re, double _im);
    Complex(const Complex& comp);
    Complex operator-();
    Complex operator=(const Complex& comp);
    Complex operator+=(const Complex& comp);
    Complex operator+(const Complex& comp);
    Complex operator-=(const Complex& comp);
    Complex operator-(const Complex& comp);
    Complex operator*=(const Complex& comp);
    Complex operator*(const Complex& comp);
    Complex operator/=(const Complex& comp);
    Complex operator/(const Complex& comp);
    friend std::ostream& operator<<(std::ostream& output, const Complex& comp);
    friend Complex operator+(const double k, const Complex& comp);
    friend Complex operator-(const double k, const Complex& comp);
    friend Complex operator*(const double k, const Complex& comp);
    friend Complex operator/(const double k, const Complex& comp);
private:
    double re, im;
};

Complex operator+(const double k, const Complex& comp);
Complex operator-(const double k, const Complex& comp);
Complex operator*(const double k, const Complex& comp);
Complex operator/(const double k, const Complex& comp);

Complex operator+(const Complex& comp, const double k);
Complex operator-(const Complex& comp, const double k);
Complex operator*(const Complex& comp, const double k);
Complex operator/(const Complex& comp, const double k);

Complex operator+=(Complex& comp, const double k);
Complex operator-=(Complex& comp, const double k);
Complex operator*=(Complex& comp, const double k);
Complex operator/=(Complex& comp, const double k);

std::ostream& operator<<(std::ostream& output, const Complex& comp);

#endif
