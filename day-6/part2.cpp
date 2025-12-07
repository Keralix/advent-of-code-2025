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
vector<string> reverseData(vector<string> oldData){
    vector<string> result;
    string number;
    string line;
    for(int i=0;i<oldData[0].size();i++){
        number.clear();
        for(int j=0;j<oldData.size()-1;j++){
            number+=oldData[j][i];
        }
        if(number.find_first_not_of(" ")==string::npos){
            result.push_back(line);
            line.clear();
        }else{
        number +=' ';
        line+=number;
        }
    }
    result.push_back(line);
    return result;
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

    vector<string> reversedData =reverseData(uncleanedData);

    for(int i =0;i<reversedData.size();i++){
        cleanedData.push_back(cleanLine(reversedData[i]));
    }
    long result;
    for(int i =0;i<operators.length();i++){
        if(operators[i]=='+'){
             result =0;
        }
        else{
             result = 1;
        }
        for(int j =0;j<cleanedData[i].size();j++){
            if(operators[i]=='+'){
                result +=cleanedData[i][j];
            }
            else{
                result *= cleanedData[i][j];
            }
        }
        sum +=result;
    }
    cout<<sum<<endl;

    return 0;
}