# `Helper`

[![wakatime](https://wakatime.com/badge/user/f89598ea-6723-481b-a51b-6323e54a3c5c/project/911ba89d-f587-4c4b-a161-9ebc246f2b34.svg)][wakatime_project_status]


[wakatime_project_status]: https://wakatime.com/badge/user/f89598ea-6723-481b-a51b-6323e54a3c5c/project/911ba89d-f587-4c4b-a161-9ebc246f2b34

```cpp
// <xstddef>
// originally exstd.h
_EXPORT_STD template <class _Ty = void>
struct plus {
    using _FIRST_ARGUMENT_TYPE_NAME _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS  = _Ty;
    using _SECOND_ARGUMENT_TYPE_NAME _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS = _Ty;
    using _RESULT_TYPE_NAME _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS          = _Ty;

    _NODISCARD constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const {
        return _Left + _Right;
    }
};
```

```cpp
// std::integral_constant<T, t>
_STD_BEGIN
_EXPORT_STD template <class _Ty, _Ty _Val>
struct integral_constant {
    static constexpr _Ty value = _Val;

    using value_type = _Ty;
    using type       = integral_constant;

    constexpr operator value_type() const noexcept {
        return value;
    }

    _NODISCARD constexpr value_type operator()() const noexcept {
        return value;
    }
};
```
