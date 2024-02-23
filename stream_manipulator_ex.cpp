#include<iostream>
#include<iomanip>
void ruler(){
    std::cout<<"\n123134567076598937468645673656596736587456456"<<std::endl;
}
int main(){
    int num1={1234};
    double num2{1234.5678};
    std::string hello {"Hello"};
//defaults
    std::cout<<"\n------------------defualts-----------------------------"<<std::endl;
    ruler();
    std::cout<<num1<<num2<<hello<<std::endl;
//default -one per line 
    std::cout<<num1<<std::endl;
    std::cout<<num2<<std::endl;
    std::cout<<hello<<std::endl;
//set field width to 10;
    std::cout<<"\n-------------------width 10 for num1---------------------------"<<std::endl;
    ruler();
    std::cout<<std::setw(10)<<num1<<num2<<hello<<std::endl;
//set field width to 10 for the first 2 outputs
//note the default justification is right for both
    std::cout<<"\n -----------------width 10 for num1 and num2-------------------------"<<std::endl;
    ruler();
    std::cout<<std::setw(10)<<num1<<std::setw(10)<<num2<<std::setw(10)<<hello<<std::endl;
//set width to 10 for all 3 output
//note the default justification is right for all
    std::cout<<"\n -----------width 10 for num1 and num2 and hello left to for all------------------"<<std::endl;
    ruler();
    std::cout<<std::setw(10)<<std::left<<num1<<std::setw(10)<<std::left<<num2<<std::setw(10)<<std::left<<hello<<std::endl;
//setfill to dash
//thsi is persistent
    std::cout<<std::setfill('-');
    std::cout<<"\n ----------width 10 for num1 and num2 and hello left to for all setfill to dash------------------"<<std::endl;
    ruler();
    std::cout<<std::setw(10)<<std::left<<num1<<std::setw(10)<<std::left<<num2<<std::setw(10)<<std::left<<hello<<std::endl;
//set width to 10 for all ,left justify and carry the setfill character
    std::cout<<"\n ----------width 10 for num1 and num2 and hello -setfill varies------------------"<<std::endl;
    ruler();
    std::cout<<std::setw(10)<<std::left<<std::setfill('*')<<num1<<std::setw(10)<<std::setfill('#')<<std::left<<num2<<std::setw(10)<<std::setfill('-')<<std::left<<hello<<std::endl;
    
    return 0;
}
