#include "WeatherStatistics.cpp"
using namespace std;

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

  WeatherStatistics::WeatherStatistics statistic = WeatherStatistics::WeatherStatistics();

  double startTimeInSecond = statistic.ConvertTimeStamps(startDate + " " + startTime);
  double endTimeInSecond = statistic.ConvertTimeStamps(endDate + " " + endTime);

  const char *dirName =
      "C:\\Users\\yuanc\\Repository\\CPlusPlus\\CppCodeClinic\\Ch01\\resources\\";

  string filePath = "";
  for (size_t i = 2012; i <= 2015; i++)
  {
    if (startDate.rfind(to_string(i), 0) == 0)
      {
        ostringstream ss;
        ss << "Environmental_Data_Deep_Moor_" << to_string(i) << ".txt";
        string fileName = ss.str();
        filePath = dirName + fileName;
        break;
      }
  }
  map<time_t, double> timeToPressure = statistic.GetDataFromFile(filePath, dirName);

  // find iterators based on input range
  map<time_t, double> ::iterator startTimePressure;
  map<time_t, double> ::iterator endTimePressure;

  startTimePressure = timeToPressure.lower_bound(startTimeInSecond);
  endTimePressure = timeToPressure.lower_bound(endTimeInSecond);

  // Extract time and time pressure values
  double timeDiff = endTimePressure->first - startTimePressure->first;
  double pressureDiff = endTimePressure->second - startTimePressure->second;

  double coefficient = pressureDiff / timeDiff;

  cout << "The coefficient is " << coefficient * 24 * 60 * 60 << endl;

  return 0;
  
}