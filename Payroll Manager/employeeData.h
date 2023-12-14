//
// Created by minau on 4/27/2023.
//

#ifndef SFML_PROJECT_EMPLOYEEDATA_H
#define SFML_PROJECT_EMPLOYEEDATA_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Helper/GUIComponents.h"
#include "../Font/Fonts.h"
#include "../Helper/MouseEvents.h"
#include "../DEFINITIONS.h"

class employeeData : public GUIComponents
{
private:
    std::string name;
    std::string position;
    std::string salary;
    sf::Text nameText;


    int priority =0;

public:

    employeeData();
    employeeData(const std::string &name,const std::string &position, const std::string &salary);

    int getPriority() const;
    void setPriority(int priority);

    void setPosition(const sf::Vector2f &pos);

    sf::FloatRect getGlobalBounds() const;

    friend bool operator<(const employeeData& lhs, const employeeData& rhs);
    friend bool operator>(const employeeData& lhs, const employeeData& rhs);
    friend bool operator<=(const employeeData& lhs, const employeeData& rhs);
    friend bool operator>=(const employeeData& lhs, const employeeData& rhs);
    friend bool operator==(const employeeData& lhs, const employeeData& rhs);
    friend bool operator!=(const employeeData& lhs, const employeeData& rhs);

    void operator+=(int plus);

    ~employeeData() override;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

public:
    const std::string &getName() const
    {
        return name;
    }

    void setName(const std::string &name)
    {
        employeeData::name = name;
        nameText.setString(name);
    }

    const std::string &getPosition() const
    {
        return position;
    }

    void setPositions(const std::string &position)
    {
        employeeData::position = position;
    }

    const std::string &getSalary() const
    {
        return salary;
    }

    void setSalary(const std::string &salary)
    {
        employeeData::salary = salary;
    }
};




#endif //SFML_PROJECT_EMPLOYEEDATA_H
