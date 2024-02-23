/*
stream manipulator :
    ->streams have useful member function to control formatting
    ->can be used on input/ output stream
    ->the time of the effect on the stream varies
    -> can be used as member function or as manipulator

ex:
    std::cout.width(10);//member function
    std::cout<<std::setw(10);//manipulator

common stream manipulator:
    ->boolean:
        boolalpha, noboolalpha
    ->Interger:
        dec, hex, oct, showbase, noshowbase, showpos, noshowpos, noshowpos
    ->Floating point:
        fixed, scientific, setprecision, noshowpoint, showpos,noshowpos
    ->field width, justification and fill:
        setw, left,right,internal, setfill
    ->other:
        endl,flush, skipws,noskipws,ws(skipwhite space & noskipwhitespace =noskipws)
        
formating the boolean types :
methods version:
    std::cout.setf(std::ios::booalpha);
    std::cout<<setf(std::ios::noboolalpha);
->reset to default
std::cout<<std::resetioflags(std::ios::boolalpha);

*/

#include<iostream>
#include<iomanip>//must include formanipulators;
int main(){
    std::cout<<"noboolalpha-default(10==10):"<<(10==10)<<std::endl;
    std::cout<<"noboolalpha-default(10==20):"<<(10==20)<<std::endl;
//set to true /false formatting;
    std::cout<<std::boolalpha;//change to true or false;
    std::cout<<"boolalpha (10==10):"<<(10==10)<<std::endl;//true
    std::cout<<"boolalpha (10==20):"<<(10==20)<<std::endl;//false
//setting still stays for future boolean insertions
    std::cout<<"Boolalha (10==10):"<<(10==10)<<std::endl;//true
    std::cout<<"boolalpha(10==20):"<<(10==20)<<std::endl;//false
//toggle to 0/1
    std::cout<<std::noboolalpha;
    std::cout<<"noboolalpha-default(10==10):"<<(10==10)<<std::endl;//1
    std::cout<<"noboolalpha-default(10==20):"<<(10==20)<<std::endl;//0
//set back to true /false using setf method:
    std::cout.setf(std::ios::boolalpha);
    std::cout<<"boolalpha (10==10):"<<(10==10)<<std::endl;//true
    std::cout<<"boolalpha (10==20):"<<(10==20)<<std::endl;//false
//reset to default which is 0/1 
    std::cout<<std::resetiosflags(std::ios::boolalpha);
    std::cout<<"default (10==10):"<<(10==10)<<std::endl;//1
    std::cout<<"default (10==20):"<<(10==20)<<std::endl;//0

return 0;
}