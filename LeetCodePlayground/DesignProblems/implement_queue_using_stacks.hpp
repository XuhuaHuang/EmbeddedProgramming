// https://leetcode.com/problems/implement-queue-using-stacks

class MyQueue
{
    template<typename T>
    using stack = std::stack<T>;

public:
    stack<int> s1, s2;
    MyQueue()
    {
        s1 = {};
        s2 = {};
    }

    void push(int x) { s1.push(x); }

    int pop()
    {
        while (s1.size() > 1)
        {
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s1.top();
        s1.pop();
        while (s2.size() > 0)
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }

    int peek()
    {
        while (s1.size() > 1)
        {
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s1.top();
        // s1.pop();
        while (s2.size() > 0)
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }

    bool empty()
    {
        if (s1.empty() == true)
        {
            return true;
        }
        return false;
    }
};
