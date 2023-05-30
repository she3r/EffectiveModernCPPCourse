#include <iterator>
#include <list>
#include <vector>
#include <iostream>
using namespace std;
//
// Created by user on 24.05.23.
//



template<class C>
double median_(C& collection, std::random_access_iterator_tag) {

    size_t n = collection.size() / 2;
    cout << "random access iterator version" << endl;

    nth_element(collection.begin(), collection.begin() + n, collection.end());
    if (collection.size() % 2 != 0)
        return collection[n];
    else {
        double a = collection[n];
        nth_element(collection.begin(), collection.begin() + (n - 1), collection.end());
        return (a + collection[n - 1]) / 2;
    }
}
template<class C>
double median_(C& collection, std::forward_iterator_tag){
        cout << "no random access iterator version" << endl;
        size_t n = collection.size() / 2;
        collection.sort();
        if(collection.size() % 2 != 0) {
            auto it = collection.begin();
            std::advance(it, n);
            return *it;
        }
        else{
            auto it = collection.begin();
            std::advance(it, n-1);
            double a = *it;
            std::advance(it,1);
            return (a + *it) / 2;
        }

}
template<class Container>
double median(Container& container){
    typename std::iterator_traits<typename Container::iterator>::iterator_category category;
    return median_(container, category);
}


int main(){
    std::list<int> a{3, 2, 5, 1, 4};
    cout << median(a) << endl; // 3
    std::vector<int> v{3, 1, 4, 2};
    cout << median(v) << endl; // 2.5

}