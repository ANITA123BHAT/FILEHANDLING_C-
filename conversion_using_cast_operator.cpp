/*
Conversion using Cast opeartor:
    this also a one way  of explicit type conversion:
    a Cast opeator is an unary operator which forces one data type to be converted into another data type;
    c++ supoort for type of casting using cast operator:
        1. static_cast;
        2. Dynamic_Cast;
        3, Const_cast
        4. reInterpret cast:

1. static_cast:
    this is the simplest cast that can used;
    it is a" compiler time cast. "  bcz this happens during the compilation time ;
    here user need to explicit specify the  data type need to convert to whuch type so this also called as explicit conversion function;
    syntax:
        static_cast<dest_type>(source);

*/

#include<iostream>
int main(){

    float f=5.87;
    std::cout<<"value of f is: before casting "<<f<<std::endl;
    //explicit type cast float to int by assignment
    int a=(int)f;
    std::cout<<"the value of a is after explocit type casting :"<<a<<std::endl;
    //using explicit static_cast<>() cast operator;
    int b=static_cast<int>(f);
    std::cout<<"the value of a is after explicit type casting using static_cast<> operator :"<<a<<std::endl;
    return 0;
}
