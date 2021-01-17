// 14476 최대공약수 하나 빼기

/*
강사님 방법
gcd(a,b,c) = gcd(gcd(a,b),c)
left right 방향으로 각각 누적 gcd 를 구해나가기
i번째의 결과를 구하고 싶으면 gcd(gcd(1~i-1), gcd(i+1~n)) 구해서 약수인지 판단

ex)
[8, 3, 4, 5] 있으면
left = [g(8), g(8~3), g(8~4), g(8~5)]
right = [g(8~5), g(3~5), g(4~5), g(5)]

index가 1인 3을 제외한 최대공약수를 구하고 싶다면
g(g(8), g(4~5)) 이므로
g(left[0], right[2]) = g(left[1-1], right[1+1])
-> g(left[i-1], right[i+1])
*/

#include<iostream>
using namespace std;

int N;
int *arr;
int *Left, *Right;

int gcd(int a, int b);
void make_gcd();
void solution();

int main(){
  cin >> N;
  arr = new int[N];
  Left = new int[N];
  Right = new int[N];
  
  for(int i=0;i<N;i++){
    cin >> arr[i];
  }
  
  make_gcd();
  solution();
  
  delete [] arr;
  delete [] Left;
  delete [] Right;
}

int gcd(int a, int b){
  // 최대 공약수 구하기 - 유클리드 호제법 gcd(a,b) = gcd(a, a%b)
  while(b){
    int r = a%b;
    a = b;
    b = r;
  }
  
  return a;
}

void make_gcd(){
  // 왼쪽부터 최대공약수 누적해가기
  Left[0] = arr[0];
  for(int i=1;i<N;i++){
    Left[i] = gcd(arr[i], Left[i-1]);
  }
  
  // 오른쪽부터 최대공약수 누적해가기
  Right[N-1] = arr[N-1];
  for(int i=N-2;i>=0;i--){
    Right[i] = gcd(arr[i], Right[i+1]);
  }
}

void solution(){
  int Max = 0, max_index = -1;
  
  for(int i=0;i<N;i++){
    int result;
    
    
    if(i == 0) 		// 왼쪽 끝이면 1~n-1 이므로 right[1]
      result = Right[i+1];
    else if(i == N-1) 		// 오른쪽 끝이면 0~n-2 이므로 left[n-2]
      result = Left[i-1];
    else 			// k번째의 결과는 gcd(left[k-1], right[k+1])
      result = gcd(Left[i-1], Right[i+1]);
      
    if((arr[i] % result != 0) && Max < result){ // 약수가 아니고, 현재 max보다 크다면!
      Max = result;
      max_index = i;
    }
  }
  
  if(max_index == -1)
    cout << -1 << "\n";
  else{
    cout << Max << " " << arr[max_index] << "\n";
  }
}

