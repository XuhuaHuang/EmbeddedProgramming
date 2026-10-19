## Standalone AST Printing

```bash
clang -Xclang -ast-print -fsyntax-only test.cc
clang -Xclang -ast-list -fsyntax-only test.cc
clang -Xclang -ast-dump -fsyntax-only test.cc
```

## With `CMake`

```bash
cmake -S AbstractSyntaxTree -B build -G Ninja
cmake --build build
./build/ast_demo 420
```
