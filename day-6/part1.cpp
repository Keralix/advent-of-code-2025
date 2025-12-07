#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <string_view>
using namespace std;
string getOperations(string line){
    auto noSpaceLine = remove(line.begin(),line.end(),' ');
    line.erase(noSpaceLine,line.end());
    return line;
}
vector<long> cleanLine(string line){
    vector<long> result;
    vector<int> spacesIndex;
    for(int i=0; i<line.length();i++){
        if(line[i]==' ')spacesIndex.push_back(i);

    }
    if(spacesIndex[0]!=0) result.push_back(stol(line));
    for(int j=0;j<spacesIndex.size()-1;j++){
        
        if(spacesIndex[j+1]-spacesIndex[j]>1){
            result.push_back(stol(line.substr(spacesIndex[j])));
        }
        if(j==spacesIndex.size()-2&&spacesIndex[j+1]!=line.size()-1){
            result.push_back(stol(line.substr(spacesIndex[j+1])));
        }
        
    }
    return result;
}

int main (){
    vector<string> uncleanedData;
    ifstream input("input.txt");
    string line;
    while(getline(input,line)){
        uncleanedData.push_back(line);
    }
    vector<vector<long>> cleanedData;
    long sum =0;
    string operators = getOperations(uncleanedData[uncleanedData.size()-1]);
    for(int i =0;i<uncleanedData.size()-1;i++){
        cleanedData.push_back(cleanLine(uncleanedData[i]));
    }
    long result;
    for(int i =0;i<operators.length();i++){
        if(operators[i]=='+'){
             result =0;
        }
        else{
             result = 1;
        }
        for(auto lines:cleanedData){
            if(operators[i]=='+'){
                result +=lines[i];
            }
            else{
                result *= lines[i];
            }
        }
        sum +=result;
    }
    cout<<sum<<endl;

    return 0;
}