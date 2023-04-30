#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int scoreUser = 0;
int scoreComputer = 0;
int userChoice, computerChoice;

int main() {
    srand(time(NULL));
    
    printf("\nLe jeu du Pierre Feuille Ciseaux \n\n");

    printf("SCORE : %d - %d\n\n", scoreUser, scoreComputer);

    for(int tries = 0; tries < 10; tries ++) {

        printf("Choisis entre [0]PIERRE, [1]FEUILLE ou [2]CISEAUX : ");
        scanf("%d", &userChoice);

        switch(userChoice) {
            case 0:
                printf("\nPLAYER : PIERRE\n");
                break;

            case 1:
                printf("\nPLAYER : FEUILLE\n");
                break;

            case 2:
                printf("\nPLAYER : CISEAUX\n");
                break;

            default:
                break;
        }

        computerChoice = rand() % 3;

        switch(computerChoice) {
            case 0:
                printf("COMPUTER : PIERRE\n\n");
                break;

            case 1:
                printf("COMPUTER : FEUILLE\n\n");
                break;

            case 2:
                printf("COMPUTER : CISEAUX\n\n");
                break;

            default:
                break;
        }

        if(userChoice == computerChoice) {

            printf("\t\tEGALITE\n\nScore : %d - %d\n\n", scoreUser, scoreComputer);

        } else if(userChoice == 0 && computerChoice == 1) {

            scoreComputer++;
            printf("\t\tMANCHE PERDUE\n\nScore : %d - %d\n\n", scoreUser, scoreComputer);

        } else if(userChoice == 0 && computerChoice == 2) {

            scoreUser++;
            printf("\t\tMANCHE GAGNEE\n\nScore : %d - %d\n\n", scoreUser, scoreComputer);

        } else if(userChoice == 1 && computerChoice == 0) {

            scoreUser++;
            printf("\t\tMANCHE GAGNEE\n\nScore : %d - %d\n\n", scoreUser, scoreComputer);

        } else if(userChoice == 1 && computerChoice == 2) {

            scoreComputer++;
            printf("\t\tMANCHE PERDUE\n\nScore : %d - %d\n\n", scoreUser, scoreComputer);

        } else if(userChoice == 2 && computerChoice == 0) {

            scoreComputer++;
            printf("\t\tMANCHE PERDUE\n\nScore : %d - %d\n\n", scoreUser, scoreComputer);

        } else if(userChoice == 2 && computerChoice == 1) {

            scoreUser++;
            printf("\t\tMANCHE GAGNEE\n\nScore : %d - %d\n\n", scoreUser, scoreComputer);

        } else if(userChoice == 9) {

            printf("\t\tMATCH STOPE");
            break;

        }

        if(scoreUser == 3) {
            printf("\n\t\tBRAVO VOUS AVEZ GAGNE\n");
            break;
        } else if(scoreComputer == 3) {
            printf("\n\t\tDOMMAGE VOUS AVEZ PERDU\n");
            break;
        }

    }

    return 0;
}
