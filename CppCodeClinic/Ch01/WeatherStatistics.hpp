#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <filesystem>
#include <map>

namespace WeatherStatistics{
    class WeatherStatistics
    {
    private:
        /* data */
    public:
        WeatherStatistics(/* args */);
        ~WeatherStatistics();
    };
    
    std::vector<std::filesystem::directory_entry> ReadDirectory(const char *directory);
    
    std::vector<std::string> GetCloumnValues(std::string &inputValue, const char deli);

    time_t ConvertTimeStamps(std::string dateInfo);

    std::map<time_t, double> GetDataFromFile(std::string filePath, const char *dirName);
}