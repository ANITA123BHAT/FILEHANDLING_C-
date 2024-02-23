/*
A type cast is basically a conversion  from one type to another.
there are two type of conversion:'
1. Implicit type conversion: it is also know as automaic type conversion;
    ->automic type conversion is done by compiler it self without any external trigner from user;
    ->in automaic type conversion / implicit type conversion there is chance to lose the information, and sugn can be lost, and overflow can occur;

It is possible for implicit conversions to lose information, signs can be lost (when signed is implicitly converted to unsigned),
 and overflow can occur (when long long is implicitly converted to float).
Done by the compiler on its own, without any external trigger from the user.
Generally takes place when in an expression more than one data type is present.
 In such condition type conversion (type promotion) takes place to avoid lose of data.
All the data types of the variables are upgraded to the data type of the variable with largest data type.

bool -> char -> short int -> int -> 

unsigned int -> long -> unsigned -> 

long long -> float -> double -> long double


*/
#include<iostream>
int main(){
    int x=10;
    char y='a';
    //y implicitly converted to int. ASCII valueof a=97;
    x=x+y;
    std::cout<<"x="<<x<<std::endl;
    std::cout<<"y="<<y<<std::endl;
    float z=x+1.090;
    std::cout<<"y="<<y<<std::endl;
    std::cout<<"z="<<z<<std::endl;

}