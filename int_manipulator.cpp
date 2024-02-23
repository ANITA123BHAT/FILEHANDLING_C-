/*

->formatting integer tyep:
->default when displaying interger values is:
    dec(base 10)
    noshowbase-prefix used toshow hexadecimal or octal
    nouppercase-when displaying a prefix and hex value it will be lower case
    noshowpos-no '+'is displayed for + numbers
->these manipulator affect all further output to the stream

*/

#include<iostream>
#include<iomanip>

int main(){
    int num{255};
//displaying using different bases
    std::cout<<"\n---------------------------------------"<<std::endl;
    std::cout<<std::dec<<num<<std::endl;
    std::cout<<std::hex<<num<<std::endl;
    std::cout<<std::oct<<num<<std::endl;
//displaying showing the base prefix for hex and oct
    std::cout<<"\n------------------showbase---------------------"<<std::endl;
    std::cout<<std::showbase;
    std::cout<<std::dec<<num<<std::endl;
    std::cout<<std::hex<<num<<std::endl;
    std::cout<<std::oct<<num<<std::endl;

//display the hex value in uppercase
    std::cout<<"\n-------------------uppercase--------------------"<<std::endl;
    std::cout<<std::showbase<<std::uppercase;
    std::cout<<std::dec<<num<<std::endl;
    std::cout<<std::hex<<num<<std::endl;
//display the +sign in front of positive base 10numbers;
    std::cout<<"\n-----------------------positive base 10 numbers----------------"<<std::endl;
    std::cout<<std::showpos;//it only works with decimal number
    std::cout<<std::dec<<num<<std::endl;
    std::cout<<std::hex<<num<<std::endl;
    std::cout<<std::oct<<num<<std::endl;

//setting using the set method
    std::cout.setf(std::ios::showbase);
    std::cout.setf(std::ios::uppercase);
    std::cout.setf(std::ios::showpos);
//resetting to defaults;
    std::cout<<std::resetiosflags(std::ios::showbase);
    std::cout<<std::resetiosflags(std::ios::showpos);
    std::cout<<std::resetiosflags(std::ios::uppercase);
    
    std::cout<<"\n---------------------------------------------"<<std::endl;
    std::cout<<"enter the inetrger: "<<std::endl;
    std::cin>>num;
    std::cout<<"decimal default:"<<num<<std::endl;
    std::cout<<"hexadecimal:"<<std::hex<<num<<std::endl;
    std::cout<<"hexadecimal:"<<std::hex<<std::uppercase<<num<<std::endl;
    std::cout<<"Hexadecimal:"<<std::hex<<num<<std::endl;
    std::cout<<"hexadecimal:"<<std::hex<<std::nouppercase<<num<<std::endl;

    std::cout<<"octal:"<<std::oct<<num<<std::endl;
    std::cout<<"hexadecimal:"<<std::hex<<std::showbase<<num<<std::endl;
    std::cout<<"Octal:"<<std::oct<<num<<std::endl;

    std::cout<<std::endl<<std::endl;
    return 0;
}