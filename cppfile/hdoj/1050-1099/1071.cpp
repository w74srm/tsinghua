#include <iostream>
#include <cstdio>
#include <cmath>
#define PI 3.1415926
#define INF 10000
using namespace std;

double matrix(int n, double a[3][3])
{ //***3*3行列式计算
    double sum1 = a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[2][0] + a[1][0] * a[2][1] * a[0][2];
    double sum2 = a[2][0] * a[1][1] * a[0][2] + a[0][0] * a[2][1] * a[1][2] + a[2][2] * a[0][1] * a[1][0];
    return sum1 - sum2;
}

int main(void)
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        double x1, y1, x2, y2, x3, y3;
        scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
        double matrix1[3][3] = {y1, x1, 1, y2, x2, 1, y3, x3, 1};
        double matrix2[3][3] = {x1 * x1, y1, 1, x2 * x2, y2, 1, x3 * x3, y3, 1};
        double matrix3[3][3] = {x1 * x1, x1, y1, x2 * x2, x2, y2, x3 * x3, x3, y3};
        double matrix4[3][3] = {x1 * x1, x1, 1, x2 * x2, x2, 1, x3 * x3, x3, 1};
        double a = matrix(3, matrix1);
        double b = matrix(3, matrix2);
        double c = matrix(3, matrix3);
        double d = matrix(3, matrix4);
        a /= d;
        b /= d;
        c /= d;
        double k = (y3 - y2) / (x3 - x2);
        double x = (k - b) / (2 * a);
        double y = a * x * x + b * x + c;
        double cnt = (x * y2 + y * x3 + x2 * y3 - x * y3 - y * x2 - y2 * x3) / 2;
        printf("%.2lf\n", cnt * 4 / 3);
    }
    return 0;
}