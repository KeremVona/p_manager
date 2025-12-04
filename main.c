#include <stdio.h>

FILE *fptr;

struct entry
{
    char service[100];
    char username[20];
    char password[12];
};

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

    struct entry e1;
    printf("Enter service, username and password in order: \n");

    scanf("%s %s %s", e1.service, e1.username, e1.password);

    printf("Saving service: %s \n", e1.service);
    printf("Saving username: %s \n", e1.username);
    printf("Saving password: %s \n", e1.password);

    fptr = fopen("data.txt", "a");

    fprintf(fptr, "Service: %s\n", e1.service);
    fprintf(fptr, "Username: %s\n", e1.username);
    fprintf(fptr, "User password: %s\n", e1.password);
    fprintf(fptr, "----------\n");

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