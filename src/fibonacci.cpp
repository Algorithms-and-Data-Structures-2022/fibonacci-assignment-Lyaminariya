#include "assignment/fibonacci.hpp"

#include <cmath>    // pow, sqrt, round
#include <cstdint>  // int64_t

namespace assignment {

  int64_t fib_binet(int n) {

    if (n <= 1) {
      return n;
    }
    double phi = (1 + sqrt(5)) / 2;
    double a = round((pow(phi, n) - pow(-phi ,-n)) / sqrt(5));
    return a;

  }

  int64_t fib_iterative(int n) {

    if (n <= 1) {
      return n;
    }

    // буфер для хранения двух последних значения ряда Фибоначчи
    int64_t fib_prev = 0;
    int64_t fib_curr = 1;
    for(int i = 1; i <= n; i++){
      fib_curr += fib_prev;
      fib_prev = fib_curr - fib_prev;
    }
    return fib_prev;

  }

  int64_t fib_recursive(int n) {
    if (n <= 1) {
      return n;
    }
    return fib_recursive(n-1) + fib_recursive(n-2);
  }

  int64_t fib_recursive_memoization(int n, std::vector<int64_t>& cache) {

    if (n <= 1) {
      return cache[n];
    }

    if (cache[n] == -1) {
      cache[n] = fib_recursive_memoization(n - 1, cache) + fib_recursive_memoization(n - 2, cache);
    }
    return cache[n];
}

  int64_t fib_matrix(int n) {

    if (n <= 1) {
      return n;
    }
    Matrix2x2 mat = {{{1, 1}, {1, 0}}};
    Matrix2x2 res = matrix_power(mat,n);
    return res[0][1];
  }

}  // namespace assignment
