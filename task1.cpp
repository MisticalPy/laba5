#include <iostream>
#include <string>
#include <cctype>

bool palindrom(const std::string& str) {
    std::string cleaned;

// тут я чекал на буквы и сейвил в нижнем регистре
    for (char c : str) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            cleaned += std::tolower(static_cast<unsigned char>(c));
        }
    }

    // Проверка палидрома
    int left = 0;
    int right = cleaned.length() - 1;

    while (left < right) {
        if (cleaned[left] != cleaned[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    const int BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];

    printf("Введите строку для проверки: ");
    fgets(buffer, BUFFER_SIZE, stdin);

    // Преобразуем в std::string (убираем символ новой строки, без этой шляпы будет неверный answer)
    std::string input(buffer);
    if (!input.empty() && input.back() == '\n') {
        input.pop_back();
    }

    bool result = palindrom(input);

    printf("Результат: %s\n", result ? "True" : "False");

    return 0;
}

// для теста город хорог - горох дорог = True