#include<iostream>
#include<fstream>
#include<string>
int main(){
    std::ifstream in_file("sample2.txt");
    std::ofstream out_file ("out_smaple3.txt");
    if(!in_file){
        std::cerr<<"error in opening"<<std::endl;
        return 1;
    }
    if(!out_file){
        std::cerr<<"error in creating the file"<<std::endl;
        return 1;
    }
    std::string line;
    while(std::getline(in_file,line)){
        out_file<<line<<std::endl;
    }
    std::cout<<"file copied"<<std::endl;
    in_file.close();
    out_file.close();
    return 0;
}