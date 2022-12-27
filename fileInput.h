/**
 * @file fileInput.h
 * @brief File to read all the words and insert them in Hashtable and Tries.
 */
#include "trie.h"
#include "hashtable.h"

class fileInput
{
private:
    ifstream iFile;

public:
    /**
     * @brief   reads words from file into the trie class.
     *
     * @param a : An object for trie class.
     */
    fileInput(TrieClass &a)
    {
        iFile.open("words.txt");
        if (!iFile.is_open())
        {
            cout << "error, file did not load successfully ";
            exit(1);
        }
        string data;

        while (getline(iFile, data))
        {
            if (data.size() > 2)
                a.insertion(data);
        }
    }
    /**
     * @brief reads wordfile into hashtable.
     *
     * @param a : An object for Hashtable.
     */
    fileInput(HashTable &a)
    {
        iFile.open("words.txt");
        if (!iFile.is_open())
        {
            cout << "error, file did not load successfully ";
            exit(1);
        }
        string data;
        while (getline(iFile, data))
            a.insert(data);
    }
};