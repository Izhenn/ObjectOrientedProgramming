#include<iostream>
using namespace std;
int main(){
	int a[50],n,temp,value;
	temp=0;
	for(int i=0;i<49;i++){
		a[i]=0;
	}
	a[49]=1;
	cout<<"請輸入一個不為零的整數"<<endl;
	cin>>n;
	if(n<0){
		cout<<"數字需大於零，請重新輸入"<<endl; 
		cin>>n;
	} 
	else if(n == 0){
		cout<<"1"<<endl;
	}
	else{
		for(int i=1;i<=n;i++){
			temp=0;
			for(int m=49;m>=0;m--){
				value=i*a[m]+temp;
				a[m]=value%10;
				temp=value/10;
			}	
		}
	}
	int p=0;
	while(a[p]==0 && p<49){
		p++;
	}
	
	for(int i=p;i<50;i++){	//用來檢視現在50位數為多少 
		cout<<a[i];
		
		
		
	}
	
} 
