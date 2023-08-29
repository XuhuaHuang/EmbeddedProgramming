// https://leetcode.com/problems/design-a-text-editor

#include <algorithm>
#include <stack>
#include <string>

class TextEditor
{
    std::stack<char> left;
    std::stack<char> right;

public:
    TextEditor() {}

    void addText(string text)
    {
        for (auto& c : text)
        {
            left.push(c);
        }
    }

    int deleteText(int k)
    {
        int cnt = 0;
        while (!left.empty() and k > 0)
        {
            left.pop();
            cnt++;
            k--;
        }
        return cnt;
    }

    std::string cursorLeft(int k)
    {
        while (!left.empty() and k > 0)
        {
            char c = left.top();
            left.pop();
            right.push(c);
            k--;
        }
        return cursorShiftString();
    }

    std::string cursorRight(int k)
    {
        while (!right.empty() and k > 0)
        {
            char c = right.top();
            right.pop();
            left.push(c);
            k--;
        }
        return cursorShiftString();
    }

    std::string cursorShiftString()
    {
        std::string rtn = "";
        int         cnt = 10;
        while (!left.empty() and cnt > 0)
        {
            char c = left.top();
            left.pop();
            rtn += c;
            cnt--;
        }
        std::reverse(rtn.begin(), rtn.end());
        for (int i = 0; i < rtn.size(); i++)
        {
            left.push(rtn[i]);
        }
        return rtn;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
