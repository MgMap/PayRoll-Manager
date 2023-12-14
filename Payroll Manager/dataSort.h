//
// Created by minau on 4/27/2023.
//

#ifndef SFML_PROJECT_DATASORT_H
#define SFML_PROJECT_DATASORT_H
#include <vector>
#include "DataReader.h"
#include "employeeData.h"
#include "../TextInput/TextBox.h"
#include "../Helper/Position.h"
#include "../WordSort/Heap.h"



class dataSort :public GUIComponents
{
private:
    std::vector<employeeData> DataBank;
    std::vector<employeeData> drawableData;

    sf::Vector2f pos;
    DataReader dataReader;
public:
    dataSort();
    dataSort(const std::string &filename);
    void clearData();
    const vector<employeeData> &getDataBank() const;

    void setDataBank(const vector<employeeData> &dataBank);

    const vector<employeeData> &getDrawableData() const;

    void setDrawableData(const vector<employeeData> &drawableData);

    const sf::Vector2f &getPos() const;

    void setPos(const sf::Vector2f &pos);

    const DataReader &getDataReader() const;

    void setDataReader(const DataReader &dataReader);

    void readData(const std::string &filename);

    void setPosition(const sf::Vector2f &pos);

    void prioritize(const std::string& tiText, const TextBox& ti);

    ~dataSort() override;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
public:
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;
};


#endif //SFML_PROJECT_DATASORT_H
