#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>

#define max 50
#define red "\x1b[31m"
#define green "\x1b[32m"
#define blue "\x1b[34m"
#define reset "\x1b[0m"

// Record 
typedef struct {
    char name [50], gender [10];
    float grade [3], average;
    int age, id, active;
} record; 

record Student [max];

// Global variables
int total = 0;
char arq_name [15];

int main () {
    show_menu ();
}

// Procedure
void show_menu () {
    int command;

    do {
        system ("cls");
        printf ("Student Registration\n");
        printf ("-----------------------------");
        printf ("\n1 - Student Register");
        printf ("\n2 - Student Search");
        printf ("\n3 - List Student");
        printf ("\n4 - Save/Open External Register\n");

        printf ("\n0 - Close Program\n\n>> ");
        scanf ("%d", &command);
        getchar ();

        switch (command) {
            case 0:
                exit (0);
            break;

            case 1:
                student_registration ();
            break;

            case 2:
                search ();
            break;

            case 3:
                list_menu ();
            break;

            default:
            printf (red "Error! invalid command\n" reset);
            system ("pause");
            show_menu ();
            break;
        }

    } while (command != 0);
}

void student_registration () {
    char name [50], gender [10];
    float grade [3], average;
    int age, id, on, command = 1;

    do {
        system ("cls");
        printf ("Student Registration\n");
	    printf ("-----------------------------\n");
        printf ("Type your name: "); fgets (name, sizeof(name),stdin);
        printf ("\nType your registration: "); scanf ("%d", & id);
        printf ("\nType your age: "); scanf ("%d", & age); getchar ();
        printf ("\nType your gender: "); fgets (gender, sizeof(gender),stdin);
        printf ("\ninsert your first grade: "); scanf ("%f", & grade [0]);
        printf ("\ninsert your second grade: "); scanf ("%f", & grade [1]);
        printf ("\ninsert your third grade: "); scanf ("%f", & grade [2]);

        for (int i = 0; i < max; i++){
            if (Student[i].active == 0) {
                
                Student [i].grade [0] = grade [0];
                Student [i].grade [1] = grade [1];
                Student [i].grade [2] = grade [2];
                Student [i].id = id;
                Student [i].age = age;
				strcpy (Student [i].name, name);
				strcpy (Student [i].gender, gender);
				Student [i].active = 1;
				total ++;
				break;	
			}
        }
        system ("cls");
        printf (green "Congratulations, you registered the student " reset "%s" , name);
        printf ("\n1 - New Register\n");
        printf ("0 - Main Menu\n");
        printf ("\n>> "); scanf ("%d", &command);
        getchar ();
        
        switch (command) {
            case 0:
                show_menu ();
            break;

            case 1:
                student_registration ();
            break;
    
            default:
            printf (red "Error! invalid command\n" reset);
            system ("pause");
            show_menu ();
            break;
        }
    } while (command != 0);
}

void search () {
    int id, command, place;
    bool exist;

    system ("cls");

    printf ("Student Search\n");
    printf ("-----------------------------\n");
    printf ("Search by ID: "); scanf ("%d", & id);

    if (total == 0) {
        printf ("-----------------------------\n");
        
        printf (red "Empty system");
        printf ("\nPlease register a new student\n" reset);

        printf ("\n1 - Register new student\n");
        printf ("0 - Back to main menu\n");
        printf ("\n>> "); scanf ("%d", & command); 
        getchar ();
        
        switch (command) {
            case 1:
                student_registration ();
            break;

            case 0:
                show_menu ();
            break;

            default:
            printf (red "Error! invalid command\n" reset);
            system ("pause");
            show_menu ();
            break;
        }
    } else {
        for (int i = 0; i < max; i++) {
            if (id == Student [i].id) {
                place = i;
                exist = true;
            }
        }
        
        for (int i = 0; i < max; i++) {
            if (exist == true && id == Student [i].id) {
                printf ("-----------------------------\n");
                printf ("Nome: %s", Student [i].name);
                printf ("ID: %d", Student [i].id);
                printf ("\nAge: %d", Student [i].age);
                printf ("\nGender: %s", Student [i].gender);
                printf ("First grade: %.2f", Student [i].grade[0]);
                printf ("\nSecond grade: %.2f", Student [i].grade[1]);
                printf ("\nThird grade: %.2f", Student [i].grade[2]);
                printf ("\n-----------------------------\n");
                printf ("\n1 - New search\n");
                printf ("0 - Main menu\n");
                printf ("\n>> "); scanf ("%d", &command);
                
                switch (command) {
                case 1:
                    search ();
                break;

                case 0:
                    show_menu ();
                break;

                default:
                    printf (red "Error! invalid command\n" reset);
                    system ("pause");
                    show_menu ();
                break;
                }
            } else if (exist == false) {
                printf ("-----------------------------\n");
                printf (red "Student not found\n" reset);
                printf ("\n1 - Register new student\n");
                printf ("0 - Back to main menu\n");
        
                printf ("\n>> "); scanf ("%d", & command); 
                getchar ();
        
                switch (command) {
                    case 1:
                        student_registration ();
                    break;

                    case 0:
                        show_menu ();
                    break;

                    default:
                        printf (red "Error! invalid command\n" reset);
                        system ("pause");
                        show_menu ();
                    break;
                }
            }
        }
    }
}

void list_menu () {
    int command;
    
    system ("cls");
    printf ("Students List\n");
	printf ("-----------------------------\n");
    printf ("1 - Students Aproved\n");
    printf ("2 - Students Reproved\n");

    printf ("\n0 - Close Program\n\n>> ");
    scanf ("%d", &command);
    getchar ();
}