#ifndef BAR_H_
#define BAR_H_

#include "Note.h"
#include <vector>

struct TimeSig {
    int num = 0;
    int denom = 0;
};

class Bar {
  public:
    Bar(TimeSig);
    Bar(std::vector<Note*>, TimeSig);
    ~Bar();
    void AddNote(Note& note);
    void SetTimeSig(TimeSig timeSig) { this->timeSig = timeSig; }
    int GetID() { return barId; }

  private:
    int barId;
    std::vector<Note*> notes;
    TimeSig timeSig;
};

#endif
