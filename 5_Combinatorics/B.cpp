// 11051 이항계수2

#include<iostream>
using namespace std;

#define MAX 1000

int D[MAX+1][MAX+1];

int main(){
  int N, K;
  cin >> N >> K;
  
  // k == 0 -> 1
  // n == k -> 1
  // D[n][k] = D[n-1][k-1] + D[n-1][k]
  
  for(int i=0;i<=N;i++){
    D[i][0] = 1;
    for(int j=0;j<i;j++){
      D[i][j] = (D[i-1][j-1] + D[i-1][j])%10007;
    }
    D[i][i] = 1;
  }
  
  cout << D[N][K] << "\n";
}
