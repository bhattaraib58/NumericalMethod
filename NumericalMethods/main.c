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
		printf("Press 1 for Push\n");
		printf("Press 2 for POP\n");
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
