/*********************************
* Alireza Ahmadian 1912941
* Project of programming 
* Version 1.0.4
*********************************/
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>

int k;
int menueNum;
int exit_num;
FILE *file;
char inventoryFileName[25];
char source[25] ="                         "; /*This valu is just about the space of print*/

void header_print(){ /*Print the header of display the itemes*/
    
    printf("+-------------------------------------------------------------------------------------+\n");
    printf("|    |            |             |           |      |          | Final | Monthly  |Inve|\n");
    printf("|Code| brand Name |    model    |  screen   |memory|  camera  | Price | 12  | 24 |ntry|\n");
    printf("+-------------------------------------------------------------------------------------+\n");
}
struct smartphone{
    int code;
    char brand[25];
    char model[25];
    float screen;
    int memory;
    float camera;
    int price[3];
    int stock;
} inventory_Fido[50];

int printTheMenue(){ /*This function return the number of main menu's item */
    int menueNum;

    printf("+-------------------------------------------------------------------------------------+\n");
    printf("| 1-Populate the inventory.                | 4-Process a return-an-item transaction.  |\n");
    printf("+------------------------------------------+------------------------------------------+\n");
    printf("| 2-Display items of a particular brand.   | 5-Display all the items in the inventory.|\n");
    printf("+------------------------------------------+------------------------------------------+\n");
    printf("| 3-Process a buy-an-item transaction.     | 6-Exit the system.                       |\n");
    printf("+-------------------------------------------------------------------------------------+\n");

    printf("Please enter the number of Menue: ");
    scanf("%d", &menueNum);

    return menueNum;
}

int PopulateTheInventory(){ /*This function upload the data file or enter data from text file to array.*/

    char dataFileName[25];
    int i = 0;

    printf("\nPlease enter your Database file  without the extension\n");
    printf("In this program the existing or default file's name is database: ");
    scanf("%s", dataFileName);
    
    file = fopen(strcpy(inventoryFileName,strcat(dataFileName,".txt")), "r+");
    
    while (EOF != fscanf(file, "%d %s %s %f %d %f %d %d %d %d", &inventory_Fido[i].code,
                                                                &inventory_Fido[i].brand,
                                                                &inventory_Fido[i].model, 
                                                                &inventory_Fido[i].screen,
                                                                &inventory_Fido[i].memory, 
                                                                &inventory_Fido[i].camera,
                                                                &inventory_Fido[i].price[1], 
                                                                &inventory_Fido[i].price[2],
                                                                &inventory_Fido[i].price[3],
                                                                &inventory_Fido[i].stock)){
        k=i++;
    }
    printf("\nthe file uploaded.\n");
    return k;
}

void displayParticularItems(){

    int rowNumberItem[50], l = 0;
    char getParticularBrand[25];
    
    if( file == NULL ){ /*Error of upload file*/
        printf( "The inventory file is not open. " ) ;
        PopulateTheInventory();
    }

    printf("Please enter your particular brand: ");
    scanf("%s", getParticularBrand);
    header_print();
    
    for (int i = 0; i <= k; i++){
    
        if (strcmp(inventory_Fido[i].brand, getParticularBrand) == 0){

            printf("|%d |%s | %s |  %f |  %d | %f | %d | %d | %d | %d|\n",  inventory_Fido[i].code,
                                                                            strncat ( inventory_Fido[i].brand, source, (11-strlen(inventory_Fido[i].brand))),
                                                                            strncat ( inventory_Fido[i].model, source, (11-strlen(inventory_Fido[i].model))), 
                                                                            inventory_Fido[i].screen,
                                                                            inventory_Fido[i].memory, 
                                                                            inventory_Fido[i].camera,
                                                                            inventory_Fido[i].price[1], 
                                                                            inventory_Fido[i].price[2],
                                                                            inventory_Fido[i].price[3],
                                                                            inventory_Fido[i].stock);
            printf("-----------------------------------------------------------------------------------\n");
        }
    }
    printf("\n");
}

void enterFinalData(){
    int i=0;
    fclose(file);
    remove(inventoryFileName);
    file = fopen(inventoryFileName, "w");
    for (int i = 0; i <= k; i++){
        fprintf(file, "%d %s %s %f %d %f %d %d %d %d \n", inventory_Fido[i].code,
                                                          inventory_Fido[i].brand,
                                                          inventory_Fido[i].model, 
                                                          inventory_Fido[i].screen,
                                                          inventory_Fido[i].memory, 
                                                          inventory_Fido[i].camera,
                                                          inventory_Fido[i].price[1], 
                                                          inventory_Fido[i].price[2],
                                                          inventory_Fido[i].price[3],
                                                          inventory_Fido[i].stock);
    }
    printf("The file just uploaded.\n");
        
}

void buyItemProcess(){ /*This is the function it related to switch 3 of main menu*/
   int select_Code, buy_sure, indexItemSelected, numberOfPurchase = 0;
   if( file == NULL ){
        printf( "The inventory file is not open. " ) ;
        PopulateTheInventory();
    }
    printf("Please enter your final selaction code: ");
    scanf("%d", &select_Code);
    header_print();
    
    for (int i = 0; i <= k; i++){
    
        if (inventory_Fido[i].code == select_Code){
            indexItemSelected = i;
            printf("|%d |%s | %s |  %f |  %d | %f | %d | %d | %d | %d|\n",  inventory_Fido[i].code,
                                                                            strncat ( inventory_Fido[i].brand, source, (11-strlen(inventory_Fido[i].brand))),
                                                                            strncat ( inventory_Fido[i].model, source, (11-strlen(inventory_Fido[i].model))), 
                                                                            inventory_Fido[i].screen,
                                                                            inventory_Fido[i].memory, 
                                                                            inventory_Fido[i].camera,
                                                                            inventory_Fido[i].price[1], 
                                                                            inventory_Fido[i].price[2],
                                                                            inventory_Fido[i].price[3],
                                                                            inventory_Fido[i].stock);
        break;
        }   
    }
    printf("-----------------------------------------------------------------------------------------\n");
    printf("If you are sure about the code. Please enter 0 : ");
    scanf("%d", &buy_sure);
    
    do{
        if (inventory_Fido[indexItemSelected].stock < numberOfPurchase){
            printf("\nYour request number is more than stock.");
            printf("FYI the number of stock is %d.\n", inventory_Fido[indexItemSelected].stock);
        }

        printf("Please enter the number of purchase as this item: ");
        scanf("%d", &numberOfPurchase);
    } while (inventory_Fido[indexItemSelected].stock < numberOfPurchase);
    
    if (buy_sure == 0){ /*This is a condition for the user for the last step of the purchase process.*/
        inventory_Fido[indexItemSelected].stock = inventory_Fido[indexItemSelected].stock - numberOfPurchase;
        printf("\nCongratulation you bought %d numbers of this item.", numberOfPurchase);
        enterFinalData();
    }
    
}

void returnItemProcess(){ /*This is the function it related to switch 4 of main menu*/
    int select_Code, return_sure, indexItemSelected, numberOfReturn = 0;
    if( file == NULL ){
        printf( "The inventory file is not open. " ) ;
        PopulateTheInventory();
    }
    printf("Please enter your final return code: ");
    scanf("%d", &select_Code);
    header_print();
    
    for (int i = 0; i <= k; i++){ /*print on screen all the inventory*/
    
        if (inventory_Fido[i].code == select_Code){
            indexItemSelected = i;
            printf("|%d |%s | %s |  %f |  %d | %f | %d | %d | %d | %d|\n",  inventory_Fido[i].code,
                                                                            strncat ( inventory_Fido[i].brand, source, (11-strlen(inventory_Fido[i].brand))),
                                                                            strncat ( inventory_Fido[i].model, source, (11-strlen(inventory_Fido[i].model))), 
                                                                            inventory_Fido[i].screen,
                                                                            inventory_Fido[i].memory, 
                                                                            inventory_Fido[i].camera,
                                                                            inventory_Fido[i].price[1], 
                                                                            inventory_Fido[i].price[2],
                                                                            inventory_Fido[i].price[3],
                                                                            inventory_Fido[i].stock);
        break;
        }   
    }
    printf("---------------------------------------------------------------------------------------\n");
    printf("If you are sure about the code. Please enter 0 : ");
    scanf("%d", &return_sure);
    
    do{
        if (inventory_Fido[indexItemSelected].stock < numberOfReturn){
            printf("\nYour request number is more than stock.");
            printf("FYI the number of stock is %d.\n", inventory_Fido[indexItemSelected].stock);
        }

        printf("Please enter the number of return as this item: ");
        scanf("%d", &numberOfReturn);
    } while (inventory_Fido[indexItemSelected].stock < numberOfReturn);
    
    if (return_sure == 0){
        inventory_Fido[indexItemSelected].stock = inventory_Fido[indexItemSelected].stock + numberOfReturn;
        printf("\nYou return %d numbers of this item.", numberOfReturn);
        enterFinalData();
    }
}

void displayItemsInventory(){ /*This is the function it related to switch 5 of main menu*/

    if( file == NULL ){
        printf( "The inventory file is not open. " ) ;
        PopulateTheInventory();
    }
    header_print();
    for (int i = 0; i <= k; i++){

        printf("|%d |%s | %s |  %f |  %d | %f | %d | %d | %d | %d|\n",  inventory_Fido[i].code,
                                                                        strncat ( inventory_Fido[i].brand, source, (11-strlen(inventory_Fido[i].brand))),
                                                                        strncat ( inventory_Fido[i].model, source, (11-strlen(inventory_Fido[i].model))), 
                                                                        inventory_Fido[i].screen,
                                                                        inventory_Fido[i].memory, 
                                                                        inventory_Fido[i].camera,
                                                                        inventory_Fido[i].price[1], 
                                                                        inventory_Fido[i].price[2],
                                                                        inventory_Fido[i].price[3],
                                                                        inventory_Fido[i].stock);
        printf("----------------------------------------------------------------------------------------\n");
    }
    printf("\n");
}

int exitTheSystem(){ /*This is the function for return the number to exit from do/while*/
    int exit_num;
    printf("\nIs there anything i can help you with?\n");
    printf("1. I want to return to main menu.\n");
    printf("2. I want to Exit the program!");
    scanf("%d", &exit_num);
    printf("\n"); 
    return exit_num;
}

int getMainNumber(){  /*This is the function for geting the number of main menu's switch*/
    int get_number;

    printf("please enter the main menu number: ");
    scanf("%d",get_number);

    return get_number;
}

int main(){   /*This is the main menu with 6 switch*/
    int mainMenuNumber;
    int exitFromProgram =1; 

    do{
        mainMenuNumber = printTheMenue();
        switch (mainMenuNumber){
        case 1: 
            k = PopulateTheInventory();
            break;
        case 2:
            displayParticularItems();
            break;
        case 3:
            buyItemProcess();
            break;
        case 4:
            returnItemProcess();
            break;
        case 5:
            displayItemsInventory();
            break;
        case 6:
            exitFromProgram = exitTheSystem();
            break;
        default:
            printf("The number you entered is out of the range!\n");
            printf("Please enter the corect number!\n");
            break;
        }
    } while (exitFromProgram == 1);

    fclose(file);
    printf("\nBye! I hope this was helpful for you.");

    return 0;    
}