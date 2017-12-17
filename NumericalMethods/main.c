#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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
                NumericalErrorCalculation();
            case 2:
                Chapter2();
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
    system("cls");
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
    getch();
}

void Chapter2()
{
    int chapter2choice=10,i=0;
	while(i<1)  //for infinite loop for the main menu even after function processed
	{
        system("cls");
        printf("Main Menu: \n");
		printf("Press 1 for Polynomail by Hornor's Method\n");
		printf("Press 2 for Chapter 2 problems\n");
		printf("Press 3 for Displaying all data\n");
		printf("Press 4 for Deleting all data\n");
		printf("Press 5 for Searching\n");
		printf("Press 0 to exit\n");
		scanf("%d",&chapter2choice);
		switch(chapter2choice)
		{
			case 1:
                PolynomialHornors();
                break;
            case 2:
                Chapter2();
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
      //for(count = degree; count >= 0; count--)
     // {
     //       sum = sum + array[count]*pow(x_val, count);
    //  }
      int pn = array[degree];
      for(count = degree; count >0; count--)
            pn = (pn * x_val) + array[count-1];
      printf("\nEvaluation of Polynomial:\t%d\n", pn);
      getch();
}
