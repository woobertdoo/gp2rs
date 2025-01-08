#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include <cstdio>
#include <cstdlib>
#include <zip.h>

#define GP_ERR_UNZIP 1
#define GP_ERR_SCORE_OPEN 2
#define GP_ERR_SCORE_READ 3
#define GP_SUCCESS 0

class Extractor {
  public:
    int extractGP(const char*);
};

#endif
