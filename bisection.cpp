#include<stdio.h>
#include<math.h>

int degree; 
double coefficients[10];

double f(double x){
	double result = 0;
	for(int i = 0; i <= degree; i++){
		result += coefficients[i] * pow(x, degree - i);
	}
	return result;
}

double bisection(double a, double b, double tol, int n){
	if(a == b || f(a)*f(b) >= 0){
		return -1;
	}
	int max = 1;
	double c;
	while(max <= n){
		c = (a + b)/2;
		if(f(c) == 0 || (b-a)/2 < tol){
			return c;
		}else if(f(c)*f(a) < 0){
			b = c;
		}else {
			a = c;
		}
		max++;
	}
	return 0;
}

void inputCoefficient(){
	for (int i = 0; i <= degree; i++) {
        printf("x^%d: ", degree - i);
        scanf("%lf", &coefficients[i]);
    }
    printf("Equation: ");
    for (int i = 0; i <= degree; i++) {
    	if(i == 0){
    		printf("(%.2lf)x^%d ", coefficients[0], degree-i);
		}else if(i == degree){
            printf("+ (%.2lf)", coefficients[i]);
        }
        else{
			printf("+ (%.2lf)x^%d ", coefficients[i], degree-i);
		}  
    }
    printf("\n");
}

void inputRequirement(double start, double end, double tol, int max){
	do{
		printf("Enter start point: "); scanf("%lf", &start);
		printf("Enter end point: "); scanf("%lf", &end);
		if(start == end || start > end){
			printf("These point isn't not valid!\n");
		}
	}while(start == end || start > end);

	do{
		printf("Enter tolerance: "); scanf("%lf", &tol);
		if(tol < 0){
			printf("- The tolerance have to be greater than zero!");
		}
	}while(tol < 0);
	
	do{
		printf("Enter maximum iterations: "); scanf("%d", &max);
		if(max < 1){
			printf("- The maximum number of iterations have to be greater than zero!");
		}
	}while(max < 1);
}

void outputRoot(double root){
	if(root ==-1){
		printf("The root does not lie in this interval!\n");
	}else if(root == 0){
		printf("Method failed!");
	}else {
		printf("The root is: %.3lf", root);
	}
}

int main(){
	double start, end; //Endpoint
	double tol; //tolerance
	int max; //maximum iterations 
	
	int choice;

    do{
		printf("-----------Choose Equation------------\n");
		printf("1. Enter the equation yourself\n");
		printf("2. Use the sample equation: 2x^3 + 3x^2 - 5x + 1\n");
		printf("3. Use the sample equation: x^2 - 4x + 4\n");
		printf("4. Quit\n");
		printf("- Your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("Enter degree (<=10): ");
				scanf("%d", &degree);
				if (degree > 10) {
					printf("- Please enter the degree less than 10\n");
					break;
				}
				inputCoefficient();
				inputRequirement(start, end, tol, max);
				outputRoot(bisection(start, end, tol, max));
				break;
			case 2:
				degree = 3;
				coefficients[0] = 2;
				coefficients[1] = 3;
				coefficients[2] = -5;
				coefficients[3] = 1;
				inputRequirement(start, end, tol, max);
				outputRoot(bisection(start, end, tol, max));
				break;
			case 3:
				degree = 2;
				coefficients[0] = 1;
				coefficients[1] = -4;
				coefficients[2] = 4;
				inputRequirement(start, end, tol, max);
				outputRoot(bisection(start, end, tol, max));
				break;
			case 4:
				printf("Quitting the program...\n");
				break;
			default:
				printf("- Your choice isn't valid!\n");
		}
	}while(choice != 4);
	
	return 0;
}
