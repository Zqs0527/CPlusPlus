#include <cstdio>
#include <iostream>
#include <cerrno>
#include <cstring>
#include <vector>
#include <fstream>
#include <string>
#include <filesystem>
#include <sstream>

using namespace std;

vector<std::filesystem::directory_entry> ReadDirectory(const char *directory){
    vector<std::filesystem::directory_entry> collectionOfFiles;
    for (auto p: std::filesystem::directory_iterator{directory})
    {
        if (p.is_regular_file())
        {
            collectionOfFiles.push_back(p);
        }    
    }
    return collectionOfFiles;
}

vector<string> GetCloumnValues(string &inputValue, const char deli){
    std::stringstream inputStream(inputValue);
    vector<string> outputStrings;
    string s;
    // string dateTime, airTemp, barometric, dewPoint, relativeHumidity, windDir, windGust, windSpeed;
    while(getline(inputStream, s, deli)){
        outputStrings.push_back(s);
    }
    return outputStrings;
}

int main() {
  const char *dirName = "C:\\Users\\yuanc\\Repository\\CPlusPlus\\CppCodeClinic\\Ch01\\resources";

  vector<std::filesystem::directory_entry> collectionFiles = ReadDirectory(dirName);
  
  ifstream inputFile;
  inputFile.open(collectionFiles[0].path());

  string line;
  const char delimiter = '\t';
  if (inputFile.fail()) {
    const char *errorMessage = strerror(errno);
    printf("There is an error to open the file %s, code %d: %s", collectionFiles[0].path(),
           errno, errorMessage);
           return 1;
  }
  // Get the header of the file
  getline(inputFile, line);
  
  while (!inputFile.eof()) {
    getline(inputFile, line, '\n');
    
    vector<string> segments = GetCloumnValues(line, delimiter);
    if (line == "") {
      break;
    }
  }

  inputFile.close();
}