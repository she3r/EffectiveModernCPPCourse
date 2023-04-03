
#ifndef STATIC_VECTOR_H
#define STATIC_VECTOR_H


#include <memory>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <cstring>
template <typename T, size_t N>
class Vector;
template <typename T, size_t N>
Vector<T,N> operator+ (const  Vector<T,N> & u, const Vector<T,N> & v );
template <typename T, size_t N>
class Vector{
    T data[N];
public:
    typedef T value_type;
    typedef std::size_t  size_type;
    typedef T* pointer;
    typedef T& reference;
    typedef const T& const_reference;

    Vector() {
        memset(data,0,sizeof(data));
    }
    Vector(const Vector & v) {
        size_type size_of_v = v.size();
        for(int i=0;i<std::min(size_of_v, N);++i){
            set(i,v.get(i));
        }
    }


    Vector(const std::initializer_list<value_type> &list){
        size_type i = 0;
        for(auto item : list){
            if(i < N)
                data[i] = item;
            else {break;}

            i++;
        }
    }
    Vector &operator=(const Vector & m) {
        if(this != m){
            size_type size_of_v = m.size();
            for(int i=0;i<std::min(size_of_v, N);++i){
                data[i] = m.get(i);
            }
        }
    }

    friend Vector operator+ <>(const  Vector & u, const Vector & v );

    [[nodiscard]] constexpr size_type size() const {
        return N;
    }

    const_reference get(size_type index) const {
        return data[index];
    }

    void set(size_type index, const_reference value) {
        data[index] = value;
    }

    reference operator[](size_type index){
        return data[index];
    }
    const_reference operator[](size_type index) const{
        return data[index];
    }

    friend std::ostream &operator<<(std::ostream &out, const Vector & v) {
        for( auto elem: v.data ){
            out << elem << " ";
        }
        return out;
    }

    operator Vector<T,0>(){
        Vector<T,0> out(size());
        for(size_type i=0;i<size();++i){
            out.set(i,get(i));
        }
        return out;
    }
    template<typename S, size_type M>
    operator Vector<S,M>(){
        Vector<S,M> out;
        for(size_type i=0;i<min(N,M);++i){
            out.set(i,static_cast<S>(get(i)));
        }
        for(size_type i=min(N,M);i<M;++i){
            out.set(i,static_cast<S>(0));
        }
        return out;
    }
};
template <typename T, size_t N>
Vector<T,N> operator+ (const  Vector<T,N> & u, const Vector<T,N> & v ){
    Vector<T,N> out{};
    size_t size_of_out = u.size();
    for(size_t i = 0; i<size_of_out; ++i){
        out[i] = u[i] + v[i];
    }
    return out;
}




#endif //STATIC_VECTOR_H