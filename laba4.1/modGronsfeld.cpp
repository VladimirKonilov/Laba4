/**
 * @file modGronsfeld.cpp
 * @brief Реализация методов класса `modAlphaCipher`.
 * 
 * Этот файл содержит реализацию всех методов, описанных в классе `modAlphaCipher`,
 * включая конструктор, преобразования строк и векторов, а также шифрование и расшифрование текста.
 * 
 * @details Класс `modAlphaCipher` основан на шифре Гронсвельда и работает с текстами,
 * содержащими символы русского алфавита. Методы используют числовое представление текста
 * для выполнения операций шифрования и расшифрования.
 * 
 * @author Конилов В.В.
 * @date 2024-12-10
 */

#include "modGronsfeld.h"

/**
 * @brief Конструктор, инициализирующий ключ.
 * 
 * Преобразует строковый ключ в числовой вектор и создает карту алфавита.
 * 
 * @param skey Строка, представляющая ключ.
 * @throw std::invalid_argument Если ключ содержит недопустимые символы.
 */
modAlphaCipher::modAlphaCipher(const std::wstring& skey) {
    for (unsigned i = 0; i < numAlpha.size(); i++) {
        alphaNum[numAlpha[i]] = i;
    }
    key = convert(skey);
}

/**
 * @brief Преобразует строку в числовой вектор.
 * 
 * Каждому символу строки присваивается его индекс в алфавите.
 * 
 * @param s Строка для преобразования.
 * @return std::vector<int> Вектор чисел, соответствующий строке.
 * @throw std::invalid_argument Если строка содержит символы, отсутствующие в алфавите.
 */
std::vector<int> modAlphaCipher::convert(const std::wstring& s) {
    std::vector<int> result;
    for (auto c : s) {
        if (alphaNum.find(c) == alphaNum.end()) {
            throw std::invalid_argument("Invalid character in text.");
        }
        result.push_back(alphaNum[c]);
    }
    return result;
}

/**
 * @brief Преобразует числовой вектор в строку.
 * 
 * Индексы из вектора преобразуются в символы алфавита.
 * 
 * @param v Вектор чисел для преобразования.
 * @return std::wstring Строка, соответствующая вектору.
 * @throw std::invalid_argument Если индекс выходит за пределы алфавита.
 */
std::wstring modAlphaCipher::convert(const std::vector<int>& v) {
    std::wstring result;
    for (size_t i = 0; i < v.size(); ++i) {
        // Преобразуем v[i] в size_t для сравнения
        if (static_cast<size_t>(v[i]) >= numAlpha.size()) {
            throw std::invalid_argument("Index out of bounds");
        }
        result += numAlpha[v[i]];
    }
    return result;
}

/**
 * @brief Шифрует текст.
 * 
 * Преобразует открытый текст в числовой вектор, добавляет к каждому символу значение
 * ключа и возвращает зашифрованную строку.
 * 
 * @param open_text Открытый текст для шифрования.
 * @return std::wstring Зашифрованный текст.
 * @throw std::invalid_argument Если текст содержит недопустимые символы.
 * @throw std::exception Если возникает ошибка шифрования.
 */
std::wstring modAlphaCipher::encrypt(const std::wstring& open_text) {
    try {
        std::vector<int> work = convert(open_text);
        for (unsigned i = 0; i < work.size(); i++) {
            work[i] = (work[i] + key[i % key.size()]) % numAlpha.size();
        }
        return convert(work);
    } catch (const std::exception& e) {
        std::wcerr << L"Encryption error: " << e.what() << std::endl;
        throw;
    }
}

/**
 * @brief Расшифровывает текст.
 * 
 * Преобразует зашифрованный текст в числовой вектор, вычитает из каждого символа
 * значение ключа и возвращает расшифрованную строку.
 * 
 * @param cipher_text Зашифрованный текст для расшифрования.
 * @return std::wstring Расшифрованный текст.
 * @throw std::invalid_argument Если текст содержит недопустимые символы.
 * @throw std::exception Если возникает ошибка расшифрования.
 */
std::wstring modAlphaCipher::decrypt(const std::wstring& cipher_text) {
    try {
        std::vector<int> work = convert(cipher_text);
        for (unsigned i = 0; i < work.size(); i++) {
            work[i] = (work[i] + numAlpha.size() - key[i % key.size()]) % numAlpha.size();
        }
        return convert(work);
    } catch (const std::exception& e) {
        std::wcerr << L"Decryption error: " << e.what() << std::endl;
        throw;
    }
}
