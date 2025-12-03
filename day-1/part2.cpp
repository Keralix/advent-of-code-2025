#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream input{"input.txt"};
    int index = 50;
    int counter =0;
    string n;
    while(getline(input,n)){
        if(n[0]=='R'){
            n.erase(0,1);
            int steps = stoi(n);
            while (steps)
            {
                index++;
                steps--;
                if(index==100){
                    index=0;
                }
                if(index==0) counter++;
            }
            
        } else{
            n[0]='-';
            int steps = stoi(n);
            while (steps)
            {
                index--;
                steps++;
                if(index==-1){
                    index=99;
                }
                if(index==0) counter++;
            }
        }
    }
    cout<<counter<<endl;
    return 0;
}