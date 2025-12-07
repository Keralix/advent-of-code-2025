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

    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++)
        if(data[y][x]=='@'&&getNumberOfNeighburs(data,x,y,width,height)<4) sum++;
    }
    cout<<sum<<endl;
    return 0;


}