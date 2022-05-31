// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>
#define PI 3.1415

double cylinder_vertical(double R, double H);
double cylinder_horizontal(double R, double L, double H);

int main() {
	double R, L, H;

	printf("Enter R: ");
	scanf_s("%lf", &R);

	printf("\nEnter L: ");
	scanf("%lf", &L);

	printf("\nEnter H: ");
	scanf("%lf", &H);

	printf("\nHorizontal cylinder area: %f", cylinder_horizontal(R, L, H));
	printf("\nVertical cylinder area: %f", cylinder_vertical(R, H));

	return 0;
}

double cylinder_vertical(double R, double H) {
	return PI * pow(R, 2) * H;
}

double cylinder_horizontal(double R, double L, double H) {
	double d1, d2, d3;
	d1 = acos((R - H) / R) * pow(R, 2);
	d2 = R - H;
	d3 = sqrt(2 * R * H - pow(H, 2));

	return d1 - d2 * d3;
}