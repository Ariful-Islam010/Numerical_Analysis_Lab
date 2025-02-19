#include <bits/stdc++.h>
using namespace std;

// Function definition: f(x) = 3x - cos(x) + 1
double f(double x) {
    return 3 * x - cos(x) - 1;
}

// False Position Method with Error Calculation
void falsePosition(double xl, double xu, int iterations) {
    double xr = xl, xr_old, fxr, error = 0;

    cout << fixed << setprecision(6);
    cout << "Iter     xl            xu            xr            f(xr)         Error" << endl;
    cout << "-------------------------------------------------------------------------" << endl;

    for (int i = 1; i <= iterations; i++) {
        xr_old = xr;
        xr = (xl * f(xu) - xu * f(xl)) / (f(xu) - f(xl));
        fxr = f(xr);

        if (i > 1) {
            error = fabs((xr - xr_old) / xr) * 100;  // Calculate percentage error
        }

        cout << left << setw(8) << i
             << setw(14) << xl
             << setw(14) << xu
             << setw(14) << xr
             << setw(14) << fxr
             << error << "%" << endl;

        if (fxr == 0.0) {
            break;
        } else if (f(xl) * fxr < 0) {
            xu = xr;
        } else {
            xl = xr;
        }
    }
    cout << "\nApproximate Root after " << iterations << " iterations: " << xr << endl;
}

// Main function
int main() {
    double xl, xu;
    int iterations;

    // Input interval and iterations
    cout << "Enter lower bound (xl): ";
    cin >> xl;
    cout << "Enter upper bound (xu): ";
    cin >> xu;
    cout << "Enter number of iterations: ";
    cin >> iterations;

    // Perform False Position Method
    falsePosition(xl, xu, iterations);

    return 0;
}
