#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> ranks,int target, int prata){
    int time = 0;                               // time taken by ith cook
    int cookedPrata = 0;                              // already cooked pratas
    for(int i = 0; i<ranks.size(); i++){
        for(int j = 1; (time + j*ranks[i]) <= target; j++){         // if time taken to cook j pratas by ith cook is less than target time then the prata will be cooked 
            cookedPrata++;                                          // incrementing cooked pratas
            if(cookedPrata == prata){                               // if required no. of pratas cooked, return true
                return true;
            }
            time += j*ranks[i];
        }
        time = 0;                                                   // setting time = 0 for calculation of time for next cook
    }
    return false;                                                   // less pratas cooked so more time needed 
}

// Function to perform binary search
// ranks -> array containing ranks of cooks
// prata -> no. of pratas ordered 

int minTime(vector<int> ranks, int prata){
    int ans = -1;
    int s = 0;
    int max = -1;
    for(int i=0; i<ranks.size(); i++){
        if(ranks[i] > max){
            max = ranks[i];
        }
    }
    int e = max * (prata*(prata+1))/2;      // Time taken by the cook with maxm rank to cook all the pratas

    while(s<=e){
        int mid = s + (e-s)/2;

        if(isPossible(ranks, mid, prata)){
            ans = mid;
            e = mid - 1;                    // searching for a lesser time
        }
        else{
            s = mid + 1;                    // all pratas couldn't be cooked at mid
                                            // so search for a greater time
        }
    }
    return ans;
}

int main(){
	int n;
	cin>> n;
	
	for(int i = 0; i<n; i++){
		int p, l;
		cin>> p;
		cin>> l;
		vector<int> ranks(l);
		for(int j = 0; j<l; j++){
			cin >> ranks[j];
		}
		cout << minTime(ranks, p) << endl;
	}
}