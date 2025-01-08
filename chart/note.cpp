#include "note.h"

Note::Note(int fretNum, int stringNum, Rhythm rhythm) {
    this->fretNum = fretNum;
    this->stringNum = stringNum;
    this->rhythm = rhythm;
}

int Note::getFret() { return this->fretNum; }

void Note::setFret(int fretNum) { this->fretNum = fretNum; }

int Note::getString() { return this->stringNum; }

void Note::setString(int stringNum) { this->stringNum = stringNum; }
