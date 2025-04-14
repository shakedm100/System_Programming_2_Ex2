#pragma once
#include <ostream>

namespace matrixImp {

    class SquareMat {
    private:
        int size;
        double** matrix;

    public:
        SquareMat(int size);
        ~SquareMat();
        SquareMat(const SquareMat& copy);
        int getSize() const;
        SquareMat& operator=(const SquareMat& copy);
        SquareMat operator+(const SquareMat& add) const;
        SquareMat operator-(const SquareMat& sub) const;
        SquareMat operator-();
        SquareMat operator*(const SquareMat& mul) const;
        SquareMat operator*(int scalar) const;
        SquareMat operator%(const SquareMat& mul) const;
        SquareMat operator%(int scalar) const;
        SquareMat operator/(int divide) const;
        SquareMat operator^(int pow) const;
        SquareMat operator++();
        SquareMat operator++(int postfix_dummy);
        SquareMat operator--();
        SquareMat operator--(int postfix_dummy);
        SquareMat operator~();
        double* operator[](int i) const;
        double*& operator[](int i);
        bool operator==(const SquareMat& compare) const;
        bool operator!=(const SquareMat& compare) const;
        bool operator<(const SquareMat& compare) const;
        bool operator>(const SquareMat& compare) const;
        bool operator<=(const SquareMat& compare) const;
        bool operator>=(const SquareMat& compare) const;
        int operator!() const;
        SquareMat& operator+=(const SquareMat& add);
        SquareMat& operator-=(const SquareMat& sub);
        SquareMat& operator*=(const SquareMat& mul);
        SquareMat& operator*=(int scalar);
        SquareMat& operator%=(const SquareMat& mul);
        SquareMat& operator%=(int scalar);
        SquareMat& operator/=(int div);
        friend std::ostream& operator<<(std::ostream& output, const SquareMat& matrix);
    };

    SquareMat operator*(int scalar, const SquareMat &mat);

}
