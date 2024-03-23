#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "function.h"

typedef struct {
    char email[51];
    char password[15];
    int credit;
} Account;

#define MAX_VOUCHER_CODE 20
#define MAX_REDEEMED_CODES 100 // Menentukan batas maksimum kode voucher yang dapat diredeem

int redeemVoucher(const char *filename, const char *code, char redeemedCodes[][MAX_VOUCHER_CODE + 1], int *redeemedCount);
enum set{FALSE, TRUE};

void printRainbowText(const char *text);
void menuPetunjuk();
void menuKonversi();
void menuUtama();
void conversiAll(int *cr);
void reamur(float suhu);
void celcius(float suhu);
void fahrenheit(float suhu);
void kelvin(float suhu);
int loginMenu(char *email, char *password);
void generateVoucherCode(char *code, int length);
void topUpVoucher(const char *filename);
// int redeemVoucher(const char *filename, const char *code);
int getCredit(const char *email);
void saveAccountInfo(Account *account);
void loadAccountInfo(Account *account);

int main() {
    int amount;
    char code[MAX_VOUCHER_CODE + 1];
    int choice;
    float suhu;
    char suhuAwal;
    srand(time(NULL)); // Seed the random number generator
    int tigakalipakai = 0;
    char email[51]; // Variabel untuk menyimpan email
    char password[15]; // Variabel untuk menyimpan password
        char redeemedCodes[MAX_REDEEMED_CODES][MAX_VOUCHER_CODE + 1];
    int redeemedCount = 0;
    Account account;
    loadAccountInfo(&account);

    do {
        int choiceLogin = 0;
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
                if (tigakalipakai < 3) {
                    menuKonversi();
                    printf("Masukkan jenis suhu awal (R/C/F/K): ");
                    while ((scanf(" %c", &suhuAwal)) != EOF && tigakalipakai < 3) {
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
                        if (input != TRUE) {
                            printf("Input tidak valid. Silakan coba lagi.\n");
                        } else {
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
                    printf("+==============================================+\n");
                    printf("|    Anda sudah melebihi batas 3x percobaan    |\n");
                    printf("+==============================================+\n");
                    printf("| Registrasi akun anda sekarang (Y)            |\n");
                    printf("| Login ke akun yang tersedia (L)              |\n");
                    printf("| Ketik karakter lainnya untuk membatalkan     |\n");
                    printf("+==============================================+\n");
                    printf("Pilihan anda : ");
                    char registChoice[2];
                    scanf("%s", registChoice);

                    if (strcmp(registChoice, "Y") == 0 || strcmp(registChoice, "y") == 0) {
                        system("cls");
                        FILE *akun;
                        akun = fopen("akun.txt", "a");
                        printf("+======================================+\n");
                        printRainbowText("|               Buat Akun              |\n");
                        printf("|======================================|\n");
                        printf(" Email    : ");
                        scanf("%s", email);
                        printf(" Password : ");
                        scanf("%s", password);
                        printf("+======================================+\n");

                        fprintf(akun, "%s %s\n", email, password);
                        fclose(akun);
                        printf("Akun anda berhasil dibuat\n");
                        system("pause");
                        system("cls");

                        int login = FALSE;
                        int credit = 0;
                        if (loginMenu(email, password) == 1) {
                            login = TRUE;
                            credit = 1; // harusnya 3
                            printf("Sekarang anda memiliki %d credit\n", credit);
                        }
                        while (login == TRUE) {
                            if (credit == 0) {
                                system("cls");
                                printf("Maaf credit Anda sudah habis\n");
                                printf("Masukkan kode voucher untuk melanjutkan (+1 credit).\n");
                            }
                            menuUtamaLog();
                            printf("Silakan pilih tujuan Anda: ");
                            scanf("%d", &choiceLogin);
                            while (choiceLogin != 0) {
                                switch (choiceLogin) {
                                    case 1:
                                        menuPetunjuk();
                                        break;
                                    case 2:
                                        (credit > 0) ? conversiAll(&credit) : printf("Maaf credit Anda sudah habis\n");
                                        break;
                                    case 3:
                                        printf("Enter the amount to top up: ");
                                        scanf("%d", &amount);
                                        topUpVoucher("code.txt");
                                        printf("Top up berhasil dilakukan\n");
                                        ccount.credit += amount;
                saveAccountInfo(&account);
                                        break;
                                    case 4:
{
    char code[MAX_VOUCHER_CODE + 1];
    printf("Enter the code to redeem: ");
    scanf("%s", code);

    int alreadyRedeemed = 0; // Flag untuk menandakan apakah kode sudah diredeem atau belum

    // Periksa apakah kode sudah ada dalam daftar redeemedCodes
    for (int i = 0; i < redeemedCount; ++i) {
        if (strcmp(redeemedCodes[i], code) == 0) {
            alreadyRedeemed = 1; // Jika kode sudah ada, set flag menjadi 1
            break;
        }
    }

    if (alreadyRedeemed) {
        printf("Invalid code or already redeemed.\n");
    } else {
                            account.credit += 1;

        // Jika kode belum ada dalam daftar redeemedCodes, tambahkan ke daftar
        strcpy(redeemedCodes[redeemedCount], code);
        redeemedCount++;

        // Lakukan proses redeeming kode dan tambahkan credit jika berhasil
        // credit += 1;
        printf("Sekarang anda memiliki %d credit\n", account.credit);
                            saveAccountInfo(&account);

    }
}
break;
                                    case 0:
                                        login = FALSE;
                                        choiceLogin = 0;
                                        break;
                                    default:
                                        printf("Invalid menu!\n");
                                        break;
                                }
                                system("pause");
                                system("cls");
                                printf("Anda memiliki %d credit\n", credit);
                                menuUtamaLog();
                                printf("Silakan pilih tujuan Anda: ");
                                scanf("%d", &choiceLogin);
                            }
                                                        if (choiceLogin==0) break;

                        }
                    } else if (strcmp(registChoice, "L") == 0 || strcmp(registChoice, "l") == 0) {
                        system("cls");
                        int login = FALSE;
                        int credit = 0;
                        if (loginMenu(email, password) == 1) {
                            login = TRUE;
                            // credit = 1;
                                credit = getCredit(email);

                            printf("Sekarang Anda memiliki %d credit (1 credit/konversi)\n", credit);
                        }
                        while (login == TRUE) {
                            if (credit == 0) {
                                system("cls");
                                printf("Maaf credit Anda sudah habis\n");
                                printf("Masukkan kode voucher untuk melanjutkan (+1 credit).\n");
                            }
                            menuUtamaLog();
                            printf("Silakan pilih tujuan Anda: ");
                            scanf("%d", &choiceLogin);
                            while (choiceLogin != 0) {
                                switch (choiceLogin) {
                                    case 1:
                                        menuPetunjuk();
                                        break;
                                    case 2:
                                        (credit > 0) ? conversiAll(&credit) : printf("Maaf credit Anda sudah habis\nSilahkan top up atau log out\n");
                                        break;
                                    case 3:
                                        printf("Enter the amount to top up: ");
                                        scanf("%d", &amount);
                                        topUpVoucher("code.txt");
                                        printf("Top up berhasil dilakukan\n");
                                        break;
                                   case 4:
{
    char code[MAX_VOUCHER_CODE + 1];
    printf("Enter the code to redeem: ");
    scanf("%s", code);

    int alreadyRedeemed = 0; // Flag untuk menandakan apakah kode sudah diredeem atau belum

    // Periksa apakah kode sudah ada dalam daftar redeemedCodes
    for (int i = 0; i < redeemedCount; ++i) {
        if (strcmp(redeemedCodes[i], code) == 0) {
            alreadyRedeemed = 1; // Jika kode sudah ada, set flag menjadi 1
            break;
        }
    }

    if (alreadyRedeemed) {
        printf("Invalid code or already redeemed.\n");
    } else {
        // Jika kode belum ada dalam daftar redeemedCodes, tambahkan ke daftar
        strcpy(redeemedCodes[redeemedCount], code);
        redeemedCount++;

        // Lakukan proses redeeming kode dan tambahkan credit jika berhasil
        credit += 1;
        printf("Sekarang anda memiliki %d credit\n", credit);
    }
}
break;
                                    case 0:
                                        login = FALSE;
                                        choiceLogin = 0;
                                        break;
                                    default:
                                        printf("Invalid menu!\n");
                                        break;
                                }
                                if (choiceLogin == 0) {
                                    login = FALSE;
                                } else {
                                    system("pause");
                                    system("cls");
                                    printf("Anda memiliki %d credit\n", credit);
                                    menuUtamaLog();
                                    printf("Silakan pilih tujuan Anda: ");
                                    scanf("%d", &choiceLogin);
                                }
                                
                            }
                            if (choiceLogin==0) break;
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
            akun = fopen("akun.txt","r");
            system("cls");
            while (fscanf(akun, "%s %s", etemp, passtemp) != EOF) { // Membaca hingga akhir file
                if (strcmp(etemp, email) == 0 && strcmp(passtemp, password) == 0) { // Membandingkan email dan password
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

void conversiAll(int *cr) {
    char suhuAwal;
    int credit = *cr;
    float suhu;
    int convert = FALSE;

    int input = FALSE;
    while (input == FALSE) {
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
            default:
                input = FALSE;
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


int redeemVoucher(const char *filename, const char *code, char redeemedCodes[][MAX_VOUCHER_CODE + 1], int *redeemedCount) {
    int primo = 0;

    for (int i = 0; i < *redeemedCount; ++i) {
        if (strcmp(redeemedCodes[i], code) == 0) {
            primo = 1; // Kode sudah diredeem
            break;
        }
    }

    if (!primo) { // Jika kode belum diredeem, tambahkan ke array redeemedCodes
        FILE *fileredeem = fopen(filename, "a+");
        if (fileredeem != NULL) {
            fprintf(fileredeem, "%s\n", code);
            fclose(fileredeem);
            strcpy(redeemedCodes[*redeemedCount], code); // Menyalin kode ke array redeemedCodes
            (*redeemedCount)++; // Menambah jumlah kode yang diredeem
        } else {
            printf("Failed to open file for redeeming voucher.\n");
        }
    }

    return primo;
}

// int redeemVoucher(const char *filename, const char *code) {
//     int n = 0, temp, primo, primgems[250];
//     char dum[200], read[20][200];
//     FILE *fileredeem;
//     fileredeem = fopen(filename, "r+");
//     rewind(fileredeem);

//     while (fscanf(fileredeem, "%s", dum)) {
//         if(strcmp(dum, code) == 0) {
//             primo = 1;
//             break;
//         }
//     }
//     return primo;
// }

int getCredit(const char *email) {
    FILE *file = fopen("accounts.txt", "r");
    if (file == NULL) {
        printf("Error: Gagal membuka file akun.\n");
        return 0;
    }

    Account account;
    while (fscanf(file, "%s %s %d", account.email, account.password, &account.credit) != EOF) {
        if (strcmp(account.email, email) == 0) {
            fclose(file);
            return account.credit;
        }
    }

    fclose(file);
    printf("Error: Akun dengan email '%s' tidak ditemukan.\n", email);
    return 0;
}

void saveAccountInfo(Account *account) {
    FILE *file = fopen("accounts.txt", "w");
    if (file != NULL) {
        fprintf(file, "%s %s %d\n", account->email, account->password, account->credit);
        fclose(file);
    } else {
        printf("Error: Gagal menyimpan informasi akun.\n");
    }
}

void loadAccountInfo(Account *account) {
    FILE *file = fopen("accounts.txt", "r");
    if (file != NULL) {
        fscanf(file, "%s %s %d", account->email, account->password, &account->credit);
        fclose(file);
    } else {
        printf("Error: Gagal memuat informasi akun.\n");
    }
}