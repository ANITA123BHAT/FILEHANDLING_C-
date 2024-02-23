#include<iostream>
template<class T1=int, class T2=float,class T3=char>
class myclass{
public:
    T1 a;
    T2 b;
    T3 c;
    myclass(T1 x, T2 y , T3 z){
        a=x;
        b=y;
        c=z;
    }
    void display(){
        std::cout<<"value of a:"<<a<<std::endl;
        std::cout<<"value of b:"<<b<<std::endl;
        std::cout<<"value of c:"<<c<<std::endl;
    }
};
int main(){
    myclass<>obj1(12,89.09,'c');//no need to specify the data type bcz template we already defined
    obj1.display();
    std::cout<<std::endl;
    myclass<float,char>obj2(34.8,'a','f');//we are specifing so allowed last not specified it will tak efault one or else specified one
    obj2.display();
    std::cout<<std::endl;
    myclass<float,char,char>obj3(9.0,'e','h');//we are specifing so allowed last not specified it will tak efault one or else specified one
    obj3.display();
    return 0;
}