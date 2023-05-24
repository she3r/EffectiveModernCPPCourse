#include <iterator>
#include <list>
#include <vector>
#include <iostream>
using namespace std;
//
// Created by user on 24.05.23.
//

template<class C>
        double median(C& collection){
            typedef typename std::iterator_traits<typename C::iterator>::iterator_category category;
            size_t n = collection.size() / 2;
            if constexpr (std::is_same_v<category, std::random_access_iterator_tag>) {
                cout << "random access iterator version" << endl;

                nth_element(collection.begin(), collection.begin()+n, collection.end());
                return collection[n];
            }
            else{
                cout << "no random access iterator version" << endl;
                collection.sort();
                auto it = collection.begin();
                std::advance(it,n);
                return *it;
            }
        }


int main(){
    std::list<int> a{3, 2, 5, 1, 4};
    cout << median(a) << endl; // 3
    std::vector<int> v{3, 1, 4, 2};
    cout << median(v) << endl; // 2.5

}