#include <fstream>
#include <iostream>
using namespace std;

int main(){
    ifstream my_in_file;
    my_in_file.open("hello.txt");
    if (my_in_file.is_open()){
        string line;
        while(getline(my_in_file, line)){
            cout<<line<<endl;
        }
        my_in_file.close();
    }
}