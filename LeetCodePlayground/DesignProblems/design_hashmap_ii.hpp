#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <utility>
#include <vector>

template<typename KeyType, typename ValueType>
class HashNode
{
public:
    KeyType                       key;
    ValueType                     value;
    HashNode<KeyType, ValueType>* next;
    HashNode(const KeyType& key, const ValueType& value)
        : key(key)
        , value(value)
        , next(nullptr)
    {
    }
    ~HashNode()
    {
        if (next != nullptr)
        {
            delete next;
        }
    }
};

template<typename KeyType, typename ValueType, typename Hash = std::hash<KeyType>>
class HashMap
{
public:
    using key_type        = KeyType;
    using mapped_type     = ValueType;
    using value_type      = std::pair<const KeyType, ValueType>;
    using size_type       = std::size_t;
    using difference_type = std::ptrdiff_t;
    using hasher          = Hash;
    using reference       = value_type&;
    using const_reference = const value_type&;

private:
    std::vector<std::list<HashNode<KeyType, ValueType>*>> buckets;
    size_type                                             num_elements;
    hasher                                                hash_function;

public:
    HashMap(size_type bucket_count = 10, const hasher& hash_fn = hasher())
        : buckets(bucket_count)
        , num_elements(0)
        , hash_function(hash_fn)
    {
    }

    ~HashMap() { clear(); }

    size_type size() const { return num_elements; }

    bool empty() const { return num_elements == 0; }

    void clear()
    {
        for (auto& bucket : buckets)
        {
            for (auto& node : bucket)
            {
                delete node;
            }
            bucket.clear();
        }
        num_elements = 0;
    }

    void insert(const value_type& value)
    {
        const KeyType& key          = value.first;
        size_type      bucket_index = hash_function(key) % buckets.size();
        for (auto& node : buckets[bucket_index])
        {
            if (node->key == key)
            {
                node->value = value.second;
                return;
            }
        }
        HashNode<KeyType, ValueType>* node = new HashNode<KeyType, ValueType>(key, value.second);
        buckets[bucket_index].push_front(node);
        ++num_elements;
    }

    void erase(const KeyType& key)
    {
        size_type bucket_index = hash_function(key) % buckets.size();
        auto&     bucket       = buckets[bucket_index];
        auto      iter         = std::find_if(
            bucket.begin(), bucket.end(), [&](const HashNode<KeyType, ValueType>* node) { return node->key == key; });
        if (iter != bucket.end())
        {
            delete *iter;
            bucket.erase(iter);
            --num_elements;
        }
    }

    ValueType& operator[](const KeyType& key)
    {
        size_type bucket_index = hash_function(key) % buckets.size();
        for (auto& node : buckets[bucket_index])
        {
            if (node->key == key)
            {
                return node->value;
            }
        }
        HashNode<KeyType, ValueType>* node = new HashNode<KeyType, ValueType>(key, ValueType());
        buckets[bucket_index].push_front(node);
        ++num_elements;
        return node->value;
    }

    const ValueType& at(const KeyType& key) const
    {
        size_type bucket_index = hash_function(key) % buckets.size();
        for (const auto& node : buckets[bucket_index])
        {
            if (node->key == key)
            {
                return node->value;
            }
        }
        throw std::out_of_range("Key not found");
    }
};
