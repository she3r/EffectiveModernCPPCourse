#include <iostream>
#include <algorithm>
#include <cstring>
#include <memory>
#include "MyString.h"
using namespace std;

class String{
   using string = emcpp::MyString;
//    using string = std::string;
    std::shared_ptr<string> s= nullptr;
/// Store a pointer to dynamically allocated string!

public:
    String();     /// creates an empty string
    String(const char * str);           /// copy C-string
    String(const String & s);            /// no copy
    String operator=(const String & other); /// no copy
    /// makes a copy of a string if it has more than one reference.
    void set(int index, char ch);
    /// no copy
    [[nodiscard]] char get(int index) const;
    /// creates a new string only if both strings are non empty
    friend String operator+(const String& a, const String& b);
    friend std::ostream & operator<< (std::ostream & out, const String& s);
};

String::String() : s(new string()){}

String::String(const char *str) : s(new string(str)) {}

String::String(const String &s) : s(s.s){}

String String::operator=(const String &other) {
    if(this != &other){
        s = other.s;
    }
    return *this;
}

void String::set(int index, char ch) {
    if(s == nullptr){
        return;
    }
    unsigned i = s.use_count();
    if(i > 1){
        //string new_instance = *s;
        //new_instance[index] = ch;
        //s = std::make_shared<string>(new_instance);
        s = std::make_shared<string>(*s);
    }
    s->at(index) = ch;
}

char String::get(int index) const {
    return s->at(index);
}

String operator+(const String& a, const String& b) {
    if(a.s and b.s and !(*a.s).empty() and !(*b.s).empty()){
        string out;
        if(a.s){
            out += *a.s;
        }
        if(b.s){
            out += *b.s;
        }
        return *new String(out.c_str());
    }
    if(a.s and !(*a.s).empty()){
        return *new String(a);
    }
    if(b.s and !(*b.s).empty()){
        return *new String(b);
    }
    return {};

}

std::ostream &operator<<(ostream &out, const String& s) {
    out << *s.s;
    return out;
}
// sharing ownership with new pointer








