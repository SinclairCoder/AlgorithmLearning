
#include<bits/stdc++.h>

using namespace std;

#define rep(i,m,n) for(int i=m;i<n;i++)
#define maxn 200

/*
	n������ k���� m����ɫ 
	ÿ���ߵ�����������ɫ������ͬ
	���ж�������ɫ���� 
*/
int adj[maxn][maxn];
int n,k,m;
int cnt = 0 ;
int x[maxn];
void disp(){
	printf("��%d����ɫ������",++cnt);
	rep(i,0,n)
		cout << x[i] << " ";
	cout << endl;
}
bool same(int i){
	rep(j,0,n){
		if(adj[i][j]==1&&x[i]==x[j])
			return false;
	}
	return true;
}

void dfs(int i){
	if(i==n){
		disp();
		return ;
	}
	else {
		rep(j,1,m+1){
			x[i] = j;
			if(same(i))
				dfs(i+1);
			x[i] = 0;
		}
	}
}

int main(){
	int x,y;
	cin >> n >> k >> m;
	rep(i,0,k){
		cin >> x >> y;
		adj[x][y] = 1;
		adj[y][x] = 1;
	}
	dfs(0);
	return 0;
} 
