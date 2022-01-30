#include <iostream>

using namespace std;

// Function Prototypes
void bubbleSort(int[], int);
void swap(int&, int&);
int modeFinder(int[], int);
int modeFinder(int[], int);

int main(){
	bool programOn = true; // Keeps do-while loop running
	do {
		// Program explanation
		cout << "This program allows the user to input a set of up\n";
		cout << "to 20 integer values, which are stored in an array.\n";
		cout << "It then calculates the mode of the set of values \n";
		cout << "which is the value that occurs most often or\n";
		cout << "with the greatest frequency.\n\n";

		// Asks user how many values they want to store
		cout << "How many values do you want to store?\n";
		cout << "The number should be between 1 and 20: ";
		int numElements;
		cin >> numElements;

		// Creates array to store elements
		int* numArray = new int[numElements]; // Allocate Heap memory
		for (int i = 0; i < numElements; i++) {
			cout << "Enter number " << i + 1 << ": ";
			cin >> numArray[i];
		}

		// Outputs the user's input
		cout << "The values you entered are: ";
		for (int i = 0; i < numElements; i++) {
			cout << numArray[i] << " ";
		}

		// Sorts the array
		bubbleSort(numArray, numElements);
		cout << "\nThe values in numerical order are: ";
		for (int i = 0; i < numElements; i++) {
			cout << numArray[i] << " ";
		}

		// Calls modeFinder function to find the mode
		int mode = modeFinder(numArray, numElements);
		cout << "\nThe mode is: " << mode;

		delete[] numArray; // Deallocate Heap memory

		// Asks user if they want to run the program again
		char playAgain = 'B';
		while (playAgain != 'y' && playAgain != 'n') { // while loop ask if players want to play again
			cout << "\nWould you like to run the program again? (y/n) ";
			cin >> playAgain;
			playAgain = tolower(playAgain);
			if (playAgain != 'y' && playAgain != 'n') {
				cout << "Invalid Response!\n";
			}
		}
		if (playAgain == 'n') {
			programOn = false;
		}
		system("cls");
	} while (programOn == true);
}


// Bubble sorts the user's array
void bubbleSort(int numArray[], int numElements) {
	int maxElement;
	int index;

	for (maxElement = numElements - 1; maxElement > 0; maxElement--) {
		for (index = 0; index < maxElement; index++) {
			if (numArray[index] > numArray[index + 1]) {
				swap(numArray[index], numArray[index + 1]);
			}
		}
	}

}

// Swap function to move elements in the array
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

// modeFinder function to find mode of inputted array
int modeFinder(int numArray[], int numElements) {
	int mode = -1;
	int maxCount = 0;
	int tempCount = 0;

	// Nested for loop that counts the instances of each element
	for (int i = 0; i < numElements; i++) {
		for (int j = 0; j < numElements; j++) {
			if (numArray[i] == numArray[j]) {
				tempCount++;
			}
			if (maxCount < tempCount) {
				maxCount = tempCount;
				mode = numArray[i];
			}
		}
		tempCount = 0;
	}

	if (maxCount == 1) {
		return -1; // Returns -1 if no mode exists
	}
	else {
		return mode; // Returns mode value if exists
	}
}