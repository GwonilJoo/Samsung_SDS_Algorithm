// 1717 집합의 표현

/*
강사님 풀이
전형적인 union find 문제
*/

#include<cstdio>

int n, m, pr[1000010];

// a의 부모가 누군지 알려줌
int findf(int a){
  if(a == pr[a]) return a;
  //return findf(p[a]); // 재귀적 .... 시간초과 O(백만 x 십만)
  pr[a] = findf(pr[a]); // 시간초과를 해결하기 위한 방법. 업데이트를 해주자!
  return pr[a];
}

// a b 합침
void unionf(int a, int b){
  a = findf(a);
  b = findf(b);
  pr[a] = b;
}


int main(){
  scanf("%d %d",&n, &m);
  
  //초기화
  for(int i=0;i<=n;i++){
    pr[i] = i;
  }
  while(m--> 0){
    int cmd, a, b;
    scanf("%d%d%d", &cmd, &a, &b);
    // cmd == 0 union
    if(cmd == 0){
      // to do union
      unionf(a,b);
    }
    // cmd == 1 find
    else if(cmd ==1){
      // to do find, print yes or no
      if(findf(a) == findf(b)) printf("yes\n");
      else printf("no\n");
    }
  }
}
