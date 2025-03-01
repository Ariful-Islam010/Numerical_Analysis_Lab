#include <iostream>
#include <cmath>

using namespace std;

// Function f(x) = 3x - cos(x) - 1
double f(double x) {
    return 3 * x - cos(x) - 1;
}

// Derivative f'(x) = 3 + sin(x)
double f_prime(double x) {
    return 3 + sin(x);
}

void Newton_Raphson(double Xo, int max_iterations) {
    double Xr_old = Xo, Xr_new, rel_error;
    int step = 0;

    if (f_prime(Xr_old) == 0) {
        cout << "Division by Zero is not allowed." << endl;
        return;
    }

    cout << "Step\t\t Xi\t\t\t Relative Error" << endl;
    
    for (step = 1; step <= max_iterations; step++) {
        Xr_new = Xr_old - f(Xr_old) / f_prime(Xr_old);
        rel_error = fabs((Xr_new - Xr_old) / Xr_new);
        
        cout << step << "\t\t " << Xr_new << "\t\t " << rel_error << endl;
        
        Xr_old = Xr_new;
    }
    
    cout << "\nThe estimated root after " << max_iterations << " iterations is: " << Xr_new << endl;
}

int main() {
    double Xo;
    int max_iterations;
    cout << "Enter Xo (Initial Guess) and number of iterations: ";
    cin >> Xo >> max_iterations;
    
    Newton_Raphson(Xo, max_iterations);
    return 0;
}
