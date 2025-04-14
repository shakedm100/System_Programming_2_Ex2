#include "matrix.hpp"
#include <iostream>

using namespace matrixImp;
using namespace std;

void initializeMatrices(SquareMat& first, SquareMat& second, SquareMat& third, SquareMat& fourth, SquareMat& fifth, SquareMat& sixth)
{
    int counter = 1;
    int size = first.getSize();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            first[i][j] = counter++;
        }
    }

    counter = 10;
    size = second.getSize();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            second[i][j] = counter;
            counter += 10;
        }
    }

    counter = 100;
    size = third.getSize();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            third[i][j] = counter;
            counter += 100;
        }
    }


    size = fourth.getSize();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            fourth[i][j] = i + j;
        }
    }

    size = fifth.getSize();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            fifth[i][j] = i * j;
        }
    }

    size = sixth.getSize();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            sixth[i][j] = i * i + j * j;
        }
    }
}

SquareMat chooseMatrix(SquareMat& first, SquareMat& second, SquareMat& third, SquareMat& fourth, SquareMat& fifth, SquareMat& sixth)
{
    cout << "Choose Matrix between 1-6\n";
    int input;

    //Condition doesn't really matter but while(true) is bad practice in this case
    while(input < 6 || input > 1)
    {
        cin >> input;
        switch (input)
        {
            case 1:
                return first;
            case 2:
                return second;
            case 3:
                return third;
            case 4:
                return fourth;
            case 5:
                return fifth;
            case 6:
                return sixth;
            default:
                cout << "Wrong input! Try again\n";
        }
    }

    return first; //To remove warning
}


int main()
{
    cout << "Welcome to MatriceLand!\n";

    SquareMat first(3), second(3), third(5), fourth(5), fifth(7), sixth(7);
    initializeMatrices(first,second,third,fourth,fifth, sixth);

    cout << "1. " << first << "2. " << second << "3. " << third << "4. " << fourth << "5. " << fifth << "6. " << sixth << endl;

    int input = -1, scalar = 0;

    SquareMat chosen1(1), chosen2(1); //Placeholder construction

    while(input != 0)
    {
        cout <<
        "Choose which action would you like to do?" <<
            "\n1. Addition" <<
            "\n2. Subtraction" <<
            "\n3. Multiplication (Matrix)" <<
            "\n4. Multiplication (Scalar)" <<
            "\n5. Division" <<
            "\n6. Members Multiplication %" <<
            "\n7. Modulo" <<
            "\n8. Matrix Power" <<
            "\n9. Matrix increase +1" <<
            "\n10. Matrix decrease -1" <<
            "\n11. Transpose" <<
            "\n12. Determinant" <<
            "\n13. Print" <<
            "\n0. Exit" << endl;

        cin >> input;
        switch (input)
        {
            case 1:
            {
                chosen1 = chooseMatrix(first, second, third, fourth, fifth, sixth);
                chosen2 = chooseMatrix(first, second, third, fourth, fifth, sixth);
                cout << chosen1 + chosen2 << endl;
                break;
            }
            case 2:
            {
                chosen1 = chooseMatrix(first, second, third, fourth, fifth, sixth);
                chosen2 = chooseMatrix(first, second, third, fourth, fifth, sixth);
                cout << chosen1 - chosen2 << endl;
                break;
            }
            case 3:
            {
                chosen1 = chooseMatrix(first, second, third, fourth, fifth, sixth);
                chosen2 = chooseMatrix(first, second, third, fourth, fifth, sixth);
                cout << chosen1 * chosen2 << endl;
                break;
            }
            case 4:
            {
                chosen1 = chooseMatrix(first, second, third, fourth, fifth, sixth);
                cout << "Choose scalar to multiply by:\n";
                cin >> scalar;
                cout << chosen1 * scalar << endl;
                break;
            }
            case 5:
            {
                chosen1 = chooseMatrix(first, second, third, fourth, fifth, sixth);
                cout << "Choose scalar to divide by:\n";
                cin >> scalar;
                cout << chosen1 / scalar << endl;
                break;
            }
            case 6:
            {
                chosen1 = chooseMatrix(first, second, third, fourth, fifth, sixth);
                chosen2 = chooseMatrix(first, second, third, fourth, fifth, sixth);
                cout << chosen1 % chosen2 << endl;
                break;
            }
            case 7:
            {
                chosen1 = chooseMatrix(first, second, third, fourth, fifth, sixth);
                cout << "Choose scalar to modulo by:\n";
                cin >> scalar;
                cout << chosen1 % scalar << endl;
                break;
            }
            case 8:
            {
                chosen1 = chooseMatrix(first, second, third, fourth, fifth, sixth);
                cout << "Choose scalar to power by:\n";
                cin >> scalar;
                cout << (chosen1^scalar) << endl;
                break;
            }
            case 9:
            {
                chosen1 = chooseMatrix(first, second, third, fourth, fifth, sixth);
                cout << ++chosen1 << endl;
                break;
            }
            case 10:
            {
                chosen1 = chooseMatrix(first, second, third, fourth, fifth, sixth);
                cout << --chosen1 << endl;
                break;
            }
            case 11:
            {
                chosen1 = chooseMatrix(first, second, third, fourth, fifth, sixth);
                cout << ~chosen1 << endl;
                break;
            }
            case 12:
            {
                chosen1 = chooseMatrix(first, second, third, fourth, fifth, sixth);
                cout << !chosen1 << endl;
                break;
            }
            case 13:
            {
                chosen1 = chooseMatrix(first, second, third, fourth, fifth, sixth);
                cout << chosen1 << endl;
            }
            case 0:
                break;
            default:
                cout << "Wrong input, Try again!" << endl;
        }
    }

    return 0;
}
