#include <iostream>
using namespace std;

bool areDigitsSame(int number) {
    int digit = number % 10;
    while (number > 0) {
        if (number % 10 != digit) {
            return false;
        }
        number /= 10;
    }
    return true;
}

void sorting(int arr[], int size) {
      for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
  
int kaprekar(int number) {
    int digits[4];
    for (int i = 3; i >= 0; --i) {
        digits[i] = number % 10;
        number /= 10;
    }

    sorting(digits, 4);

    int ascendingValue = 1000 * digits[0] + 100 * digits[1] + 10 * digits[2] + digits[3];

    sorting(digits, 4);
    
    int descendingValue = 1000 * digits[3] + 100 * digits[2] + 10 * digits[1] + digits[0];

    return descendingValue - ascendingValue;
}

int main() {
    int number;
    cout << "Enter a 4-digit number: ";
    cin >> number;

    if (areDigitsSame(number)) {
        cout << "Invalid input. Please enter a 4-digit number with distinct digits." << endl;
        return 1;
    }
    
    if (number < 1000 || number > 9999) {
        cout << "Invalid input. Please enter a 4-digit number." <<endl;
        return 1;
    }
    int maxIterations = 0;

    while (number != 6174 && maxIterations < 7) {
        number = kaprekar(number);
        cout << number << endl;
        maxIterations++;
    }

    return 0;
}

