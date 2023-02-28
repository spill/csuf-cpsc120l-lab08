// Ryan Trinh
// CPSC 120-06
// 2022-10-19
// rtrinh02@csu.fullerton.edu
// @rtrinh02
//
// Lab 09-01
// Partners: @rubenarmenta
//
// Olympic Judge Average
//

#include <iostream>
#include <string>
#include <vector>

// Calculate and return the Olympics average of scores.
// The return value is the mean of all elements of scores, except for the
// minimum and maximum elements.
double JudgeAverage(const std::vector<double>& scores) {
  double max{scores[0]};
  double min{scores[0]};
  double average{0.0};
  double sum{0.0};

  for (int i = 0; i < scores.size(); i++) {
    if (scores[i] > max) {
      max = scores[i];
    }
    if (scores[i] < min) {
      min = scores[i];
    }
  }

  double minmax{min + max};
  for (int i = 0; i < scores.size(); i++) {
    sum = sum + scores[i];
  }
  sum = sum - minmax;

  average = sum / double((scores.size() - 2));
  return average;
}

int main(int argc, char* argv[]) {
  if (argc < 4) {
    std::cout << "error: you must give at least three scores \n";
    return 1;
  }
  std::vector<double> input;

  for (int i = 1; i < argc; i++) {
    input.push_back(std::stod(argv[i]));
    std::cout << "average is " << JudgeAverage(input) << '\n';
  }
  return 0;
}
