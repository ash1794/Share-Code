/*
15. MAX BIPARTATE MATCHING
INPUT: w[i][j] = edge between row node i and column node OUTPUT: mr[i] = assignment for row node i, -1 if unassigned mc[j] = assignment for column node j, -1 if unassigned function returns number of matches made
*/
#include<bits/stdc++.h>

using namespace std;

#define MAX_R 10
#define MAX_C 10
int w[MAX_R][MAX_C];
vector<int> mr(MAX_R,-1);
vector<int> mc(MAX_C,-1);
bool FindMatch(int i, vector<int> &seen) {
  for (int j = 0; j < MAX_C; j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}   

int BipartiteMatching() {
  int ct = 0;
  for (int i = 0; i < MAX_R; i++) {
    vector<int> seen(MAX_C);
    if (FindMatch(i, seen)) ct++;
  }
  return ct;
}
