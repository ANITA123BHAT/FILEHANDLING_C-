//stateess lambda expression..
//[]-empty capture lists;

#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include<algorithm>

class Person{
    friend std::ostream &operator <<(std::ostream &os, const Person &rhs);
private:
    std::string name;
    int age;
public:
    Person(std::string name, int age):name{name},age{age}{};
    Person(const Person &p):name{p.name},age{p.age}{};
    ~Person()=default;
    std::string get_name()const {return name;};
    void set_name(std::string name){this->name=name;};
    int get_age()const{return age;}
    void set_age(int age){this->age=age;}
};

std::ostream  &operator<< (std::ostream &os, const Person &rhs){
    os << "[Person:"<<rhs.name<<":"<<rhs.age<<"]";
    return os;
}
void test1(){
    std::cout<<"\n ---Test1-------------------------"<<std::endl;
    [](){std::cout<<"Hi"<<std::endl; }();//() is must to execute otherwise we will not do anything..
    [](int x){std::cout<<x<<std::endl;}(100);
    [](int x,int y){std::cout<<x+y<<std::endl;}(100,200);
}

//using values and refernce as lambda parametrs
void test2(){
    std::cout<<"\n ----Test2-------------------------"<<std::endl;

    auto l1=[](){std::cout<<"HI"<<std::endl;};
    l1();
    int num1{100};
    int num2 {100};
    auto l2=[](int x,int y){std::cout<<x+y<<std::endl;};
    l2(10,20);
    l2(num1,num2);

    auto l3=[](int &x, int &y){
        std::cout<<"x:"<<x<<"y:"<<y<<std::endl;
        x=1000;
        y=2000;
    };
    l3(num1,num2);
    std::cout<<"num1:"<<num1<<"num2:"<<num2<<std::endl;
}

void test3(){
    std::cout<<"\n-------Test3-------------------"<<std::endl;
    Person stooge{"larry",18};
    std::cout<<stooge<<std::endl;

    auto l4=[](Person p){ std::cout<<p<<std::endl; };
    l4(stooge);

    auto l5=[](const Person &p){std::cout<<p<<std::endl;};
    l5(stooge);

    auto l6=[](Person &p){
        p.set_name("Frank");
        p.set_age(25);
    };
    l6(stooge);
    std::cout<<stooge<<std::endl;
}
//used for test4 auto as parameter type in c++20
void filter_vector(const std::vector<int> &vec, std::function<bool(int)>func){
    std::cout<<'[';
    for(int i :vec){
        if(func(i)){
            std::cout<<i<<" ";
        }
    }
    std::cout<<"]"<<std::endl;
}
//passing lambda to the function;
void test4(){
    std::cout<<"\n--------------TEST4-------------------"<<std::endl;
    std::vector<int>nums{10,20,30,40,50,60,70,80,90,100};
    filter_vector(nums,[](int x){return x>50;});
    filter_vector(nums,[](int x){return x<=30;});
    filter_vector(nums,[](int x){return x>=30 && x<=60;});
}

//used for test5
auto make_lambda(){
    return [](){std::cout<<"this lambda was made using the make_labmda fucntion"<<std::endl;};
}
void test5(){
    std::cout<<"\n -----------------Test5 --------------------------------------"<<std::endl;
    auto l5=make_lambda();
    l5();
}
void test6(){
    std::cout<<"\n ---test6--------------------------"<<std::endl;
    auto l6=[](auto x, auto y){
        std::cout<<"x:"<<x<<"y:"<<y<<std::endl;
    };
    l6(10,20);
    l6(100.3,200);
    l6(12.5,15.54);
    l6(Person("Anita",18),Person("Curly",22));
}
//simple lambda example with std::sort and std::for_each
void test7(){
    std::cout<<"\n -----test7-------------------"<<std::endl;
    std::vector<Person>stooges{
        {"Anita",18},
        {"Sunita",19},
        {"Veena",45}
    };
    std::sort(begin(stooges),end(stooges),[](const Person &p1,const Person &p2){return p1.get_name()<p2.get_name();});

    std::for_each(begin(stooges),end(stooges),[](const Person &p){std::cout<<p<<std::endl;});
    std::cout<<std::endl;
    std::sort(begin(stooges),end(stooges),[](const Person &p1, const Person &p2){return p1.get_age()<p2.get_age();});
    std::for_each(begin(stooges),end(stooges),[](const Person &p){std::cout<<p<<std::endl;});
}
int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    std::cout<<std::endl;
    return 0;
}
