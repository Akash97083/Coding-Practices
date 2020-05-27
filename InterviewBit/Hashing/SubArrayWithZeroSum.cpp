/**
 *Given an array of integers A, find and return whether the given array contains a non-empty subarray with a sum equal to 0.

If the given array contains a sub-array with sum zero return 1 else return 0.



Problem Constraints

1 <= |A| <= 100000

-10^9 <= A[i] <= 10^9



Input Format

The only argument given is the integer array A.


Output Format

Return whether the given array contains a subarray with a sum equal to 0.


Example Input

Input 1:

 A = [1, 2, 3, 4, 5]

Input 2:

 A = [-1, 1]



Example Output

Output 1:

 0

Output 2:

 1



Example Explanation

Explanation 1:

 No subarray has sum 0.

Explanation 2:

 The array has sum 0.

 */
 
 int Solution::solve(vector<int> &A) {
    
    unordered_map<long long,bool> hashTable;
    
    long long tempSum = 0;
    
    hashTable[0] = 1;
    hashTable[A[0]] = 1;
    tempSum = A[0];
    
    for(int itr = 1; itr < A.size(); itr++)
    {
        tempSum = tempSum + A[itr];
        if(hashTable[tempSum] == true) return 1;
        
        hashTable[tempSum] = true;
    }
    
    return 0;
}
