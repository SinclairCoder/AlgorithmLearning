#include<iostream>

using namespace std;
int n;
// ʱ��ֱ�����ֵ���Ƚ� 
int main(){
	string open_time,open_id,close_time,close_id;
	cin >> n;
	for(int i=0;i<n;i++){
		string in_time,id,out_time;
		cin >> id >> in_time >> out_time;
		if(!i||in_time<open_time){
			open_time = in_time ;
			open_id = id;
		}
		if(!i||out_time>close_time){
			close_time = out_time;
			close_id = id;  
		} 
	}
	cout << open_id << ' ' << close_id;
} 
