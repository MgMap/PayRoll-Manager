//
// Created by minau on 4/27/2023.
//

#ifndef SFML_PROJECT_DATAREADER_H
#define SFML_PROJECT_DATAREADER_H
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <iterator>
#include "employeeData.h"
#include <sstream>

class DataReader
{
private:
    std::vector<std::string> name;
    std::vector<std::string> position;
    std::vector<std::string> salary;
    std::vector<employeeData> data;
public:
    void readFile(const std::string &filename);
    DataReader();
    DataReader(const std::string &filename);

    std::vector<employeeData> getData();
    void setData(std::vector<employeeData> data);

};

#endif //SFML_PROJECT_DATAREADER_H
