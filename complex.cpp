#include <iostream>
#include "complex.h"

// class Complex
Complex::Complex()
{
    re = 0;
    im = 0;
}
Complex::Complex(double _re, double _im = 0)
{
    re = _re;
    im = _im;
}
Complex::Complex(const Complex& comp)
{
    re = comp.re;
    im = comp.im;
}
Complex Complex::operator-()
{
    re = -re;
    im = -im;
    return *this;
}
Complex Complex::operator=(const Complex& comp)
{
    re = comp.re;
    im = comp.im;
    return *this;
}
Complex Complex::operator+=(const Complex& comp)
{
    re += comp.re;
    im += comp.im;
    return *this;
}
Complex Complex::operator+(const Complex& comp)
{
    Complex res(*this);
    res += comp;
    return res;
}
Complex Complex::operator-=(const Complex& comp)
{
    re -= comp.re;
    im -= comp.im;
    return *this;
}
Complex Complex::operator-(const Complex& comp)
{
    Complex res(*this);
    res -= comp;
    return res;
}
Complex Complex::operator*=(const Complex& comp)
{
    double _re = re*comp.re - im*comp.im;
    im = re*comp.im + im*comp.re;
    re = _re;
    return *this;
}
Complex Complex::operator*(const Complex& comp)
{
    Complex res(*this);
    res *= comp;
    return res;
}
Complex Complex::operator/=(const Complex& comp)
{
    if (comp.re == 0 && comp.im == 0)
    {
        Complex res;
        return res;
    }
    Complex sopr(comp.re, -comp.im);
    *this *= sopr;
    sopr *= comp;
    re /= sopr.re;
    im /= sopr.re;
    return *this;
}
Complex Complex::operator/(const Complex& comp)
{
    Complex res;
    if (comp.re == 0 && comp.im == 0)
    {
        return res;
    }
    res = *this;
    res /= comp;
    return res;
}

// out of class

Complex operator+(const double k, const Complex& comp)
{
    Complex c_k(k, 0);
    return c_k + comp;
}
Complex operator-(const double k, const Complex& comp)
{
    Complex c_k(k, 0);
    return c_k - comp;
}
Complex operator*(const double k, const Complex& comp)
{
    Complex c_k(k, 0);
    return c_k * comp;
}
Complex operator/(const double k, const Complex& comp)
{
    Complex c_k(k, 0);
    return c_k / comp;
}

Complex operator+(const Complex& comp, const double k)
{
    return k + comp;
}
Complex operator-(const Complex& comp, const double k)
{
    return -k + comp;
}
Complex operator*(const Complex& comp, const double k)
{
    return k * comp;
}
Complex operator/(const Complex& comp, const double k)
{
    return 1 / (k / comp);
}

Complex operator+=(Complex& comp, const double k)
{
    Complex c_k(k, 0);
    return comp += c_k;
}
Complex operator-=(Complex& comp, const double k)
{
    Complex c_k(k, 0);
    return comp -= c_k;
}
Complex operator*=(Complex& comp, const double k)
{
    Complex c_k(k, 0);
    return comp *= c_k;
}
Complex operator/=(Complex& comp, const double k)
{
    Complex c_k(k, 0);
    return comp /= c_k;
}

std::ostream& operator<<(std::ostream& output, const Complex& comp)
{
    bool np = false;
    if (comp.re != 0)
    {
        np = true;
        output << comp.re;
    }
    if (comp.im == 0)
    {
        return output;
    }
    else if (comp.im > 0 && np)
    {
        output << "+";
    }
    if (comp.im == 1)
    {
        output << "i";
    }
    else if (comp.im == -1)
    {
        output << "-i";
    }
    else
    {
        output << comp.im << "i";
    }
    return output;
}
