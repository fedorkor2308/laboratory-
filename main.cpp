#include <iostream>
#include <limits>
#include <cmath>

using namespace std; // abc

double getValidInput(const string &prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Input a number." << endl;
        } else {
            return value;
        }
    }
}

int getValidInteger(const string &prompt) {
    double value;
    while (true) {
        value = getValidInput(prompt);
        if (value == static_cast<int>(value)) {
            return static_cast<int>(value);
        } else {
            cout << "Invalid input. Please input an integer." << endl;
        }
    }
}

void swapIfNeeded(double &a, double &b) {
    if (a > b) {
        swap(a, b);
    }
}

int main() {
    int n;
    while (true) {
        n = getValidInteger("Enter n (n >= 0): ");
        if (n >= 0) {
            break;
        } else {
            cout << "n must be greater than or equal to 0." << endl;
        }
    }

    double left = getValidInput("Enter start of range: ");
    double right = getValidInput("Enter end of range: ");
    swapIfNeeded(left, right);

    double step;
    while (true) {
        step = getValidInput("Enter step: ");
        if (step > 0 && step <= abs(right - left)) {
            break;
        } else {
            cout << "Step must be positive and not greater than the range length." << endl;
        }
    }

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
