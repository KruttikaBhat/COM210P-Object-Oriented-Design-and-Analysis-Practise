#include<iostream>
using namespace std;

int n,count1=0,count2=0;

int nondynamic(int x)
{
     count2++;
     if(x==0 || x==1)
         return x;
     else 
         return(nondynamic(x-1)+nondynamic(x-2));        
}

void dynamic()
{
     int a[n],i;
     a[0]=0;
     a[1]=1;
     for(i=2;i<n;i++)
     {
         count1++;
         a[i]=a[i-1]+a[i-2];  
     }
     for(i=0;i<n;i++)
          cout<<a[i]<<" ";
}


int main()
{
     cout<<"Enter n"<<endl;
     cin>>n;
     for(int i=0;i<n;i++)
         cout<<nondynamic(i)<<" ";
     cout<<endl;    
     cout<<"NonDynamic count: "<<count2<<endl;
     dynamic();
     cout<<"\nDynamic count: "<<count1<<endl;
return(0);
}
