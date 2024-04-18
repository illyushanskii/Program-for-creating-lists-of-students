#include "myLib.h"

Student initStudent(int id) {
    Student student;
    puts("Введіть інформацію про  студента.\n");
    student.id = id;
    printf("Введіть прізвище:");
    scanf_s("%s", student.lastName, STRING);

    printf("Введіть ім'я:");
    scanf_s("%s", student.firstName, STRING);

    printf("Введіть по-батькові:");
    scanf_s("%s", student.middleName, STRING);

    do {
        printf("Введіть дату народження(день,місяць,рік):");
        scanf_s("%d%s%d", &student.bd.day, student.bd.month, STRING, &student.bd.year);
    } while (student.bd.day < 1 || student.bd.day > 31 || student.bd.year < 1900 || student.bd.year > 2100);

    printf("Введіть стать(m - чоловіча,f - жіноча):");
    scanf_s("%s", student.sex, 2);
    student.sex[1] = '\0';

    printf("Введіть адресу:\nКраїна:");
    scanf_s("%s", student.adr.country, STRING);

    printf("Місто:");
    scanf_s("%s", student.adr.city, STRING);

    printf("Вулиця:");
    scanf_s("%s", student.adr.street, STRING);

    printf("Будинок:");
    scanf_s("%s", student.adr.house, STRING);

    do {
        printf("Квартира:");
        scanf_s("%d", &student.adr.apartment);
    } while (student.adr.apartment <= 0);

    do {
        printf("Почтовий індекс:");
        scanf_s("%d", &student.adr.post);
    } while (student.adr.post <= 0);

    printf("Номер телефону:");
    scanf_s("%s", student.phoneNum, STRING);

    printf("Введіть інформацію про навчання:\nНазва ВНЗ : ");
    scanf_s("%s", student.edu.name, STRING);

    do {
        printf("Курс:");
        scanf_s("%d", &student.edu.course);
    } while (student.edu.course <= 0 || student.edu.course > 6);

    printf("Группа:");
    scanf_s("%s", student.edu.group, STRING);

    do {
        printf("Середній бал:");
        scanf_s("%lf", &student.edu.mark);
    } while (student.edu.mark < 0.0 || student.edu.mark > 100.0);

    printf("Спеціальність:");
    scanf_s("%s", student.edu.speciality, STRING);

    return student;
}

Student* initArr(const int number, int id) {
    Student* massive = (Student*)malloc(number * sizeof(Student));

    if (massive == NULL) {
        printf("\nДинамічний масив неіснує.\n");
        return NULL;
    }
    massive[0] = initStudent(id);

    return massive;
}

void showArr(Student* massive, int num)
{
    if (num <= 0) {
        printf("Список пустий!\n");
        return 0;
    }
    puts("id) Прізвище ім'я по-батькові | стать | день місяць рік | тел. |\n пошт. інд. країна місто вулиця будинок квартира |\n ВНЗ курс група сер. бал спеціальність |");

    for (int i = 0; i < num; i++)
    {
        showStudent(massive[i]);
    }
}

void writeFile(Student* massive, int num, int id) {
    FILE* file;
    fopen_s(&file, "students.txt", "w");
    if (file == NULL) {
        puts("Failed to open file \n");
        exit(1);
    }
    fwrite(&num, sizeof(num), 1, file);
    fwrite(&id, sizeof(id), 1, file);
    for (int i = 0; i < num; i++) {
        fwrite(&massive[i], sizeof(massive[i]), 1, file);
    }
    fclose(file);
}

Student* readFile(int* num, int* id) {
    FILE* file;
    fopen_s(&file, "students.txt", "r");
    if (file == NULL) {
        puts("Помилка відкриття файлу \n");
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    if (ftell(file) == 0) {
        printf("Файл пустий, заповніть його!\n");
        fclose(file);
        *id += 1;
        *num += 1;
        int number = *num;
        Student* massive = initArr(number, *id);
        writeFile(massive, number, *id);
        showArr(massive, number);
        return massive;
    }
    else {
        fseek(file, 0, SEEK_SET);
        int idf;
        int number;
        fread_s(&number, sizeof(int), sizeof(int), 1, file);
        fread_s(&idf, sizeof(int), sizeof(int), 1, file);
        *id = idf;
        Student* massive = (Student*)malloc(number * sizeof(Student));
        if (massive == NULL) {
            printf("\nДинамічний масив неіснує.\n");
            exit(1);
        }
        int i = 0;
        while (i < number && fread_s(&massive[i], sizeof(Student), sizeof(Student), 1, file) == 1) {
            i++;
        }

        *num = i;
        fclose(file);
        number = i;

        printf("Зчитано %d студентів із файлу.\n", i);
        showArr(massive, number);
        return massive;
    }
}

Student* delStudent(Student* massive, int choice, int* num, int id) {
    if (choice == 0) {
        return choice;
    }
    int number = *num;
    if (number <= 1) {
        printf("Видалення не можливе!!!\n");
        return massive;
    }

    for (int i = choice - 1; i < number - 1; i++) {
        massive[i] = massive[i + 1];
    }

    *num -= 1;
    number = *num;
    Student* massiveDel = (Student*)malloc(number * sizeof(Student));
    if (massiveDel == NULL) {
        printf("\nДинамічний масив неіснує.\n");
        return 0;
    }
    for (int i = 0; i < number; i++) {
        massiveDel[i] = massive[i];
    }
    free(massive);

    printf("\nВидалено дані %dго студента.\n", choice);
    writeFile(massiveDel, number, id);
    showArr(massiveDel, number);
    return massiveDel;
}

Student* addStudent(Student* massive, int* num, int* id) {
    *id += 1;
    *num += 1;
    int number = *num;
    Student* massiveAdd = (Student*)malloc(number * sizeof(Student));
    if (massiveAdd == NULL) {
        printf("\nДинамічний масив неіснує.\n");
        return 0;
    }
    for (int i = 0; i < number - 1; i++) {
        massiveAdd[i] = massive[i];
    }
    massiveAdd[number - 1] = initStudent(*id);
    free(massive);
    showArr(massiveAdd, number);
    writeFile(massiveAdd, number, *id);
    return massiveAdd;
}


void editStudent(Student* massive, int choice, int* num, int id) {
    if (choice == 0) {
        return ;
    }
    int number = *num;
    int comd;
    printf("Редагування %d студента:", choice);
    editShow(massive[choice - 1]);
    do {
        puts("\nВиберіть рядок який хочете змінити,Повернутися - 0,Змінити повністю - 18");
        scanf_s("%d", &comd);
        switch (comd)
        {
        case 0:
            break;
        case 1:
            printf("Введіть прізвище:");
            scanf_s("%s", massive[choice - 1].lastName, STRING);
            editShow(massive[choice - 1]);
            break;
        case 2:
            printf("Введіть ім'я:");
            scanf_s("%s", massive[choice - 1].firstName, STRING);
            editShow(massive[choice - 1]);
            break;
        case 3:
            printf("Введіть по-батькові:");
            scanf_s("%s", massive[choice - 1].middleName, STRING);
            editShow(massive[choice - 1]);
            break;
        case 4:
            printf("Введіть стать(m - чоловіча,f - жіноча):");
            scanf_s("%s", massive[choice - 1].sex, 2);
            massive[choice - 1].sex[1] = '\0';
            editShow(massive[choice - 1]);
            break;
        case 5:
            do {
                printf("Введіть дату народження(день,місяць,рік):");
                scanf_s("%d%s%d", &massive[choice - 1].bd.day, massive[choice - 1].bd.month, STRING, &massive[choice - 1].bd.year);
            } while (massive[choice - 1].bd.day < 1 || massive[choice - 1].bd.day > 31 || massive[choice - 1].bd.year < 1900);
            editShow(massive[choice - 1]);
            break;
        case 6:
            printf("Номер телефону:");
            scanf_s("%s", massive[choice - 1].phoneNum, STRING);
            editShow(massive[choice - 1]);
            break;

        case 7:
            do {
                printf("Почтовий індекс:");
                scanf_s("%d", &massive[choice - 1].adr.post);
            } while (massive[choice - 1].adr.post <= 0);;
            editShow(massive[choice - 1]);
            break;
        case 8:
            printf("Країна:");
            scanf_s("%s", massive[choice - 1].adr.country, STRING);
            editShow(massive[choice - 1]);
            break;
        case 9:
            printf("Місто:");
            scanf_s("%s", massive[choice - 1].adr.city, STRING);
            editShow(massive[choice - 1]);
            break;
        case 10:
            printf("Вулиця:");
            scanf_s("%s", massive[choice - 1].adr.street, STRING);
            editShow(massive[choice - 1]);
            break;
        case 11:
            printf("Будинок:");
            scanf_s("%s", massive[choice - 1].adr.house, STRING);
            editShow(massive[choice - 1]);
            break;
        case 12:
            do {
                printf("Квартира:");
                scanf_s("%d", &massive[choice - 1].adr.apartment);
            } while (massive[choice - 1].adr.apartment <= 0);
            editShow(massive[choice - 1]);
            break;
        case 13:
            printf("Назва ВНЗ : ");
            scanf_s("%s", massive[choice - 1].edu.name, STRING);
            editShow(massive[choice - 1]);
            break;
        case 14:
            do {
                printf("Курс:");
                scanf_s("%d", &massive[choice - 1].edu.course);
            } while (massive[choice - 1].edu.course <= 0 || massive[choice - 1].edu.course > 6);
            editShow(massive[choice - 1]);
            break;
        case 15:
            printf("Группа:");
            scanf_s("%s", massive[choice - 1].edu.group, STRING);;
            editShow(massive[choice - 1]);
            break;
        case 16:
            do {
                printf("Середній бал:");
                scanf_s("%lf", &massive[choice - 1].edu.mark);
            } while (massive[choice - 1].edu.mark < 0.0 || massive[choice - 1].edu.mark > 100.0);;
            editShow(massive[choice - 1]);
            break;
        case 17:
            printf("Спеціальність:");
            scanf_s("%s", massive[choice - 1].edu.speciality, STRING);
            editShow(massive[choice - 1]);
            break;
        case 18:
            printf("Повна заміна:");
            massive[choice - 1] = initStudent(choice);
            editShow(massive[choice - 1]);
            break;
        default:
            printf("Неправильний вибір!!!");
            break;
        }
    } while (comd != 0);

    writeFile(massive, number, id);
    showArr(massive, number);
}

void searchStudent(Student* massive, int* num) {
    printf("\n1 - прізвище, 2 - ім'я, 3- по-батькові, 4 - стать, 5- день, 6 - місяць, 7 - рік, 8 - тел.");
    printf("\n9 - пошт. інд., 10 - країна, 11 - місто, 12 - вулиця, 13 - будинок,14 - квартира");
    printf("\n15 - ВНЗ, 16 - курс, 17 - група, 18 - сер. бал, 19 - спеціальність\n");
    int choice = 0;
    int flagChoice;
    do {
        printf("Виберіть за яким полем буде пошук:");
        flagChoice = scanf_s("%d", &choice);
        if (flagChoice != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    } while (choice < 1 || choice > 19 || flagChoice != 1);
    switch (choice) {
    case 1:
        searchLast(massive, num);
        break;
    case 2:
        searchFirst(massive, num);
        break;
    case 3:
        searchMiddle(massive, num);
        break;
    case 4:
        searchSex(massive, num);
        break;
    case 5:
        searchDay(massive, num);
        break;
    case 6:
        searchMonth(massive, num);
        break;
    case 7:
        searchYear(massive, num);
        break;
    case 8:
        searchPhone(massive, num);
        break;
    case 9:
        searchPost(massive, num);
        break;
    case 10:
        searchCountry(massive, num);
        break;
    case 11:
        searchCity(massive, num);
        break;
    case 12:
        searchStreet(massive, num);
        break;
    case 13:
        searchHouse(massive, num);
        break;
    case 14:
        searchApartment(massive, num);
        break;
    case 15:
        searchName(massive, num);
        break;
    case 16:
        searchCourse(massive, num);
        break;
    case 17:
        searchGroup(massive, num);
        break;
    case 18:
        searchMark(massive, num);
        break;
    case 19:
        searchSpeciality(massive, num);
        break;
    default:
        printf("Неправильний вибір!!!");
        break;
    }
}

void sortStudent(Student* massive, int* num, int id) {
    printf("\n1 - прізвище, 2 - ім'я, 3- по-батькові, 4 - стать, 5- день, 6 - місяць, 7 - рік, 8 - тел.");
    printf("\n9 - пошт. інд., 10 - країна, 11 - місто, 12 - вулиця, 13 - будинок,14 - квартира");
    printf("\n15 - ВНЗ, 16 - курс, 17 - група, 18 - сер. бал, 19 - спеціальність\n");
    int choice = 0;
    int flagChoice;
    do {
        printf("Виберіть за яким полем буде сортування:");
        flagChoice = scanf_s("%d", &choice);
        if (flagChoice != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    } while (choice < 1 || choice > 19 || flagChoice != 1);
    switch (choice) {
    case 1:
        sortLast(massive, num, id);
        break;
    case 2:
        sortFirst(massive, num, id);
        break;
    case 3:
        sortMiddle(massive, num, id);
        break;
    case 4:
        sortSex(massive, num, id);
        break;
    case 5:
        sortDay(massive, num, id);
        break;
    case 6:
        sortMonth(massive, num, id);
        break;
    case 7:
        sortYear(massive, num, id);
        break;
    case 8:
        sortPhone(massive, num, id);
        break;
    case 9:
        sortPost(massive, num, id);
        break;
    case 10:
        sortCountry(massive, num, id);
        break;
    case 11:
        sortCity(massive, num, id);
        break;
    case 12:
        sortStreet(massive, num, id);
        break;
    case 13:
        sortHouse(massive, num, id);
        break;
    case 14:
        sortApartment(massive, num, id);
        break;
    case 15:
        sortName(massive, num, id);
        break;
    case 16:
        sortCourse(massive, num, id);
        break;
    case 17:
        sortGroup(massive, num, id);
        break;
    case 18:
        sortMark(massive, num, id);
        break;
    case 19:
        sortSpeciality(massive, num, id);
        break;
    default:
        printf("Неправильний вибір!!!");
        break;
    }
}
int Choice(Student* massive, int num, int choice) {
    if (choice == 0) {
        return choice;
    }
    for (int i = 0; i < num; i++) {
        if (massive[i].id == choice) {
            choice = i + 1;
            return choice;
        }
    }
    return -1;
}

int main() {
    SetConsoleOutputCP(1251);
    Student* massiveStr;
    int num = 0;
    int* ptrNum = &num;
    int id = 0;
    int* ptrId = &id;

    massiveStr = readFile(ptrNum, ptrId);
    char command[N];
    int choice;
    int flagChoice;
    int flagEx, flagEd, flagDel, flagAdd, flagSort, flagSearch, errInp;
    do {
        puts("\nВийти - exit 0,Редагувати - edit №student,Видалити - del №student,Додати - add 0,Сортування - sort 0,Пошук - search 0");
        do {
            flagEx = 0; flagEd = 0; flagDel = 0; flagAdd = 0, flagSort = 0, flagSearch = 0, errInp = 0;
            scanf_s("%s", &command, N);
            flagChoice = scanf_s("%d", &choice);
            choice = Choice(massiveStr, num, choice);

            if (strcmp(command, "exit") == 0)
                flagEx++;

            else if (strcmp(command, "edit") == 0)
                flagEd++;

            else if (strcmp(command, "del") == 0)
                flagDel++;

            else if (strcmp(command, "add") == 0)
                flagAdd++;

            else if (strcmp(command, "sort") == 0)
                flagSort++;

            else if (strcmp(command, "search") == 0)
                flagSearch++;

            else {
                errInp++;
                printf("Неправильна команда!\n");
            }
        } while (errInp == 1 || choice < 0 || choice > *ptrNum || flagChoice != 1);

        if (flagEd)
            editStudent(massiveStr, choice, ptrNum, id);

        else if (flagSort)
            sortStudent(massiveStr, ptrNum, id);

        else if (flagSearch)
            searchStudent(massiveStr, ptrNum);

        else if (flagDel)
            massiveStr = delStudent(massiveStr, choice, ptrNum, id);

        else if (flagAdd)
            massiveStr = addStudent(massiveStr, ptrNum, ptrId);

    } while (flagEx != 1);

    free(massiveStr);
    return 0;
}