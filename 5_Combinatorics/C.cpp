// 11051 이항계수2

#include<iostream>
using namespace std;

#define MAX 30

long long D[MAX+1][MAX+1];

int main(){
  for(int i=0;i<30;i++){
    D[i][0] = 1;
    for(int j=1;j<i;j++){
      D[i][j] = (D[i-1][j-1] + D[i-1][j]);
    }
    D[i][i] = 1;
  }
  
  int T, N, M;
  cin >> T;
  
  for(int i=0;i<T;i++){
    cin >> N >> M;
    cout << D[N][M] << "\n";
  }
  
  
  // k == 0 -> 1
  // n == k -> 1
  // D[n][k] = D[n-1][k-1] + D[n-1][k]
  
  
  
  
}
