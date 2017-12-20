#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define EPS 0.0001
float ExternalFunctionForSolvingEquation(float b,int n,float *a);
int main()
{
    int choice=10,i=0;
	while(i<1)  //for infinite loop for the main menu even after function processed
	{
        system("cls");
        printf("Main Menu: \n");
		printf("Press 1 for Numerical Error Calculation\n");
		printf("Press 2 for Chapter 2 problems\n");
		printf("Press 3 for Chapter 3 problems\n");
		printf("Press 4 for Deleting all data\n");
		printf("Press 5 for Searching\n");
		printf("Press 100 for Viewing Source Code\n");
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
            case 3:
                system("cls");
                Chapter3();
                getch();
                break;
            case 100:
                system("cls");
                printf("%s",__FILE__);
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
        printf("Chapter 2 Menu: \n");
		printf("Press 1 for Polynomail by Hornor's Method\n");
		printf("Press 2 for Bisection Methods\n");
		printf("Press 3 for False Position Method\n");
		printf("Press 4 for Newton Raphson's Method\n");
		printf("Press 5 for Secant Method\n");
		printf("Press 6 to view Algorithm And Program of Fixed Point Iteration Method\n");
		printf("Press 7 for Hornor's Method For Finding Root\n");
		printf("Press 0 to Go Back To Main Menu\n");
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
             case 4:
                system("cls");
                //FalsePositionMethod();
                break;
             case 5:
                system("cls");
                SecantMethod();
                getch();
                break;
             case 6:
                system("cls");
                FILE *fp;
                char c;
                fp = fopen("FixedPointIterationMethod.txt","r");
                do {
                     c = getc(fp);
                     putchar(c);
                }
                while(c != EOF);
                fclose(fp);
                getch();
                break;
            case 7:
                system("cls");
                HornorsMethodForRoot();
                getch();
                break;
            case 0:
				printf("Moving Back to Main Menu\n");
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
      float array[30];
      int degree, x_val, count, sum = 0;
      printf("\nEnter the Degree of Polynomial:\t");
      scanf("%d", &degree);
      printf("\nEnter the Co - Efficients:\n");
      for(count = degree; count >= 0; count--)
      {
            printf("\nCo - Efficient of X^[%d]: \t",count);
            scanf("%f", &array[count]);
      }
      printf("\nThe Polynomial:\n\n");
      for(count = degree; count >= 0; count--)
      {
            if(array[count] != 0)
            {
                  printf("%0.1f x^%d + ", array[count], count);
            }
      }
      printf("%d", 0);
      printf("\n\nEnter the Value of X:\t");
      scanf("%d", &x_val);
      float pn = array[degree];
      for(count = degree; count >0; count--)
            pn = (pn * x_val) + array[count-1];
      printf("\nEvaluation of Polynomial:\t%f\n", pn);
}
void BisectionMethod()
{
    int n;
    float a[50];
    float xn,xp,xm;
    int j=0,i=0;
    printf("Bisection Method\n");
    printf("Enter the Degree of Polynomial: ");
    scanf("%d",&n);
    printf("\nEnter the Co - Efficients:\n");
    for(i=n;i>=0;i--)
    {
       printf("\nCo - Efficient of X^[%d]: \t",i);
       scanf("%f", &a[i]);
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

float ExternalFunctionForSolvingEquation(float b,int n,float a[])
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
    int n;
    float array[50];
    float a,b,c;
    printf("False Position Method\n");
    printf("Enter the Degree of Polynomial: ");
    scanf("%d",&n);
    printf("\nEnter the Co - Efficients:\n");
    for(i=n;i>=0;i--)
    {
       printf("\nCo - Efficient of X^[%d]: \t",i);
       scanf("%f", &array[i]);
    }
    printf("\nEnter Initial Guess Xn(Low Value): ");
    scanf("%f",&a);
    printf("\nEnter Next Guess Xp(High Value): ");
    scanf("%f",&b);
    i=1;

    printf("\n\n N\t a\t b\t c\t f(c)\n");
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
        printf("\t %0.4f",b);
        printf("\t %0.4f",c);
        printf("\t %0.4f\n",reasultc);

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
void SecantMethod()
{
    int j=0,i=0;
    int n;
    float array[50];
    float X0,X1,X2,EEPS;
    printf("Secant Method\n");
    printf("Enter the Degree of Polynomial: ");
    scanf("%d",&n);
    printf("\nEnter the Co - Efficients:\n");
    for(i=n;i>=0;i--)
    {
       printf("\nCo - Efficient of X^[%d]: \t",i);
       scanf("%f", &array[i]);
    }
    printf("\nEnter Initial Guess X0: ");
    scanf("%f",&X0);
    printf("\nEnter Next Guess X1: ");
    scanf("%f",&X1);
    i=1;
    float reasultX0=0,reasultX1=0,reasultX2=0;
    reasultX0=ExternalFunctionForSolvingEquation(X0,n,array);
    reasultX1=ExternalFunctionForSolvingEquation(X1,n,array);
    printf("\n\nN\tX0\t\tX1\t\tX2\t\tf(X2)\n");
    do
    {
        X2=X1-(reasultX1*(X1-X0))/(reasultX1-reasultX0);
        reasultX2=ExternalFunctionForSolvingEquation(X2,n,array);
        X0=X1;
        X1=X2;
        reasultX0=reasultX1;
        reasultX1=reasultX2;
        EEPS=(X2-X1)/X2;
        printf("%d\t%lf\t%lf\t%lf\t%lf\n",i,X0,X1,X2,reasultX2);
        i++;
    } while(fabs(reasultX2)>EPS);
    printf("\n\nThe Value for the Real root is: %f",X2);
}
void HornorsMethodForRoot()
{
    int n,xn,xp;
    float ValueForTable[200];
    float x,a[50],b[50];
    int j=0,i=0;

    printf("Hornors Rule for finding Roots\n");
    printf("Enter the Degree of Polynomial: ");
    scanf("%d",&n);
    printf("\nEnter the Co - Efficients:\n");
    for(i=n;i>=0;i--)
    {
       printf("\nCo - Efficient of X^[%d]: \t",i);
       scanf("%f", &a[i]);
    }
    printf("\nEnter Minimum Guess for Table(Low Value): ");
    scanf("%d",&xn);
    printf("\nEnter Maximum Guess for Table(High Value): ");
    scanf("%d",&xp);

    //copying from array a to array b
    for(i=n;i>=0;i--)
    {
       b[i]=a[i];
    }

    int pn = a[n];
    float AddingValue=0;
    float root;
    float q;
    int MinPower=0;
    int basePower=0;
    int rootPower=0;
    int power;
    int g=0;

    //solving the eqn in table
    printf("\tx\t\tf(x)\n");
    i=xn;
    for(q=xn;q<=xp;q++)
    {
            ValueForTable[i]=ExternalFunctionForSolvingEquation(q,n,b);
            printf("\t%d\t\t%f\n",i,ValueForTable[i]);
            if(ValueForTable[i-1]<0 & ValueForTable[i]>0)
            {
                x=i-1;
                break;
            }
            i++;
    }
    root=x;
    printf("\nRoot is: %f\n",root);
    printf("Enter precision required (i.e.no of digits after decimal): ");
    scanf("%d",&g);
    while(g>=0)
    {
            power=n;
            MinPower=0;
            basePower=0;
            rootPower--;
            while(n!=MinPower)
            {
                AddingValue=0;
                for(i=n;i>=MinPower;i--)
                {
                    b[i]=b[i]+AddingValue;
                    AddingValue=x*b[i];
                }
                MinPower++;
            }

            //finding auxiliary equation
            for(i=n;i>=0;i--)
            {
                b[i]=b[i]*pow(10,basePower);
                basePower++;
            }

            printf("\nThe Auxiliary Polynomial Equation is:\n\n");
              for(i = n; i >= 0; i--)
              {
                    if(b[i] != 0)
                    {
                          printf("%f x^%d + ", b[i], i);
                    }
              }
              printf("%d\n*****\n", 0);

            //solving the eqn in table
            printf("\tx\t\tf(x)\n");
            i=xn;
            for(q=xn;q<=xp;q++)
            {
                    ValueForTable[i]=ExternalFunctionForSolvingEquation(q,n,b);
                    printf("\t%d\t\t%f\n",i,ValueForTable[i]);
                    if(ValueForTable[i-1]<0 & ValueForTable[i]>0)
                    {
                        x=i-1;
                        break;
                    }
                    i++;
            }
            root=root+(x*pow(10,rootPower));
            printf("\nNew Root is: %f",root);
            g--;
            printf("\n**********************************************************************");
            printf("\n\n");
    }
    printf("\nRoot is: %f",root);
}
void Chapter3()
{
    int chapter3choice=10,i=0;
	while(i<1)  //for infinite loop for the main menu even after function processed
	{
        system("cls");
        printf("Chapter 3 Menu: \n");
		printf("Press 1 for Forward Finite Difference Method\n");
		printf("Press 2 for Backward Finite Difference Method\n");
		printf("Press 3 for Divided Finite Difference Method\n");
		/*printf("Press 4 for Newton Raphson's Method\n");
		printf("Press 5 for Secant Method\n");
		printf("Press 6 to view Algorithm And Program of Fixed Point Iteration Method\n");
		printf("Press 7 for Hornor's Method For Finding Root\n");*/
		printf("Press 0 to Go Back To Main Menu\n");
		scanf("%d",&chapter3choice);
		switch(chapter3choice)
		{
			case 1:
                system("cls");
              //  PolynomialHornors();
                getch();
                break;
            case 2:
                system("cls");
           //     BisectionMethod();
                getch();
                break;
             case 3:
                system("cls");
           //     FalsePositionMethod();
                getch();
                break;
             case 4:
                system("cls");
                //FalsePositionMethod();
                break;
             case 5:
                system("cls");
                SecantMethod();
                getch();
                break;
             case 6:
                system("cls");

                getch();
                break;
            case 7:
                system("cls");
             //   HornorsMethodForRoot();
                getch();
                break;
            case 0:
				printf("Moving Back to Main Menu\n");
				i=1;  //breaks the loop as 1>0
				break;
			default:
				printf("Invalid input entered\n");
				system("pause");
				break;
		}
	}
}
