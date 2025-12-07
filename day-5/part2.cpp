#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> combineRanges(vector<string> ranges){
     vector<pair<long, long>> parsed;

    for (auto& r : ranges) {
        long pos = r.find('-');
        long start = stol(r.substr(0, pos));
        long end = stol(r.substr(pos + 1));
        parsed.push_back({start, end});
    }

    sort(parsed.begin(), parsed.end());

    vector<pair<long, long>> merged;
    long start = parsed[0].first;
    long end = parsed[0].second;

    for (int i = 1; i < parsed.size(); i++) {
        long s = parsed[i].first;
        long e = parsed[i].second;

        if (s <= end) {
            end = max(end, e);
        } 
        else {
            merged.push_back({start, end});
            start = s;
            end = e;
        }
    }

    merged.push_back({start, end});
    vector<string> result;
    for (auto& p : merged) {
        result.push_back(to_string(p.first) + "-" + to_string(p.second));
    }

    return result;
}
int main(){
    ifstream input("input.txt");
    vector<string> rangesLines;
    string line;
    long sum=0;
    vector<long> validIDs;
    while(getline(input,line)){
        if(line.size()==0) break;
        else if(line.find('-')!=-1){
            rangesLines.push_back(line);
        }
    }
    vector<string> combined = combineRanges(rangesLines);
    for(string r : combined) {
        long pos = r.find('-');
        long start = stol(r.substr(0, pos));
        long end = stol(r.substr(pos + 1));
        sum += end-start+1;
    }
    cout<<sum<<endl;
    return 0;
}