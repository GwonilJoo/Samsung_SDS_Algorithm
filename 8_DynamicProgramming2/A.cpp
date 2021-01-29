// 7579 앱

/*
강사님 방법
*/

#include<cstdio>

int N, M, mem[101], cost[101], ans;
int dp[101][10001]; // [j][i] j까지 app을 대상으로 살펴봤을 때 cost i로 얻을 수 있는 최대 메모리 크기
bool tracking[101][10001];

int getmax(int a, int b){return a>b?a:b;} 

int main(){
  scanf("%d%d", &N, &M);
  for(int i=1;i<=N;i++) scanf("%d", &mem[i]);
  for(int i=1;i<=N;i++) scanf("%d", &cost[i]);
  
  for(int j=1;j<=100;j++){
    for(int i=0;i<=10000;i++){
      // [j][i]: j 앱까지 고려했을때(대상으로 했을때) cost i로 확보할 수 있는 최대 메모리
      // j번째 앱을 사용하거나/사용하지 않거나 -> 둘 중 큰값 사용
      dp[j][i] = dp[j-1][i];
      
      if(i-cost[j] >= 0 && dp[j-1][i] < dp[j-1][i-cost[j]] + mem[j]){
        tracking[j][i] = true;
      }
      
      if(i-cost[j] >= 0){
        dp[j][i] = getmax(dp[j][i], dp[j-1][i-cost[j]] + mem[j]);
      }
    }
  }
  
  // 답을 낼 것임
  // 비용을 찾아보면서, m 이상의 메모리를 확보했는지 확인해봄
  for(int i=0;i<=10000;i++){
    if(dp[N][i] >= M){
      ans = i;
      break;
    }
  }
  
  printf("%d\n", ans);
  int tmpcost = ans;
  for(int i=100;i>=1;i--){
    if(tracking[i][tmpcost] == true){
      printf("%d ", i);
      tmpcost -= cost[i];
    }
  }
  printf("\n");
}
