/*
This program is a lotto game. User is allowed to enter 6 lottery nums(stored in 1d array), and will be
prompted with six options each performing a specific requirement:
1)Enter their lotto numbers,
2)display their lotto numbers,
3)sort the numbers,
4)compare with winning numbers, display one of their winnings if any,
5)display the frequency of nums entered each time user enters a new set of numbers,
6)Exit program

---> program continuously runs until user selects the option to end the program

Author: Cormac Smith
Date: 19/02/20


--- to do ---




*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 6
#define NUMS 43

//function signature
int enterNums(int*,int);
void displayNums(int*);
void sortArr(int*);
void compareNums(int*, int*);
void freqNums(int*, int*);
void empty_stdin(void);
void endProgram(void);



int main()
{
    int userOption;
    int allow = 0;
    int i;
    int rtn;
    int userNums[SIZE];
    int histArr[43] = { 0 };
    int winningNums[SIZE] = { 1, 3, 5, 7, 9, 11 }; // for option 4
    do
    {
        /*
                  ----Main Menu----
                */

        
            printf("\n==================\n");
            printf("      Lotto Game     \n");
            printf("\n==================\n");
            printf("1)Enter 6 numbers (1-42 inclusive)\n");
            printf("2)Display the numbers\n");
            printf("3)Sort the numbers in increasing order\n");
            printf("4)Compare your numbers with the winning numbers\n");
            printf("5)Display the frequency of the numbers chosen\n");
            printf("6)Exit program\n");
            printf("\nEnter your choice below:\n");

            rtn = scanf("%d", &userOption); //if a character or symbol is entered, zero is returned to variable rtn

            if (rtn == 0)
            {
                //this prints an error to the users terminal
                fputs(" **error: invalid integer input**\n", stderr); //satandard error

                //clears the standard input,  repeats until valid option is entered
                empty_stdin();
                

            }


            if (userOption == 1)
            {
                //once this is greater than 0 all other options in the menu become available
                allow++;

                //calling function which will allow user to enter 6 numbers
                allow = enterNums(userNums, allow);

                //this function will store the users entered numbers in a histogram
                freqNums(userNums, histArr);
                


            }

            //if allow is greater than one it means that option one has been selected
            if (allow > 0)

            {

                if (userOption == 2)
                {
                    displayNums(userNums);
                }

                if (userOption == 3)
                {
                    sortArr(userNums);
                }

                if (userOption == 4)
                {
                    compareNums(userNums, winningNums);

                }
                if (userOption == 5)
                {
                    for (i = 1; i < NUMS; i++)
                    {


                        if (histArr[i] > 0)
                        {
                            printf("\nThe value %d, was picked %d times\n", i, histArr[i]);
                        }
                    }
                }

            }
            
         
            //this is outside the if(allow > 0) statement because we want the user to be able to exit the program whenever they want
            if (userOption == 6)
            {
                endProgram();
                break;
            }

         

    }//end while
    while(1); //continous loop

    flushall();
    getchar();
    return 0;
}


//1) function that will allow  user to enter 6 numbers (1-42). Will be stored in 1D array called userNums
int enterNums(int* myarr, int allow)
{
    int i, j;
    int rtn;
    printf("\nEnter 6 numbers of your choice:\n");
    for (i = 0; i < SIZE; i++)
    {
        do
        {
            //error checking if they enter a character
            rtn = scanf("%d", &*(myarr + i));
            if (rtn == 0)
            {
                //this prints an error to the users terminal
                fputs(" **error: invalid integer input**\n", stderr);

                //clears the standard input
                empty_stdin();
                
            }


            //checking if they entered a number within 1-42
            else if (*(myarr + i) < 1 || *(myarr + i) > 42)
            {

                printf("Error, entry is outside of lottery boundaries, please enter a number between 1 and 42\n");
            }


            //if they enter a number within the correct range, this will check if the same number has been entered twice
            else if (*(myarr + i) >= 1 && *(myarr + i) <= 42)
            {
                for (j = 0; j < i; j++)
                {
                    if (*(myarr + i) == *(myarr + j))
                    {

                        printf("Can't enter same num twice!");
                        //this will return 0 to the variable 'allow' in main. When 'allow' is 0 then the menu options 2-6 become locked again.
                        return 0;
                    }

                }

            }


        } while (*(myarr + i) < 1 || *(myarr + i) > 42); //if they entered a num out of range then this do while loop will make sure that the user can input 6 numbers
    }

    return allow; //keep options open

}

//2) this function will display the numbers the user entered 
void displayNums(int* myarr1)
{
    int i;
    printf("\nYour numbers are:\n");
    //display the numbers that were entered by the user
    for (i = 0; i < SIZE; i++)
    {
        printf("%d, ", *(myarr1 + i));

    }
    return;
}


//3) this function will sort the numbers entered by the user in ascending order
void sortArr(int* userArr1)
{
    int i;
    int j;
    int temp;
    printf("\nSorting...\n");
    //comparing the elements and sorting them in ascending order
    for (i = 0; i < SIZE; i++)
    {
        for (j = i + 1; j < SIZE; j++)
        {
            if (*(userArr1 + i) > * (userArr1 + j))
            {
                temp = *(userArr1 + i);
                *(userArr1 + i) = *(userArr1 + j);
                *(userArr1 + j) = temp;
            }

        }



    }

    //display sorted values
    for (i = 0; i < SIZE; i++)
    {
        printf("%d, ", *(userArr1 + i));
    }

    ("The sorted numbers are:\n");
    return;
}


//4) this function will compare the users numbers with the winning numbers 
void compareNums(int* userArr2, int* winningArr)
{
    int i, j;
    int match = 0; // will act as counters for matches between the two arrays

    /*
    this for loop compares the 0th element of the first array with all the elements of the
    second array. Then the 1st element is compared with all the elements of the second array
    etc.
        */
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (*(userArr2 + i) == *(winningArr + j))
            {
                match++;
            }

        }
    }
    //using a switch statement here for the different prizes 
    switch (match)
    {
    case 6:
        printf("Match 6: you win jackpot\n");
        break;
    case 5:
        printf("Match 5: you win a new car\n");
        break;
    case 4:
        printf("Match 4: you win a weekend away\n");
        break;
    case 3:
        printf("Match 3: you win a cinema pass\n");
        break;
    default:
        printf("-----Not a winner-----\n");
        break;


    }

    return;

}

/*
5)  this function will display frequency of the numbers each time the user enters a new
of numbers(without exiting the program)
*/

void freqNums(int* freqArr, int* histArr)
{
    int i, j;
    for (i = 1; i < NUMS; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (freqArr[j] == i)
                histArr[i]++;
        }

    }

}

void endProgram(void)
{
    printf("\n\nThank you for playing the lotto!\n");

    return;
}

//this function clears the standard input
void empty_stdin(void) 
{
    //getchar reads a single character from std input regardless of what it is
    int c = getchar();

    while (c != '\n' && c != EOF)
        c = getchar();
}

