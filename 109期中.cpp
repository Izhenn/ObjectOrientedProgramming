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
				cout<<"輸入錯誤，請重新輸入"<<endl; 
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
				cout<<"新增學生資料執行中"<<endl;
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
				cout<<"刪除學生資料執行中"<<endl;
				cout<<"Please input no."<<endl;
				cin >> n;
//				m=head;
				temp=head;
				if(head == NULL){
					cout<<"串列裡沒資料"<<endl; 
				}
				if(head->readno() == n){
					head=head->readptr();
					delete temp;
					cout<<"該筆資料成功刪除"<<endl;
					break;
				}
				//尋找要刪除的目標，只要temp不為最後一格、且沒找到符合的值
				while(( temp != NULL ) && ( temp -> readno() != n) ){
    				follow = temp; //把temp和follow往下移動
    				temp = temp -> readptr();
				}	
				if(temp == NULL){
					cout<<"該筆資料不存在，無法刪除"<<endl;
				}
				else{   //找到了，刪除該節點
    				follow -> writeptr(temp -> readptr());
    				delete temp;
    				cout<<"該筆資料成功刪除"<<endl;
				}
				break;
			case 3:
				cout<<"查詢學生資料執行中"<<endl;
				if(head==NULL){
					break;
				}
				cout<<"請輸入學生姓名"<<endl;
				cin.ignore(1);
				cin.getline(s2,20); 
				temp=head;
				while((temp != NULL) && (strcmp(s2,temp->getname()) != 0)){
					temp=temp->readptr();
					cout<<"找"<<endl; 
				}
				if(temp == NULL){
					cout<<"該學生不存在"<<endl;
				}
				else{
					cout<<"座號:"<<temp->readno()<<endl;
					cout<<"姓名:"<<temp->getname()<<endl;
					cout<<"計概成績:"<<temp->readcs()<<endl;
					cout<<"數學成績:"<<temp->readmath()<<endl;
					cout<<"總平均:"<<temp->readtotal()<<endl;
				}
				
				break;
			case 4:
				cout<<"列印串列資料執行中"<<endl;
				printlist(head);
				break;
			case 0:
				break;
		} 
	}
}
