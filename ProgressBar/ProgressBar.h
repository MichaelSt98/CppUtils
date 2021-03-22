#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <ostream>
#include <iostream>

#include "Color.h"

class ProgressBar {
public:
    ProgressBar(int bar_width);
    int bar_width = 100;
    void show_progress(float progress);
};


#endif //PROGRESSBAR_H
