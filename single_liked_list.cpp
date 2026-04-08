#include <iostream>
using namespace std;
struct StudentType
{
string name;
string Id;
string Department;
double GPA;
StudentType*next;
};

StudentType*Head=NULL;

void Add_Information_At_Start ()
{
  	StudentType*temp=new StudentType;
	cout<<"\nEnter your name";
	cin>>temp->name;
	cout<<"\n Enter your ID Number";
	cin>>temp->Id;
	cout<<"\n Enter youor Department ";
	cin>>temp->Department;
	cout<<"\n Enter your GPA ";
	cin>>temp->GPA;
if (Head==NULL)
{
temp->next=NULL;
}
else{
temp->next=Head;
}
Head=temp;
cout<<"\n The student information is successfully stord at the first node";
}

void Add_Information_At_End ()
{
 StudentType*temp=new StudentType;
 StudentType*current;
	cout<<"\nEnter your name";
	cin>>temp->name;
	cout<<"\n Enter your ID Number";
	cin>>temp->Id;
	cout<<"\n Enter youor Department ";
	cin>>temp->Department;
	cout<<"\n Enter your GPA ";
	cin>>temp->GPA;

temp->next=NULL //we have to assighn the temporary node to NULL beacuse it is the last node .
  if (Head==NULL)
{
 Head=temp;
}
else 
{
current=Head;
while(current->next!=NULL)
{
  current=current->next;
	
}
current->next=temp;
cout<<"\n The Student information is successfully Stored at the End";
}

void Add_Information_At_Specific_Position (int position)
{
	 StudentType*temp=new StudentType;
 StudentType*current,prev;
	cout<<"\nEnter your name";
	cin>>temp->name;
	cout<<"\n Enter your ID Number";
	cin>>temp->Id;
	cout<<"\n Enter youor Department ";
	cin>>temp->Department;
	cout<<"\n Enter your GPA ";
	cin>>temp->GPA;
  temp->next=NULL;
if (Head==NULL)
{
Head=temp;
}
else 
{
current=Head;
int i=0;
while (i<position)
{
 prev=current;
current=current->next;
	i++;
}
prev->next=temp;
temp->next=current;
}
cout<<"\n The Student Information is successfully Storde at index"<<postion;
}

void Delete_Iformation_From_Start ();

StudentType*temp;
if (Head==NULL)
{
cout<<"\n The List is empty";
}
else 
{
temp=Head;
Heade=Heade->next;
delete temp;
}
cout <<"\n The Student Information is successfully Deleted from the first position ";
}
void Delete_Information_From_End ()
{
	StudentType*current,temp;
if (Head==NULL)
{
cout<<"\n The List is empty";
}
else 
{
current=Head;
while (current->next!=NULL)
{
	temp=current;
	current=current->next;
}
temp->next=NULL;
delete current;




































