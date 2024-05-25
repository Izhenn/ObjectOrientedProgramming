#include<iostream>
#include<cstring>
using namespace std;
class node{
private:
//	friend int operator+(node&,node&);
	int no;
	node *ptr = NULL;
	char name[10];
	int prg;		//programming score
	int cmp;		//score
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
	void writename(const char* c){
		strcpy(name,c);
	}
	const char* readname(){
		return name;
	}
	void writeprg(int e){
		prg=e;
	}
	int readprg(){
		return prg;
	}
	void writecmp(int e){
		cmp=e;
	}
	int readcmp(){
		return cmp;
	}
//	int operator+(node &p){
//	return no+p.no;	
//	}
};
class MENU{
	int select;
	public:
		void show(){
			cout<<"Menu"<<endl;
			cout<<"1.add"<<endl;
			cout<<"2.search"<<endl;
			cout<<"0.exit"<<endl;
			cout<<"Please select a choice:";
		}
		void sel(){
			cin>>select;
		}
		int showsel(){
			return select;
		}
//		MENU(){
//			select=1;
//		}
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
	node *r=NULL;
	node *q=head;
	node *temp=NULL;
	node *m=NULL;
	int n,score1,score2,select;
	char name1[10];
	MENU mm;
	mm.show();
//	cin>>select;
	select=1;
	while(mm.showsel()){
//		mm.show();
		mm.sel();
		switch(mm.showsel()){
			case 1:
				cout<<"Please input no."<<endl;
				cin >> n;
				while(n > 0){
					m=head;
					while(m&&m->readno()!=n){	//find repeat no
						m=m->readptr();
					}
					if(m==NULL){		//no repeat
						cout<<"Please enter the name."<<endl;
						cin >> name1;
						cout<<"please enter programming score."<<endl;
						cin >> score1;
						cout<<"please enter computer score."<<endl;
						cin >> score2;
						node *p = new node;
						p->writeno(n);
						p->writeptr(NULL);
						p->writename(name1);
						p->writeprg(score1);
						p->writecmp(score2);
						if(head == NULL){	//找要放在哪裡 
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
						break;
					
//					mm.showsel();
					}
					else{
						cout<<"Already exist number"<<endl;
					}
					cout<<"Please input no."<<endl;
					cin >> n;
					
//					mm.sel();
				}
				mm.show();
				break;
			case 2:
				cout<<"Please input no."<<endl;
				break;
		}
	}

//	cout<<"Please input no."<<endl;
	
	printlist(head);
	
}  


