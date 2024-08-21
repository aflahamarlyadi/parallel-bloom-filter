# Parallel Bloom Filter

## Overview

This repository contains the implementation of Bloom filter in both serial and parallel. A Bloom filter is a space-efficient probabilistic data structure used to test whether an element is a member of a set. The implementation supports two hashing algorithms: MurmurHash3 and SHA-256.

## Directory

```data/``` contains sample text files used for testing the Bloom filter implementations.



```src/``` contains the source code for both the serial and parallel implementations, along with the implementations of the MurmurHash3 and SHA-256 hashing algorithms.

```include/``` contains the header files corresponding to the source files.

```build/``` contains the Makefile for compiling the project and the SLURM job script for running the parallel implementation on a cluster.

## Usage

### Preprocessing

The implementations support multiple insert files and a single query file named ```query.txt```.

* **Insert files**: Each line contains a single word.

* **Query file**: Each line contains a word and its label separated by a space.

### Compiling

To compile both the serial and parallel implementations, navigate to the build/ directory and run: ```make```

This will generate two binaries: ```bloom_filter_serial``` and ```bloom_filter_parallel```.

### Running

You can run the serial or parallel Bloom filter using the following commands:

```
./bloom_filter_serial <hash_function> <insert_file1> ... <insert_fileN>

./bloom_filter_parallel <hash_function> <insert_file1> ... <insert_fileN>
```

For example:

```
./bloom_filter_serial sha256 ../data/LITTLE_WOMEN.txt ../data/MOBY_DICK.txt ../data/SHAKESPEARE.txt

./bloom_filter_parallel murmurhash3 ../data/LITTLE_WOMEN.txt ../data/MOBY_DICK.txt ../data/SHAKESPEARE.txt
```

### Running on a Cluster

To run the parallel implementation on a cluster, use the provided SLURM job script and submit the job with sbatch:

```
sbatch bloom_filter.job
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

MurmurHash3 implementation by [Joseph Werle](https://github.com/jwerle/murmurhash.c).

SHA-256 implementation by [Brad Conte](https://github.com/B-Con/crypto-algorithms).
