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
    std::string line;
    while(std::getline(in_file,line)){
        std::cout<<line<<std::endl;
    }
    in_file.close();
    return 0;
}