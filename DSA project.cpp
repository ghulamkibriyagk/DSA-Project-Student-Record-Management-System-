#include <iostream>
#include <cmath>
#include <string>
#include<fstream>
using namespace std;
bool IsloggedIn()
{
    string username, password, un, pw;
    cout << "Enter username :";
    cin >> username;
    cout << "Enter password :";
    cin >> password;
    un=username;
    pw=password;
    ifstream read("tests.txt");
    getline(read, un);
    getline(read, pw);
    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}
class node{
public:
    string name;
    long long phone;
    double roll_no;
    string sec;
    float gpa;
    int sem;
    node* next;
    node* pre;
    node(){
        pre=NULL;
        next=NULL;
        roll_no=0;
    }
    void name1(){
    	cout<<"-----------------------------------------------------------------"<<endl;
        cout<<"Enter your name:"<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        cin>>name;
        while(!((name>="a" && name<="z") || (name>="A" && name<="Z") )){
            cout<<"Error!! try to enter charachters only\nenter again:";
            cin>>name;
        }
    }
    void Phone(){
    	cout<<"-----------------------------------------------------------------"<<endl;
        cout<<"Enter phone #: "<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        int gk=0;
        gk:
        while(!(cin>>phone)){
            cout<<"Error!! try to enter integers: Enter again:";
            cin.clear();
            cin.ignore(123,'\n');
    	}	
        int x=int(log10(phone) +1);
        while(x!=10){
            if(x!=10){ //it will ignore 0 value
                cout<<"Invalid number!\nPhone# must be of 11 digits\nEnter again:";
                goto gk;
            }
            x=int(log10(phone) +1);
        }
    }
    void roll(){
    	cout<<"-----------------------------------------------------------------"<<endl;
        cout<<"Enter Roll no:"<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        int gk1=0;
        gk1:
        while(!(cin>>roll_no)){
            cout<<"Error!! try to enter integers: Enter again:";
            cin.clear();
            cin.ignore(123,'\n');
        }
        int y=int(log10(roll_no) +1);
        while(y!= 6){
            if(y != 6 ){ //starts from 0
                cout<<"Invalid number!\nRoll# must be of 6 digits\nEnter again:";
                goto gk1;
            }
            y=int(log10(roll_no) +1);
        }

    }
    void semester(){
    	cout<<"----------------------------------------------------------------"<<endl;
        cout<<"Enter semester: "<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        while(!(cin>>sem)){
            cout<<"Error!! try to enter integer: Enter again:";
            cin.clear();
            cin.ignore(123,'\n');
        }
        while(sem<=0 || sem>=9){
            cout<<"invalid semester: Enter again:";
            cin>>sem;
        }
    }
    void section(){
    	cout<<"----------------------------------------------------------------"<<endl;
        cout<<"Enter section: "<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        cin>>sec;
        while(!((sec=="A") || (sec=="a") || (sec=="B") || (sec=="b") || (sec=="c") || (sec=="C"))){
            cout<<"try to enter only character and must be a,b,c: Enter again:";
            cin>>sec;
        }
    }
    void GPA(){
    	cout<<"----------------------------------------------------------------"<<endl;
        cout<<" Enter GPA: "<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        int gk2=0;
        gk2:
        while(!(cin>>gpa)){
            cout<<"Error!! try to enter float: Enter again:";
            cin.clear();
            cin.ignore(123,'\n');
        }
        while(gpa<=0.0 || gpa>4.0){
            cout<<"wrong input: Enter again:";
            goto gk2;
        }
    }
    
    bool isEmpty(){
    	if(roll_no==0){
    		return true;
		}
		else
		return false;
	}
};

class DLL{
public:
    node* head;
    DLL(){
        head=NULL;
    }

    void insertdata(node* n){
        if(head==NULL){
            head=n;
            cout<<"Data Entered successfully"<<endl;
        }
        else{
            node* ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=n;
            n->pre=ptr;
            cout<<"Data entered successfully"<<endl;
        }
    }

    void deletedata(double r){
        if(head==NULL){
            cout<<"No such record Exist"<<endl;
        }
        else if(head->roll_no == r){
            head=head->next;
            cout<<"Record deleted"<<endl;
            delete head->pre;
            head->pre=NULL;
        }
        else{
            bool found=false;
            node* ptr=head;
            while(ptr!=NULL){
                if(ptr->roll_no==r){
                    found=true;
                    break;
                }
                ptr=ptr->next;
            }
            if(found==true){
                node *ptr2=ptr;
                ptr->pre->next=ptr->next;
                ptr->next->pre=ptr->pre;
                delete ptr;//ghalti
                cout<<"Record deleted!"<<endl;
            }
            else if(ptr->roll_no==r && ptr->next==NULL){
                node* ptr1 =ptr;
                ptr=ptr->pre;
                ptr->next=NULL;
                delete ptr1;
                cout<<"Record deleted!"<<endl;
            }
            else{
                cout<<"roll no not found:"<<endl;
            }
        }
    }

    void updateRecord(double r) {
        if (head == NULL) {
            cout << "No such record exist! " << endl;
        }
        else {
            node *ptr = head;
            bool flag = false;
            while (ptr != NULL) {
                if (ptr->roll_no == r) {
                    flag = true;
                    break;
                }
            }
            if (flag == false) {
                cout << "No such record exist" << endl;
            }
            else {
                int x;
                do{
                    ck:
                    cout<<"What do you want to update: ";
                    cout<<"1. Roll#             : \n";
                    cout<<"2. Phone#            : \n";
                    cout<<"3. GPA               : \n";
                    cout<<"4. Semester          : \n";
                    cout<<"5. Section           : \n";
                    cout<<"6. Name              :\n";
                    cout<<"0. To Go back to menu:\n";
                    cout<<"Enter your option    : ";
                    cin>>x;
                    switch(x){
                        case 0:
                            break;
                        case 1:
                            double r;
                            cout<<"Enter new roll#: ";
                            ptr->roll();
                            break;
                        case 2:
                            long long p;
                            cout<<"Enter new phone#: ";
                            ptr->Phone();
                            break;
                        case 3:
                            float g;
                            cout<<"Enter new gpa: ";
                            ptr->GPA();
                            break;
                        case 4:
                            int s;
                            cout<<"Enter new semester: ";
                            ptr->semester();
                            break;
                        case 5:
                            char se;
                            cout<<"Enter new section: ";
                            ptr->section();
                            break;
                        case 6:
                            char n;
                            cout<<"enter new name:";
                            ptr->name1();
                            break;
                        default:
                            cout<<"Invalid input: Choose again!\n";
                            goto ck;
                            break;
                    }
                }while(x!=0);
            }

        }
    }
    void SortedRecord(){
        if(head==NULL){
            cout<<"No record exist"<<endl;
        }
        else{
            node* ptr= head;
            int count=0;
            while(ptr!=NULL){
                count++;
                ptr=ptr->next;
            }
            node* temp=head;
            double arr[count];
            for(int i=0;i<count;i++){
                arr[i]=temp->roll_no;
                temp=temp->next;
            }
            for(int i=0;i<=count;i++){
                for(int j=0;j<count-i-1;j++){
                    if(arr[j]>arr[j+1]){
                        double temp= arr[j];
                        arr[j]= arr[j+1];
                        arr[j+1]=temp;
                    }
                }
            }
            cout<<"Sorted list according to roll no:"<<endl;
            for(int i=0;i<count;i++){
                cout<<arr[i]<<"   ";
            }
        }
    }

    void display(){
        if(head==NULL){
            cout<<"List is Empty ";
        }
        else{
        	cout<<"\t\t\t\tStudents record:"<<endl;
            node* ptr= head;
            while(ptr!=NULL){
                cout<<"\t\t\tName of the student: "<<ptr->name<<endl<<"\t\t\tRoll no of the student: "<<ptr->roll_no<<endl<<"\t\t\tSection of the student: "<<ptr->sec<<endl<<"\t\t\tGPA of the student: "<<ptr->gpa<<endl<<"\t\t\tSemester of the student: "<<ptr->sem<<endl<<"\t\t\tContact No of the student: "<<ptr->phone<<endl<<endl<<endl;
                ptr=ptr->next;
            }
        }
    }

};
int main(){
    int ck=0;
    int choice;
    int again=0;
    again:
    cout << "1 : Register \n2 :Login\nYour choice :";
    
    while(!(cin>>choice)){
            cout<<"Error!! try to enter integers: Enter again:";
            cin.clear();
            cin.ignore(123,'\n');
        }
    if (choice == 1)
    {
        string username, password;
        cout << "select a username :";
        cin>>username;
        while(username.length()>5){
            cout<<"you can enter only 5 digits/characters:\n enter again:";
            cin>>username;
        }
        cout << "Enter password: ";
        cin >> password;
        ofstream file;
        file.open( "tests.txt");
        file<<username<<endl<<password;
        file.close();
        main();
    }
    else if(choice==2)
    {

        bool status =IsloggedIn();
        if(!status)
        {
            cout<<"Invalid username/password :"<<endl;
            goto again;
        }
        else
        {
        	system("CLS");
            cout<<"Successfully Logged in!"<<endl<<endl;
            goto ck;
        }
    }
    while(choice!=1 || choice!=2){
    	if(choice<=0 || choice>=3){
    	cout<<"enter only 1 or 2:"<<endl;
    	goto again;
	}
	}
    
	
    ck:
    int input;
    DLL obj;
    do{
        check:
        cout<<"0. Submission    : "<<endl;
        cout<<"1. Data Entry    : "<<endl;
        cout<<"2. Delete Record : "<<endl;
        cout<<"3. sort list     : "<<endl;
        cout<<"4. update Record : "<<endl;
        cout<<"5. display list  : "<<endl;
        cout<<"Enter your option: ";
        cin>>input;
		cout<<endl<<endl;
        node* obj1 = new node();
        switch(input){
            case 0:
            	if(obj1->isEmpty()){
            		cout<<"Can't submit! Enter some data\n"<<endl;
            		goto check;
				}
				else{
					break;
				}	
            case 1:
                obj1->name1();
                obj1->roll();
                obj1->section();
                obj1->GPA();
                obj1->Phone();
                obj1->semester();
                obj.insertdata(obj1);
                break;
            case 2:
                int x;
                cout<<"Enter roll# to delete record: "<<endl;
                cin>>x;
                obj.deletedata(x);
                break;
            case 3:
                obj.SortedRecord();
                break;
            case 4:
                double y;
                cout<<"Enter roll# to open data: "<<endl;
                cin>>y;
                obj.updateRecord(y);
                break;
            case 5:
                obj.display();
                break;
            default:
                cout<<"Wrong input please enter correct input! "<<endl;
                goto check;
                break;
        }
    }while(input!=0);
}