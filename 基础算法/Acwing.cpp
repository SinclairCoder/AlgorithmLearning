#include<iostream>

using namespace std;

const int N = 1e5+10;
// aΪԭ���飬bΪ������飬����b��һ��ǰ׺�ͼ��ɵõ���� 
int a[N],b[N];
int n,m; 
void insert(int l,int r,int c){
	b[l] += c;
	b[r+1] -= c;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	// b�ȸ���һ��a��������insert����
	for(int i=1;i<=n;i++) insert(i,i,a[i]); 
	int l,r,c;
	while(m--){
		scanf("%d%d%d",&l,&r,&c);
		insert(l,r,c); 
	}
	for(int i=1;i<=n;i++) b[i]+= b[i-1];
	for(int i=1;i<=n;i++){
		if(i==1) printf("%d",b[i]);
		else printf(" %d",b[i]);
	}
	return 0;
} 
