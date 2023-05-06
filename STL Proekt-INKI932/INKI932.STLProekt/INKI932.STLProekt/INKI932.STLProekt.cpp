#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <ctime>

using namespace std;

// Struktura
struct WeatherMK 
{
    string city;
    int day_temp;
    int night_temp;

    bool operator<(const WeatherMK& other) const 
    {
        return day_temp > other.day_temp;
    }
};

// Funkcija za popolnuvanje na vektorot so podatoci
vector<WeatherMK> fillWeatherData()
{
    vector<WeatherMK> weather_data;
    for (int i = 1; i <= 10; i++) 
    {
        string city;
        int day_temp, night_temp;
        cout << "Enter data for record " << i << ":" << endl;
        cout << "City: ";
        getline(cin, city);
        cout << "Day Temperature: ";
        cin >> day_temp;
        cout << "Night Temperature: ";
        cin >> night_temp;
        cin.ignore();
        weather_data.push_back({ city, day_temp, night_temp });
    }
    return weather_data;
}

// Funkcija za pecatenje na podatocite od vektorot
void printWeatherData(const vector<WeatherMK>& weather_data) 
{
    for (auto& data : weather_data) 
    {
        cout << "City: " << data.city << ", Day Temperature: " << data.day_temp << ", Night Temperature: " << data.night_temp << endl;
    }
}

// Funkcija za sortiranje na podatocite od vekorot po opagjacki redosled
void sortWeatherData(vector<WeatherMK>& weather_data) 
{
    sort(weather_data.begin(), weather_data.end());
}

// Funkcija za zacuvuvanje na podatocite od vektorot vo text file
void saveWeatherDataToFile(const vector<WeatherMK>& weather_data)
{
    time_t now = time(0);
    tm* date = localtime(&now);
    string file_name = "INKI932.Weather" + to_string(date->tm_mon + 1) + to_string(date->tm_mday) + ".txt";
    ofstream output_file(file_name);
    if (output_file.is_open()) 
    {
        for (auto& data : weather_data) 
        {
            output_file << "City: " << data.city << ", Day Temperature: " << data.day_temp << ", Night Temperature: " << data.night_temp << endl;
        }
        output_file.close();
        cout << endl << "Successfully saved to file " << file_name << endl;
    }
    else 
    {
        cout << endl << "Failed to open file " << file_name << " for writing" << endl;
    }
}

int main() 
{
    vector<WeatherMK> weather_data = fillWeatherData();
    cout << "\nContents of the vector as entered:" << endl;
    printWeatherData(weather_data);
    sortWeatherData(weather_data);
    cout << "\nSorted contents of the vector:" << endl;
    printWeatherData(weather_data);
    saveWeatherDataToFile(weather_data);
    return 0;
}
