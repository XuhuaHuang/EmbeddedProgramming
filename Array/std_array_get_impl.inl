namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_CONTAINER

  template<std::size_t _Int, typename _Tp, std::size_t _Nm>
    constexpr _Tp&
    get(array<_Tp, _Nm>& __arr) noexcept
    {
      static_assert(_Int < _Nm, "array index is within bounds");
      return _GLIBCXX_STD_C::__array_traits<_Tp, _Nm>::
	_S_ref(__arr._M_elems, _Int);
    }

  template<std::size_t _Int, typename _Tp, std::size_t _Nm>
    constexpr _Tp&&
    get(array<_Tp, _Nm>&& __arr) noexcept
    {
      static_assert(_Int < _Nm, "array index is within bounds");
      return std::move(_GLIBCXX_STD_C::get<_Int>(__arr));
    }

  template<std::size_t _Int, typename _Tp, std::size_t _Nm>
    constexpr const _Tp&
    get(const array<_Tp, _Nm>& __arr) noexcept
    {
      static_assert(_Int < _Nm, "array index is within bounds");
      return _GLIBCXX_STD_C::__array_traits<_Tp, _Nm>::
	_S_ref(__arr._M_elems, _Int);
    }

  template<std::size_t _Int, typename _Tp, std::size_t _Nm>
    constexpr const _Tp&&
    get(const array<_Tp, _Nm>&& __arr) noexcept
    {
      static_assert(_Int < _Nm, "array index is within bounds");
      return std::move(_GLIBCXX_STD_C::get<_Int>(__arr));
    }
	
_GLIBCXX_END_NAMESPACE_CONTAINER
} // namespace std
