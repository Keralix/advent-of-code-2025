#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream input{"input.txt"};
    int password = 50;
    int counter =0;
    string zn;
    while(getline(input,zn)){
        if(zn[0]=='R'){
            zn.erase(0,1);
            password +=stoi(zn);
        } else{
            zn[0]='-';
            password +=stoi(zn)+100;
        }
        password =password%100;
        if(!password) counter++;
    }
    cout<<counter<<endl;
    return 0;
}