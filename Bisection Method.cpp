#include <bits/stdc++.h>
using namespace std;

// Function definition: f(x) = 3x - cos(x) + 1
double f(double x)
{
    return 3 * x - cos(x) - 1;
}

// Bisection Method with Absolute Error Calculation
void bisection(double xl, double xu, int iterations)
{
    double xr_old, fxr, error = 0;
    double xr = (xl + xu) / 2;

    cout << fixed << setprecision(6);
    cout << "Iter     xl            xu            xr            f(xr)         Error" << endl;
    cout << "-------------------------------------------------------------------------" << endl;

    for (int i = 1; i <= iterations; i++)
    {
        xr_old = xr;
        xr = (xl + xu) / 2;
        fxr = f(xr);

        if (i > 1)
        {
            error = fabs(xr - xr_old);  // Absolute error
        }

        cout << left << setw(8) << i
             << setw(14) << xl
             << setw(14) << xu
             << setw(14) << xr
             << setw(14) << fxr
             << error << endl;

        if (fxr == 0.0)
        {
            break;
        }
        else if (f(xl) * fxr < 0)
        {
            xu = xr;
        }
        else
        {
            xl = xr;
        }
    }
    cout << "\nApproximate Root after " << iterations << " iterations: " << xr << endl;
}

// Main function
int main()
{
    double xl, xu;
    int iterations;

    // Input interval and iterations
    cout << "Enter lower bound (xl): ";
    cin >> xl;
    cout << "Enter upper bound (xu): ";
    cin >> xu;
    cout << "Enter number of iterations: ";
    cin >> iterations;

    // Perform Bisection Method
    bisection(xl, xu, iterations);

    return 0;
}
