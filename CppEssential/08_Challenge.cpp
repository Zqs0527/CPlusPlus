#include <cstdio>
#include <iostream>
#include <cerrno>
#include <cstring>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

constexpr int maxBuffer = 1024;
struct Inventory {
  std::string SKU;
  std::string nameOfItem;
  std::string description;
};

std::vector<std::string> getStrings(std::string &inputString, const char delimiter) {
  std::vector<std::string> outputString;
  std::string s;
  std::stringstream inputStream(inputString);

  while (std::getline(inputStream, s, delimiter)) {
    outputString.push_back(s);
  }

  return outputString;
}
int main() {
  const char *fileName = "items.txt";
  std::ifstream inputFile;
  inputFile.open(fileName);
  std::string line;
  const char delimiter = '\t';
  std::vector<Inventory> inventory;
  if (inputFile.fail()) {
    const char *errorMsg = strerror(errno);
    printf("the error code is %d: %s", errno, errorMsg);
    return 1;
  }

  while (!inputFile.eof()) {
    getline(inputFile, line);
    if (line=="")
    {
        break;
    }
    std::vector<std::string> output = getStrings(line, delimiter);
    Inventory item = {output[0], output[1], output[2]};
    std::cout << "SKU: " << item.SKU << " NAME: " << item.nameOfItem << " DESCRIPTION: " << item.description << std::endl;
  }

  // const char * fileName = "items.txt";
  // char * str;
  // printf("read the file %s\n", fileName);

  // FILE * fileHandler = fopen(fileName,"r");
  // if (!fileHandler)
  // {
  //     const char * errorMsg = strerror(errno);
  //     printf("The error number is %d: %s\n", errno, errorMsg);
  //     return 1;
  // }

  // std::vector<Inventory> inventory;
  // char buffer[maxBuffer];
  // while (fgets(buffer, maxBuffer, fileHandler))
  // {

  //     fputs(buffer, stdout);
  // }
  // fclose(fileHandler);
  return 0;
}