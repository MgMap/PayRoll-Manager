//
// Created by minau on 4/27/2023.
//

#ifndef SFML_PROJECT_FILEREADER_CPP
#define SFML_PROJECT_FILEREADER_CPP

#include "FileReader.h"
template<typename T>
FileReader<T>::FileReader()
{

}

template<typename T>
FileReader<T>::FileReader(const std::string& filename)
{
    getData(filename);
}
template<typename T>
void FileReader<T>::getData(const std::string& filename)
{
    std::ifstream fin;
    fin.open(filename);
    if(fin.fail())
        exit(28);
    T next;
    while(fin >> next)
    {
        data.push_back(next);
    }
    fin.close();
}

template<typename T>
std::vector<T> FileReader<T>::getData()
{
    return data;
}

template<typename T>
typename FileReader<T>::iterator FileReader<T>::end()
{
    return data.end();
}

template<typename T>
typename FileReader<T>::iterator FileReader<T>::begin()
{
    return data.begin();
}

template<typename T>
void FileReader<T>::printList()
{
    for(int i = 0; i < data.size();++i)
    {
        std::cout << data[i] <<std::endl;
    }
}

#endif