#include<iostream>
#include<ctime>

void drawboard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWineer(char *spaces, char player, char computer);
bool checkTie(char *spaces);


int main(){
    std::cout<< "***** Welcome to XOX game *****\n";
    std::cout<< "You are X and the computer is O. Have fun playing it\n";
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawboard(spaces);

    while(running){
        playerMove(spaces,player);
        drawboard(spaces);
        if(checkWineer(spaces,player,computer)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;
        }

        computerMove(spaces,computer);
        drawboard(spaces);
        if(checkWineer(spaces,player,computer)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;
        }
    }
    std:: cout<< "Thank's for playing the game.\n";
    std::cout << "*****************************\n";
}

void drawboard(char *spaces){
    std::cout<< '\n';
    std::cout<< "     |     |     \n";
    std::cout<< "  "<<spaces[0]<<"  |  "<<spaces[1]<<"  |   "<<spaces[2]<<"  \n";
    std::cout<< "_____|_____|_____\n";
    std::cout<< "     |     |     \n";
    std::cout<< "  "<<spaces[3]<<"  |  "<<spaces[4]<<"  |   "<<spaces[5]<<"  \n";
    std::cout<< "_____|_____|_____\n";
    std::cout<< "     |     |     \n";
    std::cout<< "  "<<spaces[6]<<"  |  "<<spaces[7]<<"  |   "<<spaces[8]<<"  \n";
    std::cout<< "     |     |     \n";
    std::cout<< '\n';
}
void playerMove(char *spaces, char player){
    int num;
    do{
        std::cout<< "Enter the position to set X (1-9): ";
        std::cin>> num;

        if(!num>0 || !num<10){
            std::cout<< "Enter Valid number.\n";
        }
        num--;

        if(spaces[num]==' '){
            spaces[num] = player ;
            break;
        }
    }while(!num>0 || !num<8);
}
void computerMove(char *spaces, char computer){
    int num;
    srand(time(0));

    while(true){
        num = rand()%9;
        if(spaces[num]==' '){
            spaces[num] = computer ;
            break;
        }
    }
}
bool checkWineer(char *spaces, char player, char computer){

    //row wise
    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
        spaces[0] == player ? std::cout<< "Congratualtions, You Win!\n" : std::cout<< "You loose! \n";
    }
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
        spaces[3] == player ? std::cout<< "Congratualtions, You Win!\n" : std::cout<< "You loose! \n";
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
        spaces[6] == player ? std::cout<< "Congratualtions, You Win!\n" : std::cout<< "You loose! \n";
    }
    //coulmn wise
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
        spaces[0] == player ? std::cout<< "Congratualtions, You Win!\n" : std::cout<< "You loose! \n";
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
        spaces[1] == player ? std::cout<< "Congratualtions, You Win!\n" : std::cout<< "You loose! \n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
        spaces[2] == player ? std::cout<< "Congratualtions, You Win!\n" : std::cout<< "You loose! \n";
    }
    //diagonally
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
        spaces[0] == player ? std::cout<< "Congratualtions, You Win!\n" : std::cout<< "You loose! \n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
        spaces[2] == player ? std::cout<< "Congratualtions, You Win!\n" : std::cout<< "You loose! \n";
    }
    else{
        return false;
    }

    return true;
}
bool checkTie(char *spaces){
    for(int i=0; i<9; i++){
        if(spaces[i]== ' '){
            return false;
        }
    }
    std::cout<< "It's a tie. Try again Later.\n";
    return true;
}
