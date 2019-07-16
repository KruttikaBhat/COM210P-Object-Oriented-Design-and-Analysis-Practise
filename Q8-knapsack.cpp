#include<iostream>
using namespace std;

class item
{
    float price,weight;
    
    public:
        float val;
        void enter()
        {
             cout<<"Enter price and weight"<<endl;
             cin>>price>>weight;
             val=price/weight;
        }
        void display()
        {
             cout<<"Price/Weight: "<<val<<"Price: "<<price<<"Weight: "<<weight<<endl;
        } 
        void sort(int size);
        void knap(int max,int size);
        
};
item I[20],obj,temp;
int n,M;

void item::sort(int size)
{
    int i,j;  
    for(i=1;i<size;i++)
       for(j=i;j>0;j--)
       {
            if(I[j].val<I[j-1].val)
            {
                 temp=I[j];
                 I[j]=I[j-1];
                 I[j-1]=temp;                            
            } 
       } 
}

void item::knap(int max,int size)
{
     int rem=max,i=size-1;
     cout<<"0-1"<<endl;
     while(i>=0 && I[i].weight<=rem)
     {
          cout<<"Price: "<<I[i].price<<" Weight: "<<I[i].weight<<endl;
          rem-=I[i].weight;
          i--;
     }  
     cout<<"Fractional"<<endl;
     rem=max;
     i=size-1;
     while(i>=0 && I[i].weight<=rem)
     {
          cout<<"Price: "<<I[i].price<<" Weight: "<<I[i].weight<<endl;
          rem-=I[i].weight;
          i--;
     }
     if(rem!=0 && I[i].weight>rem)
     {
          float mult=rem/I[i].weight;  
          cout<<"Price: "<<I[i].price*mult<<" Weight: "<<I[i].weight*mult<<endl; 
     }    
}

int main()
{
     int i;
     cout<<"Enter the number of objects"<<endl;
     cin>>n;
     for(i=0;i<n;i++)
         I[i].enter(); 
     cout<<"Before"<<endl;  
     for(i=0;i<n;i++)
         I[i].display();  
     obj.sort(n); 
     cout<<"After"<<endl;
     for(i=0;i<n;i++)
         I[i].display(); 
     cout<<"Enter the size of the bag"<<endl;
     cin>>M; 
     obj.knap(M,n);  
}
