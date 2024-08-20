/**
 * @file    murmurhash3.h
 * @brief   Header file for implementation of the MurmurHash3 hashing algorithm.
 * @author  Joseph Werle (joseph.werle@gmail.com)
 */

#ifndef MURMURHASH3_H
#define MURMURHASH3_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

uint32_t murmurhash3(char *key, uint32_t len, uint32_t seed);

#endif // MURMURHASH3_H
