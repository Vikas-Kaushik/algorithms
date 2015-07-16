#include <iostream>
#include<cstdio>
#include<vector>
using namespace std;

#define MAX 200

long long nways[MAX+1][MAX+1];
int K;

long long noWays(int N,int m)
{
	if(N == 0) return 1;
	if(m == 0) return 0;
	if(N < K || N < 0 || m < K ) return 0;
	
	if(nways[N][m] != -1) return nways[N][m];
	
	//cout<<N<<" "<<m<<endl;
	nways[N][m] = noWays(N,m-1)+noWays(N-m,m);
	
	return nways[N][m];
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int N;
    	cin>>N>>K;
    	for(int i =0 ; i< MAX+1;i++)
    		for(int j =0 ; j< MAX+1;j++)
    		nways[i][j] = -1;
    	cout<<noWays(N,N)<<endl;
    }
    return 0;
}
