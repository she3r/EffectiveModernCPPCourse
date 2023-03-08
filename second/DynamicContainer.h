#pragma once
#include <iostream>
#include <memory>
#include "Box.h"
using namespace std;
class Container{
    // Exercise 2: Use smart pointer.
//    Box * pbox = nullptr;
    std::unique_ptr<Box> pbox;
public:
    static bool verbose;
    explicit Container(int content): pbox(new Box(content)){
        if(verbose) cout << "Creating Container" << endl;
        pbox->setContent(content);
    }
    Container(const Container & container): pbox(new Box{*(container.pbox)}){
        if(verbose) cout << "Creating copy of Container\n";
    }
    Container(Container&& container)  noexcept : pbox(container.pbox.release()) {}
    Container& operator=(Container&& container) noexcept {
        std::swap(container.pbox,pbox);
        return *this;
    }

    Container & operator=(const Container &container){
        if(this != &container) {
            if(verbose) cout << "Copying Container\n";
            *pbox = *container.pbox;
        }
        return *this;
    }
    ~Container(){
        if(verbose) cout << "Destroying Container \n";
        pbox.reset();
    }
    friend Container operator+(const Container & p1, const Container & p2);
    friend std::ostream & operator << (std::ostream & out, const Container & p){
        return (out << " [" << p.pbox->getContent() << "] ");
    }
};

bool Container::verbose = false;

inline Container operator+(const Container & p1, const Container & p2){
    Container suma(p1.pbox->getContent() + p2.pbox->getContent());
    return suma;
}
