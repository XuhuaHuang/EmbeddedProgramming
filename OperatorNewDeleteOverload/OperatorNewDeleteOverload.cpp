/*****************************************************************//**
 * \file   OperatorNewDeleteOverload.cpp
 * \brief  Overloading new and delete operator
 *         Memory allocation related with debug monitoring
 *
 * \author Xuhua Huang
 * \date   April 2021
 *********************************************************************/

#include <iostream>
#include <memory>

struct AllocationMetrics
{
    uint32_t TotalAllocated = 0;
    uint32_t TotalFreed = 0;

    uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }
};

static AllocationMetrics metrics;

void* operator new(size_t size)
{
    std::cout << "Allocating " << size << " bytes memory." << "\n";
    metrics.TotalAllocated += size;
    return malloc(size);
}

void operator delete(void* memory, size_t size)
{
    std::cout << "Deallocating " << size << " bytes memory." << "\n";
    metrics.TotalFreed += size;
    free(memory);
}

static void PrintMemoryUsage()
{
    std::cout << "Current memory usage " << metrics.CurrentUsage() << " bytes." << "\n";
}

struct Object
{
    Object() : x(0), y(0), z(0) {
        std::cout << "[DFCONST]Object" << "\n";
    }

    Object(int userX, int userY, int userZ) :
        x(userX), y(userY), z(userZ) {
        std::cout << "[OLCONST]Object" << "\n";
    }

    int x, y, z;
};

int main(void)
{
    // Object *myObj = new Object();
    PrintMemoryUsage();
    {
        std::unique_ptr<Object> obj_ptr = std::make_unique<Object>();
        PrintMemoryUsage();
    }
    PrintMemoryUsage();
    return 0;
}
