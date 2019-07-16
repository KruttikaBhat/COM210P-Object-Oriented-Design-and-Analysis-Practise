#include<iostream>
using namespace std;

class sets{
     int A[20],B[20];
     int n,m; 
     public:
          void create(); 
          void uni();
          void inter(); 
          void sum();
};

void sets::create()
{
     int i;
     cout<<"Enter the size of first sequence"<<endl;
     cin>>n;
     cout<<"Enter the sequence"<<endl;
     for(i=0;i<n;i++)
          cin>>A[i];
     cout<<"Enter the size of second sequence"<<endl;
     cin>>m;
     cout<<"Enter the sequence"<<endl;
     for(i=0;i<m;i++)
          cin>>B[i];
     cout<<"The entered sequences are"<<endl;
     for(i=0;i<n;i++)
          cout<<A[i]<<" ";
     cout<<"\n";
     for(i=0;i<m;i++)
          cout<<B[i]<<" ";
     return;
}

void sets::uni()
{
    int i=0,j=0,k=0;
    int C[40];  
    while(i<n && j<m) 
    {
        if(A[i]<B[j]) 
        {
             if(k==0 || A[i]!=C[k-1])
             {
                C[k]=A[i];
                k++;
                
             }        
             i++;

        }   
        if(A[i]>B[j])
        {
             if(k==0 || B[j]!=C[k-1])
             {
                 C[k]=B[j];
                 k++;
                 
             } 
             j++; 

        }
        if(A[i]==B[j])
        {
             if(k==0 || A[i]!=C[k-1])
             {
                 C[k]=A[i];
                 k++;
                 
             } 
             i++;
             j++;
        } 
         
    }
    while(i<n)
    {
         if(A[i]!=A[i-1])
         {
              C[k]=A[i];
              k++;
              
         }
         i++;
    }
    while(j<m)
    {
         if(B[j]!=B[j-1])
         {
              C[k]=B[j];
              k++;
              
         }
         j++;
    } 
    
    for(i=0;i<k;i++)
         cout<<C[i]<<" ";
}

void sets::inter()
{
    int i=0,j=0; 
    while(i<n && j<m)
    {
        if(A[i]<B[j])
            i++;
        else if(A[i]>B[j])
            j++;
        else 
        {
             if(i==n-1 || A[i]!=A[i+1])
             cout<<A[i]<<" ";
             i++;
             j++;
        } 

    }  
}

void sets::sum()
{
    int x,i=0,j=m-1,sum;
    cout<<"Enter x"<<endl;
    cin>>x;
    while(i<n && j>0)
    {
         sum=A[i]+B[j];
         if(sum<x)
              i++;
         else if(sum>x)
              j--;
         else
         {
              if((i==n-1 || A[i]!=A[i+1]) || (j==m-1 || B[j]!=B[j+1]) )
              {
                  cout<<A[i]<<" "<<B[j]<<endl;
              }
              i++;
              j--;
         }

    } 
}

int main()
{
     int c;
     sets s;
     do{
         cout<<"Enter one of the below options\n1.Enter the arrays in sorted order\n2.Union\n3.Intersection\n4.Search sum\n5.Exit\n";
         cin>>c;
          switch(c)
          {
                case 1:
                      s.create();  
                      break;
                case 2:
                      s.uni();
                      break;
                case 3:
                      s.inter();
                      break;
                case 4:
                      s.sum();
                      break;
                case 5:
                      break;
          }  

     }while(c!=5);


}
