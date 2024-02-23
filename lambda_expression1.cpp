/*
structure of lambda expression: 

[] () ->return_type specifiers {};
[] capture list -> defines the start of the lambda
() parametre list -> comma seperated list of parameter
return_type- can be omiited and compiler will try to deduce it!
specifiers ->optional specifier and mutable and const expression
{}; body of code


exampel for stateles lambda expression: these are lambda expression that have empty capture lists
ex: [](){std::cout<<"hello";};
ex:[](){std::cout<<"hello";}();
 right side functioncall operator 2paranthesis
 these paranthesis() will instantiates the function object  from this lambda expression
 and call the function object usingthe overloaded fucntion call operator

ex:[](int x){std::cout<<x<<;};//paramater list x
ex:[](int x, int y){std::cout<<x+y;}; 

ex:auto l=[](){std::cout<<"Hi";};
    l();
    //we can assign the lambda expression to the variable
we can use the auto to tell compiler to  deduce the type of the  lambda expresison
ex:auto l=[](int x){std::cout<<"x";};
    l(10);
    l(100);

auto l=[](int x,int y)->int {retun x+y};
or 
auto l=[] (int x,int y){return x+y};
std::cout<<l(10,10);

*/
/*
STATE LESS LAMBDA EXPRESSION
    Lambda capture list allows it to  capture context or closure in which it executes
    what if the capture list is empty? an empty capture list means the expression captures no information from it's environment
    it only about the information that passed via the function parametr list. this is know as stateless lamdba expression..
ex:
int x {10};
[](int x){std::cout<x;}(100);
in this takes 1 parametr x and display x 
we can see this expression will instantiated with the value 100 as its x parameter;
and also there is an another integer x has been defined  as parametr
so 100 will o/p ; bcz lambda expression is stateless and so it capture no information from it's environment.

NOTE: using value and reference as lambda parameter
    [](int x){};
    [](int &x){};
using pointer as lambda paramter
    auto =[](int *x){cout<<*x;};
    l(&x);

NOTE:
"auto" keyword is not a actual type it is an instruction to the compiler to deduce into actual type
ADVTAGES:
it has an ability to be passed into fucntion as parameters;

1.by passing the lambda expression as  fucntion object using std::library fucntoional header"#include<functional>"
    ex:void foo(std::function<void(int)>l){
        l(10);//c++14
    }
    void is return type and int is parametr type
2. passing a lambda expession to function is a fucntion pointer
ex:
    void foo(void (*l)(int)){
        l(10);
    }//c++14
3.void foo(auto l){
    l(10)//c++20
}
*/

/*

RETURING LAMBDA EXPRESSION FROM FUNCTIONS
1.
    std::function<void(int)> foo(){
            return [] (int x){std::cout<<x;};
    }
2.
    void (*foo())(int){
        return [] (int x){std::cout<<x;};
    }
3.
    auto foo(){
        return [] (int x){std::cout<<x;};
    }
*/
