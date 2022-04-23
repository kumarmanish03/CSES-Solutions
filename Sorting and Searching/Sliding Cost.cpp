/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1077/
* @disc: slight modification of Sliding Median
*
*/

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

#define int long long

long N, M;
long arr[200010];

multiset<long> up;
multiset<long> low;
int upSum = 0, lowSum = 0;

void ins(long val){ // insert val into sets
  long a = *low.rbegin(); // current median
  if(a < val){
    up.insert(val);
    upSum += val;
    if(up.size() > M/2){
      lowSum += *up.begin();
      low.insert(*up.begin());
      upSum -= *up.begin();
      up.erase(up.find(*up.begin()));
    }
  }
  else{
    low.insert(val);
    lowSum += val;
    if(low.size() > (M + 1)/2){
      upSum += *low.rbegin();
      up.insert(*low.rbegin());
      lowSum -= *low.rbegin();
      low.erase(low.find(*low.rbegin()));
    }
  }
}


void er(long val){ // erase from sets
  if(up.find(val) != up.end()) up.erase(up.find(val)), upSum -= val;
  else low.erase(low.find(val)), lowSum -= val;

  if(low.size() < up.size()){
    upSum -= *up.begin();
    lowSum += *up.begin();
    low.insert(*up.begin());
    up.erase(up.begin());
  }
}

signed main() {
  lowSum = upSum = 0;
  cin >> N >> M;
  for(int i = 0; i < N; i++) cin >> arr[i];
  low.insert(arr[0]); 
  lowSum += arr[0];
  for(int i = 1; i < M; i++) ins(arr[i]);
  int med = *low.rbegin();
  int cost = abs(lowSum - (int)low.size()*med) + abs(upSum - (int)up.size()*med);
  cout << cost << " ";
  for(long i = M; i < N; i++){
    if(M == 1){
      ins(arr[i]);
      er(arr[i - M]);
    }
    else{
      er(arr[i - M]);
      ins(arr[i]);
    }
    med = *low.rbegin();
    cost = abs(lowSum - (int)low.size()*med) + abs(upSum - (int)up.size()*med);
    cout << cost << " ";
  }
  cout << endl;
}
