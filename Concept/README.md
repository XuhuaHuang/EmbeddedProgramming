# Concept
Concepts are a compacy way constraining template paeameters to have certain properties

```C++
template<typename T>
concept Addable = requires (T t) {
    t + t;
}

template<Addable T>
void HelloAdd(T t) { std::cout << "hello\n"; }

template<typename U>
void HelloAdd(U u) { std::cout << "goodbye\n"; }

HelloAdd(42); // "hello"
HelloAdd(std::vector<int>{}); // "goodbye"
```

An alternative way constraining the same could be also implemented in the following:
```C++
template<typename T>
    requires Addable<T>
void HelloAdd(T t) {
    std::cout << "hello\n";
}
```

## Concept and partial specialization
Concepts can be *used* as part of a partial specialization
```C++
template<typename T>
    requires std::unsigned_integral<T>
struct A<T> {
    void print() const { std::cout << "unsigned\n"; }
};
```
