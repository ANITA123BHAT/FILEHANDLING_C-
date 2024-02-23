#include<iostream>
#include<fstream>
#include<string>

int main(){
    std::ofstream out;
    out.open("sample.txt");
    out<<"this is me\n";
    out<<"this is me also ..";
    out.close();

    std::ifstream in;
    in.open("sample.txt");
    std:: string str;
   // in>>str1>>str2;//to read each word in line 
    while(in.eof()==0){//end of file
        getline(in,str);
        std::cout<<str<<std::endl;
    } 
    in.close();
    return 0;
}