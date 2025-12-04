#include <stdio.h>

FILE *fptr;

void addEntry();
void viewEntries();

int main()
{
    int key;
    printf("Welcome to p_manager\n");
    printf("Please choose your action\n");

    printf("1 - Add Entry\n2 - View Entries\n");

    scanf("%d", &key);

    switch (key)
    {
    case 1:
        addEntry();
        break;
    case 2:
        viewEntries();
        break;
    default:
        break;
    }
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

void viewEntries()
{
    printf("-- Loading the entries --\n");

    char entries[100];

    fptr = fopen("data.txt", "r");

    printf("Entries\n");

    while (fgets(entries, 100, fptr))
    {
        printf("%s", entries);
    }

    fclose(fptr);
}
