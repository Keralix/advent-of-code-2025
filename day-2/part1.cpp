#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<string> split(string input,char delim){
    vector<string> result;
    long start=0;
    long end =input.find(delim);
    while(end!=std::string::npos){
        result.push_back(input.substr(start,end-start));

        start = end + 1;
        end = input.find(delim, start);
    }
    result.push_back(input.substr(start));
    return result;
}
long invalidIDSumInRange(long start, long end){
    long sum=0;
    for(long i =start;i<=end;i++){
        long log = (long) log10(i);
        
        if(log%2&&(i/((long)pow(10,log/2+1))==i%((long)pow(10,log/2+1)))){
            sum+=i;
        }
    }

    return sum;
}
int main(){
    ifstream input{"input.txt"};
    long sum =0;
    string line;
    getline(input,line);
    vector<string> ranges=split(line,',');
    
    for(const auto& token:ranges){
        vector<string> num = split(token,'-');
        long startNum = stol(num[0]);
        long endNum = stol(num[1]);
        sum +=invalidIDSumInRange(startNum,endNum);
        
    }
    cout<<sum<<endl;
    return 0;
}