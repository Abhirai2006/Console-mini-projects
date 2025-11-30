#include<iostream>

void showbalance(double balance);
double deposite();
double withdraw(double balance);

int main(){
    double balance = 0;
    int choice;
    std::cout<< "\n***** Welcome to the Bank *********\n";

    do{
        std::cout<< "\nEnter\n";
        std::cout<< "1. Show balance." << '\n';
        std::cout<< "2. Deposit amount."<< '\n';
        std::cout<< "3. Withdraw amount."<< '\n';
        std::cout<< "4. Exit."<< '\n';
        std::cout<< "\nNow enter your choice: ";
        std::cin>> choice;

        std::cin.clear();
        fflush(stdin);

        switch (choice){
            case 1:
                showbalance(balance);
                break;

            case 2:
                balance = balance + deposite();
                showbalance(balance);
                break;

            case 3:
                balance = balance - withdraw(balance);
                showbalance(balance);
                break;

            case 4:
                std::cout<< "Thank-you for visiting our bank. \n";
                break;

            default:
                std::cout<< "Invalid operator.\n";
        }
    }while (choice != 4);
}

void showbalance(double balance){
    balance;
    std::cout<< "Your balance is right now: $ " << balance << " only.\n";

}
double deposite(){
    double amount;
    std::cout<< "Enter the amount you want to deposite: ";
    std::cin>> amount;

    if(amount < 0){
        std::cout<< amount << " cannot be deposited.\n";
        return 0;
    }
    return amount;

}
double withdraw(double balance){
    double amount;

    std::cout<< "Enter the amount you want to withdraw: ";
    std::cin>> amount;

    if (amount > balance){
        std::cout<< "Insufficient balance, so request for withdrawal is rejected.\n";
        return 0;
    }
    else if(amount < 0){
        std::cout<< "That's not a valid amount.\n";
        return 0;
    }
    else{
        return amount;
    }
}
