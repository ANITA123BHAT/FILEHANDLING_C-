/*
NOTE:
file handlinG: istream and ostream for input and output ;
here stream is a inetrface for data transfering.
#include<fstream> for file handling classes used to work with file input/output 
    1.fstreambase :base class 
    2.ifstream : derived from fstream base
    3.ofstream: derived  from fstream base to get the output/rad data from file

inorder to work with files in c++ we have two method to open a file:
    1.using the constructor
    2. using the member function open() of the class 


*/

#include<iostream>
#include<fstream>
int main(){
    std::string st="Hi, ANITA how are you?";
    std::string st2;
    //opening file using constructor..
    std::ofstream out("sample.txt");//write operation
    out<<st;

    /*opening the file using constructor and reading it
    std::ifstream in("sample1.txt");
    in>>st2;
    std::cout<<st2<<std::endl;
    in this instruction we get only one word from the file it is stopped when space comes in sentence so use getline(in,st2); this will gte one line if place one more time same getline() then next line so on..
    how many times you use getline() you wil get that many lines and end of line last line after that again if youuse same last printed line gets prints.
    */
   std::ifstream in("sample1.txt");
   getline(in,st2);
   std::cout<<st2<<std::endl;
   getline(in,st2);
   std::cout<<st2<<std::endl;
   getline(in,st2);
   std::cout<<st2<<std::endl;

    return 0;
}