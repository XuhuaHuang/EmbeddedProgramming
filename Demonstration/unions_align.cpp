/*****************************************************************//**
 * \file   unions_align.cpp
 * \brief  contains notes and examples on unions
 * 
 * Most important thing to remember:
 * An union only allows 1 of its member attribute to exist
 * The latter assigned value overwrites the former.
 * 
 * \author Xuhua Huang
 * \date   June 2021
 *********************************************************************/

#include <iostream>

struct Vector2D
{
    float x, y;
};

struct Vector4D
{
    union
    {
        struct // anonymous struct
        {
            float x, y, z, w;
        };
        struct
        {
            /**
             * memory of x and y of type float is aligned with Vector2D v1
             * memory of z and w of type float is aligned with Vector2D v2
             */
            Vector2D v1, v2;
        };
    };
};

void printVector2D(const Vector2D& vector)
{
    std::cout << __func__ << "\n"
         << "Printing struct Vector2D, x: " << vector.x << ", y: " << vector.y << "\n";
    
    return;
}

int main(void)
{

    /* Basic syntax
    union
    {
        float a;
        int b;
    };
    */

    Vector4D vector = { 1.0f, 2.0f, 3.0f, 4.0f };
    printVector2D(vector.v1); // retrieving member in the second anonymous struct
    // 1.0 and 2.0
    printVector2D(vector.v2);
    // 3.0 and 4.0

    /* Change elements in the first anonymous struct 
     * and verify change in the second anonymous struct
     */
    vector.z = 16.0f;
    printVector2D(vector.v1); // nothing changes here, prints 1.0 and 2.0
    printVector2D(vector.v2); // 16.0 and 4.0
    // memory address of float z is aligned with Vector2D v2.x [first element in v2]

    return 0;
}