// 3830 교수님은 기다리지 않는다

/*
강사님 힌트

union-find로 풀리는 문제! -> 다른 그룹이면 unknown

무게 비교는 루트를 기준으로 하기
무게 저장은 루트의 무게보다 얼마나 무거운지 또는 가벼운지를 저장한다
루트가 변경되면 무게 또한 변경된 루트를 기준으로 변경할것
find할때 해주기
*/

#include<cstdio>
#include<vector>
using namespace std;

int N, M, weight[100001], pr[100001];

void init(){
  for(int i=1;i<=N;i++){ 
    weight[i] = 0; pr[i] = i;
  }
}

int find(int a){
  int tmp = pr[a];
  if(tmp == a) return a;
  
  find(tmp);
  weight[a] += weight[tmp];
  return pr[a] = find(tmp);
}

void unionf(int a, int b, int w){
  find(a); find(b); // 업데이트
  
  int x = weight[a];
  int y = weight[b];
  
  a = find(a);
  b = find(b); // b는 원래 b의 루트
  
  pr[b] = a;
  weight[b] = x+w-y; // 원래 b의 루트의 weight
}

void show(){
  printf("\nweight: ");
  for(int i=1;i<=4;i++){
    printf("%d ", weight[i]);
  }
  printf("\nparent: ");
  for(int i=1;i<=4;i++){
    printf("%d ", pr[i]);
  }
  printf("\n");
}

int main(){
  while(true){
    scanf("%d%d", &N, &M);
    if(N == 0 && M == 0) break;
    
    init();
    
    for(int i=0;i<M;i++){
      char cmd;
      scanf(" %c", &cmd);
    
      if(cmd == '!'){
        int a,b,w;
        scanf("%d%d%d", &a, &b, &w);// a<-b
        unionf(a,b,w);
      }
      else if(cmd == '?'){
        int a,b;
        scanf("%d%d", &a, &b);
      
        if(find(a) != find(b)) printf("UNKNOWN\n");
        else printf("%d\n", weight[b] - weight[a]);
      }
    }
  }
}
