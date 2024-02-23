/*
TEMPLATE: 
is made in such a ay that i will make a class once and automatically for different data type;
template is also called as parameterized clases.
Q.why use template? 
Ans:we can do the generic program (generic class and generic function)

syntax;
template<class T> 
for vector; 
class vector{
    T *arr;//arr of any data type T(int,char ,float,double)
    public:
    vector(T *arr){//code}
};
int main(){
    vector<int>myvec(ptr);
    vector<char>myvec1(ptr);
}

*/

#include<iostream>

template<class T>
class Vector {
public:
    T *arr; // T pointer
    int size;

    Vector(int m) {
        size = m;
        arr = new T[size];
    }
    template<class U>
    T sumVec(const Vector<U>& v) const {
        T sum = 0;
        for (int i = 0; i < size; i++) {
            sum += this->arr[i] * v.arr[i];
        }
        return sum;
    }
};

int main() {
    Vector<float> v1(3);
    v1.arr[0] = 4.4;
    v1.arr[1] = 23.2;
    v1.arr[2] = 21.1;

    Vector<int> v2(3);
    v2.arr[0] = 1;
    v2.arr[1] = 0;
    v2.arr[2] = 1;

    float a = v1.sumVec(v2);
    std::cout << a << std::endl;

    return 0;
}
