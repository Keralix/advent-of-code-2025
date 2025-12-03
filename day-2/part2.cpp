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
bool isRepeating(string str, int chunk){
    if(str.length() % chunk != 0) return false; 
    string sub = str.substr(str.length() - chunk, chunk);

    for(int i = 0; i < str.length() - chunk; i += chunk){
        if(str.compare(i, chunk, sub) != 0)
            return false;
    }
    return true;
}
long invalidIDSumInRange(long start, long end){
    long sum=0;
    for(;start<=end;start++){
        string number =to_string(start);
        for(int i = 1; i<=(number.length()/2);i++){
            if(isRepeating(number,i)){
                cout<<number<<endl;
                sum+=start;
                break;
            }
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
        sum+=invalidIDSumInRange(startNum,endNum);
    }
    cout<<sum<<endl;
    return 0;
}