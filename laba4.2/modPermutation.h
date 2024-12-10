/**
 * @file modPermutation.h
 * @brief Заголовочный файл для класса шифрования методом маршрутной перестановки.
 * @details Класс предоставляет методы для шифрования и расшифрования текста с использованием заданного числового ключа.
 * @author Конилов В.В.
 * @date 2024.12.10
 */

#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include <locale>
#include <map>
#include <algorithm>
#include <iostream>

/**
 * @class modPermutationCipher
 * @brief Класс для шифрования и расшифрования текста методом маршрутной перестановки.
 */
class modPermutationCipher {
private:
    /**
     * @brief Алфавит, используемый для шифрования и расшифрования.
     * @details Содержит символы русского и английского алфавитов.
     */
    std::wstring alphabet;

    /**
     * @brief Ключ для шифрования в виде вектора чисел.
     * @details Каждое число представляет сдвиг, используемый в процессе шифрования.
     */
    std::vector<int> key;

public:
    /**
     * @brief Конструктор, инициализирующий объект класса с заданным ключом.
     * @param skey Строка, представляющая числовой ключ.
     * @throw std::invalid_argument Если ключ пуст или содержит некорректные символы.
     */
    modPermutationCipher(const std::wstring& skey);

    /**
     * @brief Метод для шифрования текста.
     * @param open_text Текст, который нужно зашифровать.
     * @return Зашифрованный текст.
     * @throw std::invalid_argument Если текст некорректный.
     */
    std::wstring encrypt(const std::wstring& open_text);

    /**
     * @brief Метод для расшифровки текста.
     * @param cipher_text Текст, который нужно расшифровать.
     * @return Расшифрованный текст.
     * @throw std::invalid_argument Если текст некорректный.
     */
    std::wstring decrypt(const std::wstring& cipher_text);

    /**
     * @brief Метод для проверки корректности ключа.
     * @param key Строка, представляющая числовой ключ.
     * @throw std::invalid_argument Если ключ содержит некорректные символы или неположительное значение.
     */
    void validateKey(const std::wstring& key);

    /**
     * @brief Метод для проверки корректности текста.
     * @param text Текст, который нужно проверить.
     * @throw std::invalid_argument Если текст пуст или содержит недопустимые символы.
     */
    void validateText(const std::wstring& text);
};
