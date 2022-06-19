#include <cstdio>
#include <iostream>
#include <cerrno>
#include <cstring>
#include <sstream>
#include <ctime>
#include <map>
#include "WeatherStatistics.hpp"

using namespace std;

WeatherStatistics::WeatherStatistics::WeatherStatistics(){}

vector<std::filesystem::directory_entry> WeatherStatistics::WeatherStatistics::ReadDirectory(const char *directory) {
  vector<std::filesystem::directory_entry> collectionOfFiles;
  for (auto p : std::filesystem::directory_iterator{directory}) {
    if (p.is_regular_file()) {
      collectionOfFiles.push_back(p);
    }
  }
  return collectionOfFiles;
}

vector<string> WeatherStatistics::WeatherStatistics::GetCloumnValues(string &inputValue, const char deli) {
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

time_t WeatherStatistics::WeatherStatistics::ConvertTimeStamps(string dateInfo) {
  struct std::tm tm;
  std::istringstream ss(dateInfo);
  ss >> std::get_time(&tm, "%Y_%m_%d %H:%M:%S");

  time_t t = mktime(&tm);

  return t;
}

std::map<time_t, double> WeatherStatistics::WeatherStatistics::GetDataFromFile(string filePath, const char *dirName){
  ifstream inputFile;
  if (filePath != "")
  {
    inputFile.open(filePath);
  }
  else{
    const char *errorMessage = strerror(errno);
    printf("Can't find the files from the given directory: %s, code %d: %s",
           dirName, errno, errorMessage);
  }
  
  string line;
  const char delimiter = '\t';
  if (inputFile.fail()) {
    const char *errorMessage = strerror(errno);
    printf("There is an error to open the file %s, code %d: %s",
           filePath, errno, errorMessage);
  }
  // Get the header of the file
  getline(inputFile, line);
  map<time_t, double> timeToPressure;
  char *p;
  while (!inputFile.eof()) {
    getline(inputFile, line, '\n');
    if (line == "") {
      break;
    }
    vector<string> segments = GetCloumnValues(line, delimiter);
    try {
      time_t timeAfterConversion = ConvertTimeStamps(segments[0]);
      timeToPressure[timeAfterConversion] = atof(segments[2].c_str());
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
    }
  }

  inputFile.close();
  return timeToPressure;
}

