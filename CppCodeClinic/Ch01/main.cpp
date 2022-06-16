#include "WeatherStatistics.cpp"

int main() {

  // Start date and time
  string startDate, startTime;
  cout << "Please endter the start date, format is yyyy_mm_dd: ";
  cin >> startDate;
  cout << "Please endter the start time, format is hh_mm_ss (24 hours): ";
  cin >> startTime;
  // End date and time
  string endDate, endTime;
  cout << "Please endter the end date, format is yyyy_mm_dd: ";
  cin >> endDate;
  cout << "Please endter the end time, format is hh:mm:ss (24 hours): ";
  cin >> endTime;

  double startTimeInSecond = WeatherStatistics::ConvertTimeStamps(startDate + " " + startTime);
  double endTimeInSecond = WeatherStatistics::ConvertTimeStamps(endDate + " " + endTime);

  const char *dirName =
      "C:\\Users\\yuanc\\Repository\\CPlusPlus\\CppCodeClinic\\Ch01\\resources";

  vector<std::filesystem::directory_entry> collectionFiles =
      WeatherStatistics::ReadDirectory(dirName);

  ifstream inputFile;

  inputFile.open(collectionFiles[0].path());

  string line;
  const char delimiter = '\t';
  if (inputFile.fail()) {
    const char *errorMessage = strerror(errno);
    printf("There is an error to open the file %s, code %d: %s",
           collectionFiles[0].path(), errno, errorMessage);
    return 1;
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
    vector<string> segments = WeatherStatistics::GetCloumnValues(line, delimiter);
    try {
      time_t timeAfterConversion = WeatherStatistics::ConvertTimeStamps(segments[0]);
      timeToPressure[timeAfterConversion] = atof(segments[2].c_str());
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
    }
  }

  inputFile.close();
}