#include<bits/stdc++.h>
using namespace std;

#define rep(i,m,n) for(int i=m;i<n;i++)
#define pb push_back

int res = 0;
void print(int a[],int n,int x){
	int j = 0; // Ҳ����j��Ϊn,ֻ�ǻ�������˳�� 
	cout << "{";
	while(x){
		if(x&1) {
			cout << a[j];
			if(x>=2) cout << " "; // �����ʽ���� 
		}
		x >>= 1;j++;
	}
	cout << "}";
	cout << endl;
	res++;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	rep(i,0,n)
		cin >> a[i];
	rep(i,0,1<<n){
		print(a,n,i);
	}
	cout << "Total��" << res ; 
}
