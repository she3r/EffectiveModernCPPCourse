#include <iostream>
#include <vector>
#include <utility>
#include <array>
#include <numeric>

using namespace std;

int f(int x){
  return x*x;
}
int cube(int x){
  return x*x*x;
}

template<typename Func>
auto computeSum(Func func) {return 0;}

template<typename Func, typename T, typename... Args>
auto computeSum(Func func, T first, Args... args) {
    return func(first) + computeSum(func,args...);
}

template <typename T, typename Alloc,
        template<typename, typename> class Container, typename S>
void insert(Container<T,Alloc>& container, S first){
    container.push_back(first);
}
template <typename T, typename Alloc,
        template<typename, typename> class Container, typename S, typename...Args>
void insert(Container<T,Alloc>& container,S first, Args...args) {
    container.push_back(first);
    insert(container,args...);
}
template<class ... Args>
double average(Args ... args)
{
    const int numArgs = sizeof...(args);
    if (numArgs == 0)
        return 0;
    double sum = computeSum([](auto a){return a;},args...);
    return sum / numArgs;
}


int main(){

    cout << average(1, 2) << endl;                    // 1.5
    cout << average(1.0, 10, 1, 34.5f, 12u) << endl;  // 11.7
    cout << computeSum(f, 1, 2, 3, 4) << endl;        // f(1)+f(2)+f(3)+f(4) = 30
    cout << computeSum(cube, 1, 2, 3, 4) << endl;     // 1^3 + 2^3 + 3^3 + 4^3 = 100

    std::vector<int> v;
    insert(v, 1, 2, 3, 4, 5, 6);
    insert(v, 7, 8);

    for(auto x: v)                              //1 2 3 4 5 6 7 8
        cout << x << " ";

}