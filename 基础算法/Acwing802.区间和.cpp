#include<iostream>
#include<algorithm>
#include<vector> 
using namespace std;

const int N = 300000+10;
typedef pair<int,int> PII;
int n,m;
// ����ӷ���������ѯ���� 
vector<PII> add,query;
// ӳ��֮�������Ϊa,a��ǰ׺��Ϊs 
int a[N],s[N];
// �������г��ֵ�λ�ã������� 
vector<int> alls;

int find(int x){
	int l = 0,r = alls.size()-1;
	while(l<r){
		int mid = l+r+1>>1;
		if(alls[mid]>x) r = mid-1;
		else l = mid;
	}
	return r+1;
} 
vector<int>::iterator unique(vector<int>& a){
	int j = 0;
	for(int i=0;i<a.size();i++){
		if(!i||a[i]!=a[i+1]) a[j++] = a[i];
	}
	return a.begin()+j;
}
int main(){
	cin >> n >>m;
	for(int i=0;i<n;i++){
		int x,c;
		cin >> x >> c;
		add.push_back({x,c});
		alls.push_back(x);		
	}
	for(int i=0;i<m;i++){
		int l,r;
		cin >> l >> r;
		alls.push_back(l), alls.push_back(r);
		query.push_back({l,r});
	}
	// ȥ�� 
	sort(alls.begin(),alls.end());
//	alls.erase(unique(alls.begin(),alls.end()),alls.end());
	alls.erase(unique(alls),alls.end());
	//  �������
	for(auto &item:add){
		int x = find(item.first);
		a[x] += item.second; 
	}
	// Ԥ����ǰ׺�� 
	for(int i=1;i<=alls.size();i++) s[i] = s[i-1] + a[i];
	// ����ѯ��
	for(auto& item:query){
		int l = find(item.first), r = find(item.second);
		cout << s[r] - s[l-1] << endl;
	} 
	return 0;
} 
