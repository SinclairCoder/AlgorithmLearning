#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 510;
int g[N][N]; // ����ͼ���ڽӾ���
int dist[N]; // �������ľ���
bool st[N]; // ����Ƿ��ҵ���̾���
int n,m;

int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    // ѭ��n��
    for(int i=0;i<n;i++){
        int t = -1; // ��δ�ҵ���̾���ĵ�ļ������Ҿ��������̵ĵ�
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dist[j]<dist[t])) t = j;
        }
        st[t] = true; // ���б��
        for(int j=1;j<=n;j++){
            dist[j] = min(dist[j],dist[t]+g[t][j]);  // ���¾���
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;  //�����n����·��Ϊ����󼴲��������·��
    else return dist[n];
    
}

int main(){
    cin >> n >> m;
    // ���Ա����Ի�
    memset(g,0x3f,sizeof g);  // ���ֽڳ�ʼ��
    while(m--){
        int x,y,z;
        cin >> x >> y >> z;
        // �����رߵ����
        g[x][y] = min(g[x][y],z);
        
    }
    cout << dijkstra()<< endl;
    return 0;
}
