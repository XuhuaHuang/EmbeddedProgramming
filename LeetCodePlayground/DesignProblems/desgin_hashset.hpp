// https://leetcode.com/problems/design-hashset

#include <list>
#include <vector>

class MyHashSet
{
private:
    int                         prime;
    std::vector<std::list<int>> table;

    int hash(int key) { return key % prime; }

    std::list<int>::iterator search(int key)
    {
        int h = hash(key);
        return std::find(table[h].begin(), table[h].end(), key);
    }

public:
    MyHashSet()
        : prime(10007)
        , table(prime)
    {
    }

    void add(int key)
    {
        int h = hash(key);
        if (!contains(key))
        {
            table[h].push_back(key);
        }
    }

    void remove(int key)
    {
        int  h  = hash(key);
        auto it = search(key);
        if (it != table[h].end())
        {
            table[h].erase(it);
        }
    }

    bool contains(int key)
    {
        int h = hash(key);
        return search(key) != table[h].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
