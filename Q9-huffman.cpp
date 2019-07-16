#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void swap(struct node &a,struct node &b);
void inorder(struct node *ptr);
void encode(char ch,struct node *ptr,int pos);
int search(char c,char a[]);
void decode(char a[],struct node *ptr);

struct node{
     int f;
     char c;
     struct node *left,*right;   
};

class huff
{ 
     struct node arr[50];
     public:
          void enterheap(struct node *ptr);
          void display();
          void huffmanTree();
          struct node *delNode();  
          void getcodes(struct node *ptr,int pos);
   
};

huff obj;
struct node *hptr;
int a[100],size;

void huff::enterheap(struct node *ptr)
{
     size++;
     arr[size].f=ptr->f;
     arr[size].c=ptr->c;
     arr[size].left=ptr->left;
     arr[size].right=ptr->right;
     int i=size;
     while(i>1 && arr[i].f<arr[i/2].f)
     {
          swap(arr[i],arr[i/2]);
          i=i/2;
     }
}

void huff::display()
{
     for(int i=1;i<=size;i++)
          cout<<"Character:"<<arr[i].c<<" Frequency:"<<arr[i].f<<endl;
}

void huff::huffmanTree()
{
     struct node *temp1,*temp2;
     while(size>1)
     {
          temp1=delNode();
          temp2=delNode();
          struct node *temp=new struct node;
          temp->left=temp1;
          temp->right=temp2;
          temp->f=temp1->f+temp2->f;
          temp->c='*';
          enterheap(temp);
     }
     hptr=delNode();
}

struct node * huff::delNode()
{
     int i=1,minpos;
     struct node *temp=new struct node;
     temp->left=arr[1].left;
     temp->right=arr[1].right;
     temp->f=arr[1].f;
     temp->c=arr[1].c;
     arr[1]=arr[size];
     size--;
     cout<<"Character:"<<temp->c<<" Frequency:"<<temp->f<<" got deleted"<<endl;
     while((arr[i].f>arr[2*i].f || arr[i].f>arr[2*i+1].f) && (2*i<=size))
     {
          if(2*i+1 > size)
              minpos=2*i;
          else if(arr[2*i+1].f>arr[2*i].f)
          {
              minpos=2*i; 
          } 
          else 
              minpos=2*i+1;
          swap(arr[minpos],arr[i]);
          i=minpos; 
     }
     return temp;
}

void huff::getcodes(struct node *ptr,int pos)
{
     if(ptr->left)
     {
          a[pos]=0;
          getcodes(ptr->left,pos+1);
     }
     if(ptr->right)
     {
          a[pos]=1;
          getcodes(ptr->right,pos+1);
     }
     if(ptr->right==NULL && ptr->left==NULL)
     {
          cout<<"Character "<<ptr->c<<": "; 
          for(int i=0;i<pos;i++)
               cout<<a[i];
          cout<<endl;     
     }
}

void inorder(struct node *ptr)
{
     if(ptr!=NULL)
     {
          inorder(ptr->left);
          cout<<"Character:"<<ptr->c<<" Frequency:"<<ptr->f<<endl;
          inorder(ptr->right);
     } 
}

void swap(struct node &a,struct node &b)
{
	struct node temp=a;
	a=b;
	b=temp;
}

void encode(char ch,struct node *ptr,int pos)
{
     if(ptr->left)
     {
          a[pos]=0;
          encode(ch,ptr->left,pos+1);
     }
     if(ptr->right)
     {
          a[pos]=1;
          encode(ch,ptr->right,pos+1);
     }
     if(ptr->right==NULL && ptr->left==NULL)
     {
          if(ptr->c==ch) 
          { 
               for(int i=0;i<pos;i++)
                   cout<<a[i];
          }
          
     }
}

void decode(char a[],struct node *ptr)
{
     int i=0;
     while(i!=strlen(a)+1)
     {
           if(ptr->left==NULL && ptr->right==NULL)
           {
                cout<<ptr->c;
                if(i==strlen(a))
                     break;
                       
                ptr=hptr;
                continue;
           }
           if(a[i]=='0')
                ptr=ptr->left;
           else if(a[i]=='1')
                ptr=ptr->right;
           else
           {
                cout<<"Invalid code"<<endl;
                break; 
           }     
           i++;
     }
     
}



int search(char c,char a[])
{
     for(int i=0;i<strlen(a);i++)
     {
          if(a[i]==c)
               return 1;
     } 
     return 0;
}

int main()
{
     int n,i,c,flag=0;
     char s[20],DC[20];  //DC-distinct char
     cout<<"Enter the number of distinct characters"<<endl;
     cin>>n;
     struct node *temp=new struct node;
     for(i=0;i<n;i++)
     {
          cout<<"Enter the character and the frequency"<<endl;
          cin>>temp->c>>temp->f;
          DC[i]=temp->c;
          temp->left=temp->right=NULL;
          obj.enterheap(temp);    
     } 
     obj.display();
     obj.huffmanTree();
     cout<<"Constructed huffman tree is:"<<endl;
     inorder(hptr);
     cout<<"The codes for each character are"<<endl;
     obj.getcodes(hptr,0);
     do{
         cout<<"\nEnter one of the below options\n1.Encode a string\n2.Decode a binary string\n3.Exit"<<endl;
         cin>>c;
         switch(c)
         {
              case 1:
                   cout<<"Enter a string"<<endl;
                   cin>>s;
                   for(i=0;s[i]!='\0';i++)
                   {
                        if(search(s[i],DC)==0)
                        {
                             flag=1;
                             break;
                        }           
                   }
                   if(flag==0)
                      for(i=0;s[i]!='\0';i++)
                           encode(s[i],hptr,0);
                   else 
                      cout<<"Invalid string"<<endl;             
                   break;
              case 2:
                   cout<<"Enter a binary string"<<endl;
                   cin>>s;
                   decode(s,hptr);
                   break;
              case 3:
                   break;           
         }
     }while(c!=3);
return(0);
}
