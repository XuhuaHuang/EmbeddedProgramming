// C++ program to convert whole string to 
// uppercase or lowercase using STL.

#include<bits/stdc++.h> 

using namespace std; 
  
int main(void) 
{ 
    // str1 is the string which is converted to uppercase 
    string str1 = "Xuhua"; 
  
    // using transform() function and ::toupper in STL 
    transform(str1.begin(), str1.end(), str.begin(), ::toupper); 
    cout << str1 << endl; // XUHUA
  
    // str2 is the string which is converted to lowercase 
    string str2 = "Huang"; 
  
    // using transform() function and ::tolower in STL 
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower); 
    cout << str2 << endl;  // "huang"
  
    return 0; 
} 
