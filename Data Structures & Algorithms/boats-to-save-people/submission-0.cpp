/*
    1) the first thing is sort the given array like [1,2,2,3] and [3,3,4,5]
    2) now create two pointer indexes l=0 and r=n-1.
    3) if sum=people[l]+people[r] <= limit, then we will make it done and count++,
    increment(l++) and decrement(r--) and count++.
    4) if the sum > limit, then it means the people[r] is too big
    5) this means nums[r] will go alone so , count++ here
    examples:
    [1,2,2,3]: l=0 and r=3, limit=3
    step 1: sum= 1 + 3. bigger than limit. r-- and count++
    step 2: sum= 1 + 2. sum ==limit. r-- , l++ and count++
    one edge case : if l==r => just count++ , l++ and r--(loop ends)
*/


class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort(p.begin(),p.end());
        int l=0,r=p.size()-1;
        int count = 0;
        while(l<=r){
            if(p[l] + p[r] <= limit) l++;
            r--;
            count++;
        }
        return count;
    }
};