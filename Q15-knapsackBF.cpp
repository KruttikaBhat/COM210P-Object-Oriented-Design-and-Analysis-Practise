#include<iostream>
#include<cmath>
using namespace std;

void ks(int w[],int p[],int n)
{
    int bin[100],rem,s,i,j,k,maxprof=0,M,resultw[20],resultp[20],count,index,fincount;
    cout<<"Enter the total weight of the knapsack"<<endl;
    cin>>M;
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
          
         int profit=0,weight=0; 
         
         for(k=0;k<n;k++)
         { 
              profit+=bin[k]*p[k]; 
              weight+=bin[k]*w[k];
         }
         
         
         if(maxprof<profit && weight<=M)
         {
               maxprof=profit;
               int count=0;
               for(index=0;index<n;index++)
               {
                    if(bin[index]==1)
                    {
                         resultw[count]=w[index];
                         resultp[count]=p[index];
                         count++;
                    }
               } 
               fincount=count;
              
         }
    }
    
     cout<<"The optimal solution would be"<<endl;
     
     for(index=0;index<fincount;index++)
     {
           cout<<"Weight: "<<resultw[index]<<" Price:"<<resultp[index]<<endl; 
     }
     cout<<"Profit: "<<maxprof<<endl;
     
}

int main()
{
     int n,i,w[20],p[20];
     cout<<"Enter the number of objects"<<endl;
     cin>>n;
     cout<<"Enter the weight and price of the objects"<<endl;
     for(i=0;i<n;i++)
         cin>>w[i]>>p[i];
     cout<<"Entered values are "<<endl;
     for(i=0;i<n;i++)
         cout<<"Weight: "<<w[i]<<" Price:"<<p[i]<<endl;
     ks(w,p,n);
}
