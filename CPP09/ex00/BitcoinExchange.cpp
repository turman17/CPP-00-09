#include "BitcoinExchange.h"

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(const std::string &date)
{
    std::istringstream iss(date);
    int year, month, day;
    char delim1, delim2;

    if (!(iss >> year >> delim1 >> month >> delim2 >> day) || delim1 != '-' || delim2 != '-')
    {
        return false;
    }
    if (month < 1 || month > 12)
    {
        return false;
    }
    static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDay = daysInMonth[month - 1];
    if (month == 2 && isLeapYear(year))
    {
        maxDay = 29;
    }
    return day > 0 && day <= maxDay;
}

int findAndValidate(const std::string &date, double number, const std::map<std::string, double> &dataToTable, std::string &foundDate)
{
    if (!isValidDate(date))
    {
        std::cerr << "Invalid date: " << date << std::endl;
        return 1;
    }
    std::map<std::string, double>::const_iterator it = dataToTable.find(date);
    foundDate = date;

    if (it != dataToTable.end())
    {
        if (number > 0 && number < 1000)
            return 0;
        else
            return 1;
    }
    else
    {
        it = dataToTable.lower_bound(date);
        if (it != dataToTable.begin())
        {
            --it;
            foundDate = it->first;
            if (it->second > 0)
                return 0;
        }
    }
    return 1;
}

void output(const std::map<std::string, double> &dataToTable, const char *input)
{
    std::fstream file(input);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << input << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    if (line != "date | value")
    {
        throw std::runtime_error("Bad header format");
    }
    while (std::getline(file, line))
    {
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
        std::istringstream iss(line);
        std::string date;
        double number;

        if (std::getline(iss, date, '|') && (iss >> number))
        {
            std::string foundDate;
            int validateResult = findAndValidate(date, number, dataToTable, foundDate);
            if (validateResult == 0)
            {
                double priceAtDay = dataToTable.at(foundDate);
                if (priceAtDay < 0)
                    std::cout << "Error: Negative price on " << foundDate << " with price " << priceAtDay << std::endl;
                else
                    std::cout << "Date: " << date << ", Number: " << number << " => " << number * priceAtDay << std::endl;
            }
            else
                std::cerr << "Validation failed for " << date << " with number " << number << std::endl; // Diagnostic output
        }
        else
            std::cerr << "Failed to parse the input string: '" << line << "'" << std::endl;
    }
    file.close();
}

std::map<std::string, double> dataToTable(const char *toOpen)
{
    std::map<std::string, double> dataStruct;
    std::fstream file(toOpen);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << toOpen << std::endl;
        return dataStruct;
    }
    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string date;
        double price;

        if (std::getline(iss, date, ',') && (iss >> price))
        {
            dataStruct[date] = price;
        }
    }
    file.close();
    return dataStruct;
}

int validation(const char *toOpen)
{
    std::fstream file(toOpen);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << toOpen << std::endl;
        return -1;
    }
    file.close();
    return 0;
}

void parseData(const char *data, const char *input)
{
    try
    {
        if (validation(data) != 0 || validation(input) != 0 || strcmp(data, input) == 0)
            throw std::invalid_argument("Invalid input or data");

        std::map<std::string, double> dataTable = dataToTable(data);
        output(dataTable, input);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred" << std::endl;
    }
}