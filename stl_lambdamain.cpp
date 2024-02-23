#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>//for std::iota

void test1(){
    std::cout<<"\n -----Test1--------------------------"<<std::endl;
    std::vector<int>nums{10,20,30,40,50};

    std:for_each(nums.begin(),nums.end(),[](int num){
        std::cout<<num<<" ";
    });
}

void test2(){
    std::cout<<"\n\n---Test2---------------------"<<std::endl;
    struct Point{
        int x;
        int y;
    };
    Point pt1{1,2};
    Point pt2{4,3};
    Point pt3{3,5};
    Point pt4{3,1};

    std::vector<Point>triangle1 {pt1,pt2,pt3};
    std::vector<Point>triangle2{pt2,pt3,pt1};
    std::vector<Point>triangle3{pt1,pt2,pt4};

    if(std::is_permutation(triangle1.begin(),triangle1.end(),triangle2.begin(),[](Point lhs,Point rhs){
        return lhs.x==rhs.x &&  lhs.y == rhs.y;
    }))
        std::cout<<"Triangle 1 and triangle 2 are equivilent!"<<std::endl;
    else{
        std::cout<<"triangle 1 nad triangle 2 are not equivilent"<<std::endl;
    }
    if(std::is_permutation(triangle1.begin(),triangle1.end(),triangle3.begin(),[](Point lhs,Point rhs){
        return lhs.x==rhs.x &&  lhs.y == rhs.y;
    }))
        std::cout<<"Triangle 1 and triangle 3 are equivilent!"<<std::endl;
    else{
         std::cout<<"triangle 1 nad triangle 3 are not equivilent"<<std::endl;
    }
}

void test3()
{
    std::cout<<"\n---test3---------------"<<std::endl;
    std::vector<int> test_scores {93,88,75,68,65};

    int bonus_points {5};

    std::transform(test_scores.begin(),test_scores.end(),test_scores.begin(),[bonus_points](int score){
        return score+=bonus_points;
    });
    for(int score:test_scores){
        std::cout<<score<<" ";
    }
}


int main(){
    test1();
    test2();
    test3();
return 0;
}