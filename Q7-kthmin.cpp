#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int findMed(int arr[],int num)
{
      sort(arr,arr+num);
      return(arr[num/2]);
}

void swap(int *a,int *b)
{
     int temp=*a;
     *a=*b;
     *b=temp;
}

int partition(int arr[],int l,int r,int x)
{
     int i,j;
     for(i=l;i<r;i++)
     {
          if(arr[i]==x)
              break; 
     }
     swap(&arr[i],&arr[r]);
     i=l;
     for(j=l;j<=r-1;j++)
     {
          if(arr[j]<=x)
          {
               swap(&arr[j],&arr[i]);
               i++;
          }
     }
     swap(&arr[i],&arr[r]);
     return i;
}

int kthmin(int arr[],int l,int r,int k)
{
   if(k>0 && k<=r-l+1)
   {  
     int n=r-l+1,MedofMed,i; 
     int median[(n+4)/5];
     for(i=0;i<n/5;i++)
          median[i]=findMed(arr+l+i*5,5);
     if(i*5<n)
     {
          median[i]=findMed(arr+l+i*5,n%5);
          i++;
     }
     if(i==1)
          MedofMed=median[i-1];
     else
          MedofMed=kthmin(median,0,i-1,i/2);
          
     int p=partition(arr,l,r,MedofMed);                    
     if(p-l==k-1)
         return arr[p];
     if(p-l>k-1)
         return kthmin(arr,l,p-1,k);
     
     return kthmin(arr,p+1,r,k-p+l-1);
   }
   return INT_MAX;          
}

int main()
{
     int n;
     cout<<"Enter the number of elements"<<endl;
     cin>>n;
     int arr[n],k;
     cout<<"Enter the elements"<<endl;
     for(int i=0;i<n;i++)
          cin>>arr[i];
     cout<<"Enter the value of k"<<endl;
     cin>>k;
     int val=kthmin(arr,0,n-1,k);
     cout<<"The kth min is "<<val<<endl;
     return 0;
}
