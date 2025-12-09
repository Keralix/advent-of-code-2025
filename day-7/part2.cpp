#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct tachyon{
    int loc;
    int value;
};
long dropBox(vector<string> data){
    int R = data.size();
    int C = data[0].size();
    vector<vector<long>> dp(R,vector<long>(C,0));
    dp[0][(data[0].find('S'))]=1;
    for(int r =0;r<R-1;r++){
        for(int c =0;c<C;c++){
            long val = dp[r][c];
            if(val==0) continue;
            if(data[r+1][c]=='^'){
                dp[r+1][c-1]+=val;
                dp[r+1][c+1]+=val;
            }else{
                dp[r+1][c]+=val;
            }
        }
    }
    long sum =0;
    for(int i=0;i<C;i++) sum+=dp[R-1][i];
    return sum;    
}
void drawBeam(vector<string> *data){
    set<int> beamLoc;
    int size = (*data)[0].size();
    vector<tachyon> timelines;
    beamLoc.insert((*data)[0].find('S'));
    for(int i =1;i<data->size();i++){
        if((*data)[i].find_first_not_of(".")==string::npos){
            for(int id:beamLoc){
                (*data)[i][id]='|';
            }
        }
        else{
            for(int j=0;j<size;j++){
                if((*data)[i][j]=='^'){
                    if(beamLoc.find(j)!=beamLoc.end()){
                        beamLoc.erase(j);
                        beamLoc.insert(j-1);
                        beamLoc.insert(j+1);
                    }
                }
            }
            for(int id:beamLoc){
                (*data)[i][id]='|';
            }
        }
    }
}
int main(){
    fstream input("input.txt");
    vector<string> map;
    string line;
    while(getline(input,line)){
        map.push_back(line);
    }
    long sum=0;
    drawBeam(&map);
    sum=dropBox(map);
    cout<<sum<<endl;
    return 0;
}