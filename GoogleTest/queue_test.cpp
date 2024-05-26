/*****************************************************************//**
 * \file   queue_test.cpp
 * \brief  Testing basic implementation of Queue.
 *
 * \author Xuhua Huang
 * \date   November 14, 2022
 *********************************************************************/

#include <iostream>
#include <stdlib.h>
#include <gtest/gtest.h>

/**
 * Test fixtures: using the same data configuration for multiple tests
 *
 * To create a fixture:
 * 1) derive a class from ::testing::Test and start its body with `protected`
 * 2) declare objects to use
 * 3) SetUp() / default constructor
 * 4) TearDown() / destructor
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
#ifndef Q_SIZE
#define Q_SIZE 10
#endif

//template<typename T>
class Queue {
public:
    Queue(int size = Q_SIZE);
    ~Queue() { delete[] arr; }

    void Enqueue(const int);
    int* Dequeue(); // returns NULL if the queue is empty

    size_t size() const { return count; }
    bool isEmpty() { return size() == 0; }
    bool isFull() { return size() == capacity; }
private:
    int* arr;        // array to store Queue element
    int capacity;    // maximum capacity of the queue
    int front;       // front element (if any)
    int rear;        // last element (if any)
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

void Queue::Enqueue(const int item) {
    // check for queue overflow
    if (isFull()) {
        std::cout << "Overflow occurred. Program Terminated." << "\n";
        exit(EXIT_FAILURE);
    }
    else {
        std::cout << "Inserting " << item << "\n";
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
    }
}

int* Queue::Dequeue() {
    if (isEmpty()) {
        std::cout << "Underflow occurred. Queue is empty." << "\n";
        return nullptr;
    }
    else {
        int* value = &arr[front];
        std::cout << "Removing " << arr[front] << "\n";
        front = (front + 1) % capacity;
        count--;
        return value;
    }
}

/* Queue class test fixture */
class QueueTest : public ::testing::Test {
protected:
    virtual void SetUp() override {
        _q1.Enqueue(1);
        _q2.Enqueue(2);
        _q2.Enqueue(3);
    }

    virtual void TearDown() override {}
    // Queue::~Queue() handles destruction and cleanup

    Queue _q0;
    Queue _q1;
    Queue _q2;
};

/* Write tests using TEST_F() and created fixture */
TEST_F(QueueTest, IsEmptyInitially) {
    EXPECT_EQ(_q0.size(), 0);
}

TEST_F(QueueTest, DequeueWorks) {
    int* n = _q0.Dequeue();
    EXPECT_EQ(n, nullptr);

    n = _q1.Dequeue();
    ASSERT_NE(n, nullptr);
    EXPECT_EQ(*n, 1);
    EXPECT_EQ(_q1.size(), 0);

    n = _q2.Dequeue();
    ASSERT_NE(n, nullptr);
    EXPECT_EQ(*n, 2);
    EXPECT_EQ(_q2.size(), 1);

    n = _q2.Dequeue();
    ASSERT_NE(n, nullptr);
    EXPECT_EQ(*n, 3);
    EXPECT_EQ(_q2.size(), 0);
}

/**
 * When these tests run, the following happens:
 * 1 - googletest constructs a QueueTest object (lets call it t1).
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
