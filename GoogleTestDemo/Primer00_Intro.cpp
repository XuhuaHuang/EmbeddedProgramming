/*****************************************************************//**
 * \file   Primer00_Intro.cpp
 * \brief  Introduction to Google Test framework following tutorial
 * https://google.github.io/googletest/primer.html
 *
 * \author Xuhua Huang
 * \date   July 2021
 *********************************************************************/

#include <iostream>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

namespace MathUtil {
	int factorial(int n) {
		if ((n == 0) || (n == 1))
			return 1;
		else
			return n * factorial(n - 1);
	}
}

/**
 * Create a simple test
 *
 * Use TEST() macro to define and name test function
 * ordinary C++ functions that do not return a value
 * result is determined by assertions
 *
 * TEST(TestSuiteName, TestName) {
 *	// ... test body ...
 * }
 */

 // Tests factorial of 0
TEST(FactorialTest, HandlesZeroInput) {
	EXPECT_EQ(MathUtil::factorial(0), 1);
}

// Tests factorial of positive numbers
TEST(FactorialTest, HandlesPositiveInput) {
	std::vector<int> posInput = { 1, 2, 3, 8 };
	std::vector<int> expResult = { 1, 2, 6, 40320 };
	for (int i = 0; i < posInput.size(); ++i) {
		EXPECT_EQ(MathUtil::factorial(posInput[i]), expResult[i]);
	}
}

/**
 * Test fixtures: using the same data configuration for multiple tests
 *
 * To create a fixture:
 * 1) derive a class from ::testing::Test and start its body with `protected`
 * 2) declare objects to use
 * 3) SetUp() / default constructor
 * 4) TearDOwn() / destructor
 *
 * Use `TEST_F() allows access to objects and subroutines in the test fixture
 * TEST_F(TestFixtureName, TestName) {
 * // ... test body ...
 * }
 *
 * Note: must declare a fixture class before using it in a TEST_F()
 * or user will get compiler error
 */

 /* Queue class definition */
#define Q_SIZE 10
class Queue {
public:
	Queue(int size = Q_SIZE);
	~Queue() { delete[] arr; }

	void Enqueue(const int&);
	int* Dequeue(); // returns NULL if the queue is empty

	size_t size() const { return count; }
	bool isEmpty() { return size() == 0; }
	bool isFull() { return size() == capacity; }
private:
	int* arr;		// array to store Queue element
	int capacity;	// maximum capacity of the queue
	int front;		// front element (if any)
	int rear;		// last element (if any)
	size_t count;
};

/* Queue class implementation */
Queue::Queue(int size) {
	arr = new int[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;
}

void Queue::Enqueue(const int& item) {
	// check for queue overflow
	if (isFull()) {
		cout << "Overflow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	else {
		std::cout << "Inserting " << item << std::endl;
		rear = (rear + 1) % capacity;
		arr[rear] = item;
		count++;
	}
}

int* Queue::Dequeue() {
	if (isEmpty()) {
		std::cout << "Underflow\nQueue is empty\nProgram Terminated\n";
		return nullptr;
	}
	else {
		int* value = &arr[front];
		std::cout << "Removing " << arr[front] << std::endl;
		front = (front + 1) % capacity;
		count--;
		return value;
	}
}

/* Queue class test fixture */
class QueueTest : public ::testing::Test {
protected:
	void SetUp() override {
		_q1.Enqueue(1);
		_q2.Enqueue(2);
		_q2.Enqueue(2);
	}

	// void TearDown() override {}
	// Queue::~Queue() handles destruction and cleanup

	Queue _q0;
	Queue _q1;
	Queue _q2;
};

/* Write tests using TEST_F() and created fixture */
TEST_F(QueueTest, InitEmpty) {
	EXPECT_EQ(_q0.size(), 0);
}

TEST_F(QueueTest, DequeueWorks) {
	int* n = _q0.Dequeue();
	EXPECT_EQ(n, nullptr);

	n = _q1.Dequeue();
	ASSERT_NE(n, nullptr);
	EXPECT_EQ(*n, 1);
	EXPECT_EQ(_q1.size(), 0);
	delete n;

	n = _q2.Dequeue();
	ASSERT_NE(n, nullptr);
	EXPECT_EQ(*n, 2);
	EXPECT_EQ(_q2.size(), 1);
	delete n;
}

/**
 * When these tests run, the following happens:
 * 1 - googletest constructs a QueueTest object (let’s call it t1).
 * 2 - t1.SetUp() initializes t1.
 * 3 - The first test (IsEmptyInitially) runs on t1.
 * 4 - t1.TearDown() cleans up after the test finishes.
 * 5 - t1 is destructed.
 * 6 - The above steps are repeated on another QueueTest object,
 * this time running the DequeueWorks test.
 */

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}