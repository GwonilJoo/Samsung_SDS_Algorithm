// 14003 가장 긴 증가하는 부분수열5

#include<cstdio>

int n, a[1000001];
int dp[1000001];

int main(){
  scanf("%d", &n);
  for(int i=1;i<=n;i++){
    scanf("%d", &a[i]);
  }
  
  for(int i=n-1;i>=1;i--){
    int tmp = -1;
    for(int j=i+1;j<=n;j++){
      if(a[i] < a[j]){
        tmp = j; break;
      }
    }
    
    if(tmp == -1) dp[i] = 1;
    else dp[i] = dp[tmp] + 1;
  }
  
  printf("%d")
}
