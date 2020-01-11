#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Maths quiz menu driven game. Displays user with four options. User can specify how many questions he wishes to be asked
  (up to a maximum of 5 questions). User is then prompted these random addition questions. Usere can see results at the end if they so wish

  Author: Cormac Smith
  Date: 29/10/2019
  Compiler used: borlands 
  
 
*/




int main()
{
    
    int option = 0;
    int num1;
    int num2;
    int TrackerCorrect = 0;
    int TrackerWrong = 0;
    int UserAns;
    int Questions = 0;
    int i;
    int ans;
    
    do
    {
        //main menu
        printf("\n==================\n");
        printf("   Maths Quiz       \n");
        printf("==================\n");
        printf("1.Enter the number of questions for this round\n");
        printf("2.Start quiz\n");
        printf("3.Display the number of questions that were answered (i) correctly and (ii) incorrectly for this round\n");
        printf("4.exit program\n");


        //clear the buffer
        fflush(stdin);
        scanf("%d", &option);

        if(option == 1)
        {
             
            //number of questions to be asked
            printf("Enter the number of questions you wish to be asked(max of 5):\n");
            scanf("%d", &Questions);


            if(Questions > 5 || Questions <= 0)
            {
                printf("Must be between 1 and 5 questions.\n");
            }

        }

        //if option 2 is pressed prompt user with questions
        if(option == 2)
        {
            TrackerCorrect = 0;
            TrackerWrong = 0;

                for(i = 0; i < Questions; i++)
                {
                    //generates random numbers between 1 and 10 for each question using srand
                    srand(time(NULL));
                    num1 = rand()% 10 + 1;
                    num2 = rand()% 10 + 1;
                    ans = num1 + num2;
                    
                    //prints out the question
                    printf("\n%d + %d: ", num1, num2);
                    scanf("%d", &UserAns);
                    
                    //if users guess is wrong, display the correct answer beside their answer 
                    if (UserAns != ans)
                    {
                    printf(" - Wrong, the correct answer is %d\n", ans);
                    TrackerWrong++;

                    }
                    else
                    {
                    printf("- Correct, well done!\n");
                    TrackerCorrect++;
                    }



                } //end for


        } //end if option 2


        //if option 3 is pressed
        if (option == 3 )
        {
            if(TrackerCorrect > 0 || TrackerWrong > 0)
            {
             printf("\nYou answered %d correctly and %d incorrectly\n\n", TrackerCorrect, TrackerWrong);
            }
            
            //if option 3 is pressed before option 1 
            else 
            {
                printf("You need to answer questions first");
            }
        } //end if option 3
        \
        
        //exits program
        if (option == 4)
        {
            printf("Exiting program... ");
            exit(0);
        }

        //if user enters an option out of range 1-4 then prompt user again 
        if(option > 4 || option < 1)
        {
            printf("\nOut of range. Enter a valid option please\n\n");
        }
        
        
    } // end do while loop
    while (option > 0 || option <=-1 ); // if user enters an option out of range 1-4 then prompt menu again - keeps menu - keeps menu running continuously




    flushall();
    getchar();
    return 0;


}
