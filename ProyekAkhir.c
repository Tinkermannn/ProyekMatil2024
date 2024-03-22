#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "function.h"

#define MAX_VOUCHER_CODE 20
enum set{FALSE, TRUE};

void printRainbowText(const char *text);
void menuPetunjuk();
void menuKonversi();
void menuUtama();
void conversiAll (int *cr);
void reamur(float suhu);
void celcius(float suhu);
void fahrenheit(float suhu);
void kelvin(float suhu);
int loginMenu(char *email, char *password);
void generateVoucherCode(char *code, int length);
void topUpVoucher(const char *filename);
int redeemVoucher(const char *filename, const char *code);

int main() {
    int amount;
    char code[MAX_VOUCHER_CODE + 1];
    int choice, userChoice, choiceLogin;
    float suhu;
    char suhuAwal;
    srand(time(NULL)); // Seed the random number generator
    int tigakalipakai = 0;
    char email[51]; // Variabel untuk menyimpan email
    char password[15]; // Variabel untuk menyimpan password

    do {
        do {
            menuUtama();
            printf("Silakan pilih tujuan Anda: ");
            scanf("%d", &choice);

            if (choice < 0 || choice > 2) {
                printf("Maaf, input pilihan Anda salah. Silakan pilih kembali\n");
                getchar();
                system("pause");
                system("cls");
            }
            system("cls");
        } while (choice < 0 || choice > 2);

        switch (choice) {
            case 1:
                menuPetunjuk();
                system("pause");
                system("cls");
                break;
            case 2:
            	if (tigakalipakai<3){
	            	menuKonversi();
	                printf("Masukkan jenis suhu awal (R/C/F/K): ");
	                while ((scanf(" %c", &suhuAwal)) != EOF && tigakalipakai<3) {
                    int input = TRUE;
                    suhuAwal = toupper(suhuAwal);
                    switch (suhuAwal) {
                        case 'R':
                            break;
                        case 'C':
                            break;
                        case 'F':
                            break;
                        case 'K':
                            break;
                        default:
                            input = FALSE;
                            break;
                    }
                    if (input!=TRUE){
                    	printf("Input tidak valid. Silakan coba lagi.\n");
					}
					else {
						printf("Masukkan suhu: ");
		                scanf("%f", &suhu);
		                getchar();
		                switch (suhuAwal) {
		                	case 'R':
		                	    reamur(suhu);
		                	    tigakalipakai += 1;
		               	    	break;
		                	case 'C':
		                    	celcius(suhu);
		                        tigakalipakai += 3;
		                        break;
		                    case 'F':
		                        fahrenheit(suhu);
		                        tigakalipakai += 1;
		                        break;
		                    case 'K':
		                        kelvin(suhu);
		                        tigakalipakai += 1;
		                        break;
		                    default:
		                        break;
		                }	
					}	  
	                system("pause");
	                system("cls");
	                menuKonversi();
	                printf("Masukkan jenis suhu awal (R/C/F/K): ");
            		}
				}
                if (tigakalipakai >= 3) {
                		system("cls");
                        printf("Anda sudah melebihi batas 3x percobaan\n");
                        printf("Registrasi akun anda sekarang (Y)\n");
                        printf("Login ke akun yang tersedia (L)\n");
                        printf("Ketik karakter lainnya untuk batal\n");
                        printf("Pilihan anda : ");
                        char registChoice[2];
                        scanf("%s", registChoice);

                        if (strcmp(registChoice, "Y") == 0 || strcmp(registChoice, "y") == 0) {
                        	system("cls");
                            FILE *akun;
                            akun = fopen("akun.txt","a");
                            printf("+======================================+\n");
                            printRainbowText("|               Buat Akun              |\n");
                            printf("|======================================|\n");
                            printf(" Email    : ");
                            scanf("%s", email);
                            printf(" Password : ");
                            scanf("%s", password);
                            printf("+======================================+\n");

                            fprintf(akun ,"%s %s\n", email, password);
                            fclose(akun);
                            printf("Akun anda berhasil dibuat\n");
                            system("pause");
                            system("cls"); 
						
                            int login = FALSE;
                            int credit=0;
                            if (loginMenu(email,password) == 1){
                            	login = TRUE;
                            	credit = 2;
							}
                            while (login==TRUE) {
                                if (credit == 0){
	                                system("cls");
	                                printf("Maaf credit Anda sudah habis\n");
	                                printf("Masukkan kode voucher untuk melanjutkan (+1 credit).\n");
								}
	                            menuUtamaLog();
	                            printf("Silakan pilih tujuan Anda: ");
	                            scanf("%d", &choiceLogin);
	                            while (choiceLogin!=0){
	                            	switch (choiceLogin) {
                                            case 1:
                                                menuPetunjuk();
                                                break;
                                            case 2: (credit>0) ? conversiAll (&credit) : printf("Maaf credit Anda sudah habis\n");
                                                break;
                                            case 3: printf("Enter the amount to top up: ");
	                                                scanf("%d", &amount);
	                                                topUpVoucher("code.txt");
	                                                printf("Top up berhasil dilakukan\n");
												break;
                                            case 4:
                                            	{
	                                            	char kode[30];
	                                                code[MAX_VOUCHER_CODE + 1];
	                                                printf("Enter the code to redeem: ");
	                                                scanf("%s", code);
	                                                int redeemedAmount = redeemVoucher("code.txt", code);
	                                                if (redeemedAmount > 0) {
	                                                    credit+=1;
	                                                    printf("Sekarang anda memiliki %d credit tambahan\n", credit);
	                                                    
	                                                } else {
	                                                    printf("Invalid code or already redeemed.\n");
	                                                }
												}
                                                break;
                                            case 0:
                                            	break;
                                            default: printf("Invalid menu!\n");
                                                break;
                                    	}  	
                                    system("pause");
                                    system("cls");
                                    printf("Anda memiliki %d credit\n", credit);
                                    menuUtamaLog();
		                            printf("Silakan pilih tujuan Anda: ");
		                            scanf("%d", &choiceLogin);
									}
								}
							}
					    else if (strcmp(registChoice, "L") == 0 || strcmp(registChoice, "l") == 0){
					    	system("cls");
					    	int login = FALSE;
                            int credit=0;
                            if (loginMenu(email,password) == 1){
                            	login = TRUE;
                            	credit = 2;
                            	printf("Sekarang Anda memiliki %d credit (1 credit/konversi)\n", credit);
							}
                            while (login==TRUE) {
                                if (credit == 0){
	                                system("cls");
	                                printf("Maaf credit Anda sudah habis\n");
	                                printf("Masukkan kode voucher untuk melanjutkan (+1 credit).\n");
								}
	                            menuUtamaLog();
	                            printf("Silakan pilih tujuan Anda: ");
	                            scanf("%d", &choiceLogin);
	                            while (choiceLogin!=0){
	                            	switch (choiceLogin) {
                                            case 1:
                                                menuPetunjuk();
                                                break;
                                            case 2: (credit>0) ? conversiAll (&credit) : printf("Maaf credit Anda sudah habis\n Silahkan top up atau log out\n");
                                                break;
                                            case 3: printf("Enter the amount to top up: ");
	                                                scanf("%d", &amount);
	                                                topUpVoucher("code.txt");
	                                                printf("Top up berhasil dilakukan\n");
												break;
                                            case 4:
                                            	{
	                                            	char kode[30];
	                                                code[MAX_VOUCHER_CODE + 1];
	                                                printf("Enter the code to redeem: ");
	                                                scanf("%s", code);
	                                                int redeemedAmount = redeemVoucher("code.txt", code);
	                                                if (redeemedAmount > 0) {
	                                                    credit+=1;
	                                                    printf("Sekarang anda memiliki %d credit\n", credit);
	                                                    
	                                                } else {
	                                                    printf("Invalid code or already redeemed.\n");
	                                                }
												}
                                                break;
                                            case 0:
                                            	break;
                                            default: printf("Invalid menu!\n");
                                                break;
                                    	}  	
                                    system("pause");
                                    system("cls");
                                    printf("Anda memiliki %d credit\n", credit);
                                    menuUtamaLog();
		                            printf("Silakan pilih tujuan Anda: ");
		                            scanf("%d", &choiceLogin);
									}
								}
                	} 
                	system("pause");
                	system("cls"); 
				}
				
                break;
            case 0: 
                break;
            default:
                break;
        }
    } while (choice != 0);
    return 0;
}

int loginMenu(char *email, char *password) {
    int choice;
    do {
        printf("+===========================+\n");
        printRainbowText("|   Program Konversi Suhu   |\n");
        printf("+===========================+\n");
        printf("| 1. Login                  |\n");
        printf("| 0. Logout                 |\n");
        printf("+===========================+\n");
        printf("Silakan pilih tujuan Anda: ");
        scanf("%d", &choice);
        system("cls");
        if (choice == 1) {
            char etemp[100];
            char passtemp[100];
            printf("+======================================+\n");
            printRainbowText("|               Login              |\n");
            printf("|======================================|\n");
            printf(" Email    : ");
            scanf("%s", email); // Membaca email
            printf(" Password : ");
            scanf("%s", password); // Membaca password
            printf("+======================================+\n");
            FILE *akun;
            akun=fopen("akun.txt","r");
            system("cls");
            while(fscanf(akun, "%s %s", etemp, passtemp) != EOF) { // Membaca hingga akhir file
                if(strcmp(etemp, email) == 0 && strcmp(passtemp, password) == 0) { // Membandingkan email dan password
                    fclose(akun); // Tutup file
                    printf("Login sukses\n");
                    return 1; // Login berhasil
                }
            }
            fclose(akun);
            printf("Login gagal. Silakan coba lagi.\n");
        } 
    } while (choice != 0);
    printf("Anda telah logout.\n");
    return 0; // Jika user memilih logout
}

void generateVoucherCode(char *code, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int i;
    for (i = 0; i < length; i++) {
        int index = rand() % (int)(sizeof(charset) - 1);
        code[i] = charset[index];
    }
    code[length] = '\0';
}

void topUpVoucher(const char *filename) {
    char code[MAX_VOUCHER_CODE + 1];
    generateVoucherCode(code, MAX_VOUCHER_CODE);
    FILE *filepoint;
    filepoint = fopen(filename, "a"); // Menggunakan mode "a" (append) untuk menambahkan ke file
    fprintf(filepoint, "%s\n", code);
    printf("Topup code generated: %s\n", code);
    fclose(filepoint);
}

void conversiAll (int *cr){
	char suhuAwal;
	int credit = *cr;
	float suhu;
	int convert = FALSE;
										
					                    int input = FALSE;
										while (input==FALSE){
											system("cls");
											menuKonversi();
							                printf("Masukkan jenis suhu awal (R/C/F/K): ");
							                scanf(" %c", &suhuAwal);
						                    input = TRUE;
						                    suhuAwal = toupper(suhuAwal);
							                switch (suhuAwal) {
							                	case 'R':
							               	    	break;
							                	case 'C':
							                        break;
							                    case 'F':
							                        break;
							                    case 'K':
							                        break;
							                    default: input = FALSE;
							                        break;
							                }
										}
											printf("Masukkan suhu: ");
							                scanf("%f", &suhu);
							                switch (suhuAwal) {
							                	case 'R':
							                	    reamur(suhu);
							                	    credit -= 1;
							               	    	break;
							                	case 'C':
							                    	celcius(suhu);
							                        credit -= 1;
							                        break;
							                    case 'F':
							                        fahrenheit(suhu);
							                        credit -= 1;
							                        break;
							                    case 'K':
							                        kelvin(suhu);
							                        credit -= 1;
							                        break;
							                    default:
							                        break;
							            }
						                
    *cr = credit;
}

int redeemVoucher(const char *filename, const char *code) {
    int n=0,temp,primo,primgems[250];
    char dum[200],read[20][200];
    FILE *fileredeem;
    fileredeem = fopen(filename, "r+");
    rewind(fileredeem);

    while(fscanf(fileredeem, "%s", dum)) {
        if(strcmp(dum,code)==0){
            primo=1;
            break;
        }
    }
    return primo;
}
