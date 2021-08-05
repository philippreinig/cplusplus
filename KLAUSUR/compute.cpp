#include <cstdlib>
#include <iostream>
#include <limits>

class Sieve {
 public:
  Sieve(int n) : not_prime_(new bool[size_=n]) {
    fill();
  }
  ~Sieve() { delete[] not_prime_; }

  int largestPrime() const {
    int i=size_;

    do { --i; } while (i>2 && not_prime_[i]);

    return i;
  }

 private:
  void fill() {
    not_prime_[0] = not_prime_[1] = true;
    for (int i=2; i<size_; ++i) {
      if (not_prime_[i])
        continue;

      for (int j=2*i; j<size_; j+=i) {
        not_prime_[j] = true;
      }
    }
  }

  bool* not_prime_;
  int size_;
};

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "no input\n";
    return -1;
  }

  int n = std::atoi(argv[1]);

  if (!(2<= n && n<std::numeric_limits<int>::max())) {
    std::cerr << "invalid input\n";
    return -2;
  }

  auto sieve = new Sieve(n);
  std::cout << sieve->largestPrime() << std::endl;
  delete sieve;
}
