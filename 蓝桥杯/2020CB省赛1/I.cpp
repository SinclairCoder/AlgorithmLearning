#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int n,K;
const int N =  1e5+10;
ll a[N],res;
ll cnt[11][N];
void solve(){
	for(int i=0;i<n;i++){
		// ֮���Է����ڲ�ѭ�����棬Ҫ���ǵ�A_i A_i����� 
		int len_a = log10(a[i])+1;
		res += cnt[len_a][(K-a[i]%K)%K];
		for(int j=1,power=10;j<=10;j++){
			ll num = (a[i]%K)*power%K;
			cnt[j][num] ++;
			power = power*10%K;
		}
	}
}
int main(){
	cin >> n >> K;
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	solve();
	memset(cnt,0,sizeof cnt);
	// �ڶ�����Ҫ���ǵ�A_i A_j����� ����i>j 
	reverse(a,a+n);
	solve();
	cout << res << endl;
	return 0;
}
