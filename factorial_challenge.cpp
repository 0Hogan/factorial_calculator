// Factorial Challenge
// Michael J. Hogan

/* Given a number, finds the number of trailing zeroes of the factorial of the inputted number. */

#include <iostream>

int trailingZeroes(int arr[]);
int* factorial(int input);
void printMirroredArray(int arr[]);

int n = 20;
int digits = 0;

int main() {
	int input;
	std::cout << "Input an integer: ";
	std::cin >> input;
	std::cout << input << "! = ";
	int* result;
	result = factorial(input);
	printMirroredArray(result);
	std::cout << "Number of trailing zeroes: " << trailingZeroes(result) << std::endl;
	std::cout << "Total Number of digits: " << digits << std::endl;
}

int trailingZeroes(int arr[]) {
	int i = 0;
	while(arr[i] == 0) 
		i++;
	return i;
}

int* factorial(int input) {
	int* pa;
	pa = new int[n];

	// Initializes first element of array to 1, and all other elements to 0.
	pa[0] = 1;
	for(int i = 1; i < n; i++) {
		pa[i] = 0;
	}
	int temp = 0;
	int* ptemp;
	for(int i = 1; i <= input; i++) {
		// Loops through, multiplying each digit in the array by i, and adding the carry.
		for(int k = 0; k < n; k++) {
			pa[k] *= i;
			pa[k] += temp;
			temp = 0;
			if(pa[k] > 9) {
				temp = pa[k] / 10;
				pa[k] = pa[k] % 10;
			}
			if(pa[n - 2] > 0) {
				n *= 2;
				ptemp = new int[n];
				for(int j = 0; j < n; j++) {
					if(j < n/2)
						ptemp[j] = pa[j];
					else
						ptemp[j] = 0;
				}
				delete pa;
				pa = ptemp;
			}

		}
	}
	return pa;
}

void printMirroredArray(int arr[]) {
	int j = 0;

	for (int i = 0; i < n; i++)
		if(arr[i] != 0)
			j = i;

	while(j >= 0) {
		std::cout << arr[j];
		digits++;
		j--;
	}
	std::cout << std::endl;
}