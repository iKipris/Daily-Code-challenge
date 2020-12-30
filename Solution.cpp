#include <iostream>
#include <vector>
using namespace std;
 
// Function to print the contents of the vector
void printVector(vector<int> const &out)
{
    for (auto it = out.begin(); it != out.end(); it++)
        cout << *it << " ";
    cout << '\n';
}
 
// Function to print all distinct combinations of length k where
// repetition of elements is allowed
void recur(int arr[], vector<int> &out, int k, int i, int n)
{
    // base case: if combination size is k, print it
    if (out.size() == k)
    {
        printVector(out);
        return;
    }
 
    // start from previous element in the current combination
    // till last element
    for (int j = i; j < n; j++)
    {
        // add current element arr[j] to the solution and recur with
        // same index j (as repeated elements are allowed in combinations)
        out.push_back(arr[j]);
        recur(arr, out, k, j, n);
 
        // backtrack - remove current element from solution
        out.pop_back();
    }
}
 
int main()
{
    int arr[] = { 1, 2, 1 };
    int k = 2;
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
    vector<int> out;
    recur(arr, out, k, 0, n);
 
    return 0;
}




