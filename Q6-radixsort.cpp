#include<iostream>
#include<cstring>
using namespace std;

class strings
{
    string arr[10],out[10];
    int n,l;
    public:
         void enter()
         {
              cout<<"Enter the number of strings"<<endl;
              cin>>n;
              cout<<"Enter the length of each string"<<endl;
              cin>>l;
              cout<<"Enter the strings"<<endl;
              for(int i=0;i<n;i++)
                  cin>>arr[i];
              cout<<"The entered strings are"<<endl;
              for(int i=0;i<n;i++)
                  cout<<arr[i]<<endl;     
         }
         void sort();
         
}; 

void strings::sort()
{
      int i,j; 
      for(j=l-1;j>=0;j--)
      {
          
            int count[26]={0}; 
            for(i=0;i<n;i++)
            {   
                 count[(int)arr[i][j]-97]++;
            }
            for(i=1;i<26;i++)
                 count[i]+=count[i-1];
     
            for(i=n-1;i>=0;i--)
            {
                 count[(int)arr[i][j]-97]--;
                 out[ count[ (int)arr[i][j]-97 ] ]=arr[i];
            } 

            for(i=0;i<n;i++)
                 arr[i]=out[i]; 
           
     
      }  
      cout<<"After sorting:"<<endl;
      for(i=0;i<n;i++)
          cout<<arr[i]<<endl;
}


int main()
{
    cout<<int('z')<<endl;
    strings obj;
    obj.enter();
    obj.sort();  

return(0);
}
