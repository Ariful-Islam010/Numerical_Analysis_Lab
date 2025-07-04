#include <bits/stdc++.h>
using namespace std;

// Function definition: f(x) = 3x - cos(x) - 1
double f(double x) {
    return 3 * x - cos(x) - 1;
}

// False Position Method
void falsePosition(double xl, double xu, int maxIterations, double stopError, bool useError) {
    double xr = xl, xr_old, fxr, error = 100;

    cout << fixed << setprecision(6);
    cout << "Iter     xl            xu            xr            f(xr)         Error(%)" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    for (int i = 1; i <= maxIterations; ++i) {
        xr_old = xr;
        xr = (xl * f(xu) - xu * f(xl)) / (f(xu) - f(xl));
        fxr = f(xr);

        if (i > 1) {
            error = fabs((xr - xr_old) / xr) * 100;
        }

        cout << left << setw(8) << i
             << setw(14) << xl
             << setw(14) << xu
             << setw(14) << xr
             << setw(14) << fxr;

        if (i == 1)
            cout << "-";
        else
            cout << error;

        cout << endl;

        if (fxr == 0.0)
            break;
        else if (f(xl) * fxr < 0)
            xu = xr;
        else
            xl = xr;

        if (useError && i > 1 && error < stopError)
            break;
    }

    cout << "\nApproximate Root: " << xr << endl;
}

// Main function
int main() {
    double xl, xu;
    int choice;

    // Ensure valid xl and xu
    while (true) {
        cout << "Enter lower bound (xl): ";
        cin >> xl;
        cout << "Enter upper bound (xu): ";
        cin >> xu;

        if (f(xl) * f(xu) < 0)
            break;
        else
            cout << "Invalid interval! f(xl) and f(xu) must have opposite signs.\n\n";
    }

    cout << "\nChoose an option:\n";
    cout << "1. Fixed number of iterations\n";
    cout << "2. Stop when Approximate Error is small enough\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int iterations;
            cout << "Enter number of iterations: ";
            cin >> iterations;
            falsePosition(xl, xu, iterations, 0.0, false);
            break;
        }
        case 2: {
            double stopError;
            cout << "Enter maximum approximate error (in %): ";
            cin >> stopError;
            falsePosition(xl, xu, 1000, stopError, true);  // max 1000 iterations
            break;
        }
        default:
            cout << "Invalid choice! Please enter 1 or 2.\n";
    }

    return 0;
}
