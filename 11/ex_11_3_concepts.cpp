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

template <typename  T>
class A{
protected:
    T x;
public:
    A(T x = T()) : x(x) {}
    void print() const{
      cout << "[" << x << "]";
    }

};

template <typename T>
class B: public A<T>{
public:
    using A<T>::A;
    friend std::ostream & operator<<(std::ostream & out, const B & b){
      return (out << "#" << b.x << "#");
    }
    friend B operator+(const B & a, const B & b){
      return a.x + b.x;
    }
};

template <class T>
concept subscriptable = requires(const T& c) { c[0]; };

template<typename T>
concept addable = requires(T a, T b){{ a + b } -> same_as<decltype(a)>;};

template <typename T>
concept Container =  requires (T a, T b){
  begin(a);
  end(a);
  subscriptable<T>;
  addable<decltype(*begin(a))>;
  hasValueType_v<T>;
};

template <typename T>
concept Printable = requires(const T a){
  a.print();
};

template <typename T>
concept Printable2 = requires(const T a){
  cout << a;
};

template <typename T>
concept Printable3 = Printable<T> && Printable2<T>;

auto print(const Printable2 auto & p){
  cout << p << endl;
}

auto print(const Printable auto & p){
  p.print();
  cout << endl;
}

auto print(const Printable3 auto & p){
  cout << p << endl;
}


auto print(const Container auto & v){
  for(int i =0; const auto & el : v){
    cout << i << " : ";
    print(el);
    i++;
  }
  cout << "-------\n";
}

template <Container C>
auto sum(const C & v){
    typename C::value_type sum{};
    for(const auto & el: v){
      sum = sum + el;
    }
    return sum;
}

using namespace std;
int main() {
  vector v{1,2,4,5};
  print(v);
  A<int> a{5};
  print(a);
  B<double> b{3.14};
  print(b);
  print(2.7);
  vector<A<int>> va{ 4, 5, 7, 9};
  vector<B<int>> vb{ 4, 5, 7, 9};
  print(va);
  print(vb);
  print( sum(v) );
 //  print( sum(va) );   // no matching function sum
  print( sum(vb) );
  return 0;
}
/**
* Expected output
0 : 1
1 : 2
2 : 4
3 : 5
-------
[5]
#3.14#
2.7
0 : [4]
1 : [5]
2 : [7]
3 : [9]
-------
0 : #4#
1 : #5#
2 : #7#
3 : #9#
-------
12
#25#
*/
