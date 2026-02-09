/*
    This file will contain reusable functions 
    across all of my C code
*/


/*
    Checks if a string is a numeric string or not
*/
int is_numeric(char str[]){
    int i;
    for (i  = 0; str[i]!= '\0'; i++){
        if (str[i] < '0' || str[i] > '9' ){
            return 0;
        }
    }
    if (i != 0){
        return 1;
    } 
    return 0;
}


/*
    Converts a string of decimal number to an integer
*/
int str_to_int(char str[]){
    int i = 0;
    int acc = 0;

    for (; str[i] != '\0'; i++){
        acc = (acc * 10) + (str[i] - '0');
    }
    return acc;
}