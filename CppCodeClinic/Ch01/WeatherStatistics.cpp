#include <cstdio>
#include <iostream>
#include <cerrno>
#include <cstring>
#include <sstream>
#include <ctime>
#include <map>
#include "WeatherStatistics.hpp"

using namespace std;

vector<std::filesystem::directory_entry> WeatherStatistics::ReadDirectory(const char *directory) {
  vector<std::filesystem::directory_entry> collectionOfFiles;
  for (auto p : std::filesystem::directory_iterator{directory}) {
    if (p.is_regular_file()) {
      collectionOfFiles.push_back(p);
    }
  }
  return collectionOfFiles;
}

vector<string> WeatherStatistics::GetCloumnValues(string &inputValue, const char deli) {
  std::stringstream inputStream(inputValue);
  vector<string> outputStrings;
  string s;
  // string dateTime, airTemp, barometric, dewPoint, relativeHumidity, windDir,
  // windGust, windSpeed;
  while (getline(inputStream, s, deli)) {
    outputStrings.push_back(s);
  }
  return outputStrings;
}

time_t WeatherStatistics::ConvertTimeStamps(string dateInfo) {
  struct std::tm tm;
  std::istringstream ss(dateInfo);
  ss >> std::get_time(&tm, "%Y_%m_%d %H:%M:%S");

  time_t t = mktime(&tm);

  return t;
}