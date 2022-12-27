/**
 * @file hashtable.h

 * @brief Our program will search the word in Hashtable first,
 *        and if it is not found there, it will try to give suggestions using Trie.
 */

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

const long long SIZE = 1009; // Size of the HashTable (prime number taken).
/**
 * @brief Node in a Hashtable containing key and data.
 *
 */
struct Node
{
  string key;
  string value;
  Node *next;
  Node()
  {
    key = "";
    value = "";
    next = NULL;
  }
};
/**
 * @brief Class for the Hashtable containg all the functions to insert, search and print the data.
 *
 */
class HashTable
{
  Node *array[SIZE];

public:
  /**
   * @brief Construct a new Hash Table object
   *        setting all the values to NULL
   *
   */
  HashTable()
  {
    for (int i = 0; i < SIZE; i++)
      array[i] = NULL;
  }
  /**
   * @brief HashFunction for the key to find the Hashval for it.
   *
   * @param key
   * @return long long
   */
  long long hash(string key)
  {
    long long hashIndex = 0;
    for (long long i = 0; i < key.length(); i++)      // Uses the ASCII value of each character of a key srting.
      hashIndex += key[i] * pow(2, key.length() - i); // Gives a different hashval for each string.

    return hashIndex % SIZE;
  }

  /**
   * @brief Function for inserting a word in a hashtable.
   *
   * @param key
   */
  void insert(string key)
  {
    Node *newnode = new Node;
    newnode->key = key;
    newnode->value = key;
    newnode->next = nullptr;
    int hashval = hash(key);
    if (array[hashval] == nullptr)
    {
      array[hashval] = newnode;
      return;
    }
    Node *temp = array[hashval];
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }
    temp->next = newnode;
    return;
  }

  /**
   * @brief Function for searching a word in HashTable.
   *
   * @param key
   * @return true
   * @return false
   */
  bool search(string key)
  {
    int hashval = hash(key);
    if (array[hashval]->key == key)
    {
      return true;
    }
    else
    {
      Node *temp = array[hashval];
      while (temp)
      {
        if (temp->key == key)
          return true;
        temp = temp->next;
      }
      return false;
    }
  }

  /**
   * @brief Function for printing all words from a Hashtable.
   *        including chained words
   *
   *
   */
  void print()
  {
    for (int i = 0; i < SIZE; i++)
    {
      if (array[i] == NULL)
        continue;
      else
      {
        Node *temp = array[i];
        while (temp != nullptr)
        {
          cout << temp->key << " ";
          temp = temp->next;
        }
      }
      cout << endl;
    }
  }
};