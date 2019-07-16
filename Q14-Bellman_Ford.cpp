#include<iostream>
using namespace std;

struct edge
{
     int s,d,w;
};

struct edge G[20];
int V,E,S;

void enter()
{
     for(int i=0;i<E;i++)
     {
        cout<<"Enter source, destination and weight"<<endl;
        cin>>G[i].s>>G[i].d>>G[i].w; 
     }
}

void print()
{
     for(int i=0;i<E;i++)
     {
        cout<<G[i].s<<" "<<G[i].d<<" Weight:"<<G[i].w<<endl; 
     }
}

void Bellman(int V,int E)
{
     int i,j,D[V],u,w,v;
     //cout<<V<<endl;
     for(i=0;i<V;i++)
     {
         D[i]=999;
         cout<<D[i]<<endl;
     }    
     D[S]=0; 
     
     //cout<<"check"<<endl;    
     for(i=1;i<=V-1;i++)
     {
          for(j=0;j<E;j++)
          {
               u=G[j].s;
               v=G[j].d;
               w=G[j].w;
               //cout<<"check1"<<endl;    
               if(D[u]!=999 && D[u]+w<D[v])
               {
                    D[v]=D[u]+w;
               } 
               
          } 
     }   
     for(i=0;i<E;i++)
     {
           u=G[i].s;
           v=G[i].d;
           w=G[i].w;   
          if(D[u]!=999 && D[u]+w<D[v])
          {
               cout<<"Negative cycle is present"<<endl;
          } 
     }
     cout<<"The distance array is"<<endl;

     for(i=0;i<V;i++)
         cout<<i<<" "<<D[i]<<endl;
}

int main()
{
     int i; 
     cout<<"Enter the number of vertices"<<endl;
     cin>>V;
     cout<<"Enter the number of edges"<<endl;
     cin>>E;
     enter(); 
     print();
     cout<<"Enter the source"<<endl;
     cin>>S;   
     Bellman(V,E);    
} 
