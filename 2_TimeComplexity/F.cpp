// 2096 내려가기

#include<iostream>
using namespace std;

int N;
int dp[100000][3];
int Max[2][3], Min[2][3];

void init(){
  cin >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<3;j++){
      cin >> dp[i][j];
    }
  }
  
  for(int i=0;i<3;i++){
    //Max[1][i] = Min[1][i] = dp[0][i];
  }
}

void solution(){
  for(int i=0;i<N;i++){
      Max[0][0] = dp[i][0] + max(Max[1][0], Max[1][1]);
      Max[0][1] = dp[i][1] + max(max(Max[1][0], Max[1][1]), Max[1][2]);
      Max[0][2] = dp[i][2] + max(Max[1][1], Max[1][2]);
      
      Min[0][0] = dp[i][0] + min(Min[1][0], Min[1][1]);
      Min[0][1] = dp[i][1] + min(min(Min[1][0], Min[1][1]), Min[1][2]);
      Min[0][2] = dp[i][2] + min(Min[1][1], Min[1][2]);
      
      Max[1][0] = Max[0][0]; Max[1][1] = Max[0][1]; Max[1][2] = Max[0][2];
      Min[1][0] = Min[0][0]; Min[1][1] = Min[0][1]; Min[1][2] = Min[0][2];
      
      cout << endl;
      cout << Max[1][0] << " " << Max[1][1] << " " << Max[1][2] << endl;
      cout << Min[1][0] << " " << Min[1][1] << " " << Min[1][2] << endl;
      cout << endl;
  }
  
  cout << max(max(Max[1][0], Max[1][1]), Max[1][2]) << " " << min(min(Min[1][0], Min[1][1]), Min[1][2]) << endl;
}

int main(){
  init();
  solution();
}
