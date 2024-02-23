/*
explicit type conversion is also called as type conversion done by the user. it is a user defined type casting;
this type casting to get the resukt in particular type

this explicit type conversion can be done in 2 ways:
        1. conversting by assignment: this can be done explicitly defining the required data type for the expression by placing the required type in front of the expression in paranthesis
        this can also consider as forceful casting;
        syntax:
        (type) expression;
        here type is the resultant type we need to get in final result;

*/

#include<iostream>
int main(){
    double x=1.909;
    std::cout<<"x="<<x<<std::endl;
    std::cout<<"Do explicit type casting by 1 conversting by assignment:"<<std::endl;
    int sum=(int)x+2;
    std::cout<<"x= will not change in builtly only  "<<x<<std::endl;
    std::cout<<"sum="<<sum<<std::endl;

}

