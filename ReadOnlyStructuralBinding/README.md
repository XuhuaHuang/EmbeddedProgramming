# Structred Bindings

## Binding with `struct`
```C++
struct MyStruct {
    int i = 0;
    std::string s;
};

MyStruct ms;

auto [i,s] = ms;

MyStruct getStruct() {
    return MyStruct {42, "hello"};
}

auto [id,val] = getStruct();
```

## Binding with `key-value pair`
```C++
for (const auto& elem : mymap) {
    std::cout << elem.first << ": " << elem.second << "\n";
}

for (const auto& [key, val] : mymap) {
    std::cout << key << ": " << val << "\n";
}
```
