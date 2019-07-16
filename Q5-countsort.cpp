#include<iostream>
using namespace std;

class count
{
    int arr[20],fre[20],cum[20],out[20],n,k,temp[20];
    public:
        void input()
        {
             cout<<"Enter the max value of input"<<endl;
             cin>>k;
             cout<<"Enter the size of the array"<<endl;
             cin>>n;
             cout<<"Enter integers in the range 0 to "<<k<<endl;
             for(int i=0;i<n;i++)
                  cin>>arr[i];
             for(int i=0;i<=k;i++)
                  fre[i]=0; 
             
        }
        void sort()
        {
             int i;
             for(i=0;i<n;i++)
             {
                 fre[arr[i]]++;
             }
            /*
             cout<<"\nFrequency array:"<<endl;  
             for(i=0;i<=k;i++)
                 cout<<fre[i]<<" ";
             */ 
             cum[0]=fre[0]; 
             for(i=1;i<=k;i++)
             {
                  cum[i]=fre[i]+cum[i-1];
                  temp[i]=cum[i];
             }
             /*
             cout<<"\nCumulative array:"<<endl;
             for(i=0;i<=k;i++)
                 cout<<cum[i]<<" ";
             */ 
             for(i=n-1;i>=0;i--)
             {
                 out[cum[arr[i]]]=arr[i];
                 cum[arr[i]]--;
             } 
             cout<<"\nOutput array:"<<endl;
             for(i=1;i<=n;i++)
                 cout<<out[i]<<" "; 
        }
        void range()
        {
             int a,b;
             cout<<"\nEnter the values of a and b"<<endl;
             cin>>a>>b;
             //cout<<temp[b]<<" "<<temp[a-1]<<endl; 
             cout<<"The numbers in this range are "<<temp[b]-temp[a-1];
        }
    

};

int main()
{
    count C;
    C.input();
    C.sort(); 
    C.range();

return(0);
}
