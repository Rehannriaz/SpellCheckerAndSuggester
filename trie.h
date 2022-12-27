#pragma once
#include "headers.h"

const int AlphaSize = 26;
/**
 * @brief Trieclass to store all the words present in the file.
 * 
 */
class TrieClass
{
    struct Trie
    {
        bool endOfWord;
        Trie *children[AlphaSize];
        Trie()
        {
            endOfWord = false;

            for (int i = 0; i < AlphaSize; i++)
                children[i] = NULL;
        }
    };
    HashTable A;                   // using hashtable because it is quicker to search for a word
    Trie *root;
    vector<string> misWords;

public:
/**
 * Constructor for the Trie Class.

*/
    TrieClass(HashTable B)
    {
        this->A = B;
        root = new Trie;
    }

/**
 * @brief Insertion Function to store the word in the trie.
 * 
 * @param word 
 */
    void insertion(string word)      
    {
        Trie *trav = root;

        for (int i = 0; i < word.length(); i++)                  
        {
            int index = word[i] - 'a';
            if (!trav->children[index])
                trav->children[index] = new Trie;

            trav = trav->children[index];
        }
        trav->endOfWord = true;
    }

/**
 * @brief Function to search a word in a trie.
 * 
 * @param key 
 */
    void search(string key)
    {
        Trie *trav = root;
        string word = "";
        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!trav->children[index])
                return;
            
            word += key[i];
            trav = trav->children[index];
        }
        if (trav->endOfWord)
            cout << key << endl;
        
        
    }

/**
 * @brief This function identifies if the word is misspelled and try to give some replacements for it.
 * 
 * @param key 
 */
    void misSpelledWords(string key)
    {

        char j = 0;

        Trie *trav = root;
        string word = "";
        for (int i = 0; i < key.length(); i++)        
        {
            int index = key[i] - 'a';
            if (!trav->children[index])
            {
                if (i == key.length() - 1)
                {
                    int wordLength = word.length();
                    
                    if (A.search(word))

                        misWords.push_back(word);

                    for (char j = 'a'; j <= 'z'; j++)           //It checks if the last  letter of the word is incorrect
                    {                                           // and replecs the last letter with the all the other letters and search them.
                        string temp = word;
                        temp += j;
                       
                        if (A.search(temp))
                            misWords.push_back(temp);
                    }
                }
                else
                {
                    word += key[i];
                    break;
                }
            }
            word += key[i];
            trav = trav->children[index];
        }

        word = key;
        for (int i = 0; i < word.length(); i++)
        {
            for (char j = 'a'; j <= 'z'; j++)
            {
                string temp = word;
                temp[i] = j;
             
                if (A.search(temp))
                    misWords.push_back(temp);
            }
        }
        word = key;
        int j_1 = 0;
        string temp2 = "";

        for (int i = 0; i < word.length(); i++)           //Looks for the incorrect letter in the middle of the word.
        {                                                 //replaces the middle letters with all the other letters and search for it.
            for (int k = 0; k < word.length(); k++)
            {
                temp2 += word[k];
                if (i == j_1 && j_1 == k)
                {
                    temp2 += "-";
                    j_1++;
                }
            }
            for (char x = 'a'; x <= 'z'; x++)
            {

                temp2[j_1] = x;

                if (A.search(temp2))
                    misWords.push_back(temp2);
            }
            temp2 = "";
        }
        printMisWords();
        misWords.clear();
    }

    /**
     * @brief function to print the misspelled word.
     * 
     */
    void printMisWords()
    {
        sort(misWords.begin(), misWords.end());
        misWords.erase(unique(misWords.begin(), misWords.end()), misWords.end());
        for (int i = 0; i < misWords.size(); i++)
        {
            cout << misWords[i];
            if (i + 1 != misWords.size())
                cout << ", ";
        }
        cout << endl;
    }
};
