// shaked1mi@gmail.com

#include "matrix.hpp"
#include <stdexcept>

using namespace std;
namespace matrixImp {

    SquareMat::SquareMat(const int size) : size(size)
    {
        matrix = new double*[size];

        //Initialize the memory and the value of all the matrix to 0
        for (int i = 0; i < size; i++)
        {
            matrix[i] = new double[size];
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
        this->matrix = new double*[size];

        for (int i = 0; i < size; i++)
        {
            this->matrix[i] = new double[size];
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

    /**
     * @brief Assigns a new matrix value by copying elements from another matrix.
     * @param copy The source matrix to copy.
     * @return Reference to the current matrix.
     */
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
            matrix = new double*[copy.size];
            for (int i = 0; i < copy.size; i++)
            {
                matrix[i] = new double[copy.size];
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

    /**
     * @brief Adds two matrices element-wise.
     * @param add The matrix to add.
     * @return A new matrix with the summed elements.
     * @throws invalid_argument if matrix sizes mismatch.
     */
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

    /**
     * @brief Subtracts one matrix from another element-wise.
     * @param sub The matrix to subtract.
     * @return A new matrix resulting from the subtraction.
     * @throws invalid_argument if matrix sizes mismatch.
     */
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

    /**
     * @brief Negates all elements of the matrix.
     * @return The matrix with all elements negated.
     */
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

    /**
     * @brief Multiplies two matrices.
     * @param mul The right-hand side matrix.
     * @return A new matrix resulting from the multiplication.
     * @throws invalid_argument if matrix sizes mismatch.
     */
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

    /**
     * @brief Multiplies the matrix by a scalar.
     * @param scalar The integer to multiply each element by.
     * @return A new matrix with each element scaled.
     */
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

    /**
     * @brief Performs element-wise multiplication with another matrix.
     * @param mul The matrix to multiply element-wise.
     * @return A new matrix with multiplied elements.
     * @throws invalid_argument if matrix sizes mismatch.
     */
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

    /**
     * @brief Performs element-wise modulo operation with a scalar.
     * @param scalar The divisor for the modulo operation.
     * @return A new matrix with each element modulo the scalar.
     */
    SquareMat SquareMat::operator%(const int scalar) const
    {
        SquareMat scalarMulMat(size);

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                scalarMulMat.matrix[i][j] = (int)matrix[i][j] % scalar;
            }
        }

        return scalarMulMat;
    }

    /**
     * @brief Divides each element of the matrix by a scalar.
     * @param divide The integer divisor.
     * @return A new matrix with divided elements.
     * @throws exception if divide is zero
     */
    SquareMat SquareMat::operator/(const int divide) const
    {
        if(divide == 0)
            throw std::invalid_argument("Can't divide by zero");
        
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

    /**
     * @brief Raises the matrix to an integer power.
     * @param pow The exponent value.
     * @return A new matrix that is the result of exponentiation.
     * @throws invalid_argument if exponent is negative.
     */
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

    /**
     * @brief Pre-increments each element in the matrix.
     * @return Reference to the incremented matrix.
     */
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

    /**
     * @brief Post-increments each element in the matrix.
     * @return The matrix before incrementation.
     */
    SquareMat SquareMat::operator++(int postfix_dummy)
    {
        SquareMat old = *this;

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                this->matrix[i][j]++;
            }
        }

        return old;
    }

    /**
     * @brief Pre-decrements each element in the matrix.
     * @return Reference to the decremented matrix.
     */
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

    /**
     * @brief Post-decrements each element in the matrix.
     * @return The matrix before decrementation.
     */
    SquareMat SquareMat::operator--(int postfix_dummy)
    {
        SquareMat old = *this;

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                this->matrix[i][j]--;
            }
        }

        return old;
    }

    /**
     * @brief Transposes the matrix.
     * @return Reference to the transposed matrix.
     */
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

    /**
     * @brief Provides read-only access to a row of the matrix.
     * @param i The row index.
     * @return A pointer to the row.
     * @throws out_of_range if index is invalid.
     */
    double* SquareMat::operator[](const int i) const
    {
        if(i < 0 || i >= size)
            throw std::out_of_range("Index out of range");

        return matrix[i];
    }

    /**
     * @brief Provides modifiable access to a row of the matrix.
     * @param i The row index.
     * @return A reference to a pointer to the row.
     * @throws out_of_range if index is invalid.
     */
    double*& SquareMat::operator[](const int i)
    {
        if(i < 0 || i >= size)
            throw std::out_of_range("Index out of range");

        return matrix[i];
    }

    /**
     * @brief Computes the sum of elements of two matrices.
     * @param original The first matrix.
     * @param other The second matrix.
     * @param sumOriginal Sum of the first matrix elements.
     * @param sumOther Sum of the second matrix elements.
     */
    void sumMatrices(const SquareMat& original, const SquareMat& other, double& sumOriginal, double& sumOther)
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

    /**
     * @brief Compares two matrices for equality based on the sum of their elements.
     * @param compare The matrix to compare.
     * @return true if sums are equal, false otherwise.
     */
    bool SquareMat::operator==(const SquareMat &compare) const
    {
        double sumThis = 0, sumCompare = 0;

        sumMatrices(*this, compare, sumThis, sumCompare);

        if(sumThis == sumCompare)
            return true;
        return false;
    }

    /**
     * @brief Determines if two matrices are not equal based on the sum of their elements.
     * @param compare The matrix to compare.
     * @return true if sums are not equal, false otherwise.
     */
    bool SquareMat::operator!=(const SquareMat &compare) const
    {
        double sumThis = 0, sumCompare = 0;

        sumMatrices(*this, compare, sumThis, sumCompare);

        if(sumThis != sumCompare)
            return true;
        return false;
    }

    /**
     * @brief Checks if this matrix's sum of elements is less than that of another.
     * @param compare The matrix to compare.
     * @return true if this matrix's sum is less, false otherwise.
     */
    bool SquareMat::operator<(const SquareMat &compare) const
    {
        double sumThis = 0, sumCompare = 0;

        sumMatrices(*this, compare, sumThis, sumCompare);

        if(sumThis < sumCompare)
            return true;
        return false;
    }

    /**
     * @brief Checks if this matrix's sum of elements is greater than that of another.
     * @param compare The matrix to compare.
     * @return true if this matrix's sum is greater, false otherwise.
     */
    bool SquareMat::operator>(const SquareMat &compare) const
    {
        double sumThis = 0, sumCompare = 0;

        sumMatrices(*this, compare, sumThis, sumCompare);

        if(sumThis > sumCompare)
            return true;
        return false;
    }

    /**
     * @brief Checks if this matrix's sum of elements is less than or equal to another's.
     * @param compare The matrix to compare.
     * @return true if this matrix's sum is less or equal, false otherwise.
     */
    bool SquareMat::operator<=(const SquareMat &compare) const
    {
        double sumThis = 0, sumCompare = 0;

        sumMatrices(*this, compare, sumThis, sumCompare);

        if(sumThis <= sumCompare)
            return true;
        return false;
    }

    /**
     * @brief Checks if this matrix's sum of elements is greater than or equal to another's.
     * @param compare The matrix to compare.
     * @return true if this matrix's sum is greater or equal, false otherwise.
     */
    bool SquareMat::operator>=(const SquareMat &compare) const
    {
        double sumThis = 0, sumCompare = 0;

        sumMatrices(*this, compare, sumThis, sumCompare);

        if(sumThis >= sumCompare)
            return true;
        return false;
    }

    /**
     * @brief Recursively calculates the determinant of a matrix.
     * @param matrix The matrix whose determinant is calculated.
     * @return The determinant value.
     */
    int calculateDeterminant(const SquareMat& matrix)
    {
        if(matrix.getSize() == 1)
            return matrix[0][0];

        if(matrix.getSize() == 2)
            return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];

        int det = 0;

        for(int k = 0; k < matrix.getSize(); k++)
        {
            SquareMat subMat(matrix.getSize()-1);
            for(int i = 1; i < matrix.getSize(); i++)
            {
                int colIndex = 0;
                for(int j = 0; j < matrix.getSize(); j++)
                {
                    if(j == k)
                        continue;
                    subMat[i-1][colIndex] = matrix[i][j];
                    colIndex++;
                }
            }

            int sign;
            if(k % 2 == 0)
                sign = 1;
            else
                sign = -1;

            det += sign * matrix[0][k] * calculateDeterminant(subMat);
        }

        return det;
    }

    /**
     * @brief Overloaded operator! that returns the determinant of the matrix.
     * @return The determinant of the matrix.
     */
    int SquareMat::operator!() const
    {
        return calculateDeterminant(*this);
    }

    /**
     * @brief Adds another matrix to the current matrix.
     * @param add The matrix to add.
     * @return Reference to the updated matrix.
     * @throws invalid_argument if matrix sizes mismatch.
     */
    SquareMat &SquareMat::operator+=(const SquareMat &add)
    {
        if(this->size != add.size)
            throw invalid_argument("Operator+ matrix sizes mismatch");

        *this = *this + add;
        return *this;
    }

    /**
     * @brief Subtracts another matrix from the current matrix.
     * @param sub The matrix to subtract.
     * @return Reference to the updated matrix.
     * @throws invalid_argument if matrix sizes mismatch.
     */
    SquareMat &SquareMat::operator-=(const SquareMat &sub)
    {
        if(this->size != sub.size)
            throw invalid_argument("Operator+ matrix sizes mismatch");

        *this = *this - sub;
        return *this;
    }

    /**
     * @brief Multiplies the current matrix by another matrix.
     * @param mul The matrix to multiply.
     * @return Reference to the updated matrix.
     * @throws invalid_argument if matrix sizes mismatch.
     */
    SquareMat &SquareMat::operator*=(const SquareMat &mul)
    {
        if(this->size != mul.size)
            throw invalid_argument("Operator+ matrix sizes mismatch");

        *this = *this * mul;
        return *this;
    }

    /**
     * @brief Multiplies the current matrix by a scalar.
     * @param scalar The scalar multiplier.
     * @return Reference to the updated matrix.
     */
    SquareMat &SquareMat::operator*=(int scalar)
    {
        *this = *this * scalar;
        return *this;
    }

    /**
     * @brief Divides the current matrix by a scalar.
     * @param div The scalar divisor.
     * @return Reference to the updated matrix.
     * @throws Exception if div is zero
     */
    SquareMat &SquareMat::operator/=(int div)
    {
        if(div == 0)
            throw std::invalid_argument("Can't divide by zero");

        *this = *this / div;
        return *this;
    }

    /**
     * @brief Applies element-wise multiplication with another matrix to the current matrix.
     * @param mul The matrix to multiply element-wise.
     * @return Reference to the updated matrix.
     */
    SquareMat &SquareMat::operator%=(const SquareMat &mul)
    {
        *this = *this % mul;
        return *this;
    }

    /**
     * @brief Applies element-wise modulo with a scalar to the current matrix.
     * @param scalar The scalar for modulo operation.
     * @return Reference to the updated matrix.
     */
    SquareMat &SquareMat::operator%=(int scalar)
    {
        *this = *this % scalar;
        return *this;
    }

    /**
     * @brief Overloads the stream insertion operator to output the matrix.
     * @param output The stream to output to.
     * @param matrix The matrix to output.
     * @return Reference to the output stream.
     */
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

    /**
     * @brief Non-member overload for scalar multiplication on the left side.
     * @param scalar The scalar multiplier.
     * @param mat The matrix to multiply.
     * @return A new matrix which is the product of scalar and matrix.
     */
    SquareMat operator*(const int scalar, const SquareMat &mat)
    {
        return mat * scalar;
    }

}
