/*
stateful lambda expressions:
[captured_varibles]()->return_type specifiers{};
Non -empty captured list;
defines what information /varaibles should be captured
NOTE:
the compiler generates what's know as a closure type class with a default constructor and an operator fucntion implementing the logic of the lambda.

capture by value
int x {100};
[x](){std::cout<<x;}();
IMP: the variable being captured by value is actually being captured by const value, so it won't be modifiable within the lambda.
so what if want to capture the value and modify?:
ANS:in that case we can use the keyword mutable to tell the compiler to generate the lambda operator fucntion as a non const member function
by doing that we can capture variable by value and modify them within the lambda 
and also we can capture the value by refernce.
IN that case any chnages made to the variable captured by reference within the lambda will be visible.

Default capture:
    [=]//default capture by value
    [&]//default capture by refernce
    [this]//default capture this object by reference

*/

#include<iostream>
#include<vector>
#include<algorithm>

int global_x{1000};

//capture by value
//the global variable global_x can not be captured bacause it is not;
//within the reaching scope of lambda , it can however still be accessed
//from wthin the lmbda using normal name lookup rules

void test1(){
    std::cout<<"\nTest1--------------"<<std::endl;
    int local_x{100};
    auto l=[local_x](){std::cout<<local_x<<std::endl;
    std::cout<<global_x<<std::endl;
    };//here global_x can't be captured so compiler will give an error
    //here we try to modify the local_x auto varaible insid ethe lambda we can't ;
    l();
}
/*capture by value-mutable;
the captured varaible x can only be modified within the lambda by
using the mutable keyword. note that this modifiablility only pertains to
 the captured varible within the lambda body and not the actual varaible..
*/
void test2(){
    std::cout<<"\nTest2--------------------------------"<<std::endl;
    int x{100};//local varaible x
    //lambda start
    auto l=[x]()mutable{ //lambda has copy of x
        x+=10;//x=100+100=200;
        std::cout<<x<<std::endl;//200 here increamnet x value by 100 so inside it can get updates bcz of mutable
    };//lambda end
    l();
    std::cout<<x<<std::endl;//100 outof scope not within the lambda
    l();//here local x =200 alreday has 
    std::cout<<x<<std::endl;//100
}

/*capture by reference
auto l=[x]()mutable{ //lambda has copy of x
        x+=10;//x=100+100=200;
        std::cout<<x<<std::endl;//200 here increamnet x value by 100 so inside it can get updates bcz of mutable
    }; this is an constructor and l(); is an operator() 
*/


//capture by reference 
//any changes made to the captured reference  varaible withinthe lambda body
//will changes the actuall variable..
void test3(){
    std::cout<<"\n ---tEST3------------------------------"<<std::endl;
    int x{100};
    auto l=[&x]()mutable{//change x will also effect in x{100} also 
        x+=100;
        std::cout<<x<<std::endl;//200
    };
    l();//200
    std::cout<<x<<std::endl;//200

    l();//300
    std::cout<<x<<std::endl;//300
}


//default capture by value-mutable
//only varaible used within the lambda body are captured by value
//the varaible z is not captured by lambda
void test4(){
    std::cout<<"\n---Test4-------------------------"<<std::endl;
    int x{100};
    int y{200};
    int z{300};

    //NOte that z is not captured in the lambda since it is not used .
    //this should produce an unused variable waring when compiling.
    auto l=[=]()mutable{
        x+=100;
        y+=100;
        std::cout<<x<<std::endl;//200
        std::cout<<y<<std::endl;//300
    };
    l();
    std::cout<<"\n";
    std::cout<<x<<std::endl;//100
    std::cout<<y<<std::endl;//200
}


//default capture by reference i,.e capturing everything by reference
//this time bacause all three variable -x,y,z are used within teh lambda body
//all three of them will be captured by reference

void test5(){
    std::cout<<"\n------------------Test5----------------------"<<std::endl;
    int x{100};
    int y{200};
    int z{300};

    auto l=[&](){
        x+=100;
        y+=100;
        z+=100;
        std::cout<<x<<std::endl;
        std::cout<<y<<std::endl;
        std::cout<<z<<std::endl;
    };
    l();
    std::cout<<"\n";
    std::cout<<x<<std::endl;
    std::cout<<y<<std::endl;
    std::cout<<z<<std::endl;

}

//default capture by value, caprure by reference;
void test6(){
    std::cout<<"\n=-------Test6------------------------"<<std::endl;
    int x{100};
    int y{200};
    int z{300};
    
    auto l= [=,&y]()mutable{
        x+=100;
        y+=100;
        z+=100;
        std::cout<<x<<std::endl;//200
        std::cout<<y<<std::endl;//300
        std::cout<<z<<std::endl;//400
    };
    l();
    std::cout<<"\n";
    std::cout<<x<<std::endl;//100
    std::cout<<y<<std::endl;//300
    std::cout<<z<<std::endl;//300
}


//default capture by reference, capture x and z by value
//equivalent to test6
void test7(){
    std::cout<<"\n------------test7-----------------------------"<<std::endl;
    int x{100};
    int y{200};
    int z{300};

    auto l=[&, x,z]()mutable{
        x+=100;
        y+=100;
        z+=100;
        std::cout<<x<<std::endl;//200
        std::cout<<y<<std::endl;//300
        std::cout<<z<<std::endl;//400
    };
    l();
    std::cout<<"\n";
    std::cout<<x<<std::endl;//100
    std::cout<<y<<std::endl;//300
    std::cout<<z<<std::endl;//300
}

//used for test8
class Person{
    friend std::ostream &operator<<(std::ostream &os, const Person &rhs);
private:
    std::string name;
    int age;
public:
    Person()=default;
    Person(std::string name, int age):name{name},age{age}{}
    Person(const Person &p)=default;
    ~Person()=default;
    std::string get_name() const {return name;};
    void set_name(std::string name){this->name=name;};
    int get_age() const {return age;}
    void set_age(int age){this->age=age;};

//here we are returing the lambda...
    auto change_person1(){return [this](std::string new_name,int new_age){name=new_name,age=new_age;};}
    auto change_person2(){return [=](std::string new_name, int new_age){name=new_name,age=new_age;};}
    auto change_person3(){return [&](std::string new_name, int new_age){name=new_name,age=new_age;};}
};

std::ostream &operator << (std::ostream &os, const Person &rhs){
    os << "[Person: "<<rhs.name<<":"<<rhs.age<<"]";
    return os;
}

//default capture by reference of the current object using [this]
//[=] and [&] and [this] are equivalent  when capturing an object's member varaible -all are captured by reference
//note that capturing thsi with [=] has been deprecated in c++20;
//also c++20; allows [*this] which captures by value;

void test8(){
    std::cout<<"\n----------------Test8-----------------"<<std::endl;

    Person person("larry",18);
    std::cout<<person<<std::endl;
    //default capture [this]
    //this is the preferred way
    auto change_person1=person.change_person1();
    change_person1("Moe",30);
    std::cout<<person<<std::endl;

    //default capture[=] value
    //this has been deprecated in c++20;
    auto change_person2=person.change_person2();
    change_person2("Curly",25);
    std::cout<<person<<std::endl;

    //default capture [&] refernce
    auto change_person3=person.change_person3();
    change_person3("Frank",34);
    std::cout<<person<<std::endl;

}
//use dfor test9
class Lambda{
private:
    int y;
public:
    Lambda(int y):y{y}{};
    void operator()(int x)const{
        std::cout<<x+y<<std::endl;
    }
};
//lambda class equivalence example
void test9(){
    std::cout<<"\n----Test9------------------"<<std::endl;
    int y{100};
    Lambda lambda1(y);
    auto lambda2=[y](int x){std::cout<<x+y<<std::endl;};
    lambda1(200);
    lambda2(200);
}

class People{
    std::vector<Person>people;
    int max_people;
public:
        People(int max=10):max_people(max){}
        People(const People &p)=default;
        void add(std::string name, int age){
            people.emplace_back(name,age);
        }
        void set_max_people(int max){
            max_people=max;
        }
        int get_max_people()const{
            return max_people;
        }

        std::vector<Person>get_people(int max_age){
            std::vector<Person>result;
            int count{0};
            std::copy_if(people.begin(),people.end(),std::back_inserter(result),[this,&count,max_age](const Person &p){return p.get_age()>max_age && ++count <=max_people; });
            return result;
        }
};

void test10(){
    std::cout<<"\n ----Test10----------------------"<<std::endl;
    People friends;
    friends.add("Larry",18);
    friends.add("curly",25);
    friends.add("Moe",35);
    friends.add("Frank",28);
    friends.add("James",65);

    auto result=friends.get_people(17);

    std::cout<<std::endl;
    for(const auto &p:result)
        std::cout<<p<<std::endl;
    
    friends.set_max_people(3);
    result=friends.get_people(17);

    std::cout<<std::endl;
    for(const auto &p:result){
        std::cout<<p<<std::endl;
    }
    result=friends.get_people(50);
    std::cout<<std::endl;

    for(const auto &p:result){
        std::cout<<p<<std::endl;
    }
}

int main(){
    
    return 0;
}


