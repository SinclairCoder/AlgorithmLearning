#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> div(vector<int>&A,int b,int &r){
    // r 为余数，C为商
	r = 0;
	vector<int> C;
	// 注意逆序 
	for(int i=A.size()-1;i>=0;i--){
		r = r*10+ A[i];
		C.push_back(r/b);
		r %= b;
	}
	reverse(C.begin(),C.end());
	while(C.size()>1&&C.back()==0) C.pop_back();
	return C;
}

int main(){
	string a;
	int b;
	cin >> a >> b;
	vector<int> A,C;
	for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
	int r;
	C = div(A,b,r);
	for(int i=C.size()-1;i>=0;i--) cout << C[i];
	cout << endl;
	cout << r << endl;
	return 0;

