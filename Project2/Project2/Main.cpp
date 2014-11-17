#include <iostream>
#include <time.h>

using namespace std;

template <typename R, typename A, typename B>
R max(A in_A, B in_B) {
	if (in_A == in_B || in_A > in_B ) {
		return in_A;
	} else {
		return in_B;
	}
}

char* max(char* in_a, char* in_b) {
	int aLen = 0;
	for (int i = 0; in_a[i] != NULL; i++) {
		aLen++;
	}

	int bLen = 0;
	for (int i = 0; in_b[i] != NULL; i++) {
		bLen++;
	}

	if (aLen == max<int>(aLen, bLen)) {
		return in_a;
	} else {
		return in_b;
	}
}

template <typename R, typename A, typename B>
R min(A in_A, B in_B) {
	if (in_A == in_B || in_A < in_B) {
		return in_A;
	}
	else {
		return in_B;
	}
}

template <typename R, typename A, typename B, typename C>
R clamp(A in_min, B in_max, C in_clamp) {
	if (in_clamp < in_min) {
		return in_min;
	} else if (in_clamp > in_max) {
		return in_max;
	} else {
		return in_clamp;
	}
}

template <typename T>
T abs(T input) {
	if (input < 0) {
		return input;
	} else {
		return input * -1;
	}
}

template <typename T>
T lerp(T in_start, T in_end, float in_interpolate) {
	T temp = in_end - in_start;
	if (temp < 0) {
		return -1;
	}

	temp *= in_interpolate;
	temp += in_start;

	return temp;
}

template <typename T>
void bubbleSort(T arr[], T n) {
      bool swapped = true;
      int j = 0;
      int tmp;
      while (swapped) {
            swapped = false;
            j++;
            for (int i = 0; i < n - j; i++) {
                  if (arr[i] > arr[i + 1]) {
                        tmp = arr[i];
                        arr[i] = arr[i + 1];
                        arr[i + 1] = tmp;
                        swapped = true;
                  }
            }
      }
}

void main() {
	srand(time(NULL));

	char out[20];
	for (int i = 0; i < 20; i++) {
		out[i] = rand() % 26 + 97;
	}

	cout << "[";
	for (int i = 0; i < 19; i++) {
		cout << out[i] << ", ";
	}
	cout << out[19] << "]" << endl;

	bubbleSort<char>(out, 20);

	cout << "[";
	for (int i = 0; i < 19; i++) {
		cout << out[i] << ", ";
	}
	cout << out[19] << "]" << endl;

	system("pause");
}