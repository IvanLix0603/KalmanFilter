#include <cstdlib>
#include <cmath>
#include <random>
#include <time.h>
#include <cstdio>
using namespace std;

//#define n 0xFFFFFFF
int n=100;
double disp;

double normal_distr(double mean, double disp)
{
  std::mt19937 gen(1701);
  std::normal_distribution <double> distr(mean, disp);
  double result = double(distr(gen));
  return result;
}

double exper(double x, double disp)
{
    double  noise = normal_distr(0, disp);
    noise *= disp;
    double z = sin(x) + noise;
    return z;
}


int kalman(double* X)
{
    double disp, Pe, Z, Pi_1, P, z_N, noise;
    disp = 1/(double(1+random()%n));
    noise= normal_distr(0, disp);
    noise *= disp;
    z_N = sin(0) + noise;
    X[0] = z_N;
    P=disp;
    for(int i = 1; i<n+1; i++)
    {
        Pi_1 = P;
        disp = 1/(double(1+random()%10));
        noise = normal_distr(0, disp);
        noise *= disp;
        Z = sin(i) + noise;
        Pe = abs(pow(sin(i)*Pi_1 - exper(X[i-1], disp) , 2));
        P = (Pe*disp)/(Pe+disp);
        X[i]  = X[i-1] + ((P/disp)*(Z - X[i-1]));
        printf("%f %f\n",noise, X[i]);

    }
    return 0;
}

int main()
{
  srand(time(0));
    double* X =  new double[n+2];
    kalman(X);
    delete X;


  return 0;
}
