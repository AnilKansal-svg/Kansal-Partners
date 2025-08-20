// Reverse an array

#include <bits/stdc++.h>
using namespace std;

voidf(int i, int arr[], int n) {
    if(i >= n/2) return;
    swap(arr[i], arr[n-i-1]);
    f(i+1, arr, n);
}

int main() {
    int n;
    cin>>n;
    int arr[];
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    f(0, arr, n);
    for(int i=0; i<n; i++) {
        cout<< arr[i] << " ";
    }
    return 0;
}

//Pallindrome 

#include <bits/stdc++.h>
using namespace std;

bool f(int i, string &s) {
    if(i >= s.size()/2) return true;
    if(s[i] != s[s.size() - i - 1]) return false;
    return f(i+1, s);
}

int main() {
    string s = "Madam";
    cout << f(0, s);
    return 0;
}


// Fibonaci Series

#include<bits/stdc++.h>
using namespace std;

void f(int n) {
    if(n <=1) {
        int last = f(n-1);
        int seclast = f(n-2);
        return last + seclast;
    }
}

int main() {
    int n;
    cin >>n;
    cout <<f(n);
    return 0;
}

// Selection Sort 
#include <iostream>
using namespace std;

void selection_sort(int arr[], int n) {
    for(int i=0; i<=n-2; i++) {
        int mini =i;
        for(int j = i; j<=n-1; j++) {
            if(arr[j]<arr[mini]) {
                mini =j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i]; 
        arr[i] = temp;
    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>> arr[i];
    }
    selection_sort(arr, n);
    for(int i=0; i<n; i++) {
        cout<< arr[i] << " ";
    }
}

#include <iostream>
using namespace std;

void selection_sort(int arr[], int n){
    for(int i=0; i<n-2; i++) {
        int mini = 0;
        for(int j=0; j<n-1;j++){
            if(arr[j]<arr[mini]){
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
    cin >>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    selection_sort(arr, n);
    for(int i=0; i<n; i++) {
        cout <<arr[i]<<" ";
    }
}







