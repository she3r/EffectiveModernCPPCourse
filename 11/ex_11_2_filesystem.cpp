#include <string_view>
#include <filesystem>
#include <iostream>
#include <regex>
#include <cmath>

using namespace std;
namespace fs = std::filesystem;

// https://en.cppreference.com/w/cpp/filesystem/file_size
struct HumanReadable {
    std::uintmax_t size{};
private: friend
    std::ostream& operator<<(std::ostream& os, HumanReadable hr) {
        int i{};
        double mantissa = hr.size;
        for (; mantissa >= 1024.; mantissa /= 1024., ++i) { }
        mantissa = std::ceil(mantissa * 10.) / 10.;
        os << mantissa << "BKMGTPE"[i];
        return i == 0 ? os : os << "B (" << hr.size << ')';
    }
};
/**
 * Prints content of directory given by path
 * Format
 * [X] file_name file_size
 * where X equals D for directories, F for regular files, L for symlinks and space otherwise.
 * @param path directory path
 */
void printDirectory (std::string_view path){
    fs::path dirPath{path};
    for (const auto & entry : fs::directory_iterator(path)) {
        if (fs::is_directory(entry)) cout << "D ";
        else if (fs::is_regular_file(entry)) cout << "F ";
        else if (fs::is_symlink(entry)) cout << "L ";
        else cout << " ";
        std::cout << entry.path() << " ";
        try {
            std::uintmax_t size = std::filesystem::file_size(entry);
            std::cout << HumanReadable{size} << std::endl;
        }
        catch(fs::filesystem_error& error){
            if(!error.path1().empty()) // file name that caused problems
                cout << "cannot get file size" <<endl;
        }
    }
}

template<class T>
T base_name(T const & path, T const & delims = "//")
{
    return path.substr(path.find_last_of(delims) + 1);
}
template<class T>
T remove_extension(T const & filename)
{
    typename T::size_type const p(filename.find_last_of('.'));
    return p > 0 && p != T::npos ? filename.substr(0, p) : filename;
}

/**
 * Makes copies of all files matching fileNames regular expression in directory given by path
 * to files in the same directory but with changes extension to newExtension
 * @param path directory path
 * @param fileNames regular expression
 * @param newExtension new extension
 */
void changeExtension(const fs::path& path, const std::string& fileNames, std::string_view newExtension ){
    const std::regex re(fileNames);
       for (const auto & entry : fs::directory_iterator(path)){
           auto filename = base_name(entry.path().string());
        if(std::regex_match(filename,re)){
            fs::path fileToCopy = entry; // make copy of path to source file
            fileToCopy.replace_extension(newExtension); // change extension
            cout<<"copy to: " << fileToCopy.string() << endl;
            fs::copy_file(entry,fileToCopy); // pass full paths
        }
    }
}

void test_1(){
    fs::path filePath{(fs::current_path() / "Testing")};
    try{
        printDirectory(filePath.string());
    }
    catch(fs::filesystem_error& error){
        cout << "Exception : " <<   error.what() << endl;
        if(!error.path1().empty()) // file name that caused problems
            cout << "file name : " << error.path1() << endl;
    }
}

void test_2(){
    fs::path filePath{(fs::current_path() / "Testing")};    // cmake-build-debug/Testing     for clion
    auto re = "^(test)(.*)\\.(.*)"; // SOString-test-anything-dot-anything
    auto newExtension = "x";    // change ext to 'x'
    try{
        changeExtension(filePath,re,newExtension);
    }
    catch(fs::filesystem_error& error){
        cout << "Exception : " <<   error.what() << endl;
        if(!error.path1().empty()) // file name that caused problems
            cout << "file name : " << error.path1() << endl;
    }
}

int main(){
    test_1();
    test_2();
}