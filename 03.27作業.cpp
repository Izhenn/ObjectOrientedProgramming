//�ھڤW�����@�~�@�ק�A�`�I�ݩʦ��y��(no)�B�m�W(char name[10])�B�{�]���Z(prg)�B�p�����Z(cmp)�P�U�@�����(*ptr)�A
//�`�I�Ѥp��j��_�ӡA�B���঳���Ʈy���A��X���禡���ܡA�@�˥u��X�y���C
#include<iostream>
using namespace std;
class node{
	private:
		int no;
		node *ptr;
		char name[10];
		int prg;  //���Z1 
		int cmp;  //���Z2 
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
    		cout<<"�w���ۦP�y���A�Э��s��J"<<endl;
//    	p->writeptr(head);
//    	head=p;
    	
		}
	cout<<"Please input no:";
	cin>>n;
	}
	printlist(head);
}
