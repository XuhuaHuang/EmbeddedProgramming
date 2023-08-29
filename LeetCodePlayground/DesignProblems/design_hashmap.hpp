// https://leetcode.com/problems/design-hashmap

static const int _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

class LinkedList
{
private:
    class node
    {
    public:
        int   key;
        int   value;
        node* next;
        node(int k = 0, int v = 0, node* nextptr = NULL)
            : key(k)
            , value(v)
            , next(nextptr)
        {
        }
    };

    node* head;
    node* tail;

    void deleteHead()
    {
        if ((head == tail) && (head == NULL))
        {
            return;
        }

        node* delNode = head;
        if ((head == tail) && (head != NULL))
        {
            head = tail = NULL;
        }
        else
        {
            head = head->next;
        }

        delete delNode;
    }

    void deleteTail()
    {
        if ((head == tail) && (tail == NULL))
        {
            return;
        }

        node* delNode = tail;
        if ((head == tail) && (tail != NULL))
        {
            head = tail = NULL;
        }
        else
        {
            node* curr = head;
            while (curr->next != delNode)
            {
                curr = curr->next;
            }

            tail       = curr;
            tail->next = NULL;
        }
        delete delNode;
    }

    node* getNode(int key)
    {
        node* curr = head;
        while (curr)
        {
            if (curr->key == key)
            {
                return curr;
            }
            curr = curr->next;
        }
        return NULL;
    }

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    int getKeyValue(int key)
    {
        node* addr = getNode(key);
        return (addr != NULL ? addr->value : -1);
    }

    void addNode(int key, int value)
    {
        node* addr = getNode(key);
        if (addr != NULL)
        {
            addr->value = value;
            return;
        }

        node* newNode = new node(key, value);
        if ((head == tail) && (tail == NULL))
        {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail       = newNode;
    }

    void deleteNode(int key)
    {
        if ((head == tail) && (head == NULL))
        {
            return;
        }
        node* prevNode = head;
        if (prevNode->key == key)
        {
            deleteHead();
            return;
        }

        bool found = false;
        while (prevNode->next)
        {
            if ((prevNode->next)->key == key)
            {
                found = true;
                break;
            }
            prevNode = prevNode->next;
        }

        if (!found)
        {
            return;
        }

        if (prevNode->next == tail)
        {
            deleteTail();
        }
        else
        {
            node* delNode  = prevNode->next;
            prevNode->next = delNode->next;
            delNode->next  = NULL;
            delete delNode;
        }
    }
};


class MyHashMap : protected LinkedList
{
private:
    LinkedList* buckets;

public:
    int tsize;

    MyHashMap(int _tsize = 823)
    {
        tsize   = _tsize;
        buckets = new LinkedList[tsize];
    }

    void put(int key, int value) { buckets[(key % tsize)].addNode(key, value); }

    int get(int key) { return buckets[(key % tsize)].getKeyValue(key); }

    void remove(int key) { buckets[(key % tsize)].deleteNode(key); }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
