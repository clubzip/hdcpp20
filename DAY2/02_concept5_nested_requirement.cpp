
// requires 안에 다시 requires 가 놓일수 있습니다.

template <class T>
concept Semiregular = DefaultConstructible<T> && 
                      CopyConstructible<T> && 
                      Destructible<T> && 
                      CopyAssignable<T> &&
requires(T a, size_t n)
{
    requires std::same_as<T*, decltype(&a)>;  // nested: "Same<...> evaluates to true"

    { a.~T() } noexcept;  // compound: "a.~T()" is a valid expression that doesn't throw

    requires std::same_as<T*, decltype(new T)>; // nested: "Same<...> evaluates to true"
    requires std::same_as<T*, decltype(new T[n])>; // nested

    { delete new T };       // compound
    { delete[] new T[n] };  // compound
};