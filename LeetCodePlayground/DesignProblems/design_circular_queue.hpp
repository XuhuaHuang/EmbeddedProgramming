// https://leetcode.com/problems/design-circular-deque

static const int _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

class MyCircularQueue
{
public:
    int* arr;
    int  front;
    int  rear;
    int  size;

    MyCircularQueue(int k)
    {
        arr   = new int[k];
        front = -1;
        rear  = -1;
        size  = k;
    }

    ~MyCircularQueue()
    {
        delete[] arr;
        arr = NULL;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
            front = 0;
        rear      = (rear + 1) % size;
        arr[rear] = value;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return arr[rear];
    }
    inline bool isEmpty() { return front == -1; }
    inline bool isFull() { return ((rear + 1) % size) == front; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
