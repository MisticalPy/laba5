#include <stdio.h>

int stringLength(const char* str) {
    int length = 0;
    
    while (str[length] != '\0') {
        length++;
    }
    
    return length;
}

int main() {
    char buffer[100];
    
    printf("Введите строку: ");
    fgets(buffer, sizeof(buffer), stdin);
    
    int len = stringLength(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
        len--;
    }
    
    // Вычисляем длину снова (без \n)
    len = stringLength(buffer);
    
    printf("Длина строки: %d\n", len);
    
    printf("Строка: \"%s\"\n", buffer);
    
    return 0;
}