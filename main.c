#include "integrate.h"


int main(int argc, char* argv[]){
    int n, status;
    double a, b, eps, res;

    func_t fs[] = {f1, f2, f3, f4, f5, f6, f7, f8, f9};    

    if (argc == 1)
	{
		printerr(argv[0]);
		return -1;
	}	

    if(argc != 5){
        fprintf(stderr, "Incorrect data\n");
        printerr(argv[0]);
        return -1;
    }

    if(toInt(argv[1], &n) == -1 || n < 1 || n > 9){
        printf("Incorrect n\n");
        return -1;
    }
    
    if(toDouble(argv[2], &a) == -1){
        printf("Incorrect a\n");
        return -1;
    }
    if(toDouble(argv[3], &b) == -1 ){
        printf("Incorrect b\n");
        return -1;
    }
    if(a > b){
        printf("Incorrect data: a > b\n");
        return -1;
    }
    if((toDouble(argv[4], &eps) == -1)  || eps <= 0){
        printf("Incorrect eps\n");
        return -1;
    }

    status = integrate(fs[n-1], a, b, eps,  &res);

    fprintf(stderr, "status: %d\n", status);

    if(status == -1)
        return -1;

    print(res);

    return 0;   
}

int toInt(const char *str, int *res){
    long l;
    char *e;

    errno = 0;
    l = strtol(str, &e, 10);

    if(!errno && *e == '\0'){
        if(INT_MIN <= l && l <= INT_MAX){
            *res = (int)l;
            return 0;
        }
    }

    return -1;
}

int toDouble(const char *str, double *res){
    double d;
    char *e;

    errno = 0;
    d = strtod(str, &e);

    if(!errno && *e == '\0'){
        *res = d;
        return 0;       
    }

    return -1;
}


void print (double res)
{
	double correct_res;

	printf ("Integral: %.15e\n\n", res);

	correct_res = M_PI / 4;
	printf ("|I-(pi/4)| =     %.15e\n\n", fabs (res - correct_res));

	correct_res = M_PI / 2;
	printf ("|I-(pi/2)| =     %.15e\n\n", fabs (res - correct_res));

	correct_res = M_E * M_E - 1;
	printf ("|I-(e^2-1)| =    %.15e\n\n", fabs (res - correct_res));

	correct_res = (M_PI/8)*M_LN2;
	printf ("|I-(pi*ln2/8)| = %.15e\n\n", fabs (res - correct_res));

	correct_res = 1. / 3;
	printf ("|I-(1/3)| =      %.15e\n\n", fabs (res - correct_res));
}

void printerr (const char *s)
{
	printf("\nUsage: %s n a b eps\n\n", s);
	printf("Test functions(n): \n");
	printf("1. f1(x) = 2x\n");
	printf("2. f2(x) = 3x^2\n");
	printf("3. f3(x) = 4x^3\n");
	printf("4. f4(x) = 5x^4\n");
	printf("5. f5(x) = 1/(1+x^2)\n");
	printf("6. f6(x) = sqrt(1-x^2)\n");
	printf("7. f7(x) = 2e^(2x)\n");
	printf("8. f8(x) = ln(x+1)/(x^2+1)\n");
	printf("9. f9(x) = x^2/(1+e^sin(x))\n");
}  