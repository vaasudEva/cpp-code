
/**
 * Print decimal number in ndigits.
 * Author: Shakthi Prashanth <m.shakthi.prashanth@gmail.com>
 * Date: 01-Sep-2018
 */

#include <iostream>
#include <string>

using namespace std;

void print_decimal(int ndigits, string soFar)
{
  const static int DEC = 10;

  if (ndigits == 1)
    for (int d = 0; d < DEC; d++)
      cout << soFar + to_string(d) << endl;
  else
    for (int d = 0; d < DEC; d++)
      print_decimal(ndigits-1, soFar + to_string(d));
}


int main(int argc, char *argv[])
{
  print_decimal(argc == 1 ? 1 : stoi(argv[1]), "");

  return 0;
}
