/*
 * Grid v2.1.x - ./main.cpp
 * 
 * Copyright (C) 2016 Guilherme de Andrade Arantes.
 *
 * This work is licensed under the Creative Commons BY SA 4.0 License
 * 
 * Visit [license](http://creativecommons.org/licenses/by-sa/4.0/) or send a letter
 * to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA to view
 * a copy of this licence.
 *
 * Git-hub page: [git](https://github.com/guiideandrade/grid.git)
 *
 * See README.md and code-you-should-use.css for more details.
 *
 */

#include <iostream>
#include <string>
#include <iomanip>

#define MIN 2
#define MAX 12
#define CLA ".col-"
#define CHA "-"
#define CSS "width: "

using namespace std;

int main(){

  int grid, cols;

  for (grid = MIN; grid <= MAX; ++grid) {
    for (cols = 1; cols <= grid; ++cols) {

      cout << CLA << cols << CHA << grid;
      cout << " { " << CSS;
      cout << fixed << 100.0 / grid * cols;
      cout << "% }";

      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
