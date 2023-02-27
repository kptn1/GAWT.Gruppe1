#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUES 100

int compare_double(const void *a, const void *b)
{
    const double *da = (const double *) a;
    const double *db = (const double *) b;
    return (*da > *db) - (*da < *db);
}

int main()
{
    double values[MAX_VALUES];
    int count = 0;
    double sum = 0;
    double mode = 0;
    double variance = 0;
    double median = 0;
    double arithmetic_mean = 0;

    // Datei öffnen
    FILE *fp = fopen("geschwindigkeit.csv", "r");
    if (fp == NULL) {
        printf("Fehler beim Öffnen der Datei.\n");
        return 1;
    }

    // Werte aus der Datei lesen
    char line[100];
    fgets(line, sizeof(line), fp); // erste Zeile überspringen
    while (fgets(line, sizeof(line), fp)) {
        values[count] = atof(line);
        sum += values[count];
        count++;
    }

    // Modus berechnen
    int max_count = 0;
    for (int i = 0; i < count; i++) {
        int count_i = 0;
        for (int j = i; j < count; j++) {
            if (values[j] == values[i]) {
                count_i++;
            }
        }
        if (count_i > max_count) {
            max_count = count_i;
            mode = values[i];
        }
    }

    // Median berechnen
    qsort(values, count, sizeof(double), compare_double);
    if (count % 2 == 0) {
        median = (values[count/2 - 1] + values[count/2]) / 2.0;
    } else {
        median = values[count/2];
    }

    // arithmetisches Mittel berechnen
    arithmetic_mean = sum / count;

    // Stichprobenvarianz berechnen
    for (int i = 0; i < count; i++) {
        variance += (values[i] - arithmetic_mean) * (values[i] - arithmetic_mean);
    }
    variance /= count - 1;

    // Ergebnisse ausgeben
    printf("Anzahl der Werte: %d\n", count);
    printf("Modus: %.2f\n", mode);
    printf("Median: %.2f\n", median);
    printf("Arithmetisches Mittel: %.2f\n", arithmetic_mean);
    printf("Stichprobenvarianz: %.2f\n", variance);

    // Datei schließen
    fclose(fp);

    return 0;
}
