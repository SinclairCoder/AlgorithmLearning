#include<bits/stdc++.h>

using namespace std;

#define rep(i,m,n) for(int i=m;i<n;i++)
#define MAXN 20
int maxv;   // ������Ž��ܼ�ֵ
int n;		// ��Ʒ���� 
int W; 		// ������ 
int x[MAXN];
void disp(){
	cout << "ѡ����Ʒ���±꣺";
	rep(i,0,n)
		if(x[i]) cout << i << " ";
	cout << endl; 
	cout << "����ֵΪ: " << maxv << endl;
}
void dfs(int i,int tw,int tv,int rw,int op[],int w[],int v[]){
	if(i>=n){
		if(tw==W&&tv>maxv){
			maxv = tv;
			rep(j,0,n)	x[j] = op[j];
		}
	}
	else {
		if(tw+w[i]<=W){  // ���뵱ǰ��Ʒ������С�������� ��������� 
			op[i] = 1;
			dfs(i+1,tw+w[i],tv+v[i],rw-w[i],op,w,v);
		}
		op[i] = 0;  //  ����д�������if������� 
		if(rw+tw>W){  // ֻ�е�ǰ������������ʣ��δ������������Wʱ��������ǰ��Ʒ������ 
			dfs(i+1,tw,tv,rw-w[i],op,w,v); //  ���ܲ��ŵ�ǰ��Ʒ��rw����Ҫ��ȥw[i] 
		} 
	}
} 
int main(){
	cin >> n; 
	cin >> W; 
	int w[n],v[n],op[n],rw;
	memset(op,0,sizeof(op));
	rep(i,0,n) {
		cin >> w[i]; rw += w[i]; 
	}
	rep(i,0,n) cin >> v[i];
	dfs(0,0,0,rw,op,w,v);
	disp();
	
	return 0;
} 
