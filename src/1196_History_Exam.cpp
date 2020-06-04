#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Timus didn't make a decision with a TL error,
// so I had to write a quick search function
bool bin_search(long int* a, long int k, int low , int high)
{
	while(low <= high) {
		int middle = low + (high - low) / 2;
    if (k == a[middle]) return true;
    else if (k < a[middle]) high = middle - 1;
    else low = middle + 1;
	}
	return false;
}

int main() {
	int n;
	std::cin >> n;
	long int* mYears = new long int[n];
	int prevYear{-1};
	int nCount{0};
	for (int i = 0; i < n; ++i) {
		long nYear;
		scanf("%ld", &nYear);
		if (prevYear != nYear) {
			mYears[nCount++] = nYear;
			prevYear = nYear;
		}
	}
	
	int m;
	std::cin >> m;
	int counter{0};
	for (int i = 0; i < m; ++i) {
		long int nYear;
		scanf("%ld", &nYear);
		if ( nYear >= mYears[0] && nYear <= mYears[nCount - 1] 
      && bin_search(mYears, nYear, 0, nCount) 
    ) {
			counter++;
		}
	}
	
	printf("%d", counter);
	
	delete [] mYears;

	return 0;
}
