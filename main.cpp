#include <iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

int mincostpathhelper(int **input,int m,int n,int i,int j)
{
  if(i==m-1 && j==n-1)
  {
    return input[i][j];
  }
  if(i>=m || j>=n)
  {
     return INT8_MAX;
  }
  int x=mincostpathhelper(input,m,n,i,j+1);
  int y=mincostpathhelper(input,m,n,i+1,j+1);
  int z=mincostpathhelper(input,m,n,i+1,j+1);
  int ans= min(x,min(y,z))+input[i][j];
  return ans;
}
int mincostpath(int**input,int m,int n)
{
  return mincostpathhelper(input,m,n,0,0);
}

int mincostpathhelpermemo(int **input,int m,int n,int i,int j,int **output)
{
  if(i==m-1 && j==n-1)
  {
    return input[i][j];
  }
  if(i>=m || j>=n)
  {
     return INT8_MAX;
  }
  if(output[i][j]!=-1)
  {
    return output[i][j];
  }
  int x=mincostpathhelpermemo(input,m,n,i,j+1,output);
  int y=mincostpathhelpermemo(input,m,n,i+1,j+1,output);
  int z=mincostpathhelpermemo(input,m,n,i+1,j+1,output);
  int a= min(x,min(y,z))+input[i][j];
  output[i][j]=a;
  return a;
}
int mincostpathmemo(int**input,int m,int n)
{
  int **output = new int*[m];
  for(int i=0;i<m;i++)
  {
    output[i]=new int[n];
    for(int j=0;j<n;j++)
    {
      output[i][j]=-1;
    }
  }
  return mincostpathhelpermemo(input,m,n,0,0,output);
}

int longestcommonsubsequence(string x,string y)
{
  if(x.size()==0 || y.size()==0)
  {
    return 0;
  }
  if(x[0]==y[0])
  {
    return 1+longestcommonsubsequence(x.substr(1),y.substr(1));
  }
  else
  {
    int a = longestcommonsubsequence(x.substr(1),y);
    int b = longestcommonsubsequence(x,y.substr(1));
    int c = longestcommonsubsequence(x.substr(1),y.substr(1));
    return max(a,max(b,c));
  }
}

int lcsmemhelper(string x,string y,int **output)
{
    if(x.size()==0 || y.size()==0)
  {
    return 0;
  }
  if(output[x.size()][y.size()]!=-1)
  {
    return output[x.size()][y.size()];
  }
  if(x[0]==y[0])
  {
    return 1+longestcommonsubsequence(x.substr(1),y.substr(1));
  }
  else
  {
    int a = longestcommonsubsequence(x.substr(1),y);
    int b = longestcommonsubsequence(x,y.substr(1));
    int c = longestcommonsubsequence(x.substr(1),y.substr(1));
    int ans= max(a,max(b,c));
    output[x.size()][y.size()]=ans;
    return ans;
  }
}

int lcsmem(string x,string y)
{
  int **output=new int*[x.size()+1];
  for(int i=0;i<=x.size();i++)
  {
    output[i]=new int(y.size()+1);
    for(int j=0;j<=y.size();j++)
    {
      output[i][j]=-1;
    }
  }
  return lcsmemhelper(x,y,output);
}
int main() 
{
  int m,n;
  cin>>m>>n;
  int **input=new int*[m];
  for(int i=0;i<m;i++)
  {
    input[i]=new int[n];
    for(int j=0;j<n;j++)
    {
      cin>>input[i][j];
    }
  }
  cout<<mincostpathmemo(input,m,n)<<endl;
  cout<<lcsmem("bcde", "amce")<<endl;
}