/*
lambda in c++11 and extednded in c++17
->function objects;
->function pointers;

->we often write many short function that control algorithm 
->these short function would be encapsulated in small clases to produce fucntion objects

*/

//fucntion objects;

#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

struct Square_Functor{
    void operator() (int x){//overloads the fucntion call operator()
        std::cout<<x*x<<" ";
    }
};

template<typename T>
struct Displayer{
    void operator() (const T &data){
        std::cout<<data<<" ";
    }
};

class  Multiplier{
private:
    int num {};
public:
    Multiplier(int n):num{n}{};
    int operator()(int n)const{
        return (n*num);
    }
};
int main(){
    std::cout<<"Test1==================="<<std::endl;
    Square_Functor square;//square object will be calling the operator() function
    square(4);//square.operator(4)
    Displayer<int>d1;
    Displayer<std::string>d2;
    d1(100);//fucntion object d1.operator(100);
    d2("anita");//d2.operator("anita");
    
    std::cout<<"\nTest2===================="<<std::endl;
    std::vector<int>vec1{1,2,3,4,5};
    std::vector<std::string>vec2{"anita","sunita","shraddha"};
    
    std::for_each(vec1.begin(),vec1.end(),square);//1 4 9 16 25
    std::cout<<std::endl;

    std::for_each(vec1.begin(),vec1.end(),Displayer<int>());//1 2 3 4 5
    std::cout<<std::endl;

    std::for_each(vec1.begin(),vec1.end(),d1);
    std::cout<<std::endl;

    std::for_each(vec2.begin(),vec2.end(),Displayer<std::string>());//this is  a constructor that creates that object
    std::cout<<std::endl;

    std::for_each(vec2.begin(),vec2.end(),d2);
    std::cout<<std::endl;

    std::cout<<"\nTest3===================================="<<std::endl;
    std::for_each(vec1.begin(),vec1.end(),[](int x){std::cout<<x*x<<" ";});//1 4 9 16 25
    std::cout<<std::endl;
    //[](int x){std::cout<<x*x<<" ";} lambda aexpression 
    std::for_each(vec1.begin(),vec1.end(),[](int x){std::cout<<x*10<<" ";});
    std::cout<<std::endl;

    std::for_each(vec1.begin(),vec1.end(),[](int x){std::cout<<x<<" ";});
    std::cout<<std::endl;

    std::for_each(vec2.begin(),vec2.end(),[](std::string s){std::cout<<s<<" ";});
    std::cout<<std::endl;

    std::cout<<"\nTest4========================="<<std::endl;

    Multiplier mult(100);
    vec1={1,2,3,4};

    //tranform changes the vetor!
    std::transform(vec1.begin(),vec1.end(),vec1.begin(),mult);//where to start where to end and where to start making and mult is the function object;
    std::for_each(vec1.begin(), vec1.end(),d1);//100 200 300 400
    std::cout<<std::endl;

    vec1={1,2,3,4};
    std::transform(vec1.begin(),vec1.end(),vec1.begin(),[](int x){return x*100;});
    std::for_each(vec1.begin(),vec1.end(),[](int x ){std::cout<<x<<" ";});
    std::cout<<std::endl;

    return 0;

}
