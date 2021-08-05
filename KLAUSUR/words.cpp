#include <iostream>
#include <string>

/*
  You program should

  1. Read words from stdin (see given code)
  2. Count the occurrence of each word
  3. Ignore -- don't count -- any words specified as an
     argument to the command line (in argv)
  4. Ouput a list "N\tWORD" where nn is the number of
     occurrences of WORD.
  5. The list (above) should be sorted by N (descending).

  Your program should be efficient, the expected runtime cost should
  be in O(#words). The required memory should in O(#distinct words)!
  Select your data structures accordingly!
 */

using namespace std;

int main() {

  // This simple loop is good enough for us! Don't worry about
  // punctuation etc.!

  string word;
  while (cin >> word) {
    cerr << word << endl;
  }
}
