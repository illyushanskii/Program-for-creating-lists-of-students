#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <Windows.h>
#define N 10
#define STRING 40

struct BIRTHDAY {
    int day;
    char month[STRING];
    int year;
};

struct ADDRESS {
    int post;
    char country[STRING];
    char city[STRING];
    char street[STRING];
    char house[STRING];
    int apartment;
};

struct EDU_INFO {
    char name[STRING];
    int course;
    char group[STRING];
    double mark;
    char speciality[STRING];
};

typedef struct {
    int id;
    char lastName[STRING];
    char firstName[STRING];
    char middleName[STRING];
    char sex[2];
    char phoneNum[STRING];
    struct BIRTHDAY bd;
    struct ADDRESS adr;
    struct EDU_INFO edu;
} Student;

void showArr(Student* massive, int num);
void writeFile(Student* massive, int num, int id);
FILE* openFile() {
    FILE* file;
    fopen_s(&file, "searchHistory.txt", "a");
    if (file == NULL) {
        puts("Failed to open file \n");
        exit(1);
    }
    return file;
}
void noSearch() {
    FILE* file = openFile();
    fprintf(file, "No search results\n");
    fclose(file);
}
void writeHistory(Student student) {
    FILE* file = openFile();
    fprintf(file, "%d) %s %s %d\n", student.id, student.lastName, student.firstName, student.bd.year);
    fclose(file);
}

void showStudent(Student student)
{
    printf("\n%d) %s  %s  %s | %s |  %d  %s  %d | %s |\n  ���.%d  �.%s  �.%s  ���.%s  ���.%s  ��.%d |\n  ��� %s  %d�.  %s��.  %.2lf�.  %s����. |\n", student.id, student.lastName,
        student.firstName, student.middleName, student.sex, student.bd.day, student.bd.month, student.bd.year, student.phoneNum, student.adr.post,
        student.adr.country, student.adr.city, student.adr.street, student.adr.house, student.adr.apartment, student.edu.name, student.edu.course,
        student.edu.group, student.edu.mark, student.edu.speciality);
}
void editShow(Student student)
{
    printf("\n1)%s\n2)%s\n3)%s\n4)C���� %s\n5)���� ���. %d  %s  %d\n6)���.%s\n7)���.%d\n8)��.%s\n9)�.%s\n10)���.%s\n11)���.%s\n12)��.%d\n13)���: %s\n14)%d�.\n15)%s��.\n16)%.2lf �.\n17)����. %s\n", student.lastName,
        student.firstName, student.middleName, student.sex, student.bd.day, student.bd.month, student.bd.year, student.phoneNum, student.adr.post,
        student.adr.country, student.adr.city, student.adr.street, student.adr.house, student.adr.apartment, student.edu.name, student.edu.course,
        student.edu.group, student.edu.mark, student.edu.speciality);
}

//������� ����������

void sortLast(Student* massive, int* num, int id)
{
    printf("\n���������� �� �������� ��������:\n");
    int number = *num;
    Student temp;
    for (int i = 0; i <= number; i++)
        for (int j = number - 1; j > i; j--)
            if (strcmp(massive[j].lastName, massive[j - 1].lastName) < 0)
            {
                temp = massive[j];
                massive[j] = massive[j - 1];
                massive[j - 1] = temp;
            }
    writeFile(massive, number, id);
    showArr(massive, number);
}

void sortFirst(Student* massive, int* num, int id)
{
    printf("\n���������� �� ��'�� ��������:\n");
    int number = *num;
    Student temp;
    for (int i = 0; i <= number; i++)
        for (int j = number - 1; j > i; j--)
            if (strcmp(massive[j].firstName, massive[j - 1].firstName) < 0)
            {
                temp = massive[j];
                massive[j] = massive[j - 1];
                massive[j - 1] = temp;
            }
    writeFile(massive, number, id);
    showArr(massive, number);
}

void sortMiddle(Student* massive, int* num, int id)
{
    printf("\n���������� �� ��-������� ��������:\n");
    int number = *num;
    Student temp;
    for (int i = 0; i <= number; i++)
        for (int j = number - 1; j > i; j--)
            if (strcmp(massive[j].middleName, massive[j - 1].middleName) < 0)
            {
                temp = massive[j];
                massive[j] = massive[j - 1];
                massive[j - 1] = temp;
            }
    writeFile(massive, number, id);
    showArr(massive, number);
}

void sortSex(Student* massive, int* num, int id)
{
    printf("\n���������� �� ������ ��������:\n");
    int number = *num;
    Student temp;
    for (int i = 0; i <= number; i++)
        for (int j = number - 1; j > i; j--)
            if (strcmp(massive[j].sex, massive[j - 1].sex) < 0)
            {
                temp = massive[j];
                massive[j] = massive[j - 1];
                massive[j - 1] = temp;
            }
    writeFile(massive, number, id);
    showArr(massive, number);
}

void sortDay(Student* massive, int* num, int id)
{
    printf("\n���������� �� ���� ���������� ��������:\n");
    int number = *num;
    Student temp;
    for (int i = 0; i <= number; i++)
        for (int j = number - 1; j > i; j--)
            if (massive[j].bd.day < massive[j - 1].bd.day)
            {
                temp = massive[j];
                massive[j] = massive[j - 1];
                massive[j - 1] = temp;
            }
    writeFile(massive, number, id);
    showArr(massive, number);
}

void sortMonth(Student* massive, int* num, int id)
{
    printf("\n���������� �� ������ ���������� ��������:\n");
    int number = *num;
    Student temp;
    for (int i = 0; i <= number; i++)
        for (int j = number - 1; j > i; j--)
            if (strcmp(massive[j].bd.month, massive[j - 1].bd.month) < 0)
            {
                temp = massive[j];
                massive[j] = massive[j - 1];
                massive[j - 1] = temp;
            }
    writeFile(massive, number, id);
    showArr(massive, number);
}

void sortYear(Student* massive, int* num, int id)
{
    printf("\n���������� �� ����� ���������� ��������:\n");
    int number = *num;
    Student temp;
    for (int i = 0; i <= number; i++)
        for (int j = number - 1; j > i; j--)
            if (massive[j].bd.year < massive[j - 1].bd.year)
            {
                temp = massive[j];
                massive[j] = massive[j - 1];
                massive[j - 1] = temp;
            }
    writeFile(massive, number, id);
    showArr(massive, number);
}

void sortPhone(Student* massive, int* num, int id)
{
    printf("\n���������� �� ��������� ��������:\n");
    int number = *num;
    Student temp;
    for (int i = 0; i <= number; i++)
        for (int j = number - 1; j > i; j--)
            if (strcmp(massive[j].phoneNum, massive[j - 1].phoneNum) < 0)
            {
                temp = massive[j];
                massive[j] = massive[j - 1];
                massive[j - 1] = temp;
            }
    writeFile(massive, number, id);
    showArr(massive, number);
}

void sortPost(Student* massive, int* num, int id)
{
    printf("\n���������� �� �������� �������� ��������:\n");
    int number = *num;
    Student temp;
    for (int i = 0; i <= number; i++)
        for (int j = number - 1; j > i; j--)
            if (massive[j].adr.post < massive[j - 1].adr.post)
            {
                temp = massive[j];
                massive[j] = massive[j - 1];
                massive[j - 1] = temp;
            }
    writeFile(massive, number, id);
    showArr(massive, number);
}

void sortCountry(Student* massive, int* num, int id)
{
    printf("\n���������� �� ������ ��������:\n");
    int number = *num;
    Student temp;
    for (int i = 0; i <= number; i++)
        for (int j = number - 1; j > i; j--)
            if (strcmp(massive[j].adr.country, massive[j - 1].adr.country) < 0)
            {
                temp = massive[j];
                massive[j] = massive[j - 1];
                massive[j - 1] = temp;
            }
    writeFile(massive, number, id);
    showArr(massive, number);
}

void sortCity(Student* massive, int* num, int id)
{
    printf("\n���������� �� ����� ��������:\n");
    int number = *num;
    Student temp;
    for (int i = 0; i <= number; i++)
        for (int j = number - 1; j > i; j--)
            if (strcmp(massive[j].adr.city, massive[j - 1].adr.city) < 0)
            {
                temp = massive[j];
                massive[j] = massive[j - 1];
                massive[j - 1] = temp;
            }
    writeFile(massive, number, id);
    showArr(massive, number);
}

void sortStreet(Student* massive, int* num, int id)
{
    printf("\n���������� �� ������� ��������:\n");
    int number = *num;
    Student temp;
    for (int i = 0; i <= number; i++)
        for (int j = number - 1; j > i; j--)
            if (strcmp(massive[j].adr.street, massive[j - 1].adr.street) < 0)
            {
                temp = massive[j];
                massive[j] = massive[j - 1];
                massive[j - 1] = temp;
            }
    writeFile(massive, number, id);
    showArr(massive, number);
}

void sortHouse(Student* massive, int* num, int id)
{
    printf("\n���������� �� �������� ��������:\n");
    int number = *num;
    Student temp;
    for (int i = 0; i <= number; i++)
        for (int j = number - 1; j > i; j--)
            if (strcmp(massive[j].adr.house, massive[j - 1].adr.house) < 0)
            {
                temp = massive[j];
                massive[j] = massive[j - 1];
                massive[j - 1] = temp;
            }
    writeFile(massive, number, id);
    showArr(massive, number);
}

void sortApartment(Student* massive, int* num, int id)
{
    printf("\n���������� �� ��������� ��������:\n");
    int number = *num;
    Student temp;
    for (int i = 0; i <= number; i++)
        for (int j = number - 1; j > i; j--)
            if (massive[j].adr.apartment < massive[j - 1].adr.apartment)
            {
                temp = massive[j];
                massive[j] = massive[j - 1];
                massive[j - 1] = temp;
            }
    writeFile(massive, number, id);
    showArr(massive, number);
}

void sortName(Student* massive, int* num, int id)
{
    printf("\n���������� �� ������ ��� ��������:\n");
    int number = *num;
    Student temp;
    for (int i = 0; i <= number; i++)
        for (int j = number - 1; j > i; j--)
            if (strcmp(massive[j].edu.name, massive[j - 1].edu.name) < 0)
            {
                temp = massive[j];
                massive[j] = massive[j - 1];
                massive[j - 1] = temp;
            }
    writeFile(massive, number, id);
    showArr(massive, number);
}

void sortCourse(Student* massive, int* num, int id)
{
    printf("\n���������� �� ������ ��������:\n");
    int number = *num;
    Student temp;
    for (int i = 0; i <= number; i++)
        for (int j = number - 1; j > i; j--)
            if (massive[j].edu.course < massive[j - 1].edu.course)
            {
                temp = massive[j];
                massive[j] = massive[j - 1];
                massive[j - 1] = temp;
            }
    writeFile(massive, number, id);
    showArr(massive, number);
}

void sortGroup(Student* massive, int* num, int id)
{
    printf("\n���������� �� ������ ��������:\n");
    int number = *num;
    Student temp;
    for (int i = 0; i <= number; i++)
        for (int j = number - 1; j > i; j--)
            if (strcmp(massive[j].edu.group, massive[j - 1].edu.group) < 0)
            {
                temp = massive[j];
                massive[j] = massive[j - 1];
                massive[j - 1] = temp;
            }
    writeFile(massive, number, id);
    showArr(massive, number);
}

void sortMark(Student* massive, int* num, int id)
{
    printf("\n���������� �� ������� ����� ��������:\n");
    int number = *num;
    Student temp;
    for (int i = 0; i <= number; i++)
        for (int j = number - 1; j > i; j--)
            if (massive[j].edu.mark < massive[j - 1].edu.mark)
            {
                temp = massive[j];
                massive[j] = massive[j - 1];
                massive[j - 1] = temp;
            }
    writeFile(massive, number, id);
    showArr(massive, number);
}

void sortSpeciality(Student* massive, int* num, int id)
{
    printf("\n���������� �� ������������ ��������:\n");
    int number = *num;
    Student temp;
    for (int i = 0; i <= number; i++)
        for (int j = number - 1; j > i; j--)
            if (strcmp(massive[j].edu.speciality, massive[j - 1].edu.speciality) < 0)
            {
                temp = massive[j];
                massive[j] = massive[j - 1];
                massive[j - 1] = temp;
            }
    writeFile(massive, number, id);
    showArr(massive, number);
}
//������� ������

void searchLast(Student* massive, int* num) {
    char search[N];
    int number = *num;
    printf("����� �� ��������:");
    scanf_s("%s", search, N);
    FILE* file = openFile();
    fprintf(file, "Search for a lastname '%s'\n", search);
    fclose(file);

    int found = 0;
    for (int inx1 = 0; inx1 < number; inx1++) {
        if (strncmp(massive[inx1].lastName, search, strlen(search)) == 0) {
            if (!found) {
                puts("\nid) ������� ��'� ��-������� | ����� | ���� ����� �� | ���. |\n ����. ���. ����� ���� ������ ������� �������� |\n ��� ���� ����� ���. ��� ������������ |");
            }
            found = 1;
            writeHistory(massive[inx1]);
            showStudent(massive[inx1]);
        }
    }

    if (!found) {
        printf("\n����� �� �������� '%s' �� ��� ����������.\n", search);
        noSearch();
    }
}
void searchFirst(Student* massive, int* num) {
    char search[N];
    int number = *num;
    printf("����� �� ��'��:");
    scanf_s("%s", search, N);
    FILE* file = openFile();
    fprintf(file, "Search for a firstname '%s'\n", search);
    fclose(file);
    int found = 0;
    for (int inx1 = 0; inx1 < number; inx1++) {
        if (strncmp(massive[inx1].firstName, search, strlen(search)) == 0) {
            if (!found) {
                puts("\nid) ������� ��'� ��-������� | ����� | ���� ����� �� | ���. |\n ����. ���. ����� ���� ������ ������� �������� |\n ��� ���� ����� ���. ��� ������������ |");
            }
            found = 1;
            writeHistory(massive[inx1]);
            showStudent(massive[inx1]);
        }
    }

    if (!found) {
        printf("\n����� �� ��'�� '%s' �� ��� ����������.\n", search);
        noSearch();
    }
}

void searchMiddle(Student* massive, int* num) {
    char search[N];
    int number = *num;
    printf("����� �� ��-�������:");
    scanf_s("%s", search, N);
    FILE* file = openFile();
    fprintf(file, "Search for a middlename '%s'\n", search);
    fclose(file);
    int found = 0;
    for (int inx1 = 0; inx1 < number; inx1++) {
        if (strncmp(massive[inx1].middleName, search, strlen(search)) == 0) {
            if (!found) {
                puts("\nid) ������� ��'� ��-������� | ����� | ���� ����� �� | ���. |\n ����. ���. ����� ���� ������ ������� �������� |\n ��� ���� ����� ���. ��� ������������ |");
            }
            found = 1;
            writeHistory(massive[inx1]);
            showStudent(massive[inx1]);
        }
    }

    if (!found) {
        printf("\n����� �� ��-������� '%s' �� ��� ����������.\n", search);
        noSearch();
    }
}

void searchSex(Student* massive, int* num) {
    char search[2];
    int number = *num;
    printf("����� �� ������:");
    scanf_s("%s", search, 2);
    search[1] = '\0';
    FILE* file = openFile();
    fprintf(file, "Search for a sex '%s'\n", search);
    fclose(file);
    int found = 0;
    for (int inx1 = 0; inx1 < number; inx1++) {
        if (massive[inx1].sex[0] == search[0]) {
            if (found == 0) {
                puts("\nid) ������� ��'� ��-������� | ����� | ���� ����� �� | ���. |\n ����. ���. ����� ���� ������ ������� �������� |\n ��� ���� ����� ���. ��� ������������ |");
            }
            found = 1;
            writeHistory(massive[inx1]);
            showStudent(massive[inx1]);
        }
    }
    if (!found) {
        printf("\n����� �� ������ '%s' �� ��� ����������.\n", search);
        noSearch();
    }
}

void searchDay(Student* massive, int* num) {
    int start;
    int finish;
    int number = *num;
    printf("����� �� ����� ����������:");
    do {
        printf("\n������ ��� ������ �� ��:");
        scanf_s("%d%d", &start, &finish);
    } while (start < 1 || start > 31 || finish < 1 || finish > 31);

    if (start > finish) {
        int copy = finish;
        finish = start;
        start = copy;
    }

    FILE* file = openFile();
    fprintf(file, "Search for the date of birth from '%d' to '%d'\n", start, finish);
    fclose(file);
    int found = 0;
    for (int inx1 = 0; inx1 < number; inx1++) {
        if (massive[inx1].bd.day >= start && massive[inx1].bd.day <= finish) {
            if (found == 0) {
                puts("\nid) ������� ��'� ��-������� | ����� | ���� ����� �� | ���. |\n ����. ���. ����� ���� ������ ������� �������� |\n ��� ���� ����� ���. ��� ������������ |");
            }
            found = 1;
            writeHistory(massive[inx1]);
            showStudent(massive[inx1]);
        }
    }
    if (!found) {
        printf("\n����� �� ����� ���������� �� '%d' �� '%d' �� ��� ����������.\n", start, finish);
        noSearch();
    }
}

void searchMonth(Student* massive, int* num) {
    char search[N];
    int number = *num;
    printf("����� �� ������ ����������:");
    scanf_s("%s", search, N);
    FILE* file = openFile();
    fprintf(file, "Search for a month of birth '%s'\n", search);
    fclose(file);
    int found = 0;
    for (int inx1 = 0; inx1 < number; inx1++) {
        if (strncmp(massive[inx1].bd.month, search, strlen(search)) == 0) {
            if (!found) {
                puts("\nid) ������� ��'� ��-������� | ����� | ���� ����� �� | ���. |\n ����. ���. ����� ���� ������ ������� �������� |\n ��� ���� ����� ���. ��� ������������ |");
            }
            found = 1;
            writeHistory(massive[inx1]);
            showStudent(massive[inx1]);
        }
    }

    if (!found) {
        printf("\n����� �� ������ ���������� '%s' �� ��� ����������.\n", search);
        noSearch();
    }
}

void searchYear(Student* massive, int* num) {
    int start;
    int finish;
    int number = *num;
    printf("����� �� ����� ����������:");
    do {
        printf("\n������ ��� ������ �� ��:");
        scanf_s("%d%d", &start, &finish);
    } while (start < 1900 || start > 2100 || finish < 1900 || finish > 2100);

    if (start > finish) {
        int copy = finish;
        finish = start;
        start = copy;
    }
    FILE* file = openFile();
    fprintf(file, "Search for the year of birth from '%d' to '%d'\n", start, finish);
    fclose(file);
    int found = 0;
    for (int inx1 = 0; inx1 < number; inx1++) {
        if (massive[inx1].bd.year >= start && massive[inx1].bd.year <= finish) {
            if (found == 0) {
                puts("\nid) ������� ��'� ��-������� | ����� | ���� ����� �� | ���. |\n ����. ���. ����� ���� ������ ������� �������� |\n ��� ���� ����� ���. ��� ������������ |");
            }
            found = 1;
            writeHistory(massive[inx1]);
            showStudent(massive[inx1]);
        }
    }
    if (!found) {
        printf("\n����� �� ����� ���������� �� '%d' �� '%d' �� ��� ����������.\n", start, finish);
        noSearch();
    }
}

void searchPhone(Student* massive, int* num) {
    char search[N];
    int number = *num;
    printf("����� �� ������� ��������:");
    scanf_s("%s", search, N);
    FILE* file = openFile();
    fprintf(file, "Search for a phone number '%s'\n", search);
    fclose(file);
    int found = 0;

    for (int inx1 = 0; inx1 < number; inx1++) {
        if (strncmp(massive[inx1].phoneNum, search, strlen(search)) == 0) {
            if (!found) {
                puts("\nid) ������� ��'� ��-������� | ����� | ���� ����� �� | ���. |\n ����. ���. ����� ���� ������ ������� �������� |\n ��� ���� ����� ���. ��� ������������ |");
            }
            found = 1;
            writeHistory(massive[inx1]);
            showStudent(massive[inx1]);
        }
    }

    if (!found) {
        printf("\n����� �� ������� �������� '%s' �� ��� ����������.\n", search);
        noSearch();
    }
}

void searchPost(Student* massive, int* num) {
    int start;
    int finish;
    int number = *num;
    printf("����� �� �������� ��������:");
    do {
        printf("\n������ ��� ������ �� ��:");
        scanf_s("%d%d", &start, &finish);
    } while (start < 1 || start > 99999 || finish < 1 || finish > 99999);

    if (start > finish) {
        int copy = finish;
        finish = start;
        start = copy;
    }
    FILE* file = openFile();
    fprintf(file, "Search for the post id from '%d' to '%d'\n", start, finish);
    fclose(file);
    int found = 0;
    for (int inx1 = 0; inx1 < number; inx1++) {
        if (massive[inx1].adr.post >= start && massive[inx1].adr.post <= finish) {
            if (found == 0) {
                puts("\nid) ������� ��'� ��-������� | ����� | ���� ����� �� | ���. |\n ����. ���. ����� ���� ������ ������� �������� |\n ��� ���� ����� ���. ��� ������������ |");
            }
            found = 1;
            writeHistory(massive[inx1]);
            showStudent(massive[inx1]);
        }
    }
    if (!found) {
        printf("\n����� �� �������� �������� �� '%d' �� '%d' �� ��� ����������.\n", start, finish);
        noSearch();
    }
}

void searchCountry(Student* massive, int* num) {
    char search[N];
    int number = *num;
    printf("����� �� ������:");
    scanf_s("%s", search, N);
    int found = 0;
    FILE* file = openFile();
    fprintf(file, "Search for a country '%s'\n", search);
    fclose(file);
    for (int inx1 = 0; inx1 < number; inx1++) {
        if (strncmp(massive[inx1].adr.country, search, strlen(search)) == 0) {
            if (!found) {
                puts("\nid) ������� ��'� ��-������� | ����� | ���� ����� �� | ���. |\n ����. ���. ����� ���� ������ ������� �������� |\n ��� ���� ����� ���. ��� ������������ |");
            }
            found = 1;
            writeHistory(massive[inx1]);
            showStudent(massive[inx1]);
        }
    }
    if (!found) {
        printf("\n����� �� ������ '%s' �� ��� ����������.\n", search);
        noSearch();
    }
}

void searchCity(Student* massive, int* num) {
    char search[N];
    int number = *num;
    printf("����� �� �����:");
    scanf_s("%s", search, N);
    FILE* file = openFile();
    fprintf(file, "Search for a city '%s'\n", search);
    fclose(file);
    int found = 0;

    for (int inx1 = 0; inx1 < number; inx1++) {
        if (strncmp(massive[inx1].adr.city, search, strlen(search)) == 0) {
            if (!found) {
                puts("\nid) ������� ��'� ��-������� | ����� | ���� ����� �� | ���. |\n ����. ���. ����� ���� ������ ������� �������� |\n ��� ���� ����� ���. ��� ������������ |");
            }
            found = 1;
            writeHistory(massive[inx1]);
            showStudent(massive[inx1]);
        }
    }

    if (!found) {
        printf("\n����� �� ����� '%s' �� ��� ����������.\n", search);
        noSearch();
    }
}

void searchStreet(Student* massive, int* num) {
    char search[N];
    int number = *num;
    printf("����� �� �������:");
    scanf_s("%s", search, N);
    FILE* file = openFile();
    fprintf(file, "Search for a street '%s'\n", search);
    fclose(file);
    int found = 0;

    for (int inx1 = 0; inx1 < number; inx1++) {
        if (strncmp(massive[inx1].adr.street, search, strlen(search)) == 0) {
            if (!found) {
                puts("\nid) ������� ��'� ��-������� | ����� | ���� ����� �� | ���. |\n ����. ���. ����� ���� ������ ������� �������� |\n ��� ���� ����� ���. ��� ������������ |");
            }
            found = 1;
            writeHistory(massive[inx1]);
            showStudent(massive[inx1]);
        }
    }

    if (!found) {
        printf("\n����� �� ������� '%s' �� ��� ����������.\n", search);
        noSearch();
    }
}

void searchHouse(Student* massive, int* num) {
    char search[N];
    int number = *num;
    printf("����� �� ��������:");
    scanf_s("%s", search, N);
    FILE* file = openFile();
    fprintf(file, "Search for a house '%s'\n", search);
    fclose(file);
    int found = 0;

    for (int inx1 = 0; inx1 < number; inx1++) {
        if (strncmp(massive[inx1].adr.house, search, strlen(search)) == 0) {
            if (!found) {
                puts("\nid) ������� ��'� ��-������� | ����� | ���� ����� �� | ���. |\n ����. ���. ����� ���� ������ ������� �������� |\n ��� ���� ����� ���. ��� ������������ |");
            }
            found = 1;
            writeHistory(massive[inx1]);
            showStudent(massive[inx1]);
        }
    }

    if (!found) {
        printf("\n����� �� �������� '%s' �� ��� ����������.\n", search);
        noSearch();
    }
}

void searchApartment(Student* massive, int* num) {
    int start;
    int finish;
    int number = *num;
    printf("����� �� ���������:");
    do {
        printf("\n������ ��� ������ �� ��:");
        scanf_s("%d%d", &start, &finish);
    } while (start < 1 || start > 1000 || finish < 1 || finish > 1000);

    if (start > finish) {
        int copy = finish;
        finish = start;
        start = copy;
    }
    FILE* file = openFile();
    fprintf(file, "Search for the apartment from '%d' to '%d'\n", start, finish);
    fclose(file);
    int found = 0;
    for (int inx1 = 0; inx1 < number; inx1++) {
        if (massive[inx1].adr.apartment >= start && massive[inx1].adr.apartment <= finish) {
            if (found == 0) {
                puts("\nid) ������� ��'� ��-������� | ����� | ���� ����� �� | ���. |\n ����. ���. ����� ���� ������ ������� �������� |\n ��� ���� ����� ���. ��� ������������ |");
            }
            found = 1;
            writeHistory(massive[inx1]);
            showStudent(massive[inx1]);
        }
    }
    if (!found) {
        printf("\n����� �� ��������� �� '%d' �� '%d' �� ��� ����������.\n", start, finish);
        noSearch();
    }
}

void searchName(Student* massive, int* num) {
    char search[N];
    int number = *num;
    printf("����� �� ������ ���:");
    scanf_s("%s", search, N);
    FILE* file = openFile();
    fprintf(file, "Search for a university name '%s'\n", search);
    fclose(file);
    int found = 0;

    for (int inx1 = 0; inx1 < number; inx1++) {
        if (strncmp(massive[inx1].edu.name, search, strlen(search)) == 0) {
            if (!found) {
                puts("\nid) ������� ��'� ��-������� | ����� | ���� ����� �� | ���. |\n ����. ���. ����� ���� ������ ������� �������� |\n ��� ���� ����� ���. ��� ������������ |");
            }
            found = 1;
            writeHistory(massive[inx1]);
            showStudent(massive[inx1]);
        }
    }

    if (!found) {
        printf("\n����� �� ������ ��� '%s' �� ��� ����������.\n", search);
        noSearch();
    }
}

void searchCourse(Student* massive, int* num) {
    int start;
    int finish;
    int number = *num;
    printf("����� �� ������:");
    do {
        printf("\n������ ��� ������ �� ��:");
        scanf_s("%d%d", &start, &finish);
    } while (start < 1 || start > 6 || finish < 1 || finish > 6);

    if (start > finish) {
        int copy = finish;
        finish = start;
        start = copy;
    }
    FILE* file = openFile();
    fprintf(file, "Search for the course from '%d' to '%d'\n", start, finish);
    fclose(file);
    int found = 0;
    for (int inx1 = 0; inx1 < number; inx1++) {
        if (massive[inx1].edu.course >= start && massive[inx1].edu.course <= finish) {
            if (found == 0) {
                puts("\nid) ������� ��'� ��-������� | ����� | ���� ����� �� | ���. |\n ����. ���. ����� ���� ������ ������� �������� |\n ��� ���� ����� ���. ��� ������������ |");
            }
            found = 1;
            writeHistory(massive[inx1]);
            showStudent(massive[inx1]);
        }
    }
    if (!found) {
        printf("\n����� ��  ������ �� '%d' �� '%d' �� ��� ����������.\n", start, finish);
        noSearch();
    }
}

void searchGroup(Student* massive, int* num) {
    char search[N];
    int number = *num;
    printf("����� �� ������:");
    scanf_s("%s", search, N);
    FILE* file = openFile();
    fprintf(file, "Search for a group '%s'\n", search);
    fclose(file);
    int found = 0;

    for (int inx1 = 0; inx1 < number; inx1++) {
        if (strncmp(massive[inx1].edu.group, search, strlen(search)) == 0) {
            if (!found) {
                puts("\nid) ������� ��'� ��-������� | ����� | ���� ����� �� | ���. |\n ����. ���. ����� ���� ������ ������� �������� |\n ��� ���� ����� ���. ��� ������������ |");
            }
            found = 1;
            writeHistory(massive[inx1]);
            showStudent(massive[inx1]);
        }
    }

    if (!found) {
        printf("\n����� �� ������ '%s' �� ��� ����������.\n", search);
        noSearch();
    }
}

void searchMark(Student* massive, int* num) {
    float start;
    float finish;
    int number = *num;
    printf("����� �� ������� �����:");
    do {
        printf("\n������ ��� ������ �� ��:");
        scanf_s("%f%f", &start, &finish);
    } while (start < 0.0 || start > 100.0 || finish < 0.0 || finish > 100.0);

    if (start > finish) {
        float copy = finish;
        finish = start;
        start = copy;
    }
    FILE* file = openFile();
    fprintf(file, "Search for the mark from '%f' to '%f'\n", start, finish);
    fclose(file);
    int found = 0;
    for (int inx1 = 0; inx1 < number; inx1++) {
        if (massive[inx1].edu.mark >= start && massive[inx1].edu.mark <= finish) {
            if (found == 0) {
                puts("\nid) ������� ��'� ��-������� | ����� | ���� ����� �� | ���. |\n ����. ���. ����� ���� ������ ������� �������� |\n ��� ���� ����� ���. ��� ������������ |");
            }
            found = 1;
            writeHistory(massive[inx1]);
            showStudent(massive[inx1]);
        }
    }
    if (!found) {
        printf("\n����� ��  ������� ����� �� '%.2f' �� '%.2f' �� ��� ����������.\n", start, finish);
        noSearch();
    }
}

void searchSpeciality(Student* massive, int* num) {
    char search[N];
    int number = *num;
    printf("����� �� ������������:");
    scanf_s("%s", search, N);
    FILE* file = openFile();
    fprintf(file, "Search for a speciality '%s'\n", search);
    fclose(file);
    int found = 0;

    for (int inx1 = 0; inx1 < number; inx1++) {
        if (strncmp(massive[inx1].edu.speciality, search, strlen(search)) == 0) {
            if (!found) {
                puts("\nid) ������� ��'� ��-������� | ����� | ���� ����� �� | ���. |\n ����. ���. ����� ���� ������ ������� �������� |\n ��� ���� ����� ���. ��� ������������ |");
            }
            found = 1;
            writeHistory(massive[inx1]);
            showStudent(massive[inx1]);
        }
    }

    if (!found) {
        printf("\n����� �� ������������ '%s' �� ��� ����������.\n", search);
        noSearch();
    }
}
