#include <iostream>
#include <vector>
#include <memory>
#include <map>
using namespace std;

template<typename...Vars>
class MultiVector;

template<typename Var, typename...Vars>
class MultiVector<Var,Vars...> : public MultiVector<Vars...>{
private:
    vector<Var> data;
public:
    //using MultiVector<Vars...>::print;
    using MultiVector<Vars...>::push_back;
    void push_back(Var v){
        data.push_back(v);
    }
    void print() override{

        cout<<"[ ";
        for(const auto& item:data){
            cout<<item<<" ";
        }
        cout<<" ] ";
        MultiVector<Vars...>::print();
    }
};

template<>
class MultiVector<>{
public:
    void push_back(){}

    virtual void print(){cout<<endl;}
};

int main(){

  MultiVector<int, string, double> m;
  m.push_back(5);
  m.push_back(string("text"));
  m.push_back(7);
  m.push_back(1.2);
  m.print();   // [ 5 7 ] [ text ] [ 1.2 ]
  auto v = std::move(m);
  for(auto x: { 1, 2, 3}){
	v.push_back(x+10);
	v.push_back(std::to_string(x));
	v.push_back(x/10.0);
  }
  m.print(); // [ ] [ ] [ ]   but can be undefined
  v.print(); // [ 5 7 11 12 13 ] [ text 1 2 3 ] [ 1.2 0.1 0.2 0.3 ]
  MultiVector<int, int, double, int> w;
  w.push_back(1);
  w.push_back(2.0);
  w.print(); // [ 1 ] [ ] [ 2 ] [ ]
}
/*
[ 5 7 ] [ text ] [ 1.2 ]
[ ] [ ] [ ]
[ 5 7 11 12 13 ] [ text 1 2 3 ] [ 1.2 0.1 0.2 0.3 ]
[ 1 ] [ ] [ 2 ] [ ]  
 */