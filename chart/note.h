#ifndef NOTE_H_
#define NOTE_H_

/* TECHNIQUE FLAGS */
#define NOTE_HOPO_SRC 1
#define NOTE_HOPO_DEST 2

struct Tuple {
    int num;
    int den;
};

struct Rhythm {
    int baseVal;
    int dots = 0;
    Tuple tuple{1, 1};
};

class Note {
  public:
    Note(int fretNum, int stringNum, Rhythm rhythm);
    ~Note();

    int getFret();
    void setFret(int fretNum);

    int getString();
    void setString(int stringNum);

    Rhythm getRhythm();
    void setRhythm(Rhythm rhythm);

  private:
    int fretNum;
    int stringNum;
    Rhythm rhythm;
};

#endif
