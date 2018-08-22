void printDuplicates(int arr[], int n)
{
   //add code here.
   bool flg = true;
   for (int i = 0; i < n; i++) {
       int num = arr[i] % n;
       if (1 == arr[num] / n) {
           if (flg == false) cout << " ";
           flg = false;
           cout << num;
       }
       arr[num] += n;
   }
   if (flg) {
       cout << -1;
   }
}
