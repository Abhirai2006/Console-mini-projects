#include<iostream>
#include<ctime>

char showUserChoice();
char showComputerChoice();
void showChoice(char choice);
void wineer(char player,char computer);

int main(){
    char player;
    char computer;
    char playAgain;

    std::cout<< "***** Welcome to the game *****\n";

    do{player = showUserChoice();
    std::cout<< "Your choice is: ";
    showChoice(player);

    computer = showComputerChoice();
    std::cout<< "Compter choice is: ";
    showChoice(computer);

    wineer(player, computer);

    std::cout<< "Do u want to play the game again (y/n): ";
    std::cin>> playAgain;
    std::cout<< "\n";

    }while (playAgain == 'y' || playAgain == 'Y');

    std::cout<< "Thank-you for playing the game.\n";
    std::cout<< "*******************************\n";
    return 0;

}

char showUserChoice(){
    char choice;
    do{

        std::cout<< "r for rock\n";
        std::cout<< "p for paper\n";
        std::cout<< "s for scissor\n\n";
        std::cout<< "Now enter your choice: ";
        std::cin >> choice;
    }while(choice != 'r' && choice != 'p' && choice != 's');

    return choice;
}
char showComputerChoice(){

    srand(time(0));
    int num = (rand()%3) +1;

    switch(num){
        case 1: return 'r';
        case 2: return 'p';
        case 3: return 's';
    }
    return 0;
}
void showChoice(char choice){

    switch(choice){
        case 'r':
            std::cout<< "Rock\n";
            break;
        case 'p':
            std::cout<< "Paper\n";
            break;
        case 's':
            std::cout<< "Scissor\n";
            break;
    }
}
void wineer(char player,char computer){

    switch (player){
        case 'r':
            if (computer == 'r'){
                std::cout<< "It's a tie\n";
            }
            else if(computer == 'p'){
                std::cout<< "You loose!\n";
            }
            else{
                std::cout<< "You win!\n";
            }
            break;

        case 'p':
            if (computer == 'p'){
                std::cout<< "It's a tie\n";
            }
            else if(computer == 's'){
                std::cout<< "You loose!\n";
            }
            else{
                std::cout<< "You win!";
            }
            break;

        case 's':
            if (computer == 's'){
                std::cout<< "It's a tie\n";
            }
            else if(computer == 'r'){
                std::cout<< "You loose!\n";
            }
            else{
                std::cout<< "You win!";
            }
            break;
    }
}
