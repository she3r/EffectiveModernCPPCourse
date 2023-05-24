#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>
#include <functional>
#include <optional>

using namespace std;
/**
 * Trie structure
 *
 * HINT: use std::map to implement it!
 *       My implementation adds less than 25 lines of code. 
 */
class Trie{
  map<std::string,Trie> tries;
public:
    static void printSentence(const std::vector<std::string>  & sentence ){
        for(const auto & w : sentence)
            cout << w << " ";
    }
    template<typename It>
    void insert(It it_start, It it_end){
        if(it_start == it_end)
            return;
        tries[*it_start].insert(next(it_start),it_end);
        // dodaje rekurencyjnie przechodzac po zdaniu slowo1 -> slowo2 -> slowo3
    }
    void add(const std::vector<std::string>  & sentence ){
       cout << "Adding : ";
       printSentence(sentence);
       cout << "\n";
       insert(begin(sentence),end(sentence));
    }
    void print(std::vector<std::string>  & v )const{
        if(tries.empty()){  // drukowanie DFS
            copy(begin(v), end(v),
                 std::ostream_iterator<std::string>(cout," "));
            cout<<endl;
        }
        for(const auto& trie: tries){   // przechodzenie DFS
            v.push_back(trie.first);
            trie.second.print(v);
            v.pop_back();
        }
    }
    void print() const{
        vector<std::string> v;
        print(v);
    }
    template<typename It>
    optional<reference_wrapper<const Trie>> subtrie(It it_start,It it_stop){
        if(it_start == it_stop){return ref(*this);}
        // np. dostepne sa {a,b,c}, {a,b,d,e}. input: {a,b} zwroci referencje do wezla ktory daje dostep do obu
        auto found = tries.find(*it_start);
        if(found == end(tries)){return {};} // jesli nie znaleziono to zwroc pusty wynik
        return found->second.subtrie(next(it_start),it_stop);   // przesuwamy sie po drzewie w kierunku wyznaczonym przez iterator it_start
    }
    auto subtrie(const std::vector<string>& v){
        return subtrie(begin(v),end(v));
    }

    void load(const std::string & fileName){
        ifstream file(fileName);
        if(!file){
            cerr << "Error when openning file " << fileName << endl;
            return;
        }
        string word;
        vector<string> sentence;
        while( file >> word) {
            sentence.push_back(word);
            // is it end of the sentence?
            if(word.find_last_of('.') != string::npos) {
                add(sentence);
                sentence.clear();
            }
        }
    }
    void printPossibleEndings(const std::initializer_list<std::string>& v){
        cout<<endl;
        cout << "Endings for \"";
        printSentence(v);
        cout << "\" are :\n";
        auto subtree(this->subtrie(v));
        if(subtree){
            subtree->get().print();  // getter dla reference wrapper
        }
    }


};


int main(){
    Trie dictionary;
    dictionary.load("/home/user/CLionProjects/EffectiveModernCPPCourse/9/sample.txt");
    //dictionary.load("hamletEN.txt");

    dictionary.printPossibleEndings({"Curiosity"});
    dictionary.printPossibleEndings({"Curiosity", "killed"});
    dictionary.printPossibleEndings({"The", "mouse","was","killed"});

    /* cout << "Beginning of sentence (ended with single .): ";
    string word;
    vector<string> sentence;
    while(true){
        cin >> word;
        if(word == ".")
            break;
        sentence.push_back(word);
        dictionary.printPossibleEndings(sentence);
    }*/
    return 0;
}
/* Expected output:
Adding : Curiosity killed the cat.
Adding : Curiosity killed the mouse.
Adding : Curiosity saved the cat.
Adding : Curiosity killed the cat and the mouse.
Adding : The cat was killed by curiosity.
Adding : The mouse was killed by cat.
Adding : The mouse was killed by curiosity.
Endings for "Curiosity " are :
 > killed the cat.
 > killed the mouse.
 > killed the cat and the mouse.
 > saved the cat.

Endings for "Curiosity killed " are :
 > killed the cat.
 > killed the mouse.
 > killed the cat and the mouse.

Endings for "The mouse was killed " are :
 > by cat.
 > by curiosity.

 */