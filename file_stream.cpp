/*
opening the file for reading with (fstream)
    std::fstream in_file{"../myfile.txt",std::ios::in};
->open for reading in binary mode
    std::fstream in_file {"../myfile.txt",std::ios::in |  std::ios::binary};
    std:ifstream in_file{"../myfile.txt",std::ios::in};
    std::ifstream in_file{"../myfile.txt",std::ios::binary};

ex:
    std::string in_file;
    std::string filename;
    std::cin>>filename;
    in_file.open(filename); or in_file.open(filename,std::ios::binary |std::ios::in );

    if(in_file.is_open()){//read it} else{//do anything}
    in_file.open()=just open to read
    in_file.close();

to read the file content:
    ex-> in_file>>num1;

in_file.get(c)//read character from file content..
*/

#include<iostream>
#include<fstream>
int main(){
    std::ifstream in_file;//object of istream to read
    std::string line;
    int num;
    double total;
    in_file.open("sample.txt");
    if(!in_file){//same as in_file.is_open()?
        std::cerr<<"problme in opening file"<<std::endl;
        return 1;
        //std::exit(0);it destroys lall varibale memory , fucntions  and someother things 
    }
    std::cout<<"file is good to go"<<std::endl;
    in_file>>line>>num>>total;//read all types 
    std::cout<<line<<std::endl;
    std::cout<<num<<std::endl;
    std::cout<<total<<std::endl;
    in_file.close();
    
    return 0;
}