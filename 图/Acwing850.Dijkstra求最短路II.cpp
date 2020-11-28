#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1e6+10;
typedef pair<int,int> PII;
// ϡ��ͼ���ڽӱ�洢
int h[N],w[N],e[N],ne[N],idx;
int dist[N]; // �������ľ���
bool st[N]; // ����Ƿ��Ѹ���Ϊ��̾���
int n,m;
// ��һ��aָ��b�ıߣ�Ȩ��Ϊc
void add(int a,int b,int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}
int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1}); // ��һ�ؼ����Ǿ��룬�ڶ��ؼ����Ǳ��
    while(heap.size()){
        int distance = heap.top().first, id = heap.top().second;
        heap.pop();
        if(st[id]) continue; // ����Ѿ����¹��˾�����
        st[id] = true; 
        for(int i = h[id];i!=-1;i=ne[i]){
            int j = e[i];
            if(dist[j]>dist[id]+w[i]){
                dist[j] = dist[id]+w[i]; // ���¾���
                heap.push({dist[j],j}); 
            }
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    else return dist[n];
}
int main(){
    cin >> n >>m;
    // ��ʼ������ͷ
    memset(h,-1,sizeof h);
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
    }
    cout << dijkstra() << endl;
    return 0;
}
