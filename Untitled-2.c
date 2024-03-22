#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>

int main () {
    int choice;
    float suhu;
    char suhuawal;
    srand(time(NULL)); // Seed the random number generator

    do {
        do{
        printf("+===========================+\n");
        printf("|       Selamat datang      |\n");
        printf("| di Program Konversi Suhu  |\n");
        printf("+===========================+\n");
        printf("| 1. Petunjuk               |\n");
        printf("| 2. Konversi               |\n");
        printf("| 0. Keluar                 |\n");
        printf("+===========================+\n");
        printf("Silakan pilih tujuan Anda: ");
            scanf("%d", &choice);

            if (choice < 1 || choice > 3) {
                printf("Maaf, input pilihan Anda salah. Silakan pilih kembali\n");
                getchar();
                system("pause");
            }
            system("cls");
        } while (choice <0 || choice > 2);
    }while (choice !=0);

    switch (choice) {
            case 1:
                menuPetunjuk();
                system("pause");
                system("cls");
                break;
            case 2:
                menuKonversi();
				printf("Masukkan jenis suhu awal (R/C/F/K): ");
                getchar();
				while ((scanf("%c", &suhuAwal))!= EOF) {
                    printf("Masukkan suhu: ");
                	scanf("%f", &suhu);
                	getchar(); 
                    suhuAwal = toupper(suhuAwal);
                    switch(suhuAwal) {
                        case 'R':
                            reamur(suhu);
                            break;
                        case 'C':
                            celcius(suhu);
                            break;
                        case 'F':
                            fahrenheit(suhu);
                            break;
                        case 'K':
                            kelvin(suhu);
                            break;
                        default:
                            printf("Input tidak valid. Silakan coba lagi.\n");
                        system("cls");    
                    }
                    system("pause");
                    system("cls");
                    menuKonversi();
                    printf("Masukkan jenis suhu awal (R/C/F/K): ");
				}
				system("cls");
                break;
            case 3:
                break;
            default:
                break;
        }
    } while (choice != 3);

    return 0;
}