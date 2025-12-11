#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    int shift;

    printf("Введите текст (только англ. буквы): ");
    fgets(text, sizeof(text), stdin);

    // Убираем \n
    int i = 0;
    while (text[i] != '\0') i++;
    if (i > 0 && text[i-1] == '\n') text[i-1] = '\0';

    printf("Введите сдвиг: ");
    scanf("%d", &shift);

    // Обрабатываем каждую букву
    for (i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        // Для больших букв
        if (c >= 'A' && c <= 'Z') {
            text[i] = 'A' + (c - 'A' + shift + 26) % 26;
        }
        // Для маленьких букв
        else if (c >= 'a' && c <= 'z') {
            text[i] = 'a' + (c - 'a' + shift + 26) % 26;
        }
    }

    printf("Результат: %s\n", text);

    return 0;
}