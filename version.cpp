#include<QtCore>
#include<iostream>

int main()
{
    std::cout<< "Using Qt version: " << qVersion() << std::endl;
    return 0;
}
//g++ -o version version.cpp -I/home/timo/Qt/5.7/gcc_64/include/QtCore -I/home/timo/Qt/5.7/gcc_64/include -L/home/timo/Qt/5.7/gcc_64/lib -lQt5Core -fPIC
