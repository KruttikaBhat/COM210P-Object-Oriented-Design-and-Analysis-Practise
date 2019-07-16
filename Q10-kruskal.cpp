#include<iostream>
#include<cstdlib>
using namespace std;

struct Edge
{
    int x,y,weight;
};

struct Graph
{
    int V,E;
    struct Edge *edge;
   
};

struct subsets
{
     int parent,rank;
};
struct Graph *createGraph(int v,int e)
{
     struct Graph *graph=new struct Graph;
     graph->V=v;
     graph->E=e;
     graph->edge=new Edge[e];
     return graph;  
}

struct Graph *sort(struct Graph *ptr)
{
      struct Edge temp;
      for(int i=1;i<ptr->E;i++)
      {
           for(int j=i;j>0;j--)
           {
                 if(ptr->edge[j].weight<ptr->edge[j-1].weight)
                 {
                       temp=ptr->edge[j];
                       ptr->edge[j]=ptr->edge[j-1];
                       ptr->edge[j-1]=temp; 
                 }
           }
      }
      return ptr;   
}

int find(struct subsets subset[],int val)
{
       if(val!=subset[val].parent)
             subset[val].parent=find(subset,subset[val].parent);
       return subset[val].parent;      
}

void Union(struct subsets subset[],int x,int y)
{
      int xroot,yroot;
      xroot=find(subset,x);
      yroot=find(subset,y);
      if(subset[xroot].rank<subset[yroot].rank)
            subset[xroot].parent=yroot;
      else if(subset[yroot].rank<subset[xroot].rank)
            subset[yroot].parent=xroot;
      else
      {
            subset[yroot].parent=xroot;  
            subset[xroot].rank++;             
      }      
}

void Kruskal(struct Graph *graph)
{
      int e=0,i=0,v=graph->V;
      struct Edge result[v];
      struct subsets *subset=(struct subsets *)malloc(v*sizeof(struct subsets));
      //struct subsets *subset=new struct subsets[v];
      for(int j=0;j<v;j++)
      {
            subset[j].parent=j;
            subset[j].rank=0;
      }
      while(e<v-1)
      {
            struct Edge next=graph->edge[i];
            i++;
            int x,y;
            x=find(subset,next.x);
            y=find(subset,next.y);
            if(x!=y)
            {
                 result[e]=next;
                 e++;
                 Union(subset,x,y);
            }
      }
      cout<<"The minimum spanning tree is"<<endl;
      for(i=0;i<e;i++)
           cout<<result[i].x<<" "<<result[i].y<<" "<<result[i].weight<<endl;
      
}

int main()
{
     int v,e;
     cout<<"Enter the number of vertices and the number of edges"<<endl;
     cin>>v>>e;
     struct Graph *graph=createGraph(v,e);
     for(int i=0;i<e;i++)
     {
          cout<<"Enter the first point, second point and the weight"<<endl;
          cin>>graph->edge[i].x>>graph->edge[i].y>>graph->edge[i].weight;
     } 
     cout<<"Before sorting"<<endl;
     for(int i=0;i<e;i++)
     {
          cout<<graph->edge[i].x<<" "<<graph->edge[i].y<<" "<<graph->edge[i].weight<<endl;
     }
     graph=sort(graph); 
     cout<<"After sorting"<<endl;
     for(int i=0;i<e;i++)
     {
          cout<<graph->edge[i].x<<" "<<graph->edge[i].y<<" "<<graph->edge[i].weight<<endl;
     }
     Kruskal(graph);
     
}
