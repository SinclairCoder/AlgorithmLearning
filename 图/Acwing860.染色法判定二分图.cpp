#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+100,M = 2*N;
int e[M],ne[M],h[N],idx;
int n,m;
// ��¼ÿ�������ɫ
int color[N];
void add(int a,int b){
    e[idx] = b , ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u,int c){
    color[u] = c;
    for(int i=h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(!color[j]){
            if(!dfs(j,3-c)) return false;
        }
        // ����������ڵ��Ⱦɫ��һ���ģ������ì��
        else if(color[j]==c) return false;
    }
    return true;
}

int main(){
    cin >> n >> m;
    // һ��Ҫ��ʼ��
    memset(h,-1,sizeof h);
    while(m--){
        int a,b;
        cin >> a >> b;
        // ����ͼ
        add(a,b), add(b,a);
    }
    bool flag = true;
    for(int i=1;i<=n;i++){
        if(!color[i]){
            if(!dfs(i,1)){
                flag = false; break;
            }
        }
    }
    if(flag) puts("Yes");
    else puts("No");
    return 0;
}
