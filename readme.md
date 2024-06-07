# Encoded Multiplexing Readout Circuits Construction

> The projects is to construction the encoded channel multiplexing scheme for the high spatial resolution detector readout. The related article is [arXiv:2405.12457](https://arxiv.org/abs/2405.12457)

# How to use

The source code is located in [./hamilton_path_gen/](./hamilton_path_gen/).

- Just do the following in linux bash

```
git clone git@github.com:wyu0725/encoded_multiplexing_scheme.git
cd encoded_multiplexing_scheme
cd hamilton_path_gen
mkdir out
cd out
cmake ../
make
```

While finish the compilation, you can run the program by

```
./hamilton_path_gen
```

and will get the help information.

```
Usage:
./hamilton_path_gen -parameter
 -G [graph type. 0: Complete graph; 1: Bipatite graph]
 -e [Number of electronics]
 -m [Multiple times. N_strips = N_electroncis * m]
```

The -G parameter is used to select the graph type, which is described in this article [arXiv:2405.12457](https://arxiv.org/abs/2405.12457).

The -e parameter is used to set the number of the used electronics channels

The -m parameter is used to set the multiple factors, which means that the detector channels is number of electronics channels times multiplexing factor.

## Example

If one type the command below,

```
./hamilton_path_gen -G 0 -e 64 -m 8
```

and will get two csv files in the out directory. The first one is asic2det_chn_complete_graph_64_line8.csv, which is the mapping from the electronics channel to the detector channel. I will show the first 10 lines of the file. The first column is the electronics channel, and the other column are the detector channels. And this file is used to construction the encoded multiplexing circuit.

| ASIC CHN | DET CHN |      |      |      |      |      |      |      |
| -------- | ------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 0        | 1       | 69   | 137  | 205  | 273  | 341  | 409  | 477  |
| 1        | 2       | 67   | 135  | 203  | 271  | 339  | 407  | 475  |
| 2        | 4       | 65   | 133  | 201  | 269  | 337  | 405  | 473  |
| 3        | 6       | 66   | 131  | 199  | 267  | 335  | 403  | 471  |
| 4        | 8       | 68   | 129  | 197  | 265  | 333  | 401  | 469  |
| 5        | 10      | 70   | 130  | 195  | 263  | 331  | 399  | 467  |
| 6        | 12      | 72   | 132  | 193  | 261  | 329  | 397  | 465  |
| 7        | 14      | 74   | 134  | 194  | 259  | 327  | 395  | 463  |
| 8        | 16      | 76   | 136  | 196  | 257  | 325  | 393  | 461  |
| 9        | 18      | 78   | 138  | 198  | 258  | 323  | 391  | 459  |
| ...      | ...     | ...  | ...  | ...  | ...  | ...  | ...  | ...  |
| 63       | 32      | 96   | 160  | 224  | 288  | 352  | 416  | 480  |

The second one is encoded_lists_chn_complete_graph_64.csv and it has 32 rows (16 * 2), the first row is the number of readout electronics channels , and the second row is the index of the detector channels (In the table, it contingous) The third row is the index of the electronics channels and the fourth row is the index of the detectors....