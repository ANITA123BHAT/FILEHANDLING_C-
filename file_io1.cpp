
/*
c++ uses the stream as inetrface btw program and i/o devices

read operation
ifstream in("file_name.txt");
string string_var;
getline(in,string_var);//if print the string_var we get the line of file multiple line multi time getline()
or in>>string_var

writes operation:
ofstream out("file_name.txr");
string string_var="hi anita";
out<<string_var; here content in string_var get override the content of file..

*/
#include<iostream>
#include<fstream>

int main(){
    //conecting our file with out_write 
    std::ofstream out_write("sample.txt");//out_write is the object of class ofstream thsi name can be anything..
    std::cout<<"enetr you name:"<<std::endl;
    std::string name;
    //writing string to the file
    std::getline(std::cin,name);
    out_write<<"My name is:"+name;
    out_write.close();//closing the writing pipe

    //read the content using in_read object
    std::ifstream in_read("sample.txt");
    std::string read_content;
    getline(in_read,read_content);
    std::cout<<"the content of file:"<<std::endl;
    std::cout<<read_content<<std::endl;
    
    return 0;
}