// https://leetcode.com/problems/design-a-stack-with-increment-operation

class CustomStack
{
public:
    vector<int> arr;
    int         size;

    CustomStack(int maxSize) { size = maxSize; }

    void push(int x)
    {
        if (arr.size() < size)
        {
            arr.push_back(x);
        }
    }

    int pop()
    {
        if (arr.size() == 0)
        {
            return -1;
        }
        int ans = arr.back();
        arr.pop_back();
        return ans;
    }

    void increment(int k, int val)
    {
        k = min(k, (int)arr.size());
        for (int i = 0; i < k; i++)
        {
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
