//WaiseHi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        queue<pair<int,int>> q;
        int n=a.size();
        int m=a[0].size();
        int fresh=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(a[i][j]==2)
                    q.push({i,j});
                if(a[i][j] ==1)
                    fresh++;
            }
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        int t=-1;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                int x=q.front().first,y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i],ny=y+dy[i];
                    if(nx<0 || ny<0 || nx>=n || ny >= m || a[nx][ny]!=1)continue;
                    a[nx][ny]=2;
                    q.push({nx,ny});
                    fresh--;
                }
            }
                t++;
        }
        if(fresh>0)return -1;
        if(t==-1)return 0;
        return t;
    }
};
int main(){
    //here
    Solution s; 
    vector<vector<int>>a={{2,1,1},{0,1,1},{1,0,1}};
    cout<<s.orangesRotting(a);
    getch();
    return 0;
}