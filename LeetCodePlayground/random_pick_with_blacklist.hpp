// https://leetcode.com/problems/random-pick-with-blacklist

class Solution
{
public:
    Solution(int n, const vector<int>& blacklist)
        : whitelist_size{n - (int)blacklist.size()}
        , dist(0, whitelist_size - 1)
    {
        unordered_set<int> whitelist_set;

        for (int i = whitelist_size; i < n; ++i)
        {
            whitelist_set.insert(i);
        }

        for (auto black_num : blacklist)
        {
            if (auto it = whitelist_set.find(black_num); it != whitelist_set.end())
            {
                whitelist_set.erase(it);
            }
        }

        auto it = whitelist_set.begin();

        for (auto black_num : blacklist)
        {
            if (black_num < whitelist_size)
            {
                index_map[black_num] = *it;
                ++it;
            }
        }
    }

    auto pick() -> int
    {
        auto random_index = dist(gen);
        return index_map.find(random_index) != index_map.end() ? index_map[random_index] : random_index;
    }

private:
    int                     whitelist_size;
    unordered_map<int, int> index_map;

    std::random_device              rd;
    std::mt19937                    gen{rd()};
    std::uniform_int_distribution<> dist;
};
