/**
 * @file CS221L_2021438_2021051_2021355.cpp
 * @author Muhammad Arsal Reg No: 2021355
 * @author Muhammad Rehan Reg No: 2021438
 * @author Adeen Amir     Reg No: 2021051
 * @brief Spellchecker using tries and Hashtables in C++
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "headers.h"
#include "trie.h"
#include "fileInput.h"
using namespace std;

/**
 * @brief Driver Funtion
 *
 * @return int
 */

int main()
{
    HashTable B;
    fileInput iFile(B);
    TrieClass A(B);
    fileInput iFile2(A);
    string key;
    cout << "Enter a Sentence: ";
    getline(cin, key);
    cout << "your entered sentence is: " << key << endl;
    key += " ";
    int i = 0;
    string word = "";

    while (key[i] != '\0') // Tokenizing the sentence
    {
        if (key[i] != ' ')
        {
            word += key[i];
            i++;
        }
        else
        {
            if (!B.search(word))
            {
                cout << "Instead of '" << word << "' you were probably trying to write: " << endl;
                A.misSpelledWords(word);

                cout << endl;
            }
            i++;
            word = "";
        }
    }
}