#include<iostream>
#include<cmath>
using namespace std;


void sss(int a[],int n)
{
    int bin[100],rem,s,i,j,k;
    cout<<"Enter the sum"<<endl;
    cin>>s;
    for(i=1;i<pow(2,n);i++)
    {
         j=i;
         for(k=0;k<n;k++)
             bin[k]=0;
             
         for(k=n-1;k>=0;k--)
         {
              rem=j%2;
              j/=2;
              bin[k]=rem;
         }  
          
         int sum=0; 
         
         for(k=0;k<n;k++)
         { 
              sum+=bin[k]*a[k]; 
              
         }
         
         if(sum==s)
         {
              cout<<"\nThe elements which give the sum are"<<endl;
              for(k=0;k<n;k++)
              {
                   if(bin[k]==1)
                       cout<<a[k]<<" ";
              }
              
         }
    }
}

int main()
{
    int a[20],n,i;
    cout<<"Enter the number of digits"<<endl;
    cin>>n;
    cout<<"Enter the digits"<<endl;
    for(i=0;i<n;i++)
        cin>>a[i];    
    sss(a,n);    
    return 0;
}
