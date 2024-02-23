
/*reda and display paragraph using unformatted get*/
#include<iostream>
#include<iomanip>
#include<fstream>

int main(){
    std::ifstream in_file;
    in_file.open("sample1.txt");
    if(!in_file){
        std::cerr<<"problem in opening file"<<std::endl;
        return 1;
    }
    char c;
    while(in_file.get(c)){//reading in unformatted or character manner is one thing like no matter of spaces special character nothing  easly read
        std::cout<<c;
    }
    std::cout<<std::endl;
    in_file.close();
    return 0;
}