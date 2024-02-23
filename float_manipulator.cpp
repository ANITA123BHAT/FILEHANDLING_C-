/*
formatting floating point types:
defualt when displaying floating point value is:
    setprecision -number of digits displayed (6)
    fixed-not fixed to a specific number of digit after the decimal point
    noshowpoint- tralling zeros are not displayed
    nouppercase-when displaying in scientific notation
    noshowpos-no '+' is dsiplayed for + numbers

Defaukt when displaying floating point value is:
->setw-not set by default
->left -when no firld width , right -when using field width
->fill not set by default-blank space is used

*/
#include<iostream>
#include<iomanip>

int main(){
    double num1{123456789.123456718};
    double num2 {1234.5678};
    double num3 {1234.0};
//using default settings:
    std::cout<<"\n-----------------------------------"<<std::endl;
    std::cout<<num1<<std::endl;
    std::cout<<num2<<std::endl;
    std::cout<<num3<<std::endl;
    std::cout<<std::endl;
//not ehow since we can't dsiplay in precision 2 scientific notation is used
    std::cout<<std::setprecision(2);
    std::cout<<num1<<std::endl;
    std::cout<<num2<<std::endl;
    std::cout<<num3<<std::endl;
    std::cout<<std::endl;
//using precision 5
    std::cout<<std::setprecision(5);
    std::cout<<num1<<std::endl;
    std::cout<<num2<<std::endl;
    std::cout<<num3<<std::endl;
    std::cout<<std::endl;
//using precision 9
    std::cout<<std::setprecision(5);
    std::cout<<num1<<std::endl;
    std::cout<<num2<<std::endl;
    std::cout<<num3<<std::endl;
    std::cout<<std::endl;
//using precision 3 and fixed
    std::cout<<std::setprecision(3)<<std::fixed;
    std::cout<<"----------precision 3 -fixed------------------"<<std::endl;
    std::cout<<num1<<std::endl;
    std::cout<<num2<<std::endl;
    std::cout<<num3<<std::endl;
    std::cout<<std::endl;
//using precision 3 fixed and scientific notation
//note precision is after the decimal
    std::cout<<std::setprecision(3)<<std::scientific;
    std::cout<<"----------precision 3 -fixed -scientific ------------------"<<std::endl;
    std::cout<<num1<<std::endl;
    std::cout<<num2<<std::endl;
    std::cout<<num3<<std::endl;
    std::cout<<std::endl;
//same  but display capital 'E' in scientific
    std::cout<<std::setprecision(3)<<std::scientific<<std::uppercase;
    std::cout<<"----------precision 3 -fixed -scientific-uppercase ------------------"<<std::endl;
    std::cout<<num1<<std::endl;
    std::cout<<num2<<std::endl;
    std::cout<<num3<<std::endl;
    std::cout<<std::endl;
//show '+' symbol for positive numbers;
    std::cout<<std::setprecision(3)<<std::scientific<<std::showpos;
    std::cout<<"----------precision 3 -fixed -scientific-showpositive ------------------"<<std::endl;
    std::cout<<num1<<std::endl;
    std::cout<<num2<<std::endl;
    std::cout<<num3<<std::endl;
    std::cout<<std::endl;
//back to default
    std::cout.unsetf(std::ios::scientific|std::ios::fixed);
    std::cout<<std::resetiosflags(std::ios::showpos);
//show trailling zero's up to precision 10;
    std::cout<<std::setprecision(10)<<std::showpoint;
    std::cout<<"----------precision 10 -showpoint ------------------"<<std::endl;
    std::cout<<num1<<std::endl;
    std::cout<<num2<<std::endl;
    std::cout<<num3<<std::endl;
    std::cout<<std::endl;
//back to default;
    std::cout.unsetf(std::ios::scientific|std::ios::fixed);
    std::cout<<std::setprecision(6);
    std::cout<<std::resetiosflags(std::ios::showpos);
    std::cout<<std::resetiosflags(std::ios::showpoint);

    std::cout<<"---------------back to defaults-------------------------"<<std::endl;
    std::cout<<num1<<std::endl;
    std::cout<<num2<<std::endl;
    std::cout<<num3<<std::endl;
    return 0;
}