# `std::valarray`

```powershell
cl .\valarray_notes.cpp /std:c++latest /EHsc
```

output:
  * `valarray_notes.exe`
  * `valarray_notes.obj`

execution and output

```powershell
.\valarray_notes.exe
```

```powershell
65 [0, 1, 2, 3, 4]
71 [0, 1, 4, 9, 16]
75 v3 is of type std::valarray<int>: true
76 [0, 2, 6, 12, 20]
79 v4 is of type std::valarray<int>: true
80 [0, 1, 3, 6, 10]
84 [1, 2, 3, 4, 5]
88 sum of v: 15
92 [1, 4, 9, 16, 25]
96 dot product of v and v_squared: 225
```
