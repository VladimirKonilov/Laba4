/**
 * @file modAlphaCipher.h
 * @brief Заголовочный файл для реализации шифра Гронсвельда.
 * 
 * Этот файл содержит описание класса `modAlphaCipher`, который реализует
 * шифрование и расшифрование текста с использованием шифра Гронсвельда.
 * 
 * @details Класс `modAlphaCipher` использует фиксированный алфавит и числовой ключ
 * для выполнения операций шифрования и расшифрования текста.
 * 
 * @author Конилов В.В.
 * @date 2024-12-10
 */

#pragma once
#include <string>
#include <map>
#include <vector>
#include <stdexcept>
#include <iostream>

/**
 * @class modAlphaCipher
 * @brief Класс для работы с шифром Гронсвельда.
 * 
 * Этот класс предоставляет методы для шифрования и расшифрования текста на основе
 * числового ключа и фиксированного алфавита.
 */
class modAlphaCipher {
private:
    std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; /**< Алфавит для шифрования. */
    std::map<wchar_t, int> alphaNum; /**< Карта соответствия символов алфавита их индексам. */
    std::vector<int> key; /**< Ключ для шифрования в виде числового вектора. */

    /**
     * @brief Преобразует строку в вектор числовых индексов.
     * 
     * @param s Строка, которую нужно преобразовать.
     * @return std::vector<int> Вектор чисел, представляющих индексы символов строки.
     */
    std::vector<int> convert(const std::wstring& s);

    /**
     * @brief Преобразует вектор чисел в строку.
     * 
     * @param v Вектор чисел.
     * @return std::wstring Строка, соответствующая переданному вектору чисел.
     */
    std::wstring convert(const std::vector<int>& v);

public:
    /**
     * @brief Удаленный конструктор по умолчанию.
     * 
     * Запрещает создание объекта без указания ключа.
     */
    modAlphaCipher() = delete;

    /**
     * @brief Конструктор с ключом.
     * 
     * @param skey Строка, представляющая ключ.
     * @throw std::invalid_argument Если ключ содержит недопустимые символы.
     */
    modAlphaCipher(const std::wstring& skey);

    /**
     * @brief Шифрует открытый текст.
     * 
     * @param open_text Текст для шифрования.
     * @return std::wstring Зашифрованный текст.
     * @throw std::invalid_argument Если входной текст содержит недопустимые символы.
     */
    std::wstring encrypt(const std::wstring& open_text);

    /**
     * @brief Расшифровывает зашифрованный текст.
     * 
     * @param cipher_text Текст для расшифрования.
     * @return std::wstring Расшифрованный текст.
     * @throw std::invalid_argument Если входной текст содержит недопустимые символы.
     */
    std::wstring decrypt(const std::wstring& cipher_text);
};
