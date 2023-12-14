//
// Created by minau on 4/27/2023.
//

#include "DataReader.h"

void DataReader::readFile(const std::string &filename)
{
    std::ifstream file(filename);

    if (file.is_open())
    {
        std::string line;
        while (getline(file, line)) {
            std::stringstream ss(line);
            std::string token;

            getline(ss, token, ',');
            name.push_back(token);

            getline(ss, token, ',');
            position.push_back(token);

            getline(ss,token,',');
            salary.push_back(token);
        }
        file.close();
        std::cout<< "Data read successfully" <<std::endl;
    }
    else
    {
        std::ofstream outfile(filename);
        std::cout << "Error opening file" << std::endl;
    }
    for(int i =0; i < name.size(); i++)
    {
        data.push_back(employeeData(name[i],position[i],salary[i]));
    }
}

DataReader::DataReader()
{

}

DataReader::DataReader(const std::string &filename)
{
    readFile(filename);

}


std::vector<employeeData> DataReader::getData()
{
    return data;
}

void DataReader::setData(std::vector<employeeData> data)
{
    this->data = data;
}
