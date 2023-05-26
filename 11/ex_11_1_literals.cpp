#include <iostream>
using namespace std;

long double operator ""_m(long double m){
    return m;
}
long double operator ""_s(long double s){
    return s;
}
long double operator ""_m(unsigned long long int m){
    return m;
}
long double operator ""_s(unsigned long long int s){
    return s;
}
long double operator ""_km(long double km){
    return km * 1000;
}
long double operator ""_h(long double h){
    return h * 3600;
}
long double operator ""_km(unsigned long long int km){
    return km * 1000;
}
long double operator ""_h(unsigned long long int h){
    return h * 3600;
}
long double operator ""_cm(long double cm){
    return cm / 100;
}
long double operator ""_ms(long double ms){
    return ms / 1000;
}
long double operator ""_cm(unsigned long long int cm){
    return cm / 100.;
}
long double operator ""_ms(unsigned long long int ms){
    return ms / 1000.;
}

/**
    Computes velocity in meters per seconds.
    @param distance  distance in meters
    @param time      time in seconds
    @return velocity in meters per seconds.
*/
double computeVelocity(double distance, double time){
    return distance/time;
}

int main(){
    cout << computeVelocity(100_m, 5_s) << endl;     //20
    cout << computeVelocity(360_km, 2.0_h) << endl;  //50
    cout << computeVelocity(3.6_km, 0.02_h) << endl; //50
    cout << computeVelocity(250_cm, 2.5_ms) << endl; //1000
    return 0;
}
