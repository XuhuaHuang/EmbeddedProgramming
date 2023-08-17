#include <cstddef> // for std::ptrdiff_t
#include <iostream>
#include <iterator>

template<typename T>
class DoublyLinkedList
{
public:
    struct Node
    {
        T     data;
        Node* prev;
        Node* next;
        Node(const T& data, Node* prev = nullptr, Node* next = nullptr)
            : data(data)
            , prev(prev)
            , next(next)
        {
        }
    };

    class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
    public:
        explicit iterator(Node* node)
            : node_(node)
        {
        }
        iterator(const iterator&)            = default;
        iterator& operator=(const iterator&) = default;
        ~iterator()                          = default;

        iterator& operator++()
        {
            node_ = node_->next;
            return *this;
        }

        iterator operator++(int)
        {
            iterator tmp(*this);
                     operator++();
            return tmp;
        }

        iterator& operator--()
        {
            node_ = node_->prev;
            return *this;
        }

        iterator operator--(int)
        {
            iterator tmp(*this);
                     operator--();
            return tmp;
        }

        bool operator==(const iterator& other) const { return node_ == other.node_; }

        bool operator!=(const iterator& other) const { return !(*this == other); }

        T& operator*() const { return node_->data; }

    private:
        Node* node_;
    };

    DoublyLinkedList()
        : head(nullptr)
        , tail(nullptr)
        , size(0)
    {
    }

    ~DoublyLinkedList()
    {
        Node* curr = head;
        while (curr)
        {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    void push_front(const T& data)
    {
        Node* new_node = new Node(data, nullptr, head);
        if (head)
        {
            head->prev = new_node;
        }
        head = new_node;
        if (!tail)
        {
            tail = new_node;
        }
        ++size;
    }

    void push_back(const T& data)
    {
        Node* new_node = new Node(data, tail, nullptr);
        if (tail)
        {
            tail->next = new_node;
        }
        tail = new_node;
        if (!head)
        {
            head = new_node;
        }
        ++size;
    }

    void insert_after(Node* node, const T& data)
    {
        if (!node)
        {
            return;
        }
        Node* new_node = new Node(data, node, node->next);
        node->next     = new_node;
        if (new_node->next)
        {
            new_node->next->prev = new_node;
        }
        else
        {
            tail = new_node;
        }
        ++size;
    }

    void insert_before(Node* node, const T& data)
    {
        if (!node)
        {
            return;
        }
        Node* new_node = new Node(data, node->prev, node);
        node->prev     = new_node;
        if (new_node->prev)
        {
            new_node->prev->next = new_node;
        }
        else
        {
            head = new_node;
        }
        ++size;
    }

    void remove(Node* node)
    {
        if (!node)
        {
            return;
        }
        if (node->prev)
        {
            node->prev->next = node->next;
        }
        else
        {
            head = node->next;
        }
        if (node->next)
        {
            node->next->prev = node->prev;
        }
        else
        {
            tail = node->prev;
        }
        delete node;
        --size;
    }
};
