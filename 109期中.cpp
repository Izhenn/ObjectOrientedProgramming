//109
#include<iostream>
#include<cstring> 
using namespace std;
class STNODE{
private:
	int no;
	char name[20];
	int cs;
	int math;
	int total;
	STNODE *ptr=NULL;	
public:
	void writeno(int a){
		no=a;
	}
	int readno(){
		return no;
	}
	void writeptr(STNODE *b){
		ptr=b;
	}
	STNODE *readptr(){
		return ptr;
	}
	void writename(const char* c){
		strcpy(name,c);
	}
	const char* getname(){
		return name;
	}
	void writecs(int a){
		cs=a;
	}
	int readcs(){
		return cs;
	}
	void writemath(int a){
		math=a;
	}
	int readmath(){
		return math;
	}
	void writetotal(int a){
		total=a;
	}
	int readtotal(){
		return total;
	}
};
class MENU{
	int select;
	public:
		void show(){
			cout<<"(1)Add student information"<<endl;
			cout<<"(2)Delete student information"<<endl;
			cout<<"(3)Search student information"<<endl;
			cout<<"(4)printlist"<<endl;
			cout<<"(0)Exit"<<endl;
			cout<<"Please select an option."<<endl;
		}
		void sel(){
			cin>>select;
			if(select>4 || select<0){
				cout<<"��J���~�A�Э��s��J"<<endl; 
			}
		}
		int showsel(){
			return select;
		}
		MENU(){
			select=1;
		}
};
void printlist(STNODE *p){
	cout<<"head->";
	while(p){
		cout<<p->readno()<<"->";
		p=p->readptr();
	}
	cout<<"||"<<endl;
}
int main(){
	MENU mm;
	int n,select,cs_score,math_score,total_score;
	STNODE *head=NULL;
	STNODE *p=new STNODE;
	STNODE *m=NULL;
	STNODE *r=NULL;
	STNODE *q=head;
	STNODE *temp=NULL;
	STNODE *follow=NULL;
	char s1[20],s2[20];
	select=1;
	while(mm.showsel()){
		mm.show();
		mm.sel();
		switch(mm.showsel()){
			case 1:
				cout<<"�s�W�ǥ͸�ư��椤"<<endl;
				cout<<"Please input no."<<endl;
				cin>>n;
				cin.ignore(1);
				while(n>0){
					m=head;
					while(m && m->readno() !=n){
						m=m->readptr();
					}
					if(m==NULL){
						cout<<"Please enter the name."<<endl;
						cin.getline(s1,20);
						cout<<"please enter cs score."<<endl;
						cin >> cs_score;
						cout<<"please enter math score."<<endl;
						cin >> math_score;
						total_score=(cs_score+math_score)/2;
						STNODE *p = new STNODE;
						p->writeno(n);
						p->writeptr(NULL);
						p->writename(s1);
						p->writecs(cs_score);
						p->writemath(math_score);
						p->writetotal(total_score);
						if(head==NULL){
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
					}
					else{
						cout<<"Already exist number"<<endl;
						cout<<"Please input no."<<endl;
						cin >> n;
					}
				}
				break;
			case 2:
				cout<<"�R���ǥ͸�ư��椤"<<endl;
				cout<<"Please input no."<<endl;
				cin >> n;
//				m=head;
				temp=head;
				if(head == NULL){
					cout<<"��C�̨S���"<<endl; 
				}
				if(head->readno() == n){
					head=head->readptr();
					delete temp;
					cout<<"�ӵ���Ʀ��\�R��"<<endl;
					break;
				}
				//�M��n�R�����ؼСA�u�ntemp�����̫�@��B�B�S���ŦX����
				while(( temp != NULL ) && ( temp -> readno() != n) ){
    				follow = temp; //��temp�Mfollow���U����
    				temp = temp -> readptr();
				}	
				if(temp == NULL){
					cout<<"�ӵ���Ƥ��s�b�A�L�k�R��"<<endl;
				}
				else{   //���F�A�R���Ӹ`�I
    				follow -> writeptr(temp -> readptr());
    				delete temp;
    				cout<<"�ӵ���Ʀ��\�R��"<<endl;
				}
				break;
			case 3:
				cout<<"�d�߾ǥ͸�ư��椤"<<endl;
				if(head==NULL){
					break;
				}
				cout<<"�п�J�ǥͩm�W"<<endl;
				cin.ignore(1);
				cin.getline(s2,20); 
				temp=head;
				while((temp != NULL) && (strcmp(s2,temp->getname()) != 0)){
					temp=temp->readptr();
					cout<<"��"<<endl; 
				}
				if(temp == NULL){
					cout<<"�Ӿǥͤ��s�b"<<endl;
				}
				else{
					cout<<"�y��:"<<temp->readno()<<endl;
					cout<<"�m�W:"<<temp->getname()<<endl;
					cout<<"�p�����Z:"<<temp->readcs()<<endl;
					cout<<"�ƾǦ��Z:"<<temp->readmath()<<endl;
					cout<<"�`����:"<<temp->readtotal()<<endl;
				}
				
				break;
			case 4:
				cout<<"�C�L��C��ư��椤"<<endl;
				printlist(head);
				break;
			case 0:
				break;
		} 
	}
}
