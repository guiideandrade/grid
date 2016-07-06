/*
 * Grid v2.2.x - ./main.cpp
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
 * See README.md for more details.
 *
 */

/*
 * Includes some C++ Standard Libraries is needed
 *
 */

#include <iostream>
#include <string>
#include <iomanip>

/*
 * Defines the desired behavior
 *
 */

#define GRID_MIN 2  // grids
#define GRID_MAX 12

#define CNAME_S1 "." // construction
#define CNAME_S2 ""
#define CNAME_S3 "-"
#define CNAME_S4 ""

#define VIEWPORT_1 "col" // short names
#define VIEWPORT_2 "sm"
#define VIEWPORT_3 "md"
#define VIEWPORT_4 "lg"
#define VIEWPORT_5 "xl"

#define CSS_PROP "width" // css property 

using namespace std;

/*
 * Viewport Class
 *
 */

class viewport {
private:
  int minGrid, maxGrid, minWidth, maxWidth; // configuration
  string shortName;                         // predefined
public:
  viewport(const int&,
    const int&,
    const double&,
    const double&,
    const string& value = VIEWPORT_1);
  void setMinGrid(const int&);
  void setMaxGrid(const int&);
  void setMinWidth(const double&);
  void setMaxWidth(const double&);
  void setShortName(const string&);
  void printBreakPoint(const double&, const double&);
  void print(const char& mode='a'); // char = meaning (for each grid)
                                    // a = print all properties,
                                    // 1 = just print one property
                                    // L = don't print last property
};

/*
 * Function for calculation
 *
 */

double perc(const int&, const int&);

/*
 * Main
 *
 */

int main(){
  viewport initial(1, 12, 0, 0);
  initial.print();
  cout << endl;
  initial.setMaxGrid(2);
  initial.setMinWidth(35.5);
  initial.setShortName(VIEWPORT_2);
  initial.print();
  cout << endl;
  initial.setMaxGrid(4);
  initial.setMinWidth(48);
  initial.setShortName(VIEWPORT_3);
  initial.print();
  cout << endl;
  initial.setMaxGrid(6);
  initial.setMinWidth(64);
  initial.setShortName(VIEWPORT_4);
  initial.print();
  cout << endl;
  initial.setMaxGrid(8);
  initial.setMinWidth(80);
  initial.setShortName(VIEWPORT_5);
  initial.print();
  return 0;
}

/*
 * Percentage calculation
 *
 */

double perc(const int& grid, const int& cols) {
  return 100.0 / grid * cols;
}

/*
 * Functions of Viewport
 *
 */

viewport::viewport(const int& a,
  const int& b,
  const double& c,
  const double& d,
  const string& value) {
  setMinGrid(a);
  setMaxGrid(b);
  setMinWidth(c);
  setMaxWidth(d);
  setShortName(value);
}
void viewport::setMinGrid(const int& value) { minGrid = value; }
void viewport::setMaxGrid(const int& value) { maxGrid = value; }
void viewport::setMinWidth(const double& value) { minWidth = value; }
void viewport::setMaxWidth(const double& value) { maxWidth = value; }
void viewport::setShortName(const string& value) { shortName = value; }
void viewport::printBreakPoint(const double& minWidth, const double& maxWidth) {

  if ((minWidth>0) || (maxWidth>0)) {
    cout << "@media screen";
    if (minWidth>0)
      cout << " and (min-width: " << minWidth << "rem)";
    if (maxWidth>0)
      cout << " and (max-width: " << maxWidth << "rem)";
    cout << " {" << endl << endl;
  }

}
void viewport::print(const char& mode) {

  printBreakPoint(minWidth, maxWidth);

  switch(mode) {
    case 'a':

    for (int grid = minGrid; grid <= maxGrid; ++grid) {
      for (int cols = 1; cols <= grid; ++cols) {

        cout << CNAME_S1;

        if (shortName.length())
          cout << shortName << CNAME_S2;
        else
          cout << VIEWPORT_1 << CNAME_S2;

        cout << cols << CNAME_S3;
        cout << grid << CNAME_S4;

        cout << " { " << CSS_PROP << ": ";
        cout << fixed << perc(grid, cols);
        cout << "% }" << endl;

      }
      if (grid != maxGrid) cout << endl;
    } break;
    case '1':
    for (int grid = minGrid; grid <= maxGrid; ++grid) {
      for (int cols = 1; cols <= 1; ++cols) {

        cout << "\t" << CNAME_S1;

        if (shortName.length())
          cout << shortName << CNAME_S2;

        cout << cols << CNAME_S3;
        cout << grid << CNAME_S4;

        cout << " { " << CSS_PROP << ": ";
        cout << fixed << perc(grid, cols);
        cout << "% }" << endl;

      }
      if (grid != maxGrid) cout << endl;
    } break;
    case 'L':
    for (int grid = minGrid; grid <= maxGrid; ++grid) {
      for (int cols = 1; cols < grid; ++cols) {

        cout << "\t" << CNAME_S1;

        if (shortName.length())
          cout << shortName << CNAME_S2;

        cout << cols << CNAME_S3;
        cout << grid << CNAME_S4;

        cout << " { " << CSS_PROP << ": ";
        cout << fixed << perc(grid, cols);
        cout << "% }" << endl;

      }
      if (grid != maxGrid) cout << endl;
    } break;
  }
  if ((minWidth>0) || (maxWidth>0)) cout << endl << "}" << endl;
}
