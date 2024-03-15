#include<iostream>
using namespace std;
class node{
private:
	int no;
	node *ptr = NULL;
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
	node *head = NULL;
	node *current ;
	node *r=NULL;
	node *q=head;
	node *temp=NULL;
	int n;
	cout<<"Please input no."<<endl;
	
	cin >> n;
	while(n > 0){
		node *p = new node;
		p->writeno(n);
		p->writeptr(NULL);
		if(head == NULL){
			head=p;
		}
		else{
			r=NULL;
			q=head;
			temp=NULL;
			if(n < q->readno()){
				//r->writeptr(p);
				p->writeptr(head);
				head=p;
			}
			else{
				r=head;
				q=r->readptr();
				
				while(q != NULL){
					if (n < q->readno()) break;
					r = q;
					q = q->readptr();
				}
				r->writeptr(p);
				p->writeptr(q);
			}
		}
		cin >> n;
	}
	printlist(head);
	
}  


