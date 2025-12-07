#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool checkIsFresh(long ingredient, vector<string> ranges){
    for(int i =0; i<ranges.size();i++){
        long pos = ranges[i].find('-');
        long start = stol(ranges[i].substr(0,pos));
        long end = stol(ranges[i].substr(pos+1,ranges[i].size()-1));
        if(ingredient>=start&&ingredient<=end) return true;
    }
    return false;
}
int main(){
    ifstream input("input.txt");
    vector<string> rangesLines;
    vector<long> ingredientsAvailable;
    string line;
    int sum=0;
    while(getline(input,line)){
        if(line.size()>0&&line.find('-')!=-1){
            rangesLines.push_back(line);
        }else if(line.size()>0){
            ingredientsAvailable.push_back(stol(line));
        }

    }
    for( long ingredient: ingredientsAvailable){
        if(checkIsFresh(ingredient,rangesLines)){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}