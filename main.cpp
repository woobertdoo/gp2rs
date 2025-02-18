#include "Parser.h"
#include <stdio.h>
#include <string.h>

int main() {
    Parser* parser = new Parser();

    ParserError parseError;

    if ((parseError = parser->LoadScore("test.gp")).status !=
        PARSE_GP_SUCCESS) {
        printf("GP ERROR: %i: %s", parseError.status, parseError.message);
        return 1;
    }

    char* scoreData = parser->GetScoreData();
    printf("%ld\n", strlen(scoreData));

    parser->ParseXML();

    return 0;
}
