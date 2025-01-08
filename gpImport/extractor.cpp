#include "extractor.h"

int Extractor::extractGP(const char* filename) {
    int open_error;
    zip_t* gp;
    zip_file_t* score;

    if ((gp = zip_open(filename, 0, &open_error)) == NULL) {
        zip_error_t error;
        zip_error_init_with_code(&error, open_error);
        fprintf(stderr, "error: cannot open zip archive '%s': %s\n", filename,
                zip_error_strerror(&error));
        zip_error_fini(&error);
        return GP_ERR_UNZIP;
    }

    if ((score = zip_fopen(gp, "Content/score.gpif", 0)) == NULL) {
        zip_error_t error;
        zip_error_init_with_code(&error, open_error);
        fprintf(stderr,
                "error: cannot read score from guitar pro file '%s': %s\n",
                filename, zip_error_strerror(&error));
        zip_error_fini(&error);
        return GP_ERR_SCORE_OPEN;
    }

    zip_stat_t* score_stat = new zip_stat_t;
    zip_stat_init(score_stat);
    if (zip_stat(gp, "Content/score.gpif", 0, score_stat) == -1) {
        fprintf(stderr, "error getting file information for score.gpif\n");
        return GP_ERR_SCORE_READ;
    }

    char* buff = new char[score_stat->size];
    if (zip_fread(score, buff, score_stat->size) != -1) {
        printf("%s", buff);
    }

    zip_fclose(score);
    zip_close(gp);

    return GP_SUCCESS;
}
