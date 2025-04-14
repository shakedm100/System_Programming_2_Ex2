#include "matrix.hpp"
#include <stdexcept>

using namespace std;
namespace matrixImp {

    SquareMat::SquareMat(const int size) : size(size)
    {
        matrix = new int*[size];

        //Initialize the memory and the value of all the matrix to 0
        for (int i = 0; i < size; i++)
        {
            matrix[i] = new int[size];
            for (int j = 0; j < size; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    SquareMat::~SquareMat()
    {
        for (int i = 0; i < size; i++)
        {
            delete[] matrix[i];
        }

        delete[] matrix;
    }

    SquareMat::SquareMat(const SquareMat &copy) : size(copy.size)
    {
        this->matrix = new int*[size];

        for (int i = 0; i < size; i++)
        {
            this->matrix[i] = new int[size];
            for (int j = 0; j < size; j++)
            {
                this->matrix[i][j] = copy.matrix[i][j];
            }
        }
    }

    int SquareMat::getSize() const
    {
        return size;
    }

    SquareMat &SquareMat::operator=(const SquareMat &copy)
    {
        if(this == &copy)
            return *this;

        if(this->size != copy.size)
        {
            for (int i = 0; i < size; i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;

            this->size = copy.size;
            matrix = new int*[copy.size];
            for (int i = 0; i < copy.size; i++)
            {
                matrix[i] = new int[copy.size];
            }
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                matrix[i][j] = copy.matrix[i][j];
            }
        }

        return *this;
    }

    SquareMat SquareMat::operator+(const SquareMat& add) const
    {
        if(this->size != add.size)
            throw invalid_argument("Operator+ matrix sizes mismatch");

        SquareMat addMat(size);

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                addMat.matrix[i][j] = matrix[i][j] + add.matrix[i][j];
            }
        }

        return addMat;
    }

    SquareMat SquareMat::operator-(const SquareMat &sub) const
    {
        if(this->size != sub.size)
            throw invalid_argument("Operator- matrix sizes mismatch");

        SquareMat subMat(size);

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                subMat.matrix[i][j] = matrix[i][j] - sub.matrix[i][j];
            }
        }

        return subMat;
    }

    SquareMat SquareMat::operator-()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                matrix[i][j] = -matrix[i][j];
            }
        }

        return *this;
    }

    SquareMat SquareMat::operator*(const SquareMat &mul) const
    {
        if(this->size != mul.size)
            throw invalid_argument("Operator* matrix sizes mismatch");

        SquareMat mulMat(size);
        for(int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                for (int k = 0; k < size; k++)
                {
                    mulMat.matrix[i][j] += this->matrix[i][k] * mul.matrix[k][j];
                }
            }
        }
        return mulMat;
    }

    SquareMat SquareMat::operator*(const int scalar) const
    {
        SquareMat scalarMulMat(size);

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                scalarMulMat.matrix[i][j] = scalar * matrix[i][j];
            }
        }

        return scalarMulMat;
    }

    SquareMat SquareMat::operator%(const SquareMat& mul) const
    {
        if(this->size != mul.size)
            throw invalid_argument("Operator* matrix sizes mismatch");

        SquareMat mulMat(size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                mulMat.matrix[i][j] = this->matrix[i][j] * mul.matrix[i][j];
            }
        }

        return mulMat;
    }

    SquareMat SquareMat::operator%(const int scalar) const
    {
        SquareMat scalarMulMat(size);

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                scalarMulMat.matrix[i][j] = matrix[i][j] % scalar;
            }
        }

        return scalarMulMat;
    }

    SquareMat SquareMat::operator/(const int divide) const
    {
        SquareMat divMat(size);

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                divMat.matrix[i][j] = matrix[i][j] / divide;
            }
        }

        return divMat;
    }

    SquareMat SquareMat::operator^(const int pow) const
    {
        if (pow < 0)
            throw std::invalid_argument("Negative exponent not supported");

        const SquareMat base(*this);
        SquareMat mulMat(*this);

        for(int i = 1; i < pow; i++)
        {
            mulMat = mulMat * base;
        }

        return mulMat;
    }

    SquareMat SquareMat::operator++()
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                ++matrix[i][j];
            }
        }

        return *this;
    }

    SquareMat SquareMat::operator++(int postfix_dummy) const
    {
        SquareMat addMat = *this;

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                addMat.matrix[i][j]++;
            }
        }

        return addMat;
    }

    SquareMat SquareMat::operator--()
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                --matrix[i][j];
            }
        }

        return *this;
    }

    SquareMat SquareMat::operator--(int postfix_dummy) const
    {
        SquareMat subMat = *this;

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                subMat.matrix[i][j]--;
            }
        }

        return subMat;
    }

    SquareMat SquareMat::operator~()
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = i+1; j < size; j++)
            {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        return *this;
    }

    int* SquareMat::operator[](const int i) const
    {
        if(i < 0 || i >= size)
            throw std::out_of_range("Index out of range");

        return matrix[i];
    }

    //Pass by reference to allow changing the index
    int*& SquareMat::operator[](const int i)
    {
        if(i < 0 || i >= size)
            throw std::out_of_range("Index out of range");

        return matrix[i];
    }

    void sumMatrices(const SquareMat& original, const SquareMat& other, int& sumOriginal, int& sumOther)
    {
        for(int i = 0; i < original.getSize(); i++)
        {
            for(int j = 0; j < original.getSize(); j++)
            {
                sumOriginal += original[i][j];
            }
        }

        for(int i = 0; i < other.getSize(); i++)
        {
            for(int j = 0; j < other.getSize(); j++)
            {
                sumOther += other[i][j];
            }
        }
    }

    //Note: it doesn't state the sizes of the matrices must be equals
    //Only the sum of the members
    bool SquareMat::operator==(const SquareMat &compare) const
    {
        int sumThis = 0, sumCompare = 0;

        sumMatrices(*this, compare, sumThis, sumCompare);

        if(sumThis == sumCompare)
            return true;
        return false;
    }

    bool SquareMat::operator!=(const SquareMat &compare) const
    {
        int sumThis = 0, sumCompare = 0;

        sumMatrices(*this, compare, sumThis, sumCompare);

        if(sumThis != sumCompare)
            return true;
        return false;
    }

    bool SquareMat::operator<(const SquareMat &compare) const
    {
        int sumThis = 0, sumCompare = 0;

        sumMatrices(*this, compare, sumThis, sumCompare);

        if(sumThis < sumCompare)
            return true;
        return false;
    }

    bool SquareMat::operator>(const SquareMat &compare) const
    {
        int sumThis = 0, sumCompare = 0;

        sumMatrices(*this, compare, sumThis, sumCompare);

        if(sumThis > sumCompare)
            return true;
        return false;
    }

    bool SquareMat::operator<=(const SquareMat &compare) const
    {
        int sumThis = 0, sumCompare = 0;

        sumMatrices(*this, compare, sumThis, sumCompare);

        if(sumThis <= sumCompare)
            return true;
        return false;
    }

    bool SquareMat::operator>=(const SquareMat &compare) const
    {
        int sumThis = 0, sumCompare = 0;

        sumMatrices(*this, compare, sumThis, sumCompare);

        if(sumThis >= sumCompare)
            return true;
        return false;
    }

    int calculateDeterminant(const SquareMat& matrix)
    {
        if(matrix.getSize() == 1)
            return matrix[0][0];

        if(matrix.getSize() == 2)
            return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];

        int det = 0;

        //This loop creates the minor
        for(int k = 0; k < matrix.getSize(); k++) //Columns
        {
            SquareMat subMat(matrix.getSize()-1); //Minor matrix
            for(int i = 1; i < matrix.getSize(); i++) //Minor row
            {
                int colIndex = 0;
                for(int j = 0; j < matrix.getSize(); j++) //Matrix column
                {
                    if(j == k) //If the minor column is equal to the k column we don't need it
                        continue;
                    subMat[i-1][colIndex] = matrix[i][j]; // Take the values from the matrix to the minor
                    colIndex++; //Update the value of the minor's column
                }
            }

            int sign;
            if(k % 2 == 0)
                sign = 1;
            else
                sign = -1;

            //Calculate the minor with a recursive call
            //Calculation is by column index
            det += sign * matrix[0][k] * calculateDeterminant(subMat);
        }

        return det;
    }

    int SquareMat::operator!() const
    {
        return calculateDeterminant(*this);
    }

    SquareMat &SquareMat::operator+=(const SquareMat &add)
    {
        if(this->size != add.size)
            throw invalid_argument("Operator+ matrix sizes mismatch");

        *this = *this + add;
        return *this;
    }

    SquareMat &SquareMat::operator-=(const SquareMat &sub)
    {
        if(this->size != sub.size)
            throw invalid_argument("Operator+ matrix sizes mismatch");

        *this = *this - sub;
        return *this;
    }

    SquareMat &SquareMat::operator*=(const SquareMat &mul)
    {
        if(this->size != mul.size)
            throw invalid_argument("Operator+ matrix sizes mismatch");

        *this = *this * mul;
        return *this;
    }

    SquareMat &SquareMat::operator*=(int scalar)
    {
        *this = *this * scalar;
        return *this;
    }

    SquareMat &SquareMat::operator/=(int div)
    {
        *this = *this / div;
        return *this;
    }

    SquareMat &SquareMat::operator%=(const SquareMat &mul)
    {
        *this = *this % mul;
        return *this;
    }

    SquareMat &SquareMat::operator%=(int scalar)
    {
        *this = *this % scalar;
        return *this;
    }

    ostream& operator<<(ostream& output, const SquareMat& matrix)
    {
        for(int i = 0; i < matrix.getSize(); i++)
        {
            output << "\n";
            for(int j = 0; j < matrix.getSize(); j++)
            {
                output << matrix[i][j] << " ";
            }
        }

        output << "\n";
        return output;
    }

    SquareMat operator*(const int scalar, const SquareMat &mat)
    {
        return mat * scalar;
    }

}
