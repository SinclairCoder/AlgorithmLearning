#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
	��ԭ������
	����һ�ö�����������������к�����������У�Ҫ�����ö������ĸ߶ȡ� 
	����������
	9
	ABDFGHIEC
	FDHGIBEAC
	���������
 	5 
*/
#define N 52
int dfs(char pre[],char in[],int n){
	if(!n) return 0;
	int i;
	for(i=0;i<n;i++)
		if(in[i]==pre[0])
			break;
	int res1 = dfs(pre+1,in,i)+1;
	int res2 = dfs(pre+i+1,in+i+1,n-i-1)+1;
	return max(res1,res2);
}
int main(){
	int n;
	cin >> n;
	char pre[N],in[N];
	scanf("%s",pre);
	scanf("%s",in);
	cout << dfs(pre,in,n);
	return 0;
}

