#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  //write your code here
  int n = (exp.length()-1)/2;
	char o[n];
	int d[n+1];
	int M[n+1][n+1];
	int m[n+1][n+1];
	for(int i=0;i<exp.length();i++)
		{
			if(i%2==0)
				d[i/2]=exp[i]-'0';
			
			else
				o[i/2]=exp[i];
				

		}
	
	

	for(int i=0;i<=n;i++)
		M[i][i]=m[i][i]=d[i];


	for(int s=0;s<=n;s++)
		for(int i=0;i<=n-s;i++)
		{
			int j=i+s;
			if(i!=j){
			M[i][j]=-10000;
			m[i][j]=10000;
		}


			for(int k=i;k<=j-1;k++)
				{

					int a=M[i][k],b=M[k+1][j],c=m[i][k],e=m[k+1][j];
					int A,B,C,E;
					if(o[k]=='+')
						A=a+b,B=a+e,C=c+e,E=c+b;
					else if(o[k]=='-')
						A=a-b,B=a-e,C=c-e,E=c-b;
					else A=a*b,B=a*e,C=c*e,E=c*b;

					 m[i][j] = min({m[i][j],A,B,C,E});
					 M[i][j] = max({M[i][j],A,B,C,E});



				}

		}
		/*for(int i=0;i<n+1;i++)
		{
			for(int k=0;k<i;k++) cout << "  " ;
			for(int j=i;j<=n;j++) cout << M[i][j] << ' ' ;
			 cout << endl ;
		}*/
		
		return M[0][n];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
