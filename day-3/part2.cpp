#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int findLargestIn(string line,int start, int limit){
    int result  = start;
    for(int i = start+1;i<=line.length()-limit;i++){

        if(line[i]>line[result])  result=i;
    }
    return result;
}
int main(){
    ifstream input{"input.txt"};
    long sum =0;
    string line;
    string jolt;
    while(getline(input,line)){
        int start = 0;
        for(int i =0;i<12;i++){
            start=findLargestIn(line,start,12-i);
            jolt+=line[start];
            start++;
        }
        cout<<jolt<<endl;
        sum+=stol(jolt);
        jolt.clear();
    }
    cout<<sum<<endl;
    return 0;
}