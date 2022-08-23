#include <stdio.h>
#include <string.h>
#include <math.h>

#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Richard Mabvirakare"
#define YEAR 2022

void template();
int baseId(int base);
void Dec2RadixI(int decValue, int radValue);

int main(){
    template();
    int decValue = 1;
    int radValue;
    //Main loop of program
    while(1){
        printf("Enter a decimal number:");
        scanf("%d",&decValue);
        if(decValue < 0) break;
        printf("The number you have entered is %d\nEnter a radix for the converter between 2 and 16: ",decValue);
        scanf("%d",&radValue);
        printf("The radix you have entered is %d\n",radValue);
        Dec2RadixI(decValue,radValue);
    }
    printf("EXIT");

    return 0;
}

//Converts decimal to radix
void Dec2RadixI(int decValue, int redValue){

    static char resultingRadixValue[100] = "", singleRedixVal[100] = "";
    int length, j;
    float getLog = log(decValue)/log(redValue);
    int numOverRad = decValue;
    printf("The log2 of the number is %.2f\n",getLog);
    printf("The integer result of the number divided by %d is %d\n",redValue, numOverRad/redValue);
    printf("The remainder is %d\n", numOverRad%redValue);
    
    while (numOverRad != 0)
    { 
        int rem = numOverRad%redValue;
        numOverRad = numOverRad/redValue;

        //---Method creates a sting of the entire number system based on the user's input for radix 
        char symbols[100] = "",tempS[100] = "";
        
        for(int i = 1;i<=redValue;i++){
            //gets the index for the number system based on the ascii system
            char tb = (char) baseId(i);
            tempS[strlen(tempS)] = tb;

            int length, j;
            length = 0;
            while (symbols[length] != '\0') {
                ++length;
            }

            // concatenate singleRedixVal to resultingRadixValue
            for (j = 0; tempS[j] != '\0'; ++j, ++length) {
                symbols[length] = tempS[j];
            }

            symbols[length] = '\0';
            strncpy(tempS,"",strlen(tempS));
            
        }
        //--- End of method
        //Indexes individual radix values based on their position in the resulting number system (symbols) 
        char symbol = symbols[rem];

        //singleRedixVal = symbol
        sprintf(singleRedixVal, "%c", symbol);

        //---String concatenation
        // store length of resultingRadixValue in the length variable
        length = 0;
        while (resultingRadixValue[length] != '\0') {
            ++length;
        }

        // concatenate singleRedixVal to resultingRadixValue
        for (j = 0; singleRedixVal[j] != '\0'; ++j, ++length) {
            resultingRadixValue[length] = singleRedixVal[j];
        }

        // terminating the resultingRadixValue string
        resultingRadixValue[length] = '\0';

    }
    
    printf("The radix-%d value is %s\n",redValue,strrev(resultingRadixValue));
    strncpy(resultingRadixValue,"",strlen(resultingRadixValue));
}

//Finds the index of the radix value in the number system by utilizing the ascii system
int baseId(int base){
    if (base <= 10){
        base += 47;
    }else{
        base -= 9;
        base += 63;
    }
    return base;
}

//Template Setup
void template(){
    char border[100] = "*****************************\n";
    printf(border);
    printf("%s\n",TITLE);
    printf("Written by: %s\n",AUTHOR);
    printf("Date: %d\n",YEAR);
    printf(border);
}