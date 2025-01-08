#include "note.h"

class Bar {
  public:
    Bar(Note* notes[]);
    Bar();
    ~Bar();
    int addNote(Note* note);

  private:
    Note* notes[];
};
