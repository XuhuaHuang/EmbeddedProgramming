# `StandardTemplateLibrary`

## Data Structures

| Container                    | Implementation                            | Lookup       | Insertion     | Deletion     |
|-----------------------------|--------------------------------------------|--------------|----------------|--------------|
| `std::list`                 | Doubly linked list                         | O(n)         | O(1) (with iterator) | O(1) (with iterator) |
| `std::forward_list`         | Singly linked list                         | O(n)         | O(1) (after node) | O(1) (after node) |
| `std::vector`               | Dynamic array (contiguous)                 | O(1) (random access) / O(n) (search) | O(1) amortized at end / O(n) elsewhere | O(n) |
| `std::deque`                | Double-ended queue (blocks)                | O(1) (random access) | O(1) at front/back | O(1) at front/back |
| `std::set`, `std::map`      | Balanced binary tree (Red-Black tree)      | O(log n)     | O(log n)       | O(log n)     |
| `std::unordered_set`, `std::unordered_map` | Hash table                  | O(1) average / O(n) worst | O(1) avg / O(n) worst | O(1) avg / O(n) worst |
| `std::multiset`, `std::multimap` | Balanced binary tree (Red-Black tree) | O(log n)     | O(log n)       | O(log n)     |
| `std::unordered_multiset`, `std::unordered_multimap` | Hash table        | O(1) average / O(n) worst | O(1) avg / O(n) worst | O(1) avg / O(n) worst |

##  **Quick Algorithm Lookup Table**

| What You Want to Know                                                           |     On a Unsorted Range     |    On a Sorted Range   |   With a set or map  |      With a multiset or multimap      |
|---------------------------------------------------------------------------------|:---------------------------:|:----------------------:|:--------------------:|:-------------------------------------:|
| Does the desired value exist?                                                   |        `std::find()`        | `std::binary_search()` |    `std::count()`    |             `std::find()`             |
| Does the desired value exist? If so, where is the first object with that value? |        `std::find()`        |  `std::equal_range()`  |     `std::find()`    | `std::find()` or `std::lower_bound()` |
| Where is the first object with a value not preceding the desired value?         |       `std::find_if()`      |  `std::lower_bound()`  | `std::lower_bound()` |          `std::lower_bound()`         |
| Where is the first object with a value succeeding the desired value?            |       `std::find_if()`      |   `std:upper_bound()`  |  `std:upper_bound()` |          `std:upper_bound()`          |
| How many objects have the desired value?                                        |        `std::count()`       |  `std::equal_range()`  |    `std::count()`    |             `std::count()`            |
| Where are all the objects with the desired value?                               | `std::find()` (iteratively) |  `std::equal_range()`  | `std::equal_range()` |          `std::equal_range()`         |
