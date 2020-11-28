#include<bits/stdc++.h>

using namespace std;
const int N = 510,INF = 0x3f3f3f3f;
// �洢����ͼ
int g[N][N];
// �洢��ǰ�㵽���ϵľ���
int dist[N];
// ��ǰ���Ƿ��ڼ�����
bool st[N];
int n,m;
int prim(){
    memset(dist,0x3f,sizeof dist);
    int res = 0;
    // ��1Ϊ���
    dist[1] = 0; 
    for(int i=0;i<n;i++){
        int t = -1;
        // �Ӳ��ڼ����е����е����ҵ����뼯�������
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dist[t]>dist[j])) t = j;
        }
        // ��������ҵ�����������Ϊ�������ֱ�ӷ���
        if(dist[t]==INF) return INF;
        // ���������뼯��
        st[t] = true;
        res+= dist[t];
        // ���¼�����ĵ㵽���ϵ���̾���
        for(int j=1;j<=n;j++){
            if(!st[j]) dist[j] = min(dist[j],g[t][j]);
        }
    }
    return res;
}
int main(){
    cin >> n >> m;
    // ͼһ��Ҫ��ʼ��
    memset(g,0x3f,sizeof g);
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        // �رߺ��Ի�
        g[a][b] = g[b][a] = min(g[a][b],c);
    }
    int t = prim();
    if(t==INF) puts("impossible");
    else cout << t << endl;
    return 0;
}
