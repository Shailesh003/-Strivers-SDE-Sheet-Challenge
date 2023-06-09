#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{   //sort the array
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> ans;
    for(int i=0;i<intervals.size();i++){
        if(ans.empty()|| ans.back()[1]<intervals[i][0]){
          ans.push_back({intervals[i][0], intervals[i][1]});
        }
        else{
            ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        }        
    }
    return ans;
}
