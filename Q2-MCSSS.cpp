#include<iostream>
using namespace std;

class seq
{
    int n;
    int a[20];
    public:
        void display(int beg,int end);
        void create();
        void brute();
        void inc();
        int div(int a[],int beg,int end);
        void dc();
        void prune();
};
  
void seq::display(int beg,int end)
{
    for(int i=beg;i<=end;i++)
        cout<<a[i]<<"  ";
}


void seq::create()
{
    cout<<"Enter the size"<<endl;
    cin>>n;
    cout<<"Enter the sequence"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    display(0,n-1);

}


void seq::brute()
{
    int i,j,k,csum=0,max=0,beg,end;
    for(i=0;i<n;i++)
    {
         for(j=0;j<n;j++)
         { 
              csum=0;
              for(k=i;k<=j;k++)
              {
                  csum+=a[k];  
              } 
              if(csum>max)
              {
                   max=csum;
                   beg=i;
                   end=j; 
              }  
         }
    }
    cout<<"\nMax: "<<max<<endl;
    display(beg,end);
    /*
    for(i=beg;i<=end;i++)
        cout<<a[i]<<"  "; 
*/
}

void seq::inc()
{
    int i,j,k,csum=0,max=0,beg,end;
    for(i=0;i<n;i++)
    {
        csum=0;
        for(j=i;j<n;j++)
        {
            csum+=a[j];
            if(csum>max)
            {
                max=csum;
                beg=i;
                end=j;
            }
        }
    }
    cout<<"\nMax: "<<max<<endl;
    display(beg,end);

}

int k[200][20]={0};
int count=0;
int seq::div(int a[],int beg,int end)
{
     int i,ls,rs,mid,lsum=0,rsum=0,csum=0,tbeg,tend,j;
     if(beg==end)
     {
          if(a[beg]<0)
          {
               k[count][0]=0;
               count++;
               return 0;
          }
          else
          {
               k[count][0]=a[beg];
               count++;
               return a[beg];
          }
               
     }
     mid=(beg+end)/2;
     ls=div(a,beg,mid);
     rs=div(a,mid+1,end);
     for(i=mid;i>=beg;i--)
     {
          csum+=a[i];
          if(csum>lsum)
          {
               lsum=csum;
               tbeg=i;
               
          }
     }  
     csum=0;
     for(i=mid+1;i<=end;i++)
     {
          csum+=a[i];
          if(csum>rsum)
          {
               rsum=csum;
               tend=i;
          }
     }
     for(i=0,j=tbeg;i<(tend-tbeg+2),j<=tend;i++,j++)
     {
          k[count][i]=a[j];  
     }
     return(max(ls,max(rs,lsum+rsum)));   

}

int max(int a,int b)
{
    if(a>b)
       return a;
    else
        return b;

}


void seq::dc()
{
     int max,sum,i,j,index,end; 
     max=div(a,0,n-1);
     cout<<"\nMax: "<<max<<endl;
     for(i=0;i<=count;i++)
     {
          sum=0;
          for(j=0;j<20;j++)
          {
               sum+=k[i][j]; 
               if(sum==max)
               {
                    index=i;
                    end=j;
                    break;
               }    
          } 
     }
     for(i=0;i<=end;i++)
          cout<<k[index][i]<<" ";
}

void seq::prune()
{
     int i,csum=0,max=0,beg,end,tempbeg;
     for(i=0;i<n;i++)
     {
         csum+=a[i];
         if(csum<0)
         {
             csum=0;
             tempbeg=i+1;
         } 
         if(csum>max)
         {
             max=csum;
             beg=tempbeg;
             end=i;   
         }
     } 
     cout<<"\nMax: "<<max<<endl;
     display(beg,end);
}

int main()
{
    int c;
    seq s;
    do{
       cout<<"Enter one of the below options\n1.Enter sequence\n2.Brute force\n3.Incremental\n4.Divide and Conquer\n5.Pruning\n6.Exit\n";
       cin>>c;
       switch(c)
       {
            case 1:
                 s.create();
                 break;       
            case 2:
                 s.brute();
                 break;       
            case 3:
                 s.inc();
                 break;       
            case 4:
                 s.dc();
                 break;       
            case 5:
                 s.prune();
                 break;         
            case 6:
                 break;

       }
    }while(c!=6);
 

return(0);
}
