#include <bits/stdc++.h>
using namespace std;

//Function to check for the possible pages
// n = number of books (array size)
// m = number of students

bool isPossible(vector<int> books, int pages, int n, int m){
    int sumPages = 0;
    int students = 1;
    for(int i = 0; i<n; i++){
        if((sumPages + books[i]) <= pages){
            sumPages += books[i];
        }
        else{
            sumPages = books[i];
            students++;
            if(students > m){
                return false;
            }
        }
    }
    return true;
}

int findMax(vector<int> arr, int n){
    int max = -1;
    for(int i=0; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int findSum(vector<int> arr, int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    return sum;
}

//Function in which binary search is done
// n = number of books (array size)
// m = number of students

int minPages(vector<int> books, int n, int m){
    int ans = -1;
    int s = findMax(books, n);
    int e = findSum(books, n);

    while(s<=e){
        int mid = s + (e-s)/2;
        if(isPossible(books, mid, n, m)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}