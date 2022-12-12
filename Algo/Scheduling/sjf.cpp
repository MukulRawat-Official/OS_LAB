#include <stdio.h>
int main(){
int n; cin >> n;
  int at[n]  , bt[n] , ct[n] , tat[n] , wt[n] , completed[n] , curr = 0 , count = 0;
  for (int i = 0; i < n; i++) {
    cin >> at[i] >> bt[i];
  }

  for (int i = 0; i < n; i++) completed[i] = 0;



  while (count != n) {
    int id = -1;

    for (int i = 0; i < n; i++) {
      if (completed[i]) continue;
      if (at[i] <= curr) {
        if (id == -1) id = i;
        else if (bt[i] <= bt[id]) id = i;
      }
    }

    if (id == -1)
    {
      for (int i = 0; i < n; i++) {
        if (completed[i]) continue;
        if (id == -1) id = i;
        else if (at[i] < at[id]) id = i;
        else if (at[i] == at[id] && bt[id] > bt[i]) id = i;
      }
    }

    completed[id] = 1;
    curr = max(curr , at[id]) + bt[id];
    ct[id] = curr;
    count++;
  }

  for (int i = 0; i < n; i++) {
    tat[i] = ct[i] - at[i];
    wt[i] = tat[i] - bt[i];
  }


  for (int i = 0; i < n; i++) cout << ct[i] << " ";
  return 0;
}
