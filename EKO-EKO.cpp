#include <bits/stdc++.h>
using namespace std;

// Function to check 
// if the height is short enough
// to get the required amount of wood

bool isPossible(vector<long long int> heights, long long int target_height, long long int m){
    int woodLength = 0;
    for(int i = 0; i<heights.size(); i++){
        if(heights[i] > target_height){
            woodLength += (heights[i] - target_height);
        }
        if(woodLength >= m){
            return true;
        }
    }
    return false;
}

//Function to apply binary search
// height -> array containing heights of the trees
// m -> metres of wood needed to be chopped off
// long long int selected due to requirement of question

long long int maxHeight(vector<long long int> heights, long long int m){
    int ans = -1;

    int s = 0;
    
    int max = -1;
    // Finding maximum value in array heights
    for(int i = 0; i<heights.size(); i++){
        if(heights[i] > max){
            max = heights[i];
        }
    }

    int e = max;                          // setting the end of search space to be maxm tree height

    while(s<=e){
        int mid = s + (e-s)/2;
        if(isPossible(heights, mid, m)){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return ans;
}