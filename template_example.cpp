#include<iostream>
using namespace std;

template<class T>

class Node{//template class 
public:
    T data;
    Node *next;
    Node(T val){
        data=val;
        next=NULL;
    }
};
int main(){
    Node<int>*node1=new Node<int>(10);
    
    Node<char>*node2=new Node<char>('c');
    std::cout<<node1->data<<endl;
    cout<<node2->data<<endl;
}