# parallel-bloom-filter

## Overview

This repository contains the implementation of Bloom filter in both serial and parallel. A Bloom filter is a space-efficient probabilistic data structure used to test whether an element is a member of a set. The implementation supports two hashing algorithms: MurmurHash3 and SHA-256.

## Directory

### data/

This directory contains sample text files used for testing the Bloom filter implementations.

Notes:
* The implementations support multiple insert files and a single query file named query.txt.
* The insert files must be preprocessed such that each line contains a word.
* The query file must be preprocessed such that each line contains a word and its label separated by a space.

### src/

This directory contains the source code for both the serial and parallel implementations, along with the implementations of the MurmurHash3 and SHA-256 hashing algorithms.

### include/

This directory contains header files corresponding to the source files.

### build/

This directory contains the Makefile for compiling the project and the SLURM job script for running the parallel implementation on a cluster.

## Usage

### Compiling

To compile both the serial and parallel implementations, navigate to the build/ directory and run:

```make```

This will generate two binaries: bloom_filter_serial and bloom_filter_parallel.

### Running

You can run the serial or parallel Bloom filter using the following commands:

```
./bloom_filter_serial <hash_function> <file1> <file2> <file3>

./bloom_filter_parallel <hash_function> <file1> <file2> <file3>
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

This project is licensed under the MIT License. See the LICENSE file for details.

## Acknowledgments

MurmurHash3 implementation by Joseph Werle.

SHA-256 implementation by Brad Conte.
