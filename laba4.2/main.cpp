/**
 * @file main.cpp
 * @brief Реализация программы для шифрования и расшифрования текста с использованием метода маршрутной перестановки.
 * @details Программа позволяет шифровать и расшифровывать текст на основе заданного числового ключа,
 *          используя шифр маршрутной перестановки. Реализован ввод текста и ключа, выбор операций,
 *          а также обработка исключений с поддержкой локализации.
 * @author Конилов В.В.
 * @date 2024.12.10
 */

#include <iostream>
#include <locale>
#include <codecvt>
#include <stdexcept>
#include "modPermutation.h"

/**
 * @brief Конвертация сообщений исключений из std::exception в std::wstring.
 * @param e Исключение типа std::exception.
 * @return Конвертированное сообщение исключения в виде std::wstring.
 */
std::wstring convertExceptionMessage(const std::exception& e) {
    std::string errorMessage = e.what(); // Получаем сообщение об ошибке
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
    return converter.from_bytes(errorMessage); // Конвертируем в wstring
}

/**
 * @brief Основная функция программы.
 * @details Реализует ввод ключа и текста, выбор операции (зашифрование или расшифрование),
 *          а также обработку исключений при работе с шифром маршрутной перестановки.
 * @return Код завершения программы (0 - успешное выполнение).
 */
int main() {
    // Устанавливаем локаль для работы с русским языком
    setlocale(LC_ALL, "ru_RU.UTF-8");

    try {
        std::wstring key;
        std::wcout << L"Введите ключ (целое число, положительное): ";
        std::getline(std::wcin, key);

        // Создаем объект для шифрования/расшифровки
        modPermutationCipher cipher(key);

        int operation;
        do {
            std::wcout << L"Выберите операцию (0 - выход, 1 - зашифровать, 2 - расшифровать): ";
            std::wcin >> operation;

            std::wstring text;
            if (operation == 1 || operation == 2) {
                std::wcout << L"Введите текст: ";
                std::wcin.ignore(); // Очищаем буфер ввода
                std::getline(std::wcin, text);

                if (operation == 1) {
                    std::wstring encrypted_text = cipher.encrypt(text);
                    std::wcout << L"Зашифрованный текст: " << encrypted_text << std::endl;
                } else if (operation == 2) {
                    std::wstring decrypted_text = cipher.decrypt(text);
                    std::wcout << L"Расшифрованный текст: " << decrypted_text << std::endl;
                }
            } else if (operation != 0) {
                std::wcout << L"Некорректная операция. Пожалуйста, выберите 0, 1 или 2." << std::endl;
            }
        } while (operation != 0);

    } catch (const std::invalid_argument& e) {
        // Используем конвертацию сообщения исключения в wstring для вывода на русском
        std::wcerr << L"Ошибка: " << convertExceptionMessage(e) << std::endl;
    } catch (const std::exception& e) {
        // Общий блок для других исключений
        std::wcerr << L"Произошла ошибка: " << convertExceptionMessage(e) << std::endl;
    }

    return 0;
}
