#include <stdio.h>

int main() {
    int meses, tempo;
    double aporte, taxa, valor_total;

    
    scanf("%d", &meses);

    
    scanf("%lf", &aporte);

    
    scanf("%lf", &taxa);

    valor_total = 0.0;

    for (tempo = 1; tempo <= meses; tempo++) {
        valor_total += aporte;
        valor_total *= (1 + taxa);
        printf("Montante ao fim do mes %d: R$ %.2lf\n", tempo, valor_total);
    }

    return 0;
}