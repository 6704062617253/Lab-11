#include <stdio.h>
#include <stdlib.h>

void addRecord(char *addName, int addAge);

int main() {
    char name[64]; int age;
    printf("Enter name: "); scanf("%s", name);
    printf("Enter age: "); scanf("%d", &age);
    addRecord(name, age);
    return 0;
}

void addRecord(char *addName, int addAge) {
    FILE *fp;
    fp = fopen("C:\\Work\\Homework\\Struce Year2\\Lab11\\no1\\lab11no1.txt", "a");
    if (fp == NULL) {
        printf("Cannot open file!\n");
        return;
    }
    fprintf(fp, "%s %d\n", addName, addAge);
    fclose(fp);
}
