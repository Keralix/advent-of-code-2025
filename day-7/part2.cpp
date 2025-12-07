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
void drawBeam(vector<string> *data, int *sum){
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
    int sum=0;
    drawBeam(&map,&sum);

    cout<<sum<<endl;
    return 0;
}