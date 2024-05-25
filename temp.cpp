#include<iostream>
using namespace std;
class node{
		int no;
		node *ptr;
		public:
		void writeno(int a){
			no=a;
		}
		int readno(){
			return no;
		}
		void writeptr(node *b){
			ptr=b;
		}
		node* readptr(){
			return ptr;
		}
	};
	
	void printlist(node *p){
		cout<<"head->";
		while(p){
			cout<<p->readno()<<"->";
			p=p->readptr();
		}
		cout<<"H"<<endl;
	}
int main(){
//	while(1){
//		new int[1000000];
//	}
	
	node *head=NULL;
	node *p;
	int n;
	p=new node;
	cout<<"Please input no."<<endl;
	cin>>n;
	p->writeno(n);
	p->writeptr(head);
	head=p;
	printlist(p);
	
} 
