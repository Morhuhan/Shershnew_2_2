#include <stdio.h>
#include <malloc.h>


// выделяет память, возвращает указатель на неё
double* set_memory (int flag, double* a, int size_a, int old_size_a) {
    
    double* tmp;

    if (flag == 0) {  // Для первой итерации

        return (double*)calloc(size_a, sizeof(double));

    }

    else {    // Для последующих итераций

        if ((size_a - old_size_a) > 0) {  // Если массив стал больше
            
            tmp = (double*)realloc(a, size_a * sizeof(double));

            if (tmp == NULL) {  // Пытаемся выделить память, если не получилось - вернуть 0
                puts("Memory allocation error!");
                return 0;
            }

            else {  // если получилось выделить память - вернуть указатель на неё
 
                a = tmp;

                for (int i = old_size_a; i < size_a; i++) {

                    *(a + i) = 0;

                    printf("%d\n", i);
                }

                return a;

            }

        }

        else {   // если массив стал меньше

            return (double*)realloc(a, size_a * sizeof(double));

        }

    }

}


// Заполняет массив a
void write (double* a, int size_a) {

    for (int i = 0; i < size_a; i++) {

        printf("Enter the number\n"); 

        scanf("%lf", (a + i));
    }

}

// Выводит массив a на экран
int view (double* a, int size_a) {

    for (int i = 0; i < size_a; i++) {
        printf("%lf ", *(a+i));
    }

}



void show_menu () {
    printf("\n1 - size of array\n");  
    printf("2 - number to write\n");  
    printf("3 - view\n");  
    printf("0 - Exit\n");  
}

void main(void) {

double* a;

int size_a;
int old_size_a;

double number;
int key;
int flag = 0;

	do {

		show_menu();

		scanf("%d", &key);

		switch (key) {

		case 0:
			break;

		case 1:

            if (flag != 1) {   // Для первой итерации

                printf("Enter the size of array\n");  
                scanf("%d", &size_a);

                a = set_memory(flag, a, size_a, old_size_a);

                flag = 1;
            }

            else {  // Для последующих итераций

                old_size_a = size_a;

                printf("Enter the size of array\n");  
                scanf("%d", &size_a);

                printf("size a = %d\n old_size_a = %d\n", size_a, old_size_a);

                a = set_memory(flag, a, size_a, old_size_a);

            }

			break;

		case 2:

            write(a, size_a);

			break;

		case 3:
            view(a, size_a);
			break;

		default:
			printf("Incorrect operation");
			break;
		}

	} while (key != 0);
    
}
