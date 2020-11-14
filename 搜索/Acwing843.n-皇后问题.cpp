#include<iostream>

using namespace std;
const int N = 10;
char g[N][N];
int q[N],n; 
bool check(int x){ // ��̽��x�з��õĻʺ���û������ 
	for(int i=0;i<x;i++){
		if(q[i]==q[x]||abs(i-x)==abs(q[i]-q[x])) return false;
	}
	return true;
}
void dfs(int u){
	if(u==n){
		for(int i=0;i<n;i++) cout << g[i] << endl;
		cout << endl;
		return ;
	}
	for(int i=0;i<n;i++){
		q[u] = i;
		if(check(u)){
		    g[u][i] = 'Q';
			dfs(u+1);
			g[u][i] = '.';
		}
	}
}
int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) g[i][j] = '.';
	}
	dfs(0);
	return 0;
} 
