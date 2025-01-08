#include "bar.h"
#include "note.h"

class Chart {
  public:
    Chart(Bar* bars[]);
    Chart();
    ~Chart();
    int addBar(Bar*);
    Bar** getBars();

  private:
    Bar* bars[];
};
