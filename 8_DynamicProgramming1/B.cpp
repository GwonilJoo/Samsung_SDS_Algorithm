// 11659 구간 합 구하기 4
/*
강사님 방법
*/

#include<cstdio>

int N, M, a[100001];
int subsum[100001]; // 1부터 i까지의 합

int main(){
  scanf("%d%d", &N, &M);
  for(int i=1;i<=N;i++){
    scanf("%d", &a[i]);
  }
  for(int i=1;i<=N;i++){
    subsum[i] = subsum[i-1] + a[i];
  }
  
  for(int i=0;i<M;i++){
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", subsum[r] - subsum[l-1]);
  }
}
