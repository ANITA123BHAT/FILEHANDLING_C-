/*
output file stream:
write a data to the file via stream
    std::fstream out_file {"myfile.txt",std::ios::out | std::ios::binary};
opeing the filw for write:
    std::ofstream out_file {"myfile.txt",std::ios::out};
opening the file for writing with:
    //truncate (discard contents) when opening;
        std::ofstream out_file {"myfile.txt",std::ios::trunc};
    //append on each write
        std::ofstream out_file{"myfile.txt",std::ios::app};
    //seek to end of stream when opening
        std::ofstream out_file{"myfile.txt",std::ios::ate};//ate =at the end
out_file.close() important bcz flushes out any buffer that may not have been written out to file yet.

*/

#include<iostream>
#include<fstream>
#include<string>
int main(){
   // std::ofstream out_file{"output.txt"};
   //if the file exist then content will be tructed while opeing if not just creat to write 
    std::ofstream out_file{"output.txt",std::ios::app};
    //here it will append the content if previously any content exist in file just append to it each time when you run ..
    if(!out_file){
        std::cerr<<"error in creating file"<<std::endl;
        return 1;
    }
    std::string line;
    std::cout<<"enetr something to write:"<<std::endl;
    std::getline(std::cin,line);
    out_file<<line<<std::endl;//once the file created if you run again it will trycted to write again in that file.
    out_file.close();
    return 0;
}