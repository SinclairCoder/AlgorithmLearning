#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int M = 1e4+100, N = 510;
struct Edge{
    int a,b,w;
}arr[M];
// backupΪdist�ı������飬����һ�ε����ݣ�dist����backup���и���
int dist[N],backup[N];
int m,n,k;
int bellman_ford(){
    // �Ծ��������ʼ��
    memset(dist,0x3f,sizeof dist);
    // ��������ľ���Ϊ0
    dist[1] = 0;
    // k���ߵ�����
    for(int i=0;i<k;i++){
        // backup�������dist�����ݣ�Ȼ�����µ�ѭ���У�dist�ù�ȥ������Ҳ����backup���и���
        memcpy(backup,dist,sizeof dist);
        for(int j=0;j<m;j++){
            auto e = arr[j];
            // ÿ��ֻ�ɳ�һ����
            dist[e.b] = min(dist[e.b],backup[e.a]+e.w);
        }
    }
    // ��Ϊ�и�Ȩ�ߣ����Բ�һ��������������ܻ�СһЩ
    if(dist[n]>0x3f3f3f3f/2) return -1;
    else return dist[n];
}
int main(){
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&arr[i].a,&arr[i].b,&arr[i].w);
    }
    int t = bellman_ford();
    if(t==-1) puts("impossible");
    else cout << t << endl;
    return 0;
}
