# Range, Views and Pipelines

## Automate Input and Output

```cxx
auto read_line = rng::istream_view<mys::Line>(test_file);
auto out_line = std::ostream_iterator<mys::Line>{
    std::cout,
    "\n"
};
```

**Filter Output for Command Lines**

```cxx
using rng = std::ranges;
using vws = std::views;

auto is_cmd = [](mys::Line const& line) {
    return line.mLine[0] == '$';
};

// filter view selects for command lines
rng::copy(rng::filter_view(read_line, is_cmd),
    out_line);

// copy only the first 5 command line
rng::copy(
    rng::take_view(
        rng::filter_view(read_line, is_cmd),
        5
    ),
    out_line
);

// change from std::ranges to std::views
// drop the _view in the names
rng::copy(
    vws::take(
        vws::filter(read_line, is_cmd),
        5
    ),
    out_line
);

// pipeline the views
auto commands = read_line
    | vws::filter(is_cmd)
    | vws::take(5);
rng::copy(commands, out_line);
```

**Utilities `emit` to Peek into a Pipeline**

```cxx
auto emit = [](char const delim = sp) {
    return vws::filter(
        [delim](auto&& value) noexcept {
            std::cout << value << delim;
            return true;
        }
    );
};
auto emit_nl = emit(mys::nl);
auto emit_tab = emit(mys::tab);
```

`eval_view` and `eval`

```cxx
struct eval {
    friend auto operator|(rng::input_range auto&& view, eval) noexcept {
        for (auto _ : view);
    }
};
```
