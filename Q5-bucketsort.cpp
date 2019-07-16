#include<iostream>
//#define k 50
using namespace std;

class student
{
    private:  
    int rno,marks;
    char name[20];
    student *next;
    public:
        void read()
        {
             cout<<"Enter the rollno,name and marks"<<endl;
             cin>>rno>>name>>marks;
             next=NULL;  
        }
        void display()
        {
              cout<<"Rollno: "<<rno<<endl;
              cout<<"Name: "<<name<<"  Marks: "<<marks<<endl;
        }
        void bucketsort(student *obj);
        void aftersort(int k);
};

student arr[20],temp;
student *beg[20]={NULL};
student *end[20]={NULL};


void student::bucketsort(student *obj)
{
    int key=obj->rno;
    if(beg[key]==NULL)
    {
         beg[key]=obj;
         end[key]=obj;
    }               
    else
    {
         end[key]->next=obj;
         end[key]=obj;
    }
} 

void student::aftersort(int k)
{
     student *temp;
     for(int i=0;i<k;i++)
     {
          temp=beg[i];
          while(temp!=NULL) 
          {
               cout<<"Rollno: "<<temp->rno<<endl;
               cout<<"Name: "<<temp->name<<"  Marks: "<<temp->marks<<endl;
               temp=temp->next;
          }
     }

}

int main()
{
     int i,n,k;
     cout<<"Enter the value of k"<<endl;
     cin>>k;
     cout<<"Enter the number of records to be inserted"<<endl;
     cin>>n;
     for(i=0;i<n;i++)
          arr[i].read();
     cout<<"Before sorting"<<endl;
     for(i=0;i<n;i++)
          arr[i].display();
     for(i=0;i<n;i++)
     {
          student *ptr=&arr[i];   
          temp.bucketsort(ptr);
     }
     cout<<"\n\nAfter sorting"<<endl;
     temp.aftersort(k);    
return(0);
}
