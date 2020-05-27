/*
Shaggy has an array A consisting of N elements. We call a pair of distinct indices in that array as a special pair if elements at that index in the array are equal.

Shaggy wants you to find a special pair such that distance between that pair is minimum. Distance between two indices is defined as |i-j|. If there is no special pair in the array then return -1.



Problem Constraints

1 <= |A| <= 105


Input Format

First and only argument is the array A.


Output Format

Return one integer corresponding to the minimum possible distance between a special pair.


Example Input

Input 1:

A = [7, 1, 3, 4, 1, 7]

Input 2:

A = [1, 1]



Example Output

Output 1:

 3

Output 2:

 1

*/

int Solution::solve(vector<int> &A) {
    
    unordered_map<int,int> hashTable;
    
    int minDistance = INT_MAX;
    
    for(int itr = 0; itr < A.size(); itr++)
    {
        minDistance = (hashTable[A[itr]] != 0) ? min(minDistance,abs(itr+1 - hashTable[A[itr]])) : minDistance;
        hashTable[A[itr]] = itr+1;
    }
    
    if(minDistance == INT_MAX) minDistance = -1; //not found
    
    return minDistance;
}
