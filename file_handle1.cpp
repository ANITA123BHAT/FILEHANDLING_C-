#include<iostream>
#include<fstream>
#include<iomanip>
int main(){
    std::ifstream in_file;
    std::string line;
    int num;
    double total;
    in_file.open("sample2.txt");
    if(!in_file){
        std::cerr<<"problem in opening the file.."<<std::endl;
        return 1;
    }
    /* while(!in_file.eof()){
        in_file>>line>>num>>total;
        std::cout<<std::setw(10)<<std::left<<line
        <<std::setw(10)<<num<<std::setw(10)<<total<<std::endl;
    }
    //or we can use this also..
    */
    
     while(in_file>>line>>num>>total){
        std::cout<<std::setw(10)<<std::left<<line
        <<std::setw(10)<<num<<std::setw(10)<<total<<std::endl;
    }
    in_file.close();
 return 0;
}