#include<iostream>
using namespace std;

struct node 
{
     int x,y,weight;
};

class prim
{
     
     public:
         void enter();  
         struct node findMinEdge();
         struct node findMin();
         void getMST();
};

prim P;
struct node Result[20];
int v,c[20][20],near[20];

void prim::enter()
{
     int i,j;
     cout<<"Enter the number of vertices"<<endl;
     cin>>v;
     for(i=1;i<=v;i++)
     {
          j=i;
          c[i][j]=9999; 
          for(j=i+1;j<=v;j++)
          {
               cout<<"Enter the weight for edge "<<i<<" "<<j<<endl;
               cin>>c[i][j];
               c[j][i]=c[i][j];
          }
     }     
     for(i=1;i<=v;i++)
     {
         for(j=1;j<=v;j++)
             cout<<c[i][j]<<" ";
         cout<<endl;    
     } 
}

struct node prim::findMinEdge()
{
     int i,j,min=10000,minX,minY;
     for(i=1;i<=v;i++)
     {
         for(j=1;j<=v;j++)
         {
              if(c[i][j]!=0 && c[i][j]<min)
              {
                   min=c[i][j];
                   minX=i;
                   minY=j; 
              }
         }    
     }
     cout<<"\nMin edge returned: "<<minX<<" "<<minY<<" "<<min<<endl;
     struct node N;
     N.x=minX;
     N.y=minY;
     N.weight=min;
     return N;
}

struct node prim::findMin()
{
     struct node temp;
     int min=10000,minX,minY;    
     for(int i=1;i<=v;i++)
     {
         if(near[i]!=0)
         {
              if(c[near[i]][i]<min)
              {
                   min=c[near[i]][i];
                   minX=near[i];
                   minY=i; 
              }
         }
     } 
     cout<<"\nMin edge returned: "<<minX<<" "<<minY<<" "<<min<<endl;
     temp.x=minX;
     temp.y=minY;
     temp.weight=min;
     return temp;
}

void prim::getMST()
{
     Result[1]=findMinEdge();
     int k=Result[1].x,l=Result[1].y,i,j;
     struct node temp;
     for(i=1;i<=v;i++)
     {
          if(i!=k && i!=l)
          {
              if(c[i][k]<=c[i][l])
                 near[i]=k;
              else
                 near[i]=l;
          }              
     }
     near[k]=0;
     near[l]=0;
         
     for(i=2;i<v;i++)
     {
          temp=findMin();
          near[temp.y]=0;
          Result[i]=temp;
          for(j=1;j<=v;j++)
          {
                if(near[j]!=0 && c[j][temp.y]<c[j][near[j]])
                     near[j]=temp.y;  
          }
          cout<<"Near array:"<<endl;
          for(int a=1;a<=v;a++)
          cout<<near[a]<<" ";
                                                                                                                                      
     }
     
     cout<<"\nMinimum spanning tree is:"<<endl;
     for(i=1;i<v;i++)
          cout<<Result[i].x<<" "<<Result[i].y<<" Weight: "<<Result[i].weight<<endl;
               
}

int main()
{
     P.enter();
     P.getMST();
     return(0);
}
