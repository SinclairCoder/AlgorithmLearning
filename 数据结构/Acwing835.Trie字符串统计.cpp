#include<iostream>

using namespace std;
const int N = 1e5+100;
// son�����ʾ��ǰ�ڵ�ĺ��ӽڵ���±꣬son[1][0]=2��ʾ1����һ��ֵΪa���ӽ��Ϊ���2
// cnt��ʾĳһ�±� ��Ӧ���ַ����ĸ������ԡ�abc���ַ���Ϊ�������һ���ַ�---��c����Ӧ��idx��Ϊcnt������±ꡣ�����ֵ�Ǹ�idx��Ӧ�ĸ�����
// idx ������ʾ�±�
// �±�Ϊ0�ĵ㣬���Ǹ��ڵ㣬���ǿսڵ�
int son[N][26], cnt[N],idx;
char str[N];

void insert(char str[]){
    int p = 0; // �Ӹ��ڵ��ߣ�û�нڵ�ʹ����ڵ�
    for(int i=0;str[i];i++){
        int u = str[i]-'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char str[]){
    int p = 0;
    for(int i=0;str[i];i++){
        int u = str[i]-'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main(){
    int n;
    cin >> n;
    char op;
    while(n--){
        cin >> op >> str;
        if(op=='I') insert(str);
        else cout << query(str) << endl;
    }
    return 0;
}
