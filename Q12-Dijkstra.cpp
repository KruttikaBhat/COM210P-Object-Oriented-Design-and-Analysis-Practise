#include<iostream>
using namespace std;

class dijkstra
{
     int v,d[20],m[20],c[20][20],pre[20],s,result[20][3];
     public:
          void enter()
          {
                int i,j;     
                cout<<"Enter the number of vertices"<<endl;
                cin>>v;
                for(i=1;i<=v;i++)
                {
                    for(j=1;j<=v;j++)
                    {
                        cout<<"Enter the weight of edge "<<i<<" "<<j<<endl;
                        cin>>c[i][j];
                        
                    }
                } 
                cout<<"The adjacency matrix is"<<endl;
                for(i=1;i<=v;i++)
                {
                    for(j=1;j<=v;j++)
                    {
                         cout<<c[i][j]<<" ";
                    }
                    cout<<endl;
                } 
          } 
          void updateDistance(int u);
          int findmin();
          void SSSP(); 
};

dijkstra D;

void dijkstra::updateDistance(int u)
{
     int i;
     m[u]=1;
     for(i=1;i<=v;i++)
     {
          if(m[i]==0 && c[u][i]!=999)
          {
               if(d[i]>d[u]+c[u][i])
               {
                   d[i]=d[u]+c[u][i];
                   pre[i]=u;
               }    
          }
     }
}

int dijkstra::findmin()
{
     int i,min=1000;
     for(i=1;i<=v;i++)
     {
         if(d[i]!=0 && m[i]==0)
         {
              if(d[i]<min)
                  min=i;
         }
     }
     return min;
}

void dijkstra::SSSP()
{
     int i,index,u;
     cout<<"Enter the source vertex"<<endl;
     cin>>s;
     for(i=1;i<=v;i++)
     {
          d[i]=c[s][i];	
          m[i]=0;
          pre[i]=s; 
     }
     d[s]=0;
     m[s]=1;
     pre[s]=999;
     for(index=1;index<v-1;index++)
     {
          u=findmin();
          updateDistance(u);
     }
     int count=0;
     for(i=1;i<=v;i++)
     {
          if(pre[i]!=999)
          {
               result[count][0]=i;
               result[count][1]=pre[i];
               result[count][2]=c[pre[i]][i];
               count++;
          }
     }
     cout<<"The resultant tree is"<<endl;
     for(i=0;i<count;i++)
     {
          cout<<result[i][0]<<" "<<result[i][1]<<" Weight: "<<result[i][2]<<endl;
     } 
     for(i=1;i<=v;i++)
     {
          cout<<"Distance of "<<i<<" from source: "<<d[i]<<endl;
     }
     
     
}

int main()
{
    D.enter();
    D.SSSP();

return(0);
}
