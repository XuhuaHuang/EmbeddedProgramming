# Range, Views and Pipelines

## Automate Input and Output

```cxx
auto read_line = rng::istream_view<mys::Line>(test_file);
auto out_line = std::ostream_iterator<mys::Line>{
    std::cout,
    "\n"
};
```
