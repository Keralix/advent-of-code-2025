#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int getNumberOfNeighburs ( vector<string> data, int x, int y, int width, int height){
    int result = 0;
    if( (x==0||x==width-1)&&(y==0||y==height-1)) return result;
    if(x==0){
        if(data[y-1][x]=='@') result++;
        if(data[y+1][x]=='@') result++;
        if(data[y][x+1]=='@') result++;
        if(data[y+1][x+1]=='@') result++;
        if(data[y-1][x+1]=='@') result++;
    }
    else if(x==width-1){
        if(data[y-1][x]=='@') result++;
        if(data[y+1][x]=='@') result++;
        if(data[y][x-1]=='@') result++;
        if(data[y+1][x-1]=='@') result++;
        if(data[y-1][x-1]=='@') result++;
    }
    else if(y==0){
        if(data[y][x+1]=='@') result++;
        if(data[y+1][x]=='@') result++;
        if(data[y][x-1]=='@') result++;
        if(data[y+1][x+1]=='@') result++;
        if(data[y+1][x-1]=='@') result++;
    }
    else if(y==height-1){
        if(data[y][x+1]=='@') result++;
        if(data[y-1][x]=='@') result++;
        if(data[y][x-1]=='@') result++;
        if(data[y-1][x+1]=='@') result++;
        if(data[y-1][x-1]=='@') result++;
    }
    else{
        if(data[y][x+1]=='@') result++;
        if(data[y][x-1]=='@') result++;
        if(data[y-1][x]=='@') result++;
        if(data[y+1][x-1]=='@') result++;
        if(data[y-1][x-1]=='@') result++;
        if(data[y+1][x]=='@') result++;
        if(data[y+1][x+1]=='@') result++;
        if(data[y-1][x+1]=='@') result++;
    }
    return result;
}

int main(){

    ifstream input{"input.txt"};
    int sum = 0;
    string line;
    vector<string> data;
    while (getline(input,line))
    {
        data.push_back(line);
    }
    int width = line.length();
    int height = data.size();

    vector<int> cords;
    do
    {
        cords.clear();
        for(int y=0;y<height;y++){
            for(int x=0;x<width;x++)
            if(data[y][x]=='@'&&getNumberOfNeighburs(data,x,y,width,height)<4) {
                
                cords.push_back(x);
                cords.push_back(y);
            }
        }
        for(int i =0;i<cords.size();i+=2){
            data[cords[i+1]][cords[i]]='.';
        }
        sum+=cords.size()/2;
    } while (!cords.empty());
    
        

    
    cout<<sum<<endl;
    return 0;


}