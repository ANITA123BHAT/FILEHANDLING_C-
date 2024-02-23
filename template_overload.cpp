#include<iostream>
template<class T>
class myclass{
public:
    int data;
    myclass( T a){
        data=a;
    }
    void display();
};

//memeber function outside class 
template < class T>
void myclass<T> ::display(){
        std::cout<<data<<std::endl;
}
void func(int a){
    std::cout<<"first funcion() just a function"<<a<<std::endl;
}
//it will executed bcz of exact match ..help of template..
template<class T>
void func(T a){
    std::cout<<"first funcion() templatized "<<a<<std::endl;
}

int main(){
    myclass<int>obj1(10);
    myclass<float>obj2(34.68);
    obj1.display();
    obj2.display();
    func('c');
    func(10);
    func(9.89);
    return 0;
}