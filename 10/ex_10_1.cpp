#include <type_traits>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct hasSize{
    typedef char Yes[1];
    typedef char No[2];
    template <typename U> static Yes& test(typename std::enable_if<std::is_member_function_pointer<decltype(&U::size)>::value,bool>::type);
    // This overload is always in the set of overloads: ellipsis
// parameter has the lowest ranking for overload resolution
    template <typename U> static No& test(...);
    static bool const value = sizeof(test<typename std::remove_cv<T>::type>(0)) == sizeof(Yes&);
    // remove_cv == remove const volatile
};


template <typename... Ts>
using voidT = void;

// Primary template
template <typename T, typename = void>
struct hasValueType : std::false_type {};

// Partial specialization (only for types with foobar member type)
template <typename T>
struct hasValueType<T, voidT<typename T::value_type>>
        : std::true_type {};

template <typename T>
inline constexpr bool hasValueType_v = hasValueType<T>::value;

template<typename T>
inline constexpr bool hasSize_v = hasSize<T>::value;


struct v1 {
// c++20
//    template<typename T>
//    static size_t getSize(const T x) requires hasValueType_v<T> && hasSize_v<T> {
//        return x.size() * sizeof(typename T::value_type);
//    }
//
//    template<typename T>
//    static size_t getSize(const T x) requires (!hasValueType_v<T>) || (!hasSize_v<T> ) {
//        return sizeof(x);
//    }
    template<typename T>
    static size_t getSize(const T& x, std::enable_if_t<hasSize_v<T> & hasValueType_v<T>,int> =0)  {
        return x.size() * sizeof(typename T::value_type);
    }
    template<typename T>
    static size_t getSize(const T& x, std::enable_if_t<!hasSize_v<T> || !hasValueType_v<T>,int> =0)  {
        return sizeof(x);
    }
};

struct v2{
    template<typename T>
    static size_t getSize(const T& x){
        if constexpr (hasSize_v<T> && hasValueType_v<T>){
            return x.size() * sizeof(typename T::value_type);
        }
        else{
            return sizeof(x);
        }
    }
};

int main(){
    cout << hasValueType_v< int > << endl;// false
    cout << hasValueType_v< vector<int> > << endl; //true
    cout << hasValueType_v< int > << endl;// false
    cout << hasValueType_v< vector<int> > << endl; //true

    std::vector<int> v{1,2,3,4,5};
    cout << v1::getSize(5) << endl;// 4
    cout << v1::getSize(v) << endl; // 20
    cout << v2::getSize(5) << endl;
// 4
    cout << v2::getSize(v) << endl; // 20
}