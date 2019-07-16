#include<iostream>
using namespace std;

class tourney
{
     int a[20],b[20];
     int n;
     public:
         void create(); 
         void maxmin();
         
}; 
int count=0;
void tourney::create()
{
     int i;
     cout<<"Enter the size of the sequence"<<endl;
     cin>>n;
     cout<<"Enter the numbers"<<endl;
     for(i=0;i<n;i++)
         cin>>a[i];
     cout<<"Entered sequence is"<<endl;
    
     for(i=0;i<n;i++)
         cout<<a[i]<<" ";
    
}

void tourney::maxmin()
{
     int i,max[20],min[20],s1=0,s2=0,count=0;
     for(i=0;i<n;i+=2)
     {
         if(a[i]<a[i+1])
         {
              max[s1]=a[i+1];
              min[s1]=a[i];
              s1++;
         }
         else
         {
              max[s1]=a[i];
              min[s1]=a[i+1];
              s1++; 
         }
             
     } 
     
     while(count<(n/2)-1)
     {
         if(count!=0)
         s1=s2;  
         s2=0;
         for(i=0;i<s1;i=i+2)
         {
              if(max[i]<max[i+1])
              {
                  max[s2]=max[i+1];
                  s2++;
              }
              else
              {
                  max[s2]=max[i];
                  s2++; 
              }
              count++;
              
         } 
     }
     cout<<"\nMax "<<max[0]<<endl;
     count=0;
     while(count<(n/2)-1)
     {
         if(count!=0)
         s1=s2;
         s2=0;
         for(i=0;i<s1;i=i+2)
         {
              if(min[i]<min[i+1])
              {
                  min[s2]=min[i];
                  s2++;
              }
              else
              {
                  min[s2]=min[i+1];
                  s2++; 
              }
              count++;
              
         } 
     }
     cout<<"Min "<<min[0]<<endl;;
    
}
int main()
{
     tourney t;
     t.create();
     t.maxmin();  
}
