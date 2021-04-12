/*****************************************************************//**
 * \file   OverloadedNewDelete.cpp
 * \brief  Overloading new and delete operator
 *	   Memory allocation related with debug monitoring
 *
 * \author Xuhua Huang
 * \date   April 2021
 *********************************************************************/

#include <iostream>
#include <memory>
using namespace std;

struct AllocationMetrics
{
	uint32_t TotalAllocated = 0;
	uint32_t TotalFreed = 0;

	uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }
};

static AllocationMetrics metrics;

void* operator new(size_t size)
{
	cout << "Allocating " << size << " bytes memory." << endl;
	metrics.TotalAllocated += size;
	return malloc(size);
}

void operator delete(void* memory, size_t size)
{
	cout << "Deallocating " << size << " bytes memory." << endl;
	metrics.TotalFreed += size;
	free(memory);
}

static void PrintMemoryUsage()
{
	cout << "Current memory usage " << metrics.CurrentUsage() << " bytes." << endl;
}

struct Object
{
	Object() : x(0), y(0), z(0) {
		cout << "[DFCONST]Object" << endl;
	}

	Object(int userX, int userY, int userZ) :
		x(userX), y(userY), z(userZ) {
		cout << "[OLCONST]Object" << endl;
	}

	int x, y, z;
};

int main(void)
{
	// Object *myObj = new Object();
	PrintMemoryUsage();
	{
		unique_ptr<Object> obj_ptr = make_unique<Object>();
		PrintMemoryUsage();
	}
	PrintMemoryUsage();
	return 0;
}
