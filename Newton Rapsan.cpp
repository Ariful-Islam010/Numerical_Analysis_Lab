#include <bits/stdc++.h>
using namespace std;

// Function f(x) = 3x - cos(x) - 1
double f(double x)
{
    return 3 * x - cos(x) - 1;
}

// Derivative f'(x) = 3 + sin(x)
double f_prime(double x)
{
    return 3 + sin(x);
}

// Newton-Raphson Method
void Newton_Raphson(double Xo, int max_iterations, double stopErrorPercent, bool useError)
{
    double Xr_old = Xo, Xr_new, approx_error = 100.0;

    cout << fixed << setprecision(6);
    cout << "Step\t\tXi\t\t\tApprox. Error (%)" << endl;

    for (int step = 1; step <= max_iterations; step++)
    {
        if (f_prime(Xr_old) == 0)
        {
            cout << "Derivative is zero. Cannot proceed (division by zero)." << endl;
            return;
        }

        Xr_new = Xr_old - f(Xr_old) / f_prime(Xr_old);

        cout << step << "\t\t" << Xr_new << "\t\t";

        if (step == 1)
        {
            cout << "-" << endl;
        }
        else
        {
            approx_error = fabs((Xr_new - Xr_old) / Xr_new) * 100;
            cout << approx_error << endl;

            if (useError && approx_error < stopErrorPercent)
            {
                break;
            }
        }

        Xr_old = Xr_new;
    }

    cout << "\nThe estimated root is: " << Xr_new << endl;
}

int main()
{
    double Xo;
    int choice;

    cout << "Enter initial guess Xo: ";
    cin >> Xo;

    cout << "\nChoose an option:\n";
    cout << "1. Fixed number of iterations\n";
    cout << "2. Stop when Approximate Error is small enough\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1)
    {
        int iterations;
        cout << "Enter number of iterations: ";
        cin >> iterations;
        Newton_Raphson(Xo, iterations, 0.0, false);
    }
    else if (choice == 2)
    {
        double errorTolerance;
        cout << "Enter maximum approximate error (in %, e.g., 0.01): ";
        cin >> errorTolerance;
        Newton_Raphson(Xo, 1000, errorTolerance, true); // Max 1000 steps
    }
    else
    {
        cout << "Invalid choice! Please enter 1 or 2." << endl;
    }

    return 0;
}
