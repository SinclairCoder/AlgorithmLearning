#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;
const int N = 1e5+100;
int e[N],ne[N],h[N],w[N],idx;
// dist��ʾ����һ�㵽��ǰ��ľ��룬cnt��ʾ����һ�㵽��ǰ����̾����Ӧ�ı���
int dist[N],cnt[N];
// ����Ƿ��ڶ�����
bool st[N];
int n,m;
// ���һ����aָ��b��ȨΪc�ı�
void add(int a,int b,int c){
    e[idx] = b,ne[idx]= h[a],w[idx]= c, h[a] = idx++;
}
bool spfa(){
//   ����������SPFA�����·�����ﲻ�ó�ʼ��Ĭ��Ϊ0����Ϊ��Ȩ�ߵĴ��ڣ�ʼ�ջ������̾���ĸ��� 
//    memset(dist,0x3f,sizeof dist);
//    dist[1] = 0;
    queue<int> q;
    // ��Ϊ��㲻һ���Ǵ�1��ʼ�������ȫ���㶼�ӵ��������棬�϶������ҵ�����
    for(int i=1;i<=n;i++) {
        q.push(i); st[i] = true;
    }
    while(q.size()){
        // ������ͷ
        int t = q.front(); q.pop(); st[t] = false;
        // �������г���
        for(int i=h[t];i!=-1;i=ne[i]){
            int j = e[i];
            /// ���¾���
            if(dist[j]>dist[t]+w[i]){
                dist[j] = dist[t]+w[i];
                cnt[j] = cnt[t]+1;
                // ����������ı߲�С��n���ǿ϶��и�Ȩ��
                if(cnt[j]>=n) return true;
                if(!st[j]){
                    q.push(j); st[j] = true;
                }
            }
        }
    }
    return false;
}
int main(){
    cin >> n >> m;
    // һ��Ҫ��ʼ��
    memset(h,-1,sizeof h);
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
    }
    if(spfa()) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
