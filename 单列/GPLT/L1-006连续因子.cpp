#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int n;
int main(){
	cin >> n;
	int maxl = sqrt(n)+1;
	// ans��1�������ڣ����Դ�0��ʼ 
	// st: ��������ӵĿ�ʼ��Ӧ�ô�0��ʼ������������0˵�����Ǹ�����������1 
	int ans = 0,st;
	for(int i=2;i<=maxl;i++){
		int tmp = 1,j;
		for(j=i;j<=maxl;j++){
			tmp*= j;
			// �������ӵ�ʱ��Ҫbreak 
			if(n%tmp!=0) break;
		}
		// ��ʱj����Ӧ�����ֲ�����Ҫ�� 
		if(j-i>ans){
			ans = j-i;
			st = i;
		}
	} 
	if(st==0){
		cout << "1" << endl;
		cout << n << endl;
	} 
	else {
		cout << ans << endl; 
		for(int i=st;i<st+ans;i++){
			if(i==st) cout << i;
			else cout << '*' << i;
		}
		cout << endl;
	}
	
	return 0;
} 
