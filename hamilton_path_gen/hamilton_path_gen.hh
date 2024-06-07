// hamiltion_path_gen.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <array>

#include <string>
#include "hamilton_path.hh"
#include "getopt.hh"

// TODO: Reference additional headers your program requires here.
extern int optind, opterr, optopt;
extern char* optarg;
int c;
void show_info(char* name);