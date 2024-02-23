#include<iostream>

//custome data type generic class 
template<class T1,class T2>
class myclass{
    public:
        T1 data1;
        T2 data2;
        myclass(T1 a , T2 b){
            data1=a;
            data2=b;
        }
        void display(){
            std::cout<<this->data1<<" "<<this->data2<<std::endl;
        }
};
int main(){
    myclass<int,float>obj1(6,19.889);
    myclass<char, int>obj2('a',2);
    obj1.display();
    obj2.display();
    return 0;
} 