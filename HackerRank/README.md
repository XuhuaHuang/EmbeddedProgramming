### Directory `EmbeddedProgramming/HackerRank`

[Profile](https://www.hackerrank.com/XuhuaHuang?hr_r=1)

#### C++ Notes Section

---

**Print Number of Digits after Decimal Point**
```C++
#include <iostream>
#include <iomanip>

int main(int argc, char** argv)
{
    /* Set 6 digits after decimal point */
    std::cout << std::fixed;
    std::cout << std::setprecision(6); 
}
```

---

**Access Individual Character in a `std::string` and `putchar()`**  
`std::string.at()` is a member function of class `std::string`;  
takes an integer as index, returns the character at such position.  
```C++
// string::at
#include <iostream>
#include <string>

int main ()
{
    std::string str("Test string");
    for (unsigned i=0; i<str.length(); ++i)
    {
        std::cout << std::quoted(str.at(i));
        // alternate way to print to the console:
        // putchar(str.at(i));
    }
    return 0;
}
```

Function `putchar()` acts like `std::cout`;  
prints parsed argument to the console, as it 'puts' the character there.

---

**Determine the Casing of a Character with `isupper()` and `islower()`**  
Prototype: `int isupper(int c);`  
Checks if parameter `c` is an uppercase alphabetic letter.  
Returns `true` or `1` if the parameter `c` is indeed uppercase.  
Similarly:  
* `islower();`
* `isalpha();`
* `toupper();`
* `tolower();`

---

