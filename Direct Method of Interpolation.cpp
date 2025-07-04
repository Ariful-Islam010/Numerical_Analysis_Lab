#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 20;

void gaussianElimination(float a[MAX][MAX], float result[MAX], int n) {
    for (int i = 0; i < n; i++) {
        // Make diagonal 1
        float pivot = a[i][i];
        for (int j = 0; j <= n; j++) {
            a[i][j] /= pivot;
        }
        // Eliminate below
        for (int k = i + 1; k < n; k++) {
            float factor = a[k][i];
            for (int j = 0; j <= n; j++) {
                a[k][j] -= factor * a[i][j];
            }
        }
    }

    // Back substitution
    for (int i = n - 1; i >= 0; i--) {
        result[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            result[i] -= a[i][j] * result[j];
        }
    }
}

int main() {
    int n, totalPoints;
    float x[MAX], y[MAX], xp;

    cout << "Enter total number of data points: ";
    cin >> totalPoints;

    cout << "Enter x values:\n";
    for (int i = 0; i < totalPoints; i++) cin >> x[i];

    cout << "Enter corresponding y values:\n";
    for (int i = 0; i < totalPoints; i++) cin >> y[i];

    cout << "Enter degree of interpolating polynomial: ";
    cin >> n;

    if (n >= totalPoints) {
        cout << "Polynomial degree must be less than number of data points.\n";
        return 1;
    }

    cout << "Enter value of x to interpolate: ";
    cin >> xp;

    // Find closest n+1 points
    int closest = 0;
    float minDiff = fabs(xp - x[0]);
    for (int i = 1; i < totalPoints; i++) {
        if (fabs(xp - x[i]) < minDiff) {
            minDiff = fabs(xp - x[i]);
            closest = i;
        }
    }

    int start = max(0, closest - n / 2);
    if (start + n >= totalPoints) start = totalPoints - n - 1;

    float matrix[MAX][MAX], result[MAX], coefficients[MAX];

    // Building matrix
    for (int i = 0; i <= n; i++) {
        float xi = x[start + i];
        float yi = y[start + i];
        for (int j = 0; j <= n; j++) {
            matrix[i][j] = pow(xi, j);
        }
        matrix[i][n + 1] = yi;
    }

    // Solve using Gaussian Elimination
    gaussianElimination(matrix, coefficients, n + 1);

    // Interpolation
    float yp = 0;
    for (int i = 0; i <= n; i++) {
        yp += coefficients[i] * pow(xp, i);
    }

    cout << "\nInterpolated value at x = " << xp << " is: " << yp << endl;

    return 0;
}
