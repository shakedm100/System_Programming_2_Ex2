#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "matrix.hpp"

using namespace matrixImp;

struct Matrices
{
    SquareMat first;
    SquareMat second;
    SquareMat third;

    Matrices() : first(3), second(3), third(4)
    {
        // 1-9
        int value = 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                first[i][j] = value++;
            }
        }

        // 10-18
        value = 10;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                second[i][j] = value++;
            }
        }

        // 1-16
        value = 1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                third[i][j] = value++;
            }
        }
    }
};

TEST_CASE_FIXTURE(Matrices, "Operator+")
{
    CHECK_THROWS(second + third);
    CHECK_THROWS(first + third);

    SquareMat result = first + second;

    CHECK(result[0][0] == 11);
    CHECK(result[0][1] == 13);
    CHECK(result[0][2] == 15);
    CHECK(result[1][0] == 17);
    CHECK(result[1][1] == 19);
    CHECK(result[1][2] == 21);
    CHECK(result[2][0] == 23);
    CHECK(result[2][1] == 25);
    CHECK(result[2][2] == 27);
}

TEST_CASE_FIXTURE(Matrices, "Operator-")
{
    CHECK_THROWS(second - third);
    CHECK_THROWS(first - third);

    SquareMat result = first - second;

    CHECK(result[0][0] == -9);
    CHECK(result[0][1] == -9);
    CHECK(result[0][2] == -9);
    CHECK(result[1][0] == -9);
    CHECK(result[1][1] == -9);
    CHECK(result[1][2] == -9);
    CHECK(result[2][0] == -9);
    CHECK(result[2][1] == -9);
    CHECK(result[2][2] == -9);
}

TEST_CASE_FIXTURE(Matrices, "Operator- Unary")
{
    SquareMat result = -first;

    CHECK(result[0][0] == -1);
    CHECK(result[0][1] == -2);
    CHECK(result[0][2] == -3);
    CHECK(result[1][0] == -4);
    CHECK(result[1][1] == -5);
    CHECK(result[1][2] == -6);
    CHECK(result[2][0] == -7);
    CHECK(result[2][1] == -8);
    CHECK(result[2][2] == -9);
}

TEST_CASE_FIXTURE(Matrices, "Operator* Matrix")
{
    CHECK_THROWS(second * third);
    CHECK_THROWS(first * third);

    SquareMat result = first * second;
    CHECK(result[0][0] == 84);
    CHECK(result[0][1] == 90);
    CHECK(result[0][2] == 96);
    CHECK(result[1][0] == 201);
    CHECK(result[1][1] == 216);
    CHECK(result[1][2] == 231);
    CHECK(result[2][0] == 318);
    CHECK(result[2][1] == 342);
    CHECK(result[2][2] == 366);
}

TEST_CASE_FIXTURE(Matrices, "Operator* Scalar")
{
    SquareMat result = first * 5;
    CHECK(result[0][0] == 5);
    CHECK(result[0][1] == 10);
    CHECK(result[0][2] == 15);
    CHECK(result[1][0] == 20);
    CHECK(result[1][1] == 25);
    CHECK(result[1][2] == 30);
    CHECK(result[2][0] == 35);
    CHECK(result[2][1] == 40);
    CHECK(result[2][2] == 45);

    SquareMat result2 = 5 * second;
    CHECK(result2[0][0] == 50);
    CHECK(result2[0][1] == 55);
    CHECK(result2[0][2] == 60);
    CHECK(result2[1][0] == 65);
    CHECK(result2[1][1] == 70);
    CHECK(result2[1][2] == 75);
    CHECK(result2[2][0] == 80);
    CHECK(result2[2][1] == 85);
    CHECK(result2[2][2] == 90);
}

TEST_CASE_FIXTURE(Matrices, "Operator% Matrix")
{
    CHECK_THROWS(second % third);
    CHECK_THROWS(first % third);

    SquareMat result = first % second;
    CHECK(result[0][0] == 10);
    CHECK(result[0][1] == 22);
    CHECK(result[0][2] == 36);
    CHECK(result[1][0] == 52);
    CHECK(result[1][1] == 70);
    CHECK(result[1][2] == 90);
    CHECK(result[2][0] == 112);
    CHECK(result[2][1] == 136);
    CHECK(result[2][2] == 162);
}

TEST_CASE_FIXTURE(Matrices, "Operator% Scalar")
{
    SquareMat result = second % 8;

    CHECK(result[0][0] == 2);
    CHECK(result[0][1] == 3);
    CHECK(result[0][2] == 4);
    CHECK(result[1][0] == 5);
    CHECK(result[1][1] == 6);
    CHECK(result[1][2] == 7);
    CHECK(result[2][0] == 0);
    CHECK(result[2][1] == 1);
    CHECK(result[2][2] == 2);
}

TEST_CASE_FIXTURE(Matrices, "Operator/")
{
    SquareMat result = second / 8;

    CHECK(result[0][0] == 1); //10 / 8 = 1
    CHECK(result[0][1] == 1); //11 / 8 = 1
    CHECK(result[0][2] == 1); //...
    CHECK(result[1][0] == 1);
    CHECK(result[1][1] == 1);
    CHECK(result[1][2] == 1);
    CHECK(result[2][0] == 2); //16 / 8 = 2
    CHECK(result[2][1] == 2);
    CHECK(result[2][2] == 2);
}

TEST_CASE_FIXTURE(Matrices, "Operator^")
{
    CHECK_THROWS(first ^ -2);

    SquareMat result = first ^ 3;

    CHECK(result[0][0] == 468);
    CHECK(result[0][1] == 576);
    CHECK(result[0][2] == 684);
    CHECK(result[1][0] == 1062);
    CHECK(result[1][1] == 1305);
    CHECK(result[1][2] == 1548);
    CHECK(result[2][0] == 1656);
    CHECK(result[2][1] == 2034);
    CHECK(result[2][2] == 2412);

    SquareMat result2 = second ^ 2;

    CHECK(result2[0][0] == 435);
    CHECK(result2[0][1] == 468);
    CHECK(result2[0][2] == 501);
    CHECK(result2[1][0] == 552);
    CHECK(result2[1][1] == 594);
    CHECK(result2[1][2] == 636);
    CHECK(result2[2][0] == 669);
    CHECK(result2[2][1] == 720);
    CHECK(result2[2][2] == 771);

}

TEST_CASE_FIXTURE(Matrices, "Operator++")
{
    SquareMat result = first++;
    SquareMat result2 = ++second;

    CHECK(first[0][0] == 2);
    CHECK(first[0][1] == 3);
    CHECK(first[0][2] == 4);
    CHECK(first[1][0] == 5);
    CHECK(first[1][1] == 6);
    CHECK(first[1][2] == 7);
    CHECK(first[2][0] == 8);
    CHECK(first[2][1] == 9);
    CHECK(first[2][2] == 10);

    CHECK(result[0][0] == 1);
    CHECK(result[0][1] == 2);
    CHECK(result[0][2] == 3);
    CHECK(result[1][0] == 4);
    CHECK(result[1][1] == 5);
    CHECK(result[1][2] == 6);
    CHECK(result[2][0] == 7);
    CHECK(result[2][1] == 8);
    CHECK(result[2][2] == 9);

    CHECK(result2[0][0] == 11);
    CHECK(result2[0][1] == 12);
    CHECK(result2[0][2] == 13);
    CHECK(result2[1][0] == 14);
    CHECK(result2[1][1] == 15);
    CHECK(result2[1][2] == 16);
    CHECK(result2[2][0] == 17);
    CHECK(result2[2][1] == 18);
    CHECK(result2[2][2] == 19);

}

TEST_CASE_FIXTURE(Matrices, "Operator--")
{
    SquareMat result = first--;
    SquareMat result2 = --second;

    CHECK(first[0][0] == 0);
    CHECK(first[0][1] == 1);
    CHECK(first[0][2] == 2);
    CHECK(first[1][0] == 3);
    CHECK(first[1][1] == 4);
    CHECK(first[1][2] == 5);
    CHECK(first[2][0] == 6);
    CHECK(first[2][1] == 7);
    CHECK(first[2][2] == 8);

    CHECK(result[0][0] == 1);
    CHECK(result[0][1] == 2);
    CHECK(result[0][2] == 3);
    CHECK(result[1][0] == 4);
    CHECK(result[1][1] == 5);
    CHECK(result[1][2] == 6);
    CHECK(result[2][0] == 7);
    CHECK(result[2][1] == 8);
    CHECK(result[2][2] == 9);

    CHECK(result2[0][0] == 9);
    CHECK(result2[0][1] == 10);
    CHECK(result2[0][2] == 11);
    CHECK(result2[1][0] == 12);
    CHECK(result2[1][1] == 13);
    CHECK(result2[1][2] == 14);
    CHECK(result2[2][0] == 15);
    CHECK(result2[2][1] == 16);
    CHECK(result2[2][2] == 17);
}

TEST_CASE_FIXTURE(Matrices, "Operator~")
{
    SquareMat result = ~first; //3x3 transpose
    SquareMat result2 = ~third; //4x4 transpose


    CHECK(result[0][0] == 1);
    CHECK(result[0][1] == 4);
    CHECK(result[0][2] == 7);
    CHECK(result[1][0] == 2);
    CHECK(result[1][1] == 5);
    CHECK(result[1][2] == 8);
    CHECK(result[2][0] == 3);
    CHECK(result[2][1] == 6);
    CHECK(result[2][2] == 9);

    CHECK(result2[0][0] == 1);
    CHECK(result2[0][1] == 5);
    CHECK(result2[0][2] == 9);
    CHECK(result2[0][3] == 13);
    CHECK(result2[1][0] == 2);
    CHECK(result2[1][1] == 6);
    CHECK(result2[1][2] == 10);
    CHECK(result2[1][3] == 14);
    CHECK(result2[2][0] == 3);
    CHECK(result2[2][1] == 7);
    CHECK(result2[2][2] == 11);
    CHECK(result2[2][3] == 15);
    CHECK(result2[3][0] == 4);
    CHECK(result2[3][1] == 8);
    CHECK(result2[3][2] == 12);
    CHECK(result2[3][3] == 16);
}

//Right side has been tested in most other cases
//But the LValue implementation wasn't tested yet
TEST_CASE_FIXTURE(Matrices, "Operator[]")
{
    int* row = first[2];
    int check = first[1][0];

    CHECK(row[0] == 7);
    CHECK(row[1] == 8);
    CHECK(row[2] == 9);
    CHECK(check == 4);

    SquareMat  result = first;
    result[0][0] = 100;
    result[1][1] = 200;

    CHECK(result[0][0] == 100);
    CHECK(result[1][1] == 200);
}

TEST_CASE_FIXTURE(Matrices, "Operator==/!=")
{
    bool result = first == second;
    CHECK(result == false);
    bool result2 = first != second;
    CHECK(result2 == true);

    first[0][0] = 82;

    bool result3 = first == second;
    CHECK(result3 == true);
    bool result4 = first != second;
    CHECK(result4 == false);
}

TEST_CASE_FIXTURE(Matrices, "Operator<>>=>=")
{
    bool result1 = first < second;
    bool result2 = second < first;
    bool result3 = first > second;
    bool result4 = second > first;
    bool result5 = first <= second;
    bool result6 = second <= first;
    bool result7 = first >= second;
    bool result8 = second >= first;

    CHECK(result1 == true);
    CHECK(result2 == false);
    CHECK(result3 == false);
    CHECK(result4 == true);
    CHECK(result5 == true);
    CHECK(result6 == false);
    CHECK(result7 == false);
    CHECK(result8 == true);
}

TEST_CASE_FIXTURE(Matrices, "Operator!")
{
    int result1 = !first;
    int result2 = !second;
    int result3 = !third;

    CHECK(result1 == 0);
    CHECK(result2 == 0);
    CHECK(result3 == 0);

    first[0][1] = 203;
    third[0][0] = 19;
    third[3][1] = 23;

    int result4 = !first;
    int result5 = !third;

    CHECK(result4 == 1206);
    CHECK(result5 == -648);
}

TEST_CASE_FIXTURE(Matrices, "Operator +=")
{
    CHECK_THROWS(first += third);

    first += second;
    CHECK(first[0][0] == 11);
    CHECK(first[0][1] == 13);
    CHECK(first[0][2] == 15);
    CHECK(first[1][0] == 17);
    CHECK(first[1][1] == 19);
    CHECK(first[1][2] == 21);
    CHECK(first[2][0] == 23);
    CHECK(first[2][1] == 25);
    CHECK(first[2][2] == 27);
}

TEST_CASE_FIXTURE(Matrices, "Operator -=")
{
    CHECK_THROWS(second -= third);
    CHECK_THROWS(first -= third);

    first -= second;

    CHECK(first[0][0] == -9);
    CHECK(first[0][1] == -9);
    CHECK(first[0][2] == -9);
    CHECK(first[1][0] == -9);
    CHECK(first[1][1] == -9);
    CHECK(first[1][2] == -9);
    CHECK(first[2][0] == -9);
    CHECK(first[2][1] == -9);
    CHECK(first[2][2] == -9);
}

TEST_CASE_FIXTURE(Matrices, "Operator*= Matrix")
{
    CHECK_THROWS(second *= third);
    CHECK_THROWS(first *= third);

    first *= second;
    CHECK(first[0][0] == 84);
    CHECK(first[0][1] == 90);
    CHECK(first[0][2] == 96);
    CHECK(first[1][0] == 201);
    CHECK(first[1][1] == 216);
    CHECK(first[1][2] == 231);
    CHECK(first[2][0] == 318);
    CHECK(first[2][1] == 342);
    CHECK(first[2][2] == 366);
}

TEST_CASE_FIXTURE(Matrices, "Operator*= Scalar")
{
    first *= 5;
    CHECK(first[0][0] == 5);
    CHECK(first[0][1] == 10);
    CHECK(first[0][2] == 15);
    CHECK(first[1][0] == 20);
    CHECK(first[1][1] == 25);
    CHECK(first[1][2] == 30);
    CHECK(first[2][0] == 35);
    CHECK(first[2][1] == 40);
    CHECK(first[2][2] == 45);
}

TEST_CASE_FIXTURE(Matrices, "Operator%= Matrix")
{
    CHECK_THROWS(second %= third);
    CHECK_THROWS(first %= third);

    first %= second;
    CHECK(first[0][0] == 10);
    CHECK(first[0][1] == 22);
    CHECK(first[0][2] == 36);
    CHECK(first[1][0] == 52);
    CHECK(first[1][1] == 70);
    CHECK(first[1][2] == 90);
    CHECK(first[2][0] == 112);
    CHECK(first[2][1] == 136);
    CHECK(first[2][2] == 162);
}

TEST_CASE_FIXTURE(Matrices, "Operator%= Scalar")
{
    second %= 8;

    CHECK(second[0][0] == 2);
    CHECK(second[0][1] == 3);
    CHECK(second[0][2] == 4);
    CHECK(second[1][0] == 5);
    CHECK(second[1][1] == 6);
    CHECK(second[1][2] == 7);
    CHECK(second[2][0] == 0);
    CHECK(second[2][1] == 1);
    CHECK(second[2][2] == 2);
}

TEST_CASE_FIXTURE(Matrices, "Operator/")
{
    second /= 8;

    CHECK(second[0][0] == 1); //10 / 8 = 1
    CHECK(second[0][1] == 1); //11 / 8 = 1
    CHECK(second[0][2] == 1); //...
    CHECK(second[1][0] == 1);
    CHECK(second[1][1] == 1);
    CHECK(second[1][2] == 1);
    CHECK(second[2][0] == 2); //16 / 8 = 2
    CHECK(second[2][1] == 2);
    CHECK(second[2][2] == 2);
}

TEST_CASE_FIXTURE(Matrices, "Operator<<")
{
    std::cout << "The testing matrices are:\n";
    std::cout << "1) " << first;
    std::cout << "2) " << second;
    std::cout << "3) " << third << std::endl;
}