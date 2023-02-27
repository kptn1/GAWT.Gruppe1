#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *fp;
    int i;
    float speed_kmph;
    char filename[] = "geschwindigkeit.csv";
    srand(time(NULL));

    // CSV-Datei zum Schreiben öffnen
    fp = fopen(filename, "w");
    fprintf(fp, "Geschwindigkeit (km/h)\n");

    // 100 zufällige Geschwindigkeitswerte zwischen 0 und 30 km/h generieren und in die CSV-Datei schreiben
    for (i = 0; i < 100; i++) {
        speed_kmph = (float)rand() / RAND_MAX * 30.0;  // Zufällige Geschwindigkeit zwischen 0 und 30 km/h generieren
        fprintf(fp, "%.2f\n", speed_kmph);  // Geschwindigkeit in die CSV-Datei schreiben
    }

    // CSV-Datei schließen
    fclose(fp);
    printf("CSV-Datei erfolgreich erstellt!");

    return 0;
}
