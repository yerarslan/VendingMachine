#include <stdio.h>
#include <math.h>
#include <string.h>
#define NAMEMAX 30
int money=0;
//char code[5]={'1', '1', '1', '0', '\0'};
int code=1110;
int A[2]={10}, B[2]={10}, C[2]={10}, D[2]={10}, E[2]={10}, b, equalsign=61, revenue=0;
struct Drink {
    char name[21];
    int price;
    int quantity;
    int presense;
    int availibility;
};
typedef struct Drink drink;
drink drinkA = {"Juice", 10, 5};
drink drinkB = {"Cola", 6, 1};
drink drinkC = {"Tea", 5, 2};
drink drinkD = {"Water", 8, 1};
drink drinkE = {"Coffee", 7, 9};

/*Let's create the function which will print vending machine. Before we initialized 5 arrays where first element of every array assigned to 10. This value corresponds to the remaing number of each drink. Second element of each array corresponds to the character which will appears under each drink(whether we have sufficient amount of money or not). variable a corresponds to money in vending machine, variable b corresponds to character which will appear in dropoff window (drinks A, B, C, D, E or equalsign if no drink in window).*/
void printVendingMachine(int a, int b, drink drinkA, drink drinkB, drink drinkC, drink drinkD, drink drinkE) {
    if (drinkA.quantity <= 0) {
        drinkA.presense = 88;
    } else drinkA.presense = 32;
    if (drinkB.quantity <= 0) {
        drinkB.presense = 88;
    } else drinkB.presense = 32;
    if (drinkC.quantity <= 0) {
        drinkC.presense = 88;
    } else drinkC.presense = 32;
    if (drinkD.quantity <= 0) {
        drinkD.presense = 88;
    } else drinkD.presense = 32;
    if (drinkE.quantity <= 0) {
        drinkE.presense = 88;
    } else drinkE.presense = 32;
    printf("*");
    int i=0;
    for(i = 0 ; i < 27 ; i++) {
        printf("-");
    }
    printf("*\n");
    printf("|");
    for(i = 0 ; i < 6 ; i++) {
        printf(" ");
    }
    printf("Vending Machine");
    for(i=0; i<6; i++) {
        printf(" ");
    }
    printf("|\n");
    printf("*");
    for( i = 0 ; i < 27 ; i++) {
        printf("-");
    }
    printf("*\n");
    printf("|   A    B    C    D    E   |\n");
    printf("|  $%d  $%d   &%d   $%d   $%d   |\n", drinkA.price, drinkB.price, drinkC.price, drinkD.price, drinkE.price);
    printf("|  [%c]  [%c]  [%c]  [%c]  [%c]  |\n", drinkA.presense, drinkB.presense, drinkC.presense, drinkD.presense, drinkE.presense);
    printf("*");
       for(i = 0 ; i < 27 ; i++) {
           printf("-");
       }
    printf("*\n");
    printf("|                    [$%2d]  |\n", a);
    printf("|                           |\n");
    printf("|           [=%c=]           |\n", b);
    printf("*");
    for(i = 0; i < 27; i++) {
        printf("-");
    }
    printf("*\n\n");
    
}
void readProductInformation(void) {
    printf("(1) The displayed products are:\nA. %s ($%d)\nB. %s ($%d)\nC. %s ($%d)\nD. %s ($%d)\nE. %s ($%d)\n\n",
    drinkA.name, drinkA.price, drinkB.name, drinkB.price, drinkC.name, drinkC.price, drinkD.name, drinkD.price, drinkE.name, drinkE.price);
    return;
}

void vendingMachineInsertMenu(int a) { //here a is money
    printf("*");
    int i = 0;
    for(i = 0 ; i < 27 ; i++) {
        printf("-");
    }
    printf("*\n");
    printf("|");
    for(i = 0 ; i < 6 ; i++) {
        printf(" ");
    }
    printf("Vending Machine");
    for(i = 0; i < 6; i++) {
        printf(" ");
    }
    printf("|\n");
    printf("*");
    for( i = 0 ; i < 27 ; i++) {
        printf("-");
    }
    printf("*\n");
    printf("|   A    B    C    D    E   |\n");
    printf("|  $%d  $%d   &%d   $%d   $%d   |\n", drinkA.price, drinkB.price, drinkC.price, drinkD.price, drinkE.price);
    if (a >= drinkA.price) {
        drinkA.availibility = 79;
    } else drinkA.availibility = 32;
    if (drinkB.price <= a) {
        drinkB.availibility = 79;
    } else drinkB.availibility = 32;
    if (drinkC.price <= a) {
        drinkC.availibility = 79;
    } else drinkC.availibility = 32;
    if (drinkD.price <= a) {
        drinkD.availibility = 79;
    } else drinkD.availibility = 32;
    if (drinkE.price <= a) {
        drinkE.availibility = 79;
    } else drinkE.availibility = 32;
    printf("|  [%c]  [%c]  [%c]  [%c]  [%c]  |\n", drinkA.availibility, drinkB.availibility, drinkC.availibility, drinkD.availibility, drinkE.availibility);
    printf("*");
       for(i = 0 ; i < 27 ; i++) {
           printf("-");
       }
    printf("*\n");
    printf("|                    [$%2d]  |\n", a);
    printf("|                           |\n");
    printf("|           [===]           |\n");
    printf("*");
    for(i = 0; i < 27; i++) {
        printf("-");
    }
    printf("*\n\n");
    
}

void insertCoins(void) {
    printf("(2) Which coin would you like to insert?\n1. $1\n2. $2\n3. $5\n4. $10\n0. Go back\nYour choice: ");
    char choice[2];
    scanf("%s", choice);
    if (strcmp(choice, "1\0") == 0) {
        money = money + 1;
        printf("You have inserted $1.\n\n");
        vendingMachineInsertMenu(money);
        insertCoins();
    }
    else if (strcmp(choice, "2\0") == 0) {
        money = money + 2;
        printf("You have inserted $2.\n\n");
        vendingMachineInsertMenu(money);
        insertCoins();
    }
    else if (strcmp(choice, "3\0") == 0) {
        money = money + 5;
        printf("You have inserted $5.\n\n");
        vendingMachineInsertMenu(money);
        insertCoins();
    }
    else if (strcmp(choice, "4\0") == 0) {
        money = money + 10;
        printf("You have inserted $10.\n\n");
        vendingMachineInsertMenu(money);
        insertCoins();
    }
    else if (strcmp(choice, "0\0") == 0) {
        printf("Going back!\n\n");
        vendingMachineInsertMenu(money);
        return;
    }
    else {
        printf("Invalid choice!\n\n");
        insertCoins();
    }
}

void pressProductButton(void) {
    printf("(3) Which product button would you like to press?\n1. A\n2. B\n3. C\n4. D\n5. E\n0. Go back\nYour choice: ");
    char choice[2];
    scanf("%s", choice);
    if ((strcmp(choice, "1\0") == 0) && money >= drinkA.price && drinkA.quantity > 0) {
            printf("You have pressed button A.\n\n");
            money = money - drinkA.price;
            revenue = revenue + drinkA.price;
            drinkA.quantity--;
            printVendingMachine(money, 65, drinkA, drinkB, drinkC, drinkD, drinkE);
            pressProductButton();
    }
    else if ((strcmp(choice, "1\0") == 0) && (money < drinkA.price || drinkA.quantity <= 0)) {
            printf("You have pressed button A.\n\n");
            pressProductButton();
    }
    else if((strcmp(choice, "2\0") == 0) && money >= drinkB.price && drinkB.quantity > 0) {
            money = money - drinkB.price;
            revenue = revenue + drinkB.price;
            printf("You have pressed button B.\n\n");
            drinkB.quantity--;
            printVendingMachine(money, 66, drinkA, drinkB, drinkC, drinkD, drinkE);
            pressProductButton();
    }
    else if ((strcmp(choice, "2\0") == 0) && (money < drinkB.price || drinkB.quantity <= 0)) {
            printf("You have pressed button B.\n\n");
            pressProductButton();
    }
    else if((strcmp(choice, "3\0") == 0) && money >= drinkC.price && drinkC.quantity > 0) {
            money = money - drinkC.price;
            revenue = revenue + drinkC.price;
            printf("You have pressed button C.\n\n");
            drinkC.quantity--;
            printVendingMachine(money, 67, drinkA, drinkB, drinkC, drinkD, drinkE);
            pressProductButton();
    }
    else if ((strcmp(choice, "3\0") == 0) && (money < drinkC.price || drinkC.quantity <= 0)) {
            printf("You have pressed button C.\n\n");
            pressProductButton();
    }
    else if((strcmp(choice, "4\0") == 0) && money >= drinkD.price && drinkD.quantity > 0) {
            money = money - drinkD.price;
            revenue = revenue + drinkD.price;
            printf("You have pressed button D.\n\n");
            drinkD.quantity--;
            printVendingMachine(money, 68, drinkA, drinkB, drinkC, drinkD, drinkE);
            pressProductButton();
    }
    else if ((strcmp(choice, "4\0") == 0) && (money < drinkD.price || drinkD.quantity <= 0)) {
            printf("You have pressed button D.\n\n");
            pressProductButton();
    }
    else if((strcmp(choice, "5\0") == 0) && money >= drinkE.price && drinkE.quantity > 0) {
            money = money - drinkE.price;
            revenue = revenue + drinkE.price;
            printf("You have pressed button E.\n\n");
            drinkE.quantity--;
            printVendingMachine(money, 69, drinkA, drinkB, drinkC, drinkD, drinkE);
            pressProductButton();
    }
    else if (strcmp(choice, "5\0") == 0 && (money < drinkE.price || drinkE.quantity <= 0)) {
            printf("You have pressed button E.\n\n");
            pressProductButton();
    }
    else if(strcmp(choice, "0\0") == 0) {
            printf("Going back!\n\n");
            printVendingMachine(money, 61, drinkA, drinkB, drinkC, drinkD, drinkE);
            return;
    }
    else {
            printf("Invalid choice!\n\n");
            pressProductButton();
    }
}

void pressReturnButton(void) {
    printf("(4) Return button is pressed.\n$%d has been returned.\n\n", money);
    money=0;
}

void refillProduct(void) {
    printf("(9-3) Which product would you like to refill?\n1. A\n2. B\n3. C\n4. D\n5. E\n0. Go back\nYour choice ");
    char anotherChoice[2];
    scanf("%s", anotherChoice);
    if (strcmp(anotherChoice, "1\0") == 0) {
        printf("You have refilled product A to full\n\n");
        drinkA.quantity = 10;
        return;
    }
    else if (strcmp(anotherChoice, "2\0") == 0) {
        printf("You have refilled product B to full\n\n");
        drinkB.quantity = 10;
        return;
    }
    else if (strcmp(anotherChoice, "3\0") == 0) {
        printf("You have refilled product C to full\n\n");
        drinkC.quantity = 10;
        return;
    }
    else if (strcmp(anotherChoice, "4\0") == 0) {
        printf("You have refilled product D to full\n\n");
        drinkD.quantity = 10;
        return;
    }
    else if (strcmp(anotherChoice, "%\0") == 0) {
        printf("You have refilled product E to full\n\n");
        drinkE.quantity = 10;
        return;
    }
    else if (strcmp(anotherChoice, "0\0") == 0) {
        printf("Going back!\n\n");
        return;
    }
    else {
        printf("Invalid choice!\n\n");
        refillProduct();
    }
}

void changeProduct(void) {
    printf("(9-4) Which product would you like to change?\n1. A\n2. B\n3. C\n4. D\n5. E\n0. Go back\nYour choice ");
    char anotherChoice[2];
    scanf("%s", anotherChoice);
    if (strcmp(anotherChoice, "1\0") == 0) {
        printf("You are changing product A\n");
        printf("Emter new product name: ");
        scanf("%s", drinkA.name);
        printf("Enter new product price: ");
        scanf("%d", &drinkA.price);
        printf("The new product A has been filled to full.\n\n");
        drinkA.quantity = 10;
        return;
    }
    else if (strcmp(anotherChoice, "2\0") == 0) {
        printf("You are changing product B");
        printf("Emter new product name: ");
        scanf("%s", drinkB.name);
        printf("Enter new product price: ");
        scanf("%d", &drinkB.price);
        printf("The new product B has been filled to full.\n\n");
        drinkB.quantity = 10;
        return;
    }
    else if (strcmp(anotherChoice, "3\0") == 0) {
        printf("You are changing product C");
        printf("Emter new product name: ");
        scanf("%s", drinkC.name);
        printf("Enter new product price: ");
        scanf("%d", &drinkC.price);
        printf("The new product C has been filled to full.\n\n");
        drinkC.quantity = 10;
        return;
    }
    else if (strcmp(anotherChoice, "4\0") == 0) {
        printf("You are changing product D");
        printf("Emter new product name: ");
        scanf("%s", drinkD.name);
        printf("Enter new product price: ");
        scanf("%d", &drinkD.price);
        printf("The new product D has been filled to full.\n\n");
        drinkD.quantity = 10;
        return;
    }
    else if (strcmp(anotherChoice, "5\0") == 0) {
        printf("You are changing product E");
        printf("Emter new product name: ");
        scanf("%s", drinkE.name);
        printf("Enter new product price: ");
        scanf("%d", &drinkE.price);
        printf("The new product E has been filled to full.\n\n");
        drinkE.quantity = 10;
        return;
    }
    else if (strcmp(anotherChoice, "0\0") == 0) {
        printf("Going back!\n\n");
        return;
    }
    else {
        printf("Invalid choice!\n\n");
        changeProduct();
    }
}

void unlockedSeviceMenu(void) {
    char choice[2];
    printf("(9) What would you like to do?\n1. Inspect machine status\n2. Withdraw all money\n3. Refill product\n4. Change product\n0. Go back\n");
    printf("Your choice: ");
    scanf("%s", choice);
    if (strcmp(choice, "1\0") == 0) {
        printf("\n");
        printf("(9-1) Machine status\n");
        printf("Amount of revenue: %d\n", revenue);
        printf("Amount of inserted coins: %d\n", money);
        if (drinkA.quantity == 0) {
            printf("A. %s ($%d) (sold out)\n", drinkA.name, drinkA.price);
        }
        else {
            printf("A. %s ($%d) (%d left)\n", drinkA.name, drinkA.price, drinkA.quantity);
        }
        if (drinkB.quantity == 0) {
            printf("B. %s ($%d) (sold out)\n", drinkB.name, drinkB.price);
        }
        else {
            printf("B. %s ($%d) (%d left)\n", drinkB.name, drinkB.price, drinkB.quantity);
        }
        if (drinkC.quantity == 0) {
            printf("C. %s ($%d) (sold out)\n", drinkC.name, drinkC.price);
        }
        else {
            printf("C. %s ($%d) (%d left)\n", drinkC.name, drinkC.price, drinkC.quantity);
        }
        if (drinkD.quantity == 0) {
            printf("D. %s ($%d) (sold out)\n", drinkD.name, drinkD.price);
        }
        else {
            printf("D. %s ($%d) (%d left)\n", drinkD.name, drinkD.price, drinkD.quantity);
        }
        if (drinkE.quantity == 0) {
            printf("E. %s ($%d) (sold out)\n", drinkE.name, drinkE.price);
        }
        else {
            printf("E. %s ($%d) (%d left)\n\n", drinkE.name, drinkE.price, drinkE.quantity);
        }
        unlockedSeviceMenu();
    }
    else if (strcmp(choice, "2\0") == 0) {
        printf("\n");
        printf("(9-2) All money is being withdrawn.\n%d is withdrawn.\n\n", money+revenue);
        money = 0;
        revenue = 0;
        unlockedSeviceMenu();
    }
    else if (strcmp(choice, "3\0") == 0) {
        printf("\n");
        refillProduct();
        unlockedSeviceMenu();
    }
    else if (strcmp(choice, "4\0") == 0) {
        printf("\n");
        changeProduct();
        unlockedSeviceMenu();
    }
    else if (strcmp(choice, "0\0") == 0) {
        printf("Going back!\n\n");
        return;
    }
    else {
        printf("Invalid choice!\n\n");
        unlockedSeviceMenu();
    }
}

void serviceMenu(void) {
    printf("(9) Opening service menu. Access code is required.\nEnter access code: ");
//    char pseudocode[21];
//    scanf("%s", pseudocode);
//    if (strcmp(code, pseudocode) != 0) {
    int pseudocode;
    scanf("%d", &pseudocode);
    if (pseudocode != code) {
        printf("Incorrect code!\n\n");
        printVendingMachine(money, equalsign, drinkA, drinkB, drinkC, drinkD, drinkE);
        return;
    }
    else {
        printf("Correct code!\n\n");
        unlockedSeviceMenu();
        }
}

void mainMenu(void) {
    printf("What you would like to do?\n");
    printf("1. Read product information\n2. Insert coin\n3. Press product button\n4. Press return button\n9. Open service menu (code required)\n0. Quit\nYour choice: ");
    char choice[2];
    scanf("%s", choice);
    if(strcmp(choice, "1\0") == 0) {
        printf("\n");
        readProductInformation();
        mainMenu();
    }
    else if(strcmp(choice, "2\0") == 0) {
        printf("\n");
        insertCoins();
        mainMenu();
    }
    else if(strcmp(choice, "3\0") == 0) {
        printf("\n");
        pressProductButton();
        mainMenu();
    }
    else if(strcmp(choice, "4\0") == 0) {
        printf("\n");
        pressReturnButton();
        mainMenu();
    }
    else if(strcmp(choice, "9\0") == 0) {
        printf("\n");
        serviceMenu();
        mainMenu();
    }
    else if(strcmp(choice, "0\0") == 0) {
        return;
    }
    else {
        printf("Invalid choice!\n\n");
        mainMenu();
    }
}

int main(void) {
    printVendingMachine(money, equalsign, drinkA, drinkB, drinkC, drinkD, drinkE);
    mainMenu();
}
