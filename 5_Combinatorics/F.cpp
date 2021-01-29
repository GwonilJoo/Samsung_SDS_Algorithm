// 5557 1학년

#include<cstdio>

int n, a[100], cnt;
int dp[100][21];

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%d", &a[i]);
  }
  
  dp[1][a[1]] = 1;
  for(int i=2;i<=n;i++){
    for(int j=0;j<=20;j++){
      dp[i][a[j]];
    }
  }
}
