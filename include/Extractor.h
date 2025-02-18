#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include <zip.h>

enum GP_EXTRACT_STATUS {
    GP_ERR_UNZIP,
    GP_ERR_SCORE_OPEN,
    GP_ERR_SCORE_READ,
    GP_SUCCESS
};

class Extractor {
  public:
    static GP_EXTRACT_STATUS ExtractGP(const char*, char**, zip_error*);
};

#endif
