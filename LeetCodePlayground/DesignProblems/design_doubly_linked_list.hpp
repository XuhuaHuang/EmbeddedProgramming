// https://leetcode.com/problems/design-linked-list

static const int _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

struct MyLinkedListNode
{
    int               val;
    MyLinkedListNode* prev;
    MyLinkedListNode* next;

    MyLinkedListNode(int v)
        : val(v)
        , prev(nullptr)
        , next(nullptr)
    {
    }
    MyLinkedListNode(int v, MyLinkedListNode* p, MyLinkedListNode* n)
        : val(v)
        , prev(p)
        , next(n)
    {
    }
};

class MyLinkedList
{
private:
    MyLinkedListNode *head, *tail;
    int               size;

public:
    MyLinkedList()
        : size(0)
    {
        head       = new MyLinkedListNode(0);
        tail       = new MyLinkedListNode(0);

        head->next = tail;
        tail->prev = head;
    }

    ~MyLinkedList()
    {
        auto curr = head;
        auto del  = curr;
        while (curr)
        {
            del  = curr;
            curr = curr->next;
            delete del;
        }
    }

    MyLinkedListNode* findFromTail(int index)
    {
        int  i    = size - 1;
        auto curr = tail->prev;
        while (curr != head)
        {
            if (i == index)
                return curr;

            i -= 1;
            curr = curr->prev;
        }

        return nullptr;
    }

    MyLinkedListNode* findFromHead(int index)
    {
        int  i    = 0;
        auto curr = head->next;
        while (curr != tail)
        {
            if (i == index)
            {
                return curr;
            }

            i += 1;
            curr = curr->next;
        }

        return nullptr;
    }

    MyLinkedListNode* find(int index)
    {
        if (index > size / 2)
        {
            return findFromTail(index);
        }
        return findFromHead(index);
    }

    int get(int index)
    {
        if (index >= size || index < 0)
        {
            return -1;
        }

        auto n = find(index);
        if (n != nullptr)
        {
            return n->val;
        }

        return -1;
    }

    void addAtHead(int val)
    {
        auto node  = new MyLinkedListNode(val, head, head->next);
        head->next = head->next->prev = node;
        size += 1;
    }

    void addAtTail(int val)
    {
        auto node  = new MyLinkedListNode(val, tail->prev, tail);
        tail->prev = tail->prev->next = node;
        size += 1;
    }

    void addAtIndex(int index, int val)
    {
        if (index > size || index < 0)
        {
            return;
        }

        if (index == size)
        {
            return addAtTail(val);
        }

        auto n = find(index);
        if (n != nullptr)
        {
            n         = n->prev;
            auto node = new MyLinkedListNode(val, n, n->next);
            n->next = n->next->prev = node;
            size += 1;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index >= size || index < 0)
        {
            return;
        }

        auto n = find(index);
        if (n != nullptr)
        {
            n->prev->next = n->next;
            n->next->prev = n->prev;
            delete n;
            size -= 1;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
