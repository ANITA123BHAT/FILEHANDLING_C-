
/*********function template*********/
/*float func(int a,int b){
    float avg;
    avg=(a+b)/2.0;
    return avg;
}
float func1(int a,float b){
    float avg=(a+b)/2.0;
    return avg;
}*/
#include<iostream>
template<class T>
void swap(T &a,T &b){
    T temp=a;
    a=b;
    b=temp;
}
template<class T1, class T2>
float func(T1 a,T2 b){
    float avg;
    avg=(a+b)/2.0;
    return avg;
}


int main(){
    float a=func(5, 2.4);
    float b=func(3.4, 9);
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    int x=5,y=8;
    std::cout<<"before"<<x<<" "<<y<<std::endl;
    swap(x,y);
    std::cout<<"after"<<x<<" "<<y<<std::endl;
    return 0;
}