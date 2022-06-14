#include <iostream>
#include <vector>
#include <cassert>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

using namespace std;
namespace fs = boost::filesystem;

void readDir(int argc, char *argv[]) {
  fs::path p(argc > 1 ? argv[1] : ".");
  vector<fs::directory_entry> v;
  if (is_directory(p)) {
    copy(fs::directory_iterator(p), fs::directory_iterator(), back_inserter(v));
    cout << p << "contains: \n";
    for (auto &t : v) {
      cout << (t).path().string() << endl;
    }
  }
}

void createDir() {
  const auto dirName = "TestDir";
  fs::path pp{dirName};
  try {
    if (create_directory(pp)) {
      fs::rename(pp, dirName);
    }

  } catch (const fs::filesystem_error &e) {
    std::cerr << e.what() << '\n';
  }
}

void writeFile() {
  fs::path fpath{"test.txt"};
  fs::ofstream ofs{fpath};
  ofs << "hello world...\n";
}

enum TrafficLight { red, green, yellow };

enum CarColor {
  black,
  white,
  gray,
  silver
  // yellow // can't have the color green in two enums
};

enum class Pet { dog, cat, bird };
enum class Mammal { bear, cougar, coyote, dog };

template <typename T> T rcatenate(T v) { return v; }

template <typename T, typename... Args> T rcatenate(T first, Args... args) {
  return rcatenate(args...) + " " + first;
}
template <typename T> T summer(T first) { return first; }

template <typename T, typename... Args> T summer(T first, Args... args) {
  return first += summer(args...);
}

int main(int argc, char *argv[]) {

  readDir(argc, argv);
  createDir();
  writeFile();

  int i1 = 2, i2 = 3, i3 = 4;
  int summation = summer(i1, i2, i3);
  cout << "The summation is " << summation << endl;
  string s1 = "big", s2 = "cat", s3 = "time";
  string cc = rcatenate(s1, s2, s3);
  cout << "reverse concatenated = " << cc << endl;

  TrafficLight color = TrafficLight::red;
  CarColor camry = CarColor::silver;

  // the surround scope has been polluted
  int colorNumber = red;
  int myCarsColor = black;

  Pet pet = Pet::dog;
  Mammal mammal = Mammal::dog;
  vector<int> alpha{1, 2, 3};
  // auto beta{1,2,3}; // error: initializer for variable beta with auto type
  // contains three values
  auto gama = {1, 2, 3}; // this is a list of int event
  auto delta = vector<int>{1, 2, 3, 4};
  vector<int> epsilon;
  // auto zeta; // error : declaration of variable zeta with deduced type auto
  // required initialization
}