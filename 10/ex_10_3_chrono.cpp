#include <iostream>
#include <chrono>
#include <string>
#include <iomanip>      // std::setprecision



class Timer{
   std::string name;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_beg;

public:
   Timer(const std::string & name) : name(name), m_beg(std::chrono::high_resolution_clock::now()){
   }
   ~Timer(){
       auto end = std::chrono::high_resolution_clock::now();
       auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - m_beg);
       std::cout << std::setprecision(12) << name << " : " << duration_ms.count() << " ms. " << std::endl;
   }
   auto durationInNanoseconds(){
       auto end = std::chrono::high_resolution_clock::now();
       auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - m_beg);
       return duration_ns.count();
   }

};

long fibonacci(unsigned n){
    if (n < 2) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{

    Timer total("Total time");
    for(auto n : {1, 5, 15, 20, 25, 40, 45}){
        {
            Timer t("fibonacci(" + std::to_string(n) + ")");  // RAII
            fibonacci(n);

        }
    //2
    //3
    }
    std::cout << "Elapsed " << total.durationInNanoseconds() << " ns.\n";
}
/** Expected output similar to:

fibonacci(1) : 0.000619 ms.
fibonacci(5) : 0.000891 ms.
fibonacci(15) : 0.01025 ms.
fibonacci(20) : 0.094905 ms.
fibonacci(25) : 1.04443 ms.
fibonacci(40) : 989.97 ms.
fibonacci(45) : 8537.47 ms.
Elapsed 9528821533 ns.
Total time : 9528.84 ms.
*/