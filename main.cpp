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

int main(int argc, char** argv) {

  int grid, cols;

  int min    = MIN;
  int max    = MAX;
  string cla = CLA;
  string cha = CHA;
  string css = CSS;

  if (argc>=2)
    css = argv[1];
  if (argc>=3)
    min = stoi(argv[2]);
  if (argc>=4)
    max = stoi(argv[3]);
  if (argc>=5)
    cla = argv[4];
  if (argc>=6)
    cha = argv[5];

  for (grid = min; grid <= max; ++grid) {
    for (cols = 1; cols <= grid; ++cols) {

      cout << cla << cols << cha << grid;
      cout << " { " << css;
      cout << fixed << 100.0 / grid * cols;
      cout << "% }";

      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
