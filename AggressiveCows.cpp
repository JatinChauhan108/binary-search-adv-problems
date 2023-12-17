#include <bits/stdc++.h>
using namespace std;

//Function to check if a given distance is possible with the required no.
// of stalls and cows

bool isPossible(vector<int> stalls, int dist, int cows){
	int cowCount = 1;
	int lastpos = stalls[0];						//storing the position of last placed cow
													//assuming the first cow to be placed at first stall
	for(int i = 0; i<stalls.size(); i++){
		if((stalls[i] - lastpos) >= dist){
			cowCount ++;							// placing the next cow
			if(cowCount == cows){
				return true;						// all cows placed
			}
			lastpos = stalls[i];					// updating the last position to recently placed cow
		}
	}
	return false;									// distance was too big for all cows to be placed
}

//Function to apply binary search
// k = no. of cows
// stalls -> contains the position of stall

int minDist(vector<int> stalls, int k){
	int ans = -1;
	sort(stalls.begin(), stalls.end());
	int s = 0;								  // search space starts with 0
	int e = stalls[(stalls.size()) - 1];		  // search space ends with the maxm distance

	while(s<=e){
		int mid = s = (e-s)/2;

		if(isPossible(stalls, mid, k)){		// if the value of distance is possible
			ans = mid;						// storing the possible answer
			s = mid + 1;					// and checking for greater distances
		}
		else{
			e = mid - 1;					// go to smaller distances as distances >= mid are not possible
		}

	}
	return ans;
}