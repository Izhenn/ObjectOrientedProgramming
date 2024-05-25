//根據上次的作業作修改，節點屬性有座號(no)、姓名(char name[10])、程設成績(prg)、計概成績(cmp)與下一筆資料(*ptr)，
//節點由小到大串起來，且不能有重複座號，輸出的函式不變，一樣只輸出座號。
#include<iostream>
using namespace std;
class node{
	private:
		int no;
		node *ptr;
		char name[10];
		int prg;  //成績1 
		int cmp;  //成績2 
	public:
		node():no(),ptr(){}
		void writeno(int a){
			no=a;
		}
		int readno(){
			return no;
		}
		void writeptr(node *b){
			ptr=b;
		}
		node *readptr(){
			return ptr;
		}
		void writename(const char *x){
			name[10]=*x;
		}
		const char *readname(){
			return name;
		}
		void writeprg(int y){
			prg=y;
		}
		int readprg(){
			return prg;
		}
		void writecmp(int z){
			cmp=z;
		}
		int readcmp(){
			return cmp;
		}
		
	int operator+(node&p){
		return no+p.no;
	}
};

//void insert(node*& head,int n,const char* x, int y, int z) {
//    node* p = new node();
    

    
//    p->writeptr(temp->readptr());
//    temp->writeptr(p);
//}

void printlist(node *p){
	cout<<"head->";
	while(p){
		cout<<p->readno()<<"->";
		p=p->readptr();
	}
	cout<<"H"<<endl;
}
int main(){
	node *head=NULL;
	int n;
	char x[10];
	int y,z;
	node* temp=head;
	node* p = new node();
	cout<<"Please input no:";
	cin>>n;
	while(n>0){
		node* q=NULL;
		node* temp=head;
    	while (temp&& temp->readno()!= n) {
        	temp=temp->readptr();
    	}
    	if (temp==NULL) {
    		cout <<"name:";
	        cin>>x;
	        cout<<"prg grade:";
	        cin>>y;
	        cout<<"cmp grade:";
	        cin>>z;
	        p->writeno(n);
    	p->writename(x);
    	p->writeprg(y);
    	p->writecmp(z);
    	p->writeptr(NULL);
//            insert(head,n,x,y,z);
    	}
    	else{
    		cout<<"已有相同座號，請重新輸入"<<endl;
//    	p->writeptr(head);
//    	head=p;
    	
		}
	cout<<"Please input no:";
	cin>>n;
	}
	printlist(head);
}
