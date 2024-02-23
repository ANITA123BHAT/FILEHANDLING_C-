/*
using string stream
->allows us read or write from string in memory much as we would read and write to file;
->very useful for data validation

using string streams:
    stringstream , istringstream, ostringstream;
1. #include<sstream>
2.declare an stringstream , istringstream  or ostringstream object;
3.connect it to a std::string
4. read/write data from/to the string using foratted I/O
ex:
reading from a stringstream;
#include<sstream>
int num{};
double total {};
std::string name{};
std::string info {"Moe 100 1234.56"};
std::istringstream iss{info};
iss >>name>>num>>total;

writing to stringstream
#include<sstream>
int num {100};
double total {1244.6};
std::string name {"anita"};

std::ostringstream oss{};
oss<<name<<" "<<num<<" "<<total;
std::cout<<oss.str()<<std::endl;

*/
#include<iostream>
#include<iomanip>
#include<sstream>
#include<string>
#include<limits>
int main(){
    int num{};
    double total{};
    std::string name{};

    std::string info {"anita 100 1234.5"};
    std::istringstream iss{info};//iss object of input sringstream
    iss>>name>>num>>total;//one by onebased on space..
    std::cout<<std::setw(10)<<std::left<<name<<std::setw(10)<<num<<std::setw(10)<<total<<std::endl;

    std::cout<<"\n------------------------------------------------"<<std::endl;
    std::ostringstream oss{};
    oss<<std::setw(10)<<std::left<<name<<std::setw(10)<<num<<std::setw(10)<<total<<std::endl;
    std::cout<<oss.str()<<std::endl;

    std::cout<<"\n----data validation----------------"<<std::endl;
    int value{};
    std::string entry{};
    bool done =false;
    do{
        std::cout<<"please enetr an inetrger"<<std::endl;
        std::cin>>entry;
        std::istringstream iss{entry};
        if(iss>>value){
            done=true;
        }
        else{
            std::cout<<"sorry that is not an interger"<<std::endl;
        }
        //discard the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    } while(!done);
    std::cout<<"you entered the interger:"<<value<<std::endl;
    std::cout<<std::endl;

    return 0;
}