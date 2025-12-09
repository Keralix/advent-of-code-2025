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
    double result =0;
    auto firstConverted = convertSTOI(first);
    auto secondConverted=convertSTOI(second);
    result = sqrt(pow(secondConverted[0]-firstConverted[0],2)+pow(secondConverted[1]-firstConverted[1],2)+pow(secondConverted[2]-firstConverted[2],2));
    return result;
}
bool sortDistances(const Distance &a,const Distance&b){
    return a.distance <b.distance;

}

std::unordered_map<std::string, int> idMap;
std::vector<int> parentUF;
std::vector<int> sizeUF;
int nextId = 0;

int getId(const std::string& s){
    if(idMap.count(s)) return idMap[s];
    idMap[s] = nextId++;
    return idMap[s];
}

void makeSet(int n){
    parentUF.resize(n);
    sizeUF.resize(n);
    for(int i = 0; i < n; i++){
        parentUF[i] = i;
        sizeUF[i] = 1;
    }
}

int findSet(int x){
    if(parentUF[x] == x) return x;
    parentUF[x] = findSet(parentUF[x]);
    return parentUF[x];
}

void unionSets(int a, int b){
    a = findSet(a);
    b = findSet(b);
    if(a == b) return;

    if(sizeUF[a] < sizeUF[b])
        std::swap(a, b);

    parentUF[b] = a;
    sizeUF[a] += sizeUF[b];
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
            Distance newDistance;
            newDistance.distance=calculateDistance(junctions[i],junctions[j]);
            newDistance.start=junctions[i];
            newDistance.end= junctions[j];
            distances.push_back(newDistance);
        }
    }
    std::sort(distances.begin(),distances.end(),sortDistances);
     for(auto& d : distances){
        getId(d.start);
        getId(d.end);
    }
    int N = nextId;
    makeSet(N);

    int K = junctions.size();
    for(int i = 0; i < K; i++){
        int a = getId(distances[i].start);
        int b = getId(distances[i].end);
        unionSets(a, b);
    }

    std::unordered_map<int, int> groups;

    for(int i = 0; i < N; i++){
        int root = findSet(i);
        groups[root] = sizeUF[root];
    }

    std::vector<int> sizes;
    for(auto& g : groups){
        sizes.push_back(g.second);
    }

    std::sort(sizes.begin(), sizes.end(), std::greater<>());
    int result = 1;
    std::cout<<sizes.size()<<'\n';
    for(int i = 0;i < sizes.size(); i++){
        result *= sizes[i];
    }

    std::cout << result << "\n";

}