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
        priority[i] = ele;
        fault++;
        break;
      }

      if (arr[i] == ele) {free = 1; break;}
    }  // slot is free or element already available

    if (!free) // element not found removing first priroity element
    {
      fault ++;
      for (int i = 0; i < n; i++) {
        if (arr[i] == priority[0]) {
          arr[i] = ele;
          break;
        }
      }

      for (int i = 0; i < 2; i++)   swap(priority[i], priority[i + 1]);
      priority[2] = ele;
    }

    for (int i = 0; i < 3; i++) {
      cout << setw(3) << arr[i] << " ";
    }
    cout << endl;
  }

  cout << "page fault = " << fault << endl;
}
