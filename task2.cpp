#include <iostream>
#include <string>
#include <cctype>

bool checkPassword(const std::string& password) {
    // Проверка длины
    if (password.length() < 8 || password.length() > 14) {
        return false;
    }
    
    // Проверка символов ASCII (33-126)
    for (char c : password) {
        if (c < 33 || c > 126) {
            return false;
        }
    }
    
    //  Проверка классов символов
    bool classes[4] = {false, false, false, false};
    
    for (char c : password) {
        if (isupper(c)) {
            classes[0] = true;
        } else if (islower(c)) {
            classes[1] = true;
        } else if (isdigit(c)) {
            classes[2] = true;
        } else {
            classes[3] = true;
        }
    }
    
    // Подсчет сколько классов присутствует
    int count = 0;
    for (int i = 0; i < 4; i++) {
        if (classes[i]) count++;
    }
    
    return count >= 3;
}

int main() {
    char buffer[100];
    
    printf("Введите пароль: ");
    fgets(buffer, sizeof(buffer), stdin);
    
    std::string password(buffer);
    if (!password.empty() && password.back() == '\n') {
        password.pop_back();
    }
    
    bool result = checkPassword(password);
    printf("%s\n", result ? "YES" : "NO");
    
    return 0;
}

// тестики Pass!word = труе