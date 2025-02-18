#ifndef CHART_H_
#define CHART_H_

#include "Bar.h"
#include "Track.h"

class Chart {
  public:
    Chart(std::vector<Bar*>);
    Chart();
    ~Chart();
    int AddTrack(Track*);
    int AddBar(Bar*);
    std::vector<Bar*> GetBars() { return bars; }

  private:
    std::vector<Bar*> bars;
};

#endif
