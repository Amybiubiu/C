#include <stdio.h>
#include <math.h>
int main() {
    float a;
    float x1, x2;

    printf("请输入待求平方根的数：");
    scanf("%f",&a);
    x1 = a / 2;
    x2 = (x1 + a / x1) / 2;
    while (fabs(x1 - x2) >= 1e-5) {
        x1 = x2;
        x2 = (x1 + a / x1) / 2;
    }   
    printf("%f",x2);
}
