#include<bits/stdc++.h>
using namespace std;

int main()
{
    float x[10],y[10],xp,yp=0;
    int n;

    cout<<"Enter number of data points: ";
    cin>>n;

    cout << "Enter x and y values (one pair per line):\n";
    for (int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }

    cout<<"Enter the value of x for interpolation: ";
    cin>>xp;

    cout<<fixed<<setprecision(6);
    cout<<"\nCalculating Lagrange interpolation step-by-step:\n";

    for (int i=0;i<n;i++)
    {
        float term = y[i];
        cout<<"L"<<i<<" = "<<y[i];
        for (int j=0;j<n;j++)
        {
            if (j!=i)
            {
                term *= (xp-x[j]) / (x[i]-x[j]);
                cout << " * ((" << xp << " - " << x[j] << ") / (" << x[i] << " - " << x[j] << "))";
            }
        }
        cout<<" = "<<term<<endl;
        yp += term;
    }

    cout << "\nEstimated value at x = " <<xp<< " is: " <<yp<<endl;

    return 0;
}

