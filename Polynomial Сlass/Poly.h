#include <iostream>
#include <cmath>
using namespace std;

class Poly
{
private:
    double *coeff;
    int size;

public:
    Poly();
    Poly(const Poly &other);
    Poly(double value);
    ~Poly();
    Poly &operator=(const Poly &other);
    double &operator[](int power);
    double operator[](int power) const;
    double operator()(double value) const;
    friend ostream &operator<<(ostream &os, const Poly &p);

    Poly operator+(const Poly &other) const;
    Poly operator+(double value) const;
    Poly operator-(const Poly &other) const;
    Poly operator-(double value) const;
    Poly operator*(const Poly &other) const;
    Poly operator*(double value) const;
};

Poly::Poly(double value)
{ // konstruktor s parametrom
    size = 1;
    coeff = new double[size];
    coeff[0] = value;
}
Poly::Poly()
{ // konstruktor po umolchaniu
    size = 1;
    coeff = new double[size];
    coeff[0] = 0;
}
Poly::Poly(const Poly &other)
{ // kopirovanie
    size = other.size;
    coeff = new double[size];
    for (int i = 0; i < size; i++)
    {
        coeff[i] = other.coeff[i];
    }
}
Poly &Poly::operator=(const Poly &other)
{ // prisoedinenie
    if (this != &other)
    {
        delete[] coeff;

        size = other.size;
        coeff = new double[size];
        for (int i = 0; i < size; i++)
        {
            coeff[i] = other.coeff[i];
        }
    }
    return *this;
}
double &Poly::operator[](int power)
{ // izmenenie koefficienta
    if (power < size)
    {
        return coeff[power];
    }

    int newSize = power + 1;
    double *newCoef = new double[newSize];

    for (int i = 0; i < size; i++)
    {
        newCoef[i] = coeff[i];
    }

    for (int i = size; i < newSize; i++)
    {
        newCoef[i] = 0.0;
    }

    delete[] coeff;
    coeff = newCoef;
    size = newSize;

    return coeff[power];
}

double Poly::operator[](int power) const
{ // chtenie koefficienta
    if (power >= size)
    {
        return 0.0;
    }
    return coeff[power];
}
ostream &operator<<(ostream &os, const Poly &p)
{                       // vyvod
    bool first = false; // znak
    os << "y = ";
    for (int i = p.size - 1; i >= 0; --i)
    {                          // stepen
        double c = p.coeff[i]; // cooficient
        if (c == 0.0)
        {
            if (!c && !i && !first)
            {
                os << "0";
            }
            continue;
        }
        if (c > 0 && first)
            os << "+";
        if (c)
        {
            first = true;
        }
        if (c < 0)
            os << "-";
        if (c != 1)
            os << abs(c);
        if (i > 1)
            os << "x^" << i;
        else if (i)
            os << "x";
    }
    return os;
}

Poly Poly::operator+(const Poly &other) const
{ // primer na primer
    Poly result;
    int max_size = (size > other.size) ? size : other.size;
    for (int i = 0; i < max_size; i++)
    {
        result[i] = (*this)[i] + other[i];
    }
    return result;
}
Poly Poly::operator+(double value) const
{ // result
    Poly result = *this;
    result[0] += value;
    return result;
}
Poly operator+(double value, const Poly &p)
{ // chislo na primer
    return p + value;
}
Poly Poly::operator-(const Poly &other) const
{ // primer na primer
    Poly result;

    int max_size = (size > other.size) ? size : other.size;
    for (int i = 0; i < max_size; i++)
    {
        result[i] = (*this)[i] - other[i];
    }
    return result;
}
Poly Poly::operator-(double value) const
{ // resultat
    Poly result = *this;
    result[0] -= value;
    return result;
}

Poly Poly::operator*(const Poly &other) const
{ // primer na primer
    Poly result;

    int newSize = size + other.size - 1;
    for (int i = 0; i < newSize; i++)
        result[i] = 0; // massiv zabivaem nulyami

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < other.size; j++)
        {
            result[i + j] += coeff[i] * other.coeff[j];
        }
    }

    return result;
}

Poly operator-(double value, const Poly &p)
{                           // chislo na primer
    Poly result = p * (-1); // meniaet znak urawnienia na -
    result[0] += value;
    return result;
}
Poly Poly::operator*(double value) const
{ // resultat
    Poly result = *this;
    result[0] *= value;
    return result;
}
Poly operator*(double value, const Poly &p)
{ // chislo na primer
    return p * value;
}
double Poly::operator()(double value) const
{ // vychislenie znachenia polinoma pri dannom x
    double result = 0.0;
    for (int i = 0; i < size; i++)
    {
        result += coeff[i] * pow(value, i);
    }
    return result;
}
Poly::~Poly()
{
    delete[] coeff;
}
