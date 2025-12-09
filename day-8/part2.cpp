#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <array>
#include <algorithm>
#include <unordered_map>

struct Distance{
    double distance;
    std::string start;
    std::string end;
};

std::array<int,3> convertSTOI(std::string number){
    std::array<int,3> result;
    for(int i = 0 ;i<3;i++){
        int pos = number.find(',');
        result[i]=stoi(number.substr(0,pos));
        number =number.substr(pos+1);
    }
    return result;
}

double calculateDistance(std::string first, std::string second){
    auto a = convertSTOI(first);
    auto b = convertSTOI(second);
    return sqrt(pow(b[0]-a[0],2)+pow(b[1]-a[1],2)+pow(b[2]-a[2],2));
}

bool sortDistances(const Distance &a,const Distance&b){
    return a.distance < b.distance;
}

std::vector<int> parentUF;
std::vector<int> rnkUF;

int findSet(int v){
    if(parentUF[v] == v) return v;
    return parentUF[v] = findSet(parentUF[v]);
}

void unionSets(int a, int b){
    a = findSet(a);
    b = findSet(b);
    if(a != b){
        if(rnkUF[a] < rnkUF[b]) std::swap(a,b);
        parentUF[b] = a;
        if(rnkUF[a] == rnkUF[b]) rnkUF[a]++;
    }
}

int main(){
    std::fstream file("input.txt");
    std::string line;
    std::vector<std::string> junctions;

    while(getline(file,line)){
        junctions.push_back(line);
    }

    std::vector<Distance> distances;

    for(int i = 0;i<junctions.size()-1;i++){
        for(int j=i+1;j<junctions.size();j++){
            distances.push_back({
                calculateDistance(junctions[i],junctions[j]),
                junctions[i],
                junctions[j]
            });
        }
    }

    std::sort(distances.begin(),distances.end(),sortDistances);

    std::unordered_map<std::string,int> idMap;
    int nextId = 0;
    auto getId = [&](const std::string &s){
        if(idMap.find(s)==idMap.end()) idMap[s] = nextId++;
        return idMap[s];
    };

    for(auto &d : distances){
        getId(d.start);
        getId(d.end);
    }

    parentUF.resize(nextId);
    rnkUF.assign(nextId,0);

    for(int i=0;i<nextId;i++) parentUF[i] = i;

    std::vector<std::string> idToName(nextId);
    for(auto &p : idMap) idToName[p.second] = p.first;

    int components = nextId;
    int lastA = -1, lastB = -1;

    for(size_t i = 0; i < distances.size() && components > 1; ++i){
        int a = getId(distances[i].start);
        int b = getId(distances[i].end);
        int ra = findSet(a);
        int rb = findSet(b);
        if(ra != rb){
            unionSets(ra, rb);
            components--;
            lastA = a;
            lastB = b;
        }
    }

   

    auto cA = convertSTOI(idToName[lastA]);
    auto cB = convertSTOI(idToName[lastB]);

    long long product = 1LL * cA[0] * cB[0];

    std::cout << product << "\n";

    return 0;
}
