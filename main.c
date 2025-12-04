#include <stdio.h>

FILE *fptr;

void addEntry();

int main()
{
    addEntry();
    return 0;
}

void addEntry()
{
    printf("-- Adding an entry --\n");
    char userPassword[16];
    char username[16];
    printf("Enter your password and username in order: \n");
    scanf("%s %s", userPassword, username);
    printf("Your password is: %s \n", userPassword);
    printf("Your username is: %s \n", username);

    fptr = fopen("data.txt", "a");

    fprintf(fptr, "User password: %s\n", userPassword);

    fprintf(fptr, "Username: %s\n", username);

    fclose(fptr);

    printf("Entry added\n");
}
