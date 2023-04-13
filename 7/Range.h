

#ifndef LAB6_RANGE_H
#define LAB6_RANGE_H

#include <iterator> // For std::forward_iterator_tag
#include <cstddef>  // For std::ptrdiff_t
#include <array>


template <typename T>
class Range{
public:
    struct Iterator {
        // tags
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T *;  // or also value_type*
        using reference = T &;  // or also value_type&

        Iterator(reference ref) : p(ref){}

        reference operator*(){return *p;}
        pointer operator->(){return p;}
        Iterator& operator=(const Iterator& iterator){
            if(*this != iterator){
                this->p=iterator.p;
            }
        }
        Iterator& operator++(){p++;}
        Iterator operator++(int){Iterator tmp=*this;++(*this);return tmp;}

        friend bool operator==(const Iterator& a, const Iterator&b){return a.p==b.p;}
        friend bool operator!=(const Iterator& a, const Iterator&b){return a.p!=b.p;}

    private:
        pointer p;

    };
    Iterator begin(){ return Iterator(&arr[0]);}
    Iterator end(){ return Iterator(&arr[size()]);}

    size_t size(){ if(shift%2==0) return (stop-start)/shift; else return (stop-start)/shift + 1;}

    Range(T start, T stop, T shift) : start(start),stop(stop),shift(shift),arr(new T[size()]){
        T curr=start;
        for(T i=0;i<stop;i++){
            arr[i]=curr;
            curr+=shift;
        }
    }
private:
    T start;
    T stop;
    T shift;
    T* arr;
};


#endif //LAB6_RANGE_H
