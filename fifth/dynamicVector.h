//
// Created by Piotr Kubacki on 29.03.2023.
//

#ifndef EFFECTIVEMODERNCPPCOURSE_DYNAMICVECTOR_H
#define EFFECTIVEMODERNCPPCOURSE_DYNAMICVECTOR_H

#include <cstddef>
#include "staticVector.h"
#include <stdexcept>

template<typename T>
class Vector<T,0>{
    std::unique_ptr<T> data;
public:
    typedef T value_type;
    typedef std::size_t  size_type;
    typedef std::unique_ptr<T> pointer;
    typedef T& reference;
    typedef const T& const_reference;
private:
    size_type _size;
public:

    Vector(const Vector& v) : _size(v.size()), data(new value_type[v.size()]){
        for(size_type i=0;i<v.size();++i){
            //data.get()[i]=v.get()[i];
            set(i,v.get(i));
        }
    }

    Vector(const std::initializer_list<value_type> &list) : _size(list.size()),data(new value_type[list.size()]){
        size_type i = 0;
        for(auto item : list){
            this->set(i++,item);
        }
    }
    Vector(size_type size) : _size(size), data(new value_type[size]){
        for(size_type i=0;i<size;++i){
            //data.get()[i]=0;
            this->set(i,0);
        }
    }

    template<size_type n>
    operator Vector<T,n> (){
        Vector<T,n> out;
        for(size_type i=0;i<n;++i){
            out.set(i,get(i));
        }
        return out;
    }

    Vector &operator=(const Vector & m) {
        if(this != m){
            size_type size_of_v = m.size();
            for(int i=0;i<std::min(size_of_v, this->size());++i){
                this->set(i,m.get(i));
            }
        }
    }

    const_reference get(size_type index) const {
        return data.get()[index];
    }

    void set(size_type index, const_reference value) {
        data.get()[index] = value;
    }

    void resize(size_type new_size){
        if(this->data != nullptr) {
            auto old_pointer = this->data.release();
            auto _min = min(this->size(),new_size);
            data.reset(new value_type[new_size]);
            for(size_type i=0;i< _min;++i){
                set(i,old_pointer[i]);
            }
            for(size_type i= _min; i < new_size;++i){
                set(i,0);
            }
            _size = new_size;
        }
        else{
            throw domain_error("cannot resize null data pointer");
        }
    }



    friend Vector operator+ <>(const  Vector & u, const Vector & v );

    [[nodiscard]] constexpr size_type size() const {
        return _size;
    }

    reference operator[](size_type index){
        return data.get()[index];
    }
    const_reference operator[](size_type index) const{
        return data.get()[index];
    }

    friend std::ostream &operator<<(std::ostream &out, const Vector & v) {
        for(size_type i=0;i<v.size();++i){
            out << v.get(i) << " ";
        }
        return out;
    }
};
template<typename T>
Vector<T,0> operator+ (const  Vector<T,0> & u, const Vector<T,0> & v ){
    if(u.size() != v.size()){
        throw invalid_argument("incompatible sizes in Vector::operator+");
    }
    size_t size_of_out = u.size();
    Vector<T,0> out(size_of_out);
    for(size_t i = 0; i<size_of_out; ++i){
        out[i] = u[i] + v[i];
    }
    return out;
}

template<typename T, size_t N>
auto operator +(const Vector<T,0>& u, const Vector<T,N>& v){
    Vector<T,N> out;
    for(size_t i=0;i<N;++i){
        out.set(i,u.get(i) + v.get(i));
    }
    return out;
}
template<typename T, size_t N>
auto operator +(const Vector<T,N>& v,const Vector<T,0>& u){
    return u+v;
}
#endif //EFFECTIVEMODERNCPPCOURSE_DYNAMICVECTOR_H
