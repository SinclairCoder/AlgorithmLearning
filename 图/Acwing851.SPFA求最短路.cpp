#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int N = 1e5+100;
int e[N],ne[N],h[N],w[N],idx;
int dist[N];
// ����Ƿ��ڶ�����
bool st[N]; 
int n,m;
// ���һ����aָ��b��ȨΪc�ı�
void add(int a,int b,int c){
    e[idx]=b,ne[idx]= h[a], w[idx] = c, h[a] = idx++;
}
int spfa(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    // �����������
    queue<int> q;
    q.push(1);
    st[1] = true;
    while(q.size()){
        int t = q.front(); q.pop();
        st[t] = false;
        // ����t�����г���
        for(int i=h[t];i!=-1;i=ne[i]){
            int j = e[i];
            // ���¾���
            if(dist[j]>dist[t]+w[i]){
                dist[j]=dist[t]+w[i];
                // ����õ㲻�ڶ�����
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
                
            }
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    else return dist[n];
}
int main(){
    cin >> n >> m;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
    }
    int t = spfa();
    if(t==-1) puts("impossible");
    else cout << t << endl; 
    return 0;
}
