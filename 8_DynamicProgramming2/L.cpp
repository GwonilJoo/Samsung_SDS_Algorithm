// 10714 케이크 자르기2

/*
강사님 방법
*/

#include<cstdio>

int n, cake[2010];
long long ans;
long long dp[2010][2010]; //[i][j] J군이 바라볼때 왼쪽에는 i번째, 오른쪽에는 j번째 케이크, 이 상태에서 가장 많이 먹을 수 있는 값, J군과 I양의 dp를 한군데에 써도 된다 -> J군과 I양이 접근하는 인덱스는 서로 다르기 때문!

long long getmax(long long a, long long b) {return a>b?a:b;}
long long J_eat(int l, int r);
long long I_eat(int l, int r);


int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%d", &cake[i]);
  }
  
  if(n==1){
    printf("%lld\n", (long long)cake[0]);
    return 0;
  }
  
  for(int i=0;i<n;i++){
    // i번째 케이크를 j군이 먹으면서 시작
    int nextl, nextr;
    nextl = i+1;
    if(nextl == n) nextl = 0;
    nextr = i-1;
    if(nextr < 0) nextr = n-1;
    
    ans = getmax(ans, cake[i] + I_eat(nextl, nextr));
  }
  
  printf("%lld\n", ans);
}

// J군이 먹을 차례가 되었는데 바라볼때 왼쪽은 l케이크, 오른쪽은 r케이크가 있을때 많이 먹을 수 있는 값
long long J_eat(int l, int r){
  if(l == r) return cake[l];
  
  if(dp[l][r]) return dp[l][r];
  // 먹을 수 있는 경우의 수
  int nextl, nextr;
  nextl = l+1;
  if(nextl == n) nextl = 0;
 
  nextr = r-1;
  if(nextr < 0) nextr = n-1;
  
  // l을 먹거나...cake[l]
  // r을 먹거나...cake[r]
  // 이중에 큰값을 리턴
  
  return dp[l][r] = getmax(cake[l] + I_eat(nextl, r), cake[r] + I_eat(l, nextr));
}

// I양이 먹을 차례가 되었는데 바라볼때 왼쪽은 l케이크, 오른쪽은 r케이크가 있을때 I양이 많이 먹을 수 있는 값
// I양이 먹을 차례가 되었는데 바라볼때 왼쪽은 l케이크, 오른쪽은 r케이크가 있을때 J군이 많이 먹을 수 있는 값 ==> 선택
long long I_eat(int l, int r){
  if(l == r) return 0;
  //먹을 수 있는 경우의 수가....없고 큰것만 먹어야 함
  
  if(dp[l][r]) return dp[l][r];
  
  int nextl, nextr;
  if(cake[l] > cake[r]){
    //cake[l] 먹고
    nextl = l+1;
    if(nextl == n) nextl = 0;
    return dp[l][r] = J_eat(nextl,r);
  }
  else{
    //cake[r] 먹음
    nextr = r-1;
    if(nextr < 0) nextr = n-1;
    return dp[l][r] = J_eat(l, nextr);
  }
}
