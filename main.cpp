#include <iostream>
#include <limits>
#include <cmath>

using namespace std;
double getValidInput(const string &prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Input a number" << endl;
        } else {
            return value;
        }
    }
}
void swapIfNeeded(double &a, double &b) {
    if (a > b) {
        swap(a, b); 
    }
}

int main() {
    double n = getValidInput("Enter n (n > -1): ");
    while (n <= -1) {
        cout << "n must be bigger than -1." << endl;
        n = getValidInput("Enter n (n > -1): ");
    }

    double step = getValidInput("Enter step: ");
    double left = getValidInput("Enter start: ");
    double right = getValidInput("Enter the end: ");
    while (step > abs(right - left)) {
        cout << "Step can't be bigger than length of interval" << endl;
        step = getValidInput("Enter step: ");
    }
    swapIfNeeded(left, right);
    for (double x = left; x <= right; x += step) {
        double result = 0;

        if (x < -4) {
            int j = -1;
            double mlt = 1;

            while (j <= 3) {
                mlt *= (j + 2) * x;
                j++;
            }

            int i = 3;
            double sum = 0;

            while (i <= n) {
                sum += (12 * i + 1.0 / x);
                i++;
            }

            result = mlt + 3 * sum;
        } else {
            int i = 0;
            double sum = 0;

            while (i <= n + 1) {
                int j = 1;
                double mlt = 1;

                while (j <= n - 3) {
                    mlt *= (i + j + 1) / pow(j, 2);
                    j++;
                }

                sum += mlt;
                i++;
            }

            result = sum;
        }

        cout << "For x = " << x << ", Result = " << result << endl;
    }

    return 0;
}
