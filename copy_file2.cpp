#include<iostream>
#include<fstream>
#include<string>
int main(){
    std::ifstream in_file("sample1.txt");
    std::ofstream out_file ("out_smaple1.txt");
    if(!in_file){
        std::cerr<<"error in opening"<<std::endl;
        return 1;
    }
    if(!out_file){
        std::cerr<<"error in creating the file"<<std::endl;
        return 1;
    }
    char c;
    while(in_file.get(c)){
        out_file<<c;
    }
    std::cout<<"file copied"<<std::endl;
    in_file.close();
    out_file.close();
    return 0;
}