void solve()
{
  // input = pages  , pages no
  int n, ele; cin >> n;
  vector<int>arr(3, -1) , priority(3, -1);
  int fault = 0;
  for (int i = 0; i < n; i++) {
    cin >> ele;
    int free = 0;

    for (int i = 0; i < 3; i++) {
      if (arr[i] == -1) {
        free = 1;
        arr[i] = ele;
        fault++;

        for (int j = i; j > 0; j--) {
          swap(priority[j], priority[j - 1]);
        }
        break;
      }

      if (arr[i] == ele) {
        free = 1;
        int idx = 0;
        while (idx < 3) {if (priority[idx] == ele) break; idx++;}
        for (int j = idx; j > 0; j--) swap(priority[j], priority[j - 1]);
        break;
      }
    }  // slot is free or element already available


    if (!free) // element not found removing first priroity element
    {
      fault ++;
      int elem = 0;

      for (int i = 2; i >= 0; i--) {
        if (priority[i] == -1) continue;
        elem = priority[i]; break;
      }
      for (int i = 0; i < n; i++) {
        if (arr[i] == elem) {
          arr[i] = ele;
          break;
        }
      }

      for (int i = 2; i > 0; i--)   swap(priority[i], priority[i - 1]);

    }

    priority[0] = ele;
    for (int i = 0; i < 3; i++) {
      cout << setw(3) << arr[i] << " ";
    }
    cout << endl;
  }

  cout << "page fault = " << fault << endl;
}
