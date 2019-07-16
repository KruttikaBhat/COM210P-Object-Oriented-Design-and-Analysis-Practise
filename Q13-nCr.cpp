#include<iostream>
using namespace std;
int n,r,count1=0,count2=0;

int min(int a,int b)
{
    return(a>b)? b:a;
}

int dynamic(int n, int k)
{
    int C[n+1][k+1];
    int i, j;
 
    // Caculate value of Binomial Coefficient in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            // Base Cases
            count1++;
            if (j == 0 || j == i)
                C[i][j] = 1;
 
            // Calculate value using previosly stored values
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
 
    return C[n][k];
}
/*
int fact(int x)
{
     int p=1;
     for(int i=x;i>1;i--)
     {
         p*=i;
         count2++;
     }    
     return p;    
}

void nonDynamic()
{
     int result=fact(n)/(fact(n-r)*fact(r));
     cout<<"Non dyanamic approach: "<<count2<<" "<<result<<endl;
}
*/
int binomialCoeff(int n, int k)
{
  count2++; 
  // Base Cases
  if (k==0 || k==n)
    return 1;
 
  // Recur
  return  binomialCoeff(n-1, k-1) + binomialCoeff(n-1, k);
}

int main()
{
     cout<<"Enter n and r"<<endl;
     cin>>n>>r; 
     cout<<"Hi";
     cout<<"Dynamic: "<<count1<<" "<<dynamic(n,r);
     cout<<"nonDynamic: "<<count2<<" "<<binomialCoeff(n,r);
}

