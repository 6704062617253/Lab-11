#include <stdio.h>
#include <stdlib.h>

#define NO_SCORE 5
#define NO_STUDENT 10

typedef struct {
    char name[16];
    char surname[20];
    int score[NO_SCORE];
    float total;
} Student;

void readStudentData(Student *);
void saveToFile(Student [], int);
void loadFromFile(Student [], int);
void findTotalScore(Student [], int);
float findAveragePerExam(Student [], int, int);
void findLessThanTen(Student [], int);

int main() {
    Student std[NO_STUDENT];
    int i;

    for (i = 0; i < NO_STUDENT; i++) {
        printf("\n--- Student %d ---\n", i+1);
        readStudentData(&std[i]);
    }

    saveToFile(std, NO_STUDENT);

    loadFromFile(std, NO_STUDENT);

    findTotalScore(std, NO_STUDENT);

    printf("\nAverage score per exam:\n");
    for (i = 0; i < NO_SCORE; i++) {
        printf("\tExam %d: %.2f\n", i+1, findAveragePerExam(std, NO_STUDENT, i));
    }

    findLessThanTen(std, NO_STUDENT);

    return 0;
}

void readStudentData(Student *pStd) {
    int i;
    printf("\tName : ");    scanf("%s", pStd->name);
    printf("\tSurname : "); scanf("%s", pStd->surname);
    for (i = 0; i < NO_SCORE; i++) {
        printf("\tScore %d : ", i+1);
        scanf("%d", &pStd->score[i]);
    }
}

void saveToFile(Student std[], int n) {
    FILE *fp;
    fp = fopen("C:\\Work\\Homework\\Struce Year2\\Lab11\\no2\\std10.dat", "wb");
    if (fp == NULL) {
        printf("Cannot open file!\n");
        return;
    }
    fwrite(std, sizeof(Student), n, fp);
    fclose(fp);
    printf("\nData saved to file.\n");
}

void loadFromFile(Student std[], int n) {
    FILE *fp;
    fp = fopen("C:\\Work\\Homework\\Struce Year2\\Lab11\\no2\\std10.dat", "rb");
    if (fp == NULL) {
        printf("Cannot open file!\n");
        return;
    }
    fread(std, sizeof(Student), n, fp);
    fclose(fp);
    printf("Data loaded from file.\n");
}

void findTotalScore(Student std[], int n) {
    int i, j;
    printf("\nTotal score per student:\n");
    for (i = 0; i < n; i++) {
        std[i].total = 0;
        for (j = 0; j < NO_SCORE; j++) {
            std[i].total += std[i].score[j];
        }
        printf("\t%s %s - Total: %.2f\n", std[i].name, std[i].surname, std[i].total);
    }
}

float findAveragePerExam(Student std[], int n, int examIndex) {
    int i;
    float sum = 0;
    for (i = 0; i < n; i++) {
        sum += std[i].score[examIndex];
    }
    return sum / n;
}

void findLessThanTen(Student std[], int n) {
    int i, j, count;
    printf("\nScore less than 10:\n");
    for (i = 0; i < n; i++) {
        count = 0;
        printf("\t%s %s : ", std[i].name, std[i].surname);
        for (j = 0; j < NO_SCORE; j++) {
            if (std[i].score[j] < 10) {
                printf("Exam %d = %d  ", j+1, std[i].score[j]);
                count++;
            }
        }
        if (count == 0) printf("None");
        printf("\n");
    }
}
