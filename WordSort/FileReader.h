//
// Created by minau on 4/27/2023.
//

#ifndef SFML_PROJECT_FILEREADER_H
#define SFML_PROJECT_FILEREADER_H
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <iterator>
template<typename T>
class FileReader : public std::iterator<std::random_access_iterator_tag, T>
{
private:

    std::vector<T> data;
public:
    typedef typename std::vector<T>::iterator iterator;
    void getData(const std::string& filename);
    FileReader();
    FileReader(const std::string& filename);
    std::vector<T> getData();
    iterator begin();
    iterator end();
    void printList();

};
#include "FileReader.cpp"

#endif //SFML_PROJECT_FILEREADER_H
