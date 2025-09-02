// Selection Sort

#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n) {
  for (int i = 0; i <= n - 2; i++) {
    int mini = i;
    for (int j = i; j <= n - 1; j++) {
      if (arr[j] < arr[mini]) {
        mini = j;
      }
    }
    int temp = arr[mini];
    arr[mini] = arr[i];
    arr[i] = temp;
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  selection_sort(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

// Bubble Sort

#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n) {
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  bubble_sort(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}

// Insertion Sort

#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
      int temp = arr[j - 1];
      arr[j - 1] = arr[j];
      arr[j] = temp;
      j--;
    }
  }
}

int main() {
  int n;
  cin >> n;
  int ar[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  insertion_sort(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}

// Merge Sort

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
  vector<int> temp;    // temporary array
  int left = low;      // starting index of left half of arr
  int right = mid + 1; // starting index of right half of arr

  // storing elements in the temporary array in a sorted manner//

  while (left <= mid && right <= high) {
    if (arr[left] < arr[right]) {
      temp.push_back(arr[left]);
      left++;
    } else {
      temp.push_back(arr[right]);
      right++;
    }
  }

  // if elements on the left half are still left //

  while (left <= mid) {
    temp.push_back(arr[left]);
    left++;
  }

  // if elements on the right half are still left //
  while (right <= high) {
    temp.push_back(arr[right]);
    right++;
  }

  // transfering all elements from temporary to arr //
  for (int i = low; i <= high; i++) {
    arr[i] = temp[i - low];
  }
}

void mergeSort(vector<int> &arr, int low, int high) {
  if (low >= high)
    return;
  int mid = (low + high) / 2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);
  merge(arr, low, mid, high);
}

int main() {
  vector<int> arr = {2, 6, 4, 9, 5, 1};
  int n = 6;

  for (int i = 0; i <= n; i++) {
    cin >> arr[i];
  }
  cout << endl;
  mergeSort(arr, 0, n - 1);

  for (int i = 0; i <= n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}

// Quick Sort

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
  int pivot = arr[low];
  int i = low;
  int j = high;

  while (i < j) { // Loop until the two pointers cross.
    while (arr[i] <= pivot && i <= high - 1) {
      i++; // Move i right until it finds a number greater than the pivot
    }

    while (arr[j] > pivot &&
           j >= low + 1) { // Move j left until it finds a number less than or
                           // equal to the pivot
      j--;
    }
    if (i < j)
      swap(arr[i],
           arr[j]); // If i and j haven’t crossed, swap the wrong elements.
  }
  swap(arr[low], arr[j]); // Finally, put the pivot in its correct position.
  return j;
}

void qs(vector<int> &arr, int low, int high) {
  if (low < high) { // Only sort if there’s more than one element.
    int pIndex = partition(arr, low, high);
    qs(arr, low, pIndex - 1);
    qs(arr, pIndex + 1, high);
  }
}

vector<int> quickSort(vector<int> arr) {
  qs(arr, 0, arr.size() - 1);
  return arr;
}

int main() {
  vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
  int n = arr.size();
  cout << " Before Quick Sort" << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  arr = quickSort(arr);
  cout << " After Quick Sort" << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}

// Largest Element in an array

#include <bits/stdc++.h>
using namespace std;

int Large(int arr[], int n) {
  int max = arr[0];
  for (int i = 0; i < n; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int max = Large(arr, n);
  cout << "The Largest Element in the array is " << max << endl;
}

// Second Largest Element in an array
// Second Smallest Element in an array

#include <bits/stdc++.h>
using namespace std;

int secondSmallest(int arr[], int n) {
  if (n < 2)
    return -1;

  int small = INT_MAX;
  int Ssmall = INT_MAX;

  for (int i = 0; i < n; i++) {
    if (arr[i] < small) {
      Ssmall = small;
      small = arr[i];
    }

    else if (arr[i] < Ssmall && arr[i] != small) {
      Ssmall = arr[i];
    }
  }
  return Ssmall;
}

int secondLargest(int arr[], int n) {
  if (n < 2)
    return -1;

  int large = INT_MIN;
  int Slarge = INT_MIN;

  for (int i = 0; i < n; i++) {
    if (arr[i] > large) {
      Slarge = large;
      large = arr[i];
    }

    else if (arr[i] > Slarge && arr[i] != large) {
      Slarge = arr[i];
    }
  }
  return Slarge;
}

int main() {
  int arr[] = {1, 2, 4, 7, 7, 5};
  int n = 6;
  int Sl = secondLargest(arr, n);
  int Ss = secondSmallest(arr, n);

  cout << "The second largest element is " << Sl << endl;
  cout << "The second smallest element is " << Ss << endl;
  return 0;
}

// Check if Array is Sorted

#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    if (arr[i] < arr[i - 1])
      return false;
  }

  return true;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int n = 7;

  cout << (isSorted(arr, n) ? "True" : "False") << endl;
}

// Remove Duplicate from an array

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(int arr[], int n) {
  int i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[i] != arr[j]) {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}

int main() {
  int arr[] = {1, 1, 2, 2, 2, 3, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = removeDuplicates(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}

// Left Rotate the Array by One

#include <bits/stdc++.h>
using namespace std;

void Lefty(int arr[], int n) {
  int temp = arr[0];
  for (int i = 0; i < n - 1; i++) {
    arr[i] = arr[i + 1];
  }
  arr[n - 1] = temp;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  Lefty(arr, n);
  return 0;
}

// Left Rotate by K places

#include <bits/stdc++.h>
using namespace std;

void Reverse(int arr[], int start, int end) {
  while (start <= end) {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    start++;
    end--;
  }
}

void Rotate(int arr[], int n, int k) {

  Reverse(arr, 0, k - 1);
  Reverse(arr, k, n - 1);
  Reverse(arr, 0, n - 1);
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int n = 7;
  int k = 2;
  Rotate(arr, n, k);
  cout << " After rotating it by 2 elements :" << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}

// Move all Zeros to the end of the array

#include <bits/stdc++.h>
using namespace std;

vector<int> moveZeros(int n, vector<int> a) {
  int j = -1;
  // place the pointer j:
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      j = i;
      break;
    }
  }

  // no non-zero elements:
  if (j == -1)
    return a;

  // Move the pointers i and j
  // and swap accordingly:
  for (int i = j + 1; i < n; i++) {
    if (a[i] != 0) {
      swap(a[i], a[j]);
      j++;
    }
  }
  return a;
}

int main() {
  vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
  int n = 10;
  vector<int> ans = moveZeros(n, arr);
  for (auto &it : ans) {
    cout << it << " ";
  }
  cout << '\n';
  return 0;
}

// Linear Search

#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int num) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == num) {
      return i;
    }
  }
  return -1; // Element not found
}

int main() {
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int num = 4;
  int n = sizeof(arr) / sizeof(arr[0]);
  int val = search(arr, n, num);
  cout << "The element is found at index :" << val << endl;
}

//  Union of Two Arrays

#include <bits/stdc++.h>
using namespace std;

vector<int> FindUnion(int arr1[], int arr2[], int n, int m) {
  int i = 0, j = 0;  // pointers
  vector<int> Union; // Uninon vector
  while (i < n && j < m) {
    if (arr1[i] <= arr2[j]) // Case 1 and 2
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
    } else // case 3
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    }
  }
  while (i < n) // IF any element left in arr1
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m) // If any elements left in arr2
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
  return Union;
}

int main()

{
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12};
  vector<int> Union = FindUnion(arr1, arr2, n, m);
  cout << "Union of arr1 and arr2 is  " << endl;
  for (auto &val : Union)
    cout << val << " ";
  return 0;
}


#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>&a, int N) {

    //Summation of first N numbers:
    int sum = (N * (N + 1)) / 2;

    //Summation of all array elements:
    int s2 = 0;
    for (int i = 0; i < N - 1; i++) {
        s2 += a[i];
    }

    int missingNum = sum - s2;
    return missingNum;
}

int main()
{
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}

// Miissing Number in an array

// (Brute Force Approach)
#include <bits/stdc++.h>
using namespace std;

int MissingNum(int arr[], int n){
  for(int i=1; i<n; i++){
    int flag = 0;

    for(int j = 0; j < n-1; j++){
      if(arr[j] == i)
      {
        flag = 1;
        break;
      }
    }
    if(flag == 0)
    return i;
  }
  return -1;
}

int main() {
  int n = 8;
  int arr[] ={1, 2, 4, 5, 6, 7, 8};
  int ans = MissingNum(arr, n);
  cout <<" The missing element in the array is " << ans << endl;
  return 0;
}


// (Optimal Approach)
#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>&a, int N) {

    //Summation of first N numbers:
    int sum = (N * (N + 1)) / 2;

    //Summation of all array elements:
    int s2 = 0;
    for (int i = 0; i < N - 1; i++) {
        s2 += a[i];
    }

    int missingNum = sum - s2;
    return missingNum;
}

int main()
{
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}

// Maximum Consecutive 1's

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMaxConsecutiveOnes(vector < int > & nums) {
      int cnt = 0;
      int maxi = 0;
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
          cnt++;
        } else {
          cnt = 0;
        }

        maxi = max(maxi, cnt);
      }
      return maxi;  
    }
};

int main() {
  vector < int > nums = { 1, 1, 0, 1, 1, 1 };
  Solution obj;
  int ans = obj.findMaxConsecutiveOnes(nums);
  cout << "The maximum  consecutive 1's are " << ans;
  return 0;
}


