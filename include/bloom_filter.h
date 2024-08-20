/**
 * @file    bloom_filter.h
 * @brief   Header file for both the serial and parallel implementations of Bloom Filter.
 * @author  Aflah Hanif Amarlyadi (aflahamarlyadi@gmail.com)
 */

#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <stdint.h>

#define MAX_FP_RATE 0.01        // Maximum false positive rate
#define MAX_WORD_LENGTH 100     // Maximum length of a word

typedef enum {
    HASH_SHA256,
    HASH_MURMURHASH3
} HashType;

/**
 * @brief   Checks if a word is distinct in an array of words.
 * @param   word        The word to check.
 * @param   array       The array of words.
 * @param   arrayLength The length of the array.
 * @return  1 if the word is found in the array, 0 otherwise.
 */
int isDistinct(char *word, char **array, int arrayLength);

/**
 * @brief   Reads words from a file and inserts them into an array.
 * @param   filename    The name of the file to read.
 * @param   wordArray   Pointer to the array where words will be stored.
 * @param   numWords    Pointer to the number of words read.
 * @return  The number of words read from the file.
 */
int readInsertFile(const char *filename, char ***wordArray, int *numWords);

/**
 * @brief   Reads words and labels from a file and inserts them into arrays.
 * @param   filename    The name of the file to read.
 * @param   wordArray   Pointer to the array where words will be stored.
 * @param   labelArray  Pointer to the array where labels will be stored.
 * @return  The number of words read from the file.
 */
int readQueryFile(const char *filename, char ***wordArray, int **labelArray);

/**
 * @brief   Inserts a word into the Bloom Filter.
 * @param   str         The word to insert.
 * @param   bitArray    The bit array representing the Bloom Filter.
 * @param   m           The size of the bit array.
 * @param   numHashes   The number of hash functions to use.
 * @param   hashType    The type of hash function to use.
 */
void insert(char *str, unsigned char *bitArray, unsigned int m, const int numHashes, HashType hashType);

/**
 * @brief   Queries a word from the Bloom Filter.
 * @param   str        The word to query.
 * @param   bitArray   The bit array representing the Bloom Filter.
 * @param   m          The size of the bit array.
 * @param   numHashes  The number of hash functions to use.
 * @param   hashType   The type of hash function to use.
 * @return  1 if the word is possibly in the set (could be a false positive), 0 if the word is definitely not in the set.
 */
int query(char *str, unsigned char *bitArray, unsigned int m, const int numHashes, HashType hashType);

#endif // BLOOM_FILTER_H
