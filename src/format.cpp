#include <string>
#include <cmath>

#include "format.h"

using std::string;
using std::to_string;
using std::floor;

string PadLeft(string n) {
  if (n.length() == 1) return "0" + n;
  return n;
}

string Format::ElapsedTime(long seconds) {
  string h = to_string((int)floor(seconds / 3600));
  seconds %= 3600;
  string m = to_string((int)floor(seconds / 60));
  string s = to_string((int)floor(seconds % 60));
  return PadLeft(h) + ":" + PadLeft(m) + ":" + PadLeft(s);
}