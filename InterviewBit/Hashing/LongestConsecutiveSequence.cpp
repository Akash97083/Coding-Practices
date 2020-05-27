/*
Given an unsorted integer array A of size N.

Find the length of the longest set of consecutive elements from the array A.



Problem Constraints

1 <= N <= 106

-106 <= A[i] <= 106



Input Format

First argument is an integer array A of size N.


Output Format

Return an integer denoting the length of the longest set of consecutive elements from the array A.


Example Input

Input 1:

A = [100, 4, 200, 1, 3, 2]

Input 2:

A = [2, 1]



Example Output

Output 1:

 4

Output 2:

 2



Example Explanation

Explanation 1:

 The set of consecutive elements will be [1, 2, 3, 4].

Explanation 2:

 The set of consecutive elements will be [1, 2].

*/

int Solution::longestConsecutive(const vector<int> &A) {
    
    unordered_map<int,int> hashTable;
    int countLength = INT_MIN;
    int tempLength = 0;
    
    for(int itr = 0; itr < A.size(); itr++)
    {
        hashTable[A[itr]] = 1;
    }
    
    for(int itr = 0; itr < A.size(); itr++)
    {
        tempLength = 0;
        int items = A[itr];
        while(hashTable[items] == 1)
        {
            hashTable[items] = 0;
            items--;
            tempLength++;
        }
        items = A[itr]+1;
        while(hashTable[items] == 1)
        {
            hashTable[items] = 0;
            items++;
            tempLength++;
        }
        countLength = max(countLength, tempLength);
    }
    return countLength;
}
