#include <bits/stdc++.h>
using namespace std;

// Function to find a triplet with a given sum in an array
bool find3Numbers(int A[], int arr_size, int sum)
{
	// Fix the first element as A[i]
	for (int i = 0; i < arr_size - 2; i++) {

		// Create a set to store potential second elements
		// that complement the desired sum
		unordered_set<int> s;

		// Calculate the current sum needed to reach the
		// target sum
		int curr_sum = sum - A[i];

		// Iterate through the subarray A[i+1..n-1] to find
		// a pair with the required sum
		for (int j = i + 1; j < arr_size; j++) {

			// Calculate the required value for the second
			// element
			int required_value = curr_sum - A[j];

			// Check if the required value is present in the
			// set
			if (s.find(required_value) != s.end()) {

				// Triplet is found; print the triplet
				// elements
				printf("Triplet is %d, %d, %d", A[i], A[j],
					required_value);
				return true;
			}

			// Add the current element to the set for future
			// complement checks
			s.insert(A[j]);
		}
	}

	// If no triplet is found, return false
	return false;
}

/* Driver program to test above function */
int main()
{
	int A[] = { 1, 4, 45, 6, 10, 8 };
	int sum = 22;
	int arr_size = sizeof(A) / sizeof(A[0]);

	// Call the find3Numbers function to find and print the
	// triplet, if it exists
	find3Numbers(A, arr_size, sum);

	return 0;
}
