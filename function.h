#include <stdio.h>
#include <string.h>

void printRainbowText(const char *text) {
    int text_length = strlen(text);
    int color_index = 0;

    // Define the ANSI escape codes for colors
    char *colors[] = {
        "\033[1;31m", // Red
        "\033[1;33m", // Yellow
        "\033[1;32m", // Green
        "\033[1;36m", // Cyan
        "\033[1;34m", // Blue
        "\033[1;35m"  // Magenta
};

 for (int i = 0; i < text_length; i++) {
        printf("%s%c\033[0m", colors[color_index], text[i]);

        // Increment the color index, loop back to 0 if we reach the end of the color array
        color_index = (color_index + 1) % (sizeof(colors) / sizeof(colors[0]));
    }
}

void reamur(float suhu) {
    printf("+-----------------------------+\n");
    printf("|          Hasil Konversi     |\n");
    printf("+-----------------------------+\n");
    printf("| Celcius     | %-9.2f     |\n", (5.0 / 4.0) * suhu);
    printf("| Fahrenheit  | %-9.2f     |\n", (9.0 / 4.0 * suhu) + 32);
    printf("| Kelvin      | %-9.2f     |\n", (5.0 / 4.0 * suhu) + 273.15);
    printf("+-----------------------------+\n");
}

void celcius(float suhu) {
    printf("+-----------------------------+\n");
    printf("|          Hasil Konversi     |\n");
    printf("+-----------------------------+\n");
    printf("| Reamur      | %-9.2f     |\n", (4.0 / 5.0) * suhu);
    printf("| Fahrenheit  | %-9.2f     |\n", (9.0 / 5.0 * suhu) + 32);
    printf("| Kelvin      | %-9.2f     |\n", suhu + 273.15);
    printf("+-----------------------------+\n");
} 
    
void fahrenheit(float suhu) {
    printf("+-----------------------------+\n");
    printf("|          Hasil Konversi     |\n");
    printf("+-----------------------------+\n");
    printf("| Reamur      | %-9.2f     |\n", (4.0 / 9.0) * (suhu - 32));
    printf("| Celsius     | %-9.2f     |\n", (5.0 / 9.0 * (suhu - 32)));
    printf("| Kelvin      | %-9.2f     |\n", (5.0 / 9.0 * (suhu - 32)) + 273.15);
    printf("+-----------------------------+\n");
}

void kelvin(float suhu) {
    printf("+-----------------------------+\n");
    printf("|          Hasil Konversi     |\n");
    printf("+-----------------------------+\n");
    printf("| Reamur      | %-9.2f     |\n", (4.0 / 5.0) * (suhu - 273.15));
    printf("| Celsius     | %-9.2f     |\n", suhu - 273.15);
    printf("| Fahrenheit  | %-9.2f     |\n", (9.0 / 5.0 * (suhu - 273.15)) + 32);
    printf("+-----------------------------+\n");
}

void menuUtama() {
    printf("+===========================+\n");
    printf("|       Selamat datang      |\n");
    printf("| di Program Konversi Suhu  |\n");
    printf("+===========================+\n");
    printf("| 1. Petunjuk               |\n");
    printf("| 2. Konversi               |\n");
    printf("| 3. Keluar                 |\n");
    printf("+===========================+\n");
}
    
void menuKonversi(){
	printf("+=====================+\n");
    printf("|    Konversi Suhu    |\n");
    printf("+=====================+\n");
    printf("| Satuan suhu:        |\n");
    printf("| 1.Reamur            |\n");
    printf("| 2.Celcius           |\n");
    printf("| 3.Fahrenheit        |\n");
    printf("| 4.Kelvin            |\n");
    printf("+=====================+\n");	
}

void menuPetunjuk () {
    printf("+=========================================+\n");
    printf("|             Petunjuk Penggunaan         |\n");
    printf("+=========================================+\n");
    printf("| Program ini digunakan untuk melakukan   |\n");
    printf("| konversi suhu antara Reamur, Celcius,   |\n");
    printf("| Fahrenheit, dan Kelvin.                 |\n");
    printf("|                                         |\n");
    printf("| Langkah-langkah penggunaan program:     |\n");
    printf("| 1. Pilih menu konversi pada menu utama  |\n");
    printf("| 2. Masukkan jenis suhu awal (R/C/F/K)   |\n");
    printf("| 3. Masukkan suhu yang akan dikonversi   |\n");
    printf("| 4. Program akan menampilkan hasil       |\n");
    printf("|    konversi suhu sesuai pilihan Anda    |\n");
    printf("| 5. Ulangi langkah 2-4 untuk konversi    |\n");
    printf("|    suhu lainnya                         |\n");
    printf("| 6. Pilih menu keluar untuk keluar       |\n");
    printf("+=========================================+\n");
}

void landingpage() {
    printf("+-------------------------------------------+\n");
    printf("|      Selamat Datang di Konversi Suhu      |\n");
    printf("+-------------------------------------------+\n");
    printf("|                                           |\n");
    printf("|      Pilihlah dengan bijak, jelajahi      |\n");
    printf("|     kemungkinan-kemungkinan yang tak      |\n");
    printf("|  terbatas dengan Program Konversi Suhu!   |\n");
    printf("|                                           |\n");
    printf("|         Dibuat oleh Wilman Saragih Sitio  |\n");
    printf("|                               2306161776  |\n");
    printf("+-------------------------------------------+\n");
}
