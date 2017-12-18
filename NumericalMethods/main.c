#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define EPS 0.0001
float ExternalFunctionForSolvingEquation(float b,int n,int *a);
int main()
{
    int choice=10,i=0;
	while(i<1)  //for infinite loop for the main menu even after function processed
	{
        system("cls");
        printf("Main Menu: \n");
		printf("Press 1 for Numerical Error Calculation\n");
		printf("Press 2 for Chapter 2 problems\n");
		printf("Press 3 for Displaying all data\n");
		printf("Press 4 for Deleting all data\n");
		printf("Press 5 for Searching\n");
		printf("Press 0 to exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
                system("cls");
                NumericalErrorCalculation();
                getch();
                break;
            case 2:
                system("cls");
                Chapter2();
                getch();
                break;
            case 0:
				printf("Thank you for Using the Program\n");
				i=1;  //breaks the loop as 1>0
				break;
			default:
				printf("Invalid input entered\n");
				system("pause");
				break;
		}
	}
    return 0;
}

void NumericalErrorCalculation()
{
    float TrueValue,ApproxValue,AbsoluteError, RelativeError,PercentageError, RelativeAccuracy;
    printf("Enter True Value: ");
    scanf("%f", &TrueValue);
    printf("\nEnter Approximate Value: ");
    scanf("%f", &ApproxValue);
    AbsoluteError=TrueValue-ApproxValue;
    RelativeError=AbsoluteError/TrueValue;
    PercentageError=AbsoluteError/TrueValue*100;
    RelativeAccuracy=AbsoluteError/abs(ApproxValue);
    printf("\nThe Absolute Error is %f", AbsoluteError);
    printf("\nThe Relative Error is %f", RelativeError);
    printf("\nThe Percentage Error is %f", PercentageError);
    printf("\nThe Relative Accuracy is %f", RelativeAccuracy);
}

void Chapter2()
{
    int chapter2choice=10,i=0;
	while(i<1)  //for infinite loop for the main menu even after function processed
	{
        system("cls");
        printf("Main Menu: \n");
		printf("Press 1 for Polynomail by Hornor's Method\n");
		printf("Press 2 for Bisection Methods\n");
		printf("Press 3 for False Position Method\n");
		printf("Press 4 for Deleting all data\n");
		printf("Press 5 for Searching\n");
		printf("Press 0 to exit\n");
		scanf("%d",&chapter2choice);
		switch(chapter2choice)
		{
			case 1:
                system("cls");
                PolynomialHornors();
                getch();
                break;
            case 2:
                system("cls");
                BisectionMethod();
                getch();
                break;
             case 3:
                system("cls");
                FalsePositionMethod();
                getch();
                break;
            case 0:
				printf("Thank you for Using the Program\n");
				i=1;  //breaks the loop as 1>0
				break;
			default:
				printf("Invalid input entered\n");
				system("pause");
				break;
		}
	}
}

void PolynomialHornors()
{
      int array[30], degree, x_val, count, sum = 0;
      printf("\nEnter the Degree of Polynomial:\t");
      scanf("%d", &degree);
      printf("\nEnter the Co - Efficients:\n");
      for(count = degree; count >= 0; count--)
      {
            printf("\nCo - Efficient of A[%d]: \t", count);
            scanf("%d", &array[count]);
      }
      printf("\nThe Polynomial:\n\n");
      for(count = degree; count >= 0; count--)
      {
            if(array[count] != 0)
            {
                  printf("%dx^%d + ", array[count], count);
            }
      }
      printf("%d", 0);
      printf("\n\nEnter the Value of X:\t");
      scanf("%d", &x_val);
      int pn = array[degree];
      for(count = degree; count >0; count--)
            pn = (pn * x_val) + array[count-1];
      printf("\nEvaluation of Polynomial:\t%d\n", pn);
      getch();
}
void BisectionMethod()
{
    int n,a[50];
    float xn,xp,xm;
    int j=0,i=0;
    printf("Bisection Method\n");
    printf("Enter the Degree of Polynomial: ");
    scanf("%d",&n);
    printf("\nEnter the Co - Efficients:\n");
    for(i=n;i>=0;i--)
    {
       printf("\nCo - Efficient of X^[%d]: \t",i);
       scanf("%d", &a[i]);
    }
    printf("\nEnter Initial Guess Xn(Low Value): ");
    scanf("%f",&xn);
    printf("\nEnter Next Guess Xp(High Value): ");
    scanf("%f",&xp);
    xm=(xn+xp)/2;
    i=1;
    printf("\n\nn\t\txn\t\txp\t\txm\t\tf(xm)\n");
    float reasult=0;
    while(j==0)
    {
        printf("\n\n%d",i);
        i++;
        printf("\t\t%0.4f",xn);
        printf("\t\t%0.4f",xp);
        printf("\t\t%0.4f",xm);
        printf("\t\t%0.4f",ExternalFunctionForSolvingEquation(xm,n,a));
        xm=(xn+xp)/2;
        if(((xp-xn)/xn)<EPS)
        {
            j=40;
        }
        if(ExternalFunctionForSolvingEquation(xm,n,a)==0)
        {
            j=40;
        }
        if(ExternalFunctionForSolvingEquation(xm,n,a)<0)
        {
            xn=xm;
        }
        if(ExternalFunctionForSolvingEquation(xm,n,a)>0)
        {
            xp=xm;
        }
    }
    printf("\n\nThe Value for the Real root is: %f",xm);
}

float ExternalFunctionForSolvingEquation(float b,int n,int a[])
{
    float fx=0,x[50];
    int l;
    x[0]=1;
    for(l=1;l<=n;l++)
    {
        x[l]=b*x[l-1];
    }
    for(l=0;l<=n;l++)
    {
        fx=a[l]*x[l]+fx;
    }
   // printf("\n\nThe Value for the Real root is: %f",fx);
    return fx;
}
void FalsePositionMethod()
{
    int j=0,i=0;
    int n,array[50];
    float a,b,c;
    printf("False Position Method\n");
    printf("Enter the Degree of Polynomial: ");
    scanf("%d",&n);
    printf("\nEnter the Co - Efficients:\n");
    for(i=n;i>=0;i--)
    {
       printf("\nCo - Efficient of X^[%d]: \t",i);
       scanf("%d", &array[i]);
    }
    printf("\nEnter Initial Guess Xn(Low Value): ");
    scanf("%f",&a);
    printf("\nEnter Next Guess Xp(High Value): ");
    scanf("%f",&b);
    i=1;

    printf("\n\n N\t a\t f(a)\t b\t f(b)\t c\t f(c)\n");
    float reasultc=0,reasulta=0,reasultb=0;
    reasulta=ExternalFunctionForSolvingEquation(a,n,array);
    reasultb=ExternalFunctionForSolvingEquation(b,n,array);

    do
    {
        c=((a*reasultb)-(b*reasulta))/(reasultb-reasulta);
        reasultc=ExternalFunctionForSolvingEquation(c,n,array);
        printf(" %d",i);
        i++;
        printf("\t %0.4f",a);
        printf("\t %0.4f",reasulta);
        printf("\t %0.4f",b);
        printf("\t %0.4f\n",reasultb);
        printf("\t %0.4f",c);
        printf("\t %0.4f",reasultc);

        if(reasultc>0)
        {
          b=c; // f(b)==f(c);
          reasultb=reasultc;
          reasulta=ExternalFunctionForSolvingEquation(a,n,array);
        }
        else if(reasultc<0)
        {
            a=c; // f(a)==f(c);
            reasulta=reasultc;
            reasultb=ExternalFunctionForSolvingEquation(b,n,array);
        }
        else if(reasultc==0)
           break;
        else
        {}//nothing
    } while(fabs(reasultc)>EPS & reasultc!=0);
    printf("\n\nThe Value for the Real root is: %f",c);
}

