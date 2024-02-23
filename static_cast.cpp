/*
The Behaviour of staic_cast for different scenarios:
1.static_cast for primitive data type pointers:
   ex:
   int a=1-;
   char c='a';
   int *q=(int *)&c;//ERROR
   int *p=static_cast<int*>(&c);//ERROR
   IF we try to convert from one particular object pointer to naother type pointer both will throw an error;

2. Converting an object using a User Defined conversion operator:
3. staic _cast for inheritance in c++
    static_cast <> provide the both upcasting and down casting in case of inheritance;
    So to use static_cast in case of inheritance, the base class must be accessible, non virtual and unambiguous.
4. static_cast to Cast "to or from " void pointer;
    static _cast operator allows operator allows casting from any pointer type to voidp pointer and vice versa
    
void pointer;*/


// #include<iostream>
// #include<string>
// /*

// When obj is created then the constructor is called which in our case is also a Conversion Constructor (for C++14 rules are changed a bit).
// When you create str out of obj, the compiler will not throw an error as we have defined the Conversion operator.
// When you make obj = 20, you are actually calling the conversion constructor.
// When you make str2 out of static_cast, it is pretty similar to string str = obj; but with tight type checking.
// When you write obj = static_cast <integer> (30), you convert 30 into an integer using static_cast.

// */
// class Interger{
// private:
//     int x;
// public:
//     Interger(int x_val=0):x{x_val}{
//         std::cout<<"Constructor is called"<<std::endl;
//     }
//     operator std::string(){//conversion operator is string  we are returing std::string;
//         std::cout<<"Conversion operator is called"<<std::endl;
//         return std::to_string(x);
//     }
// };

// class  Dervied:public Interger{

// };
// int main(){
//     Interger obj(3);//this is also conversion constructor
//     std::string str= obj;//here conversio operator is defined so compiler will not throw an error
//     obj=20;//here actual conversion operator is called;;

//     //using static_cast for typecasting;
//     std::string str2=static_cast<std::string>(obj);
//     obj=static_cast<Interger>(30);
    
//     Dervied d1;
//     //implicit cast allowed;
//     Interger *ptr_int=(Interger*)(&d1);

//     //upcasting usingsttaic_cast
//     Interger *b2= static_cast<Interger*> (&d1);

//      /*
//         Explanation: The above code will compile without any error.

//         We took the address of d1 and explicitly cast it into Base and stored it in b1.
//         We took the address of d1 and used static_cast to cast it into Base and stored it in b2.

//         In the above example, we inherited the base class as public. What happens when we inherit it as private? we //ERROR
//         The above code will not compile even if you inherit it as protected.

//     */


//     return 0;
// }


#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include<algorithm>
std::vector<int>& findlast(std::vector<int>&digits){
   // std::vector<int> plusOne(std::vector<int>& digits) 
   for(int i=digits.size()-1;i>=0;--i){
               if(digits[i]!=9){
                   digits[i]++;
                   return digits;
               }
               else{
                   digits[i]=0;
               }
           }
           digits.push_back(0);
           digits[0]=1;
return digits;
          
}
int main(){
    std::vector<int>vec={9,9};
    std::vector<int>vec1=findlast(vec);
     for(auto num:vec1){
            std::cout<<num<<" ";
           }
    return 0;
}