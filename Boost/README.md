# `boost`

```cpp
#include <boost/type_index.hpp>
#include <iostream>

template<typename T>
void f(const T& param) {
    using std::cout;
    using boost::typeindex::type_id_with_cvr;

    cout << "T = "
         << type_id_with_cvr<T>().pretty_name() << "\n";

    cout << "param = "
         << type_id_with_cvr<decltype(param)>().pretty_name() << "\n";
}
```
