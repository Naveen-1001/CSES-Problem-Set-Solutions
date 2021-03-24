#include <bits/stdc++.h>
using namespace std;
 
string s;int a[7][7];
 
bool isWallPartitioned(int x,int y){
		if(x==0&&y>0&&y<6&&a[1][y]==1&&a[0][y+1]==0&&a[0][y-1]==0)return true;
        if(x==6&&y>0&&y<6&&a[5][y]==1&&a[6][y+1]==0&&a[6][y-1]==0)return true;
        if(y==0&&x>0&&x<6&&a[x][1]==1&&a[x+1][0]==0&&a[x-1][0]==0)return true;
        if(y==6&&x>0&&x<6&&a[x][5]==1&&a[x+1][6]==0&&a[x-1][6]==0)return true;
        else return false;
}
bool isLooped(int x,int y){
	if(x==0||x==6||y==0||y==6)return false;
	if(a[x][y+1]==1&&a[x][y-1]==1&&a[x-1][y]==0&&a[x+1][y]==0)return true;
	if(a[x+1][y]==1&&a[x-1][y]==1&&a[x][y+1]==0&&a[x][y-1]==0)return true;
	return false;
}
 
 
int solve(int x,int y,int i){
 
	if(x==6&&y==0){
		if(i==48)return 1;
		return 0;
	}
	if(i==48){
		return 0;
	}
	if(isWallPartitioned(x,y))return 0;
	if(isLooped(x,y))return 0;
	if(s[i]=='?'){
		int r[]={0,1,0,-1};
		int c[]={-1,0,1,0};
		int k=0;
		for(int j=0;j<4;j++){
			int xx= x+r[j];
			int yy= y+c[j];
			if(xx<0||xx>6)continue;
			if(yy<0||yy>6)continue;
			if(a[xx][yy]==1)continue;
			a[xx][yy]=1;
			k+=solve(xx,yy,i+1);
			a[xx][yy]=0;
		}
		return k;
	}
 
	if(s[i]=='L')y--;
	else if(s[i]=='R')y++;
	else if(s[i]=='D')x++;
	else if(s[i]=='U')x--;
	if(x<0||x>6)return 0;
	if(y<0||y>6)return 0;
	if(a[x][y]==1)return 0;
	a[x][y]=1;
	int k=solve(x,y,i+1);
	a[x][y]=0;
	return k;
 
}
 
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	a[0][0]=1;
	cin>>s;
	cout<<solve(0,0,0);
	return 0;
}