#include <stdio.h>
#include <string.h>

int romanToDecimal(char roman) {
    if (roman == 'I') return 1;
    if (roman == 'V') return 5;
    if (roman == 'X') return 10;
    if (roman == 'L') return 50;
    if (roman == 'C') return 100;
    if (roman == 'D') return 500;
    if (roman == 'M') return 1000;
    return -1;
}

int romanToDecimalConverter(char *roman) {
    int result = 0;

    for (int i = 0; i < strlen(roman); i++) {
        int current = romanToDecimal(roman[i]);

        if (i + 1 < strlen(roman)) {
            int next = romanToDecimal(roman[i + 1]);

            if (current >= next) {
                result += current;
            } else {
                result += (next - current);
                i++;
            }
        } else {
            result += current;
        }
    }

    return result;
}

void decimalToBinary(int decimal) {
    int binary[32];
    int i = 0;

    while (decimal > 0) {
        binary[i++] = decimal % 2;
        decimal /= 2;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

int main() {
    char romanNum[13];
    int decimalNum;

    scanf("%s", romanNum);

    decimalNum = romanToDecimalConverter(romanNum);

    printf("%s na base 2: ", romanNum);
    decimalToBinary(decimalNum);
    printf("\n");

    printf("%s na base 10: %d\n", romanNum, decimalNum);

    printf("%s na base 16: %x\n", romanNum, decimalNum);

    return 0;
}       