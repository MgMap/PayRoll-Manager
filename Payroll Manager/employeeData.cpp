//
// Created by minau on 4/27/2023.
//

#include "employeeData.h"

employeeData::employeeData() : employeeData("","","")
{

}

employeeData::employeeData(const std::string &name, const std::string &position, const std::string &salary)
{
    nameText.setString(name);
    nameText.setFillColor(sf::Color::Red);
    nameText.setFont(Fonts::getFont(ROBOTOMONO));
    nameText.setCharacterSize(CHARACTER_SIZE);
    setName(name);
    setPositions((position));
    setSalary(salary);
}

void employeeData::setPriority(int priority)
{
    this->priority = priority;
}

int employeeData::getPriority() const
{
    return priority;
}

bool operator<(const employeeData &lhs, const employeeData &rhs)
{
    return lhs.priority < rhs.priority;
}

bool operator>(const employeeData &lhs, const employeeData &rhs)
{
    return lhs.priority > rhs.priority;
}

bool operator<=(const employeeData &lhs, const employeeData &rhs)
{
    return lhs.priority <= rhs.priority;
}

bool operator>=(const employeeData &lhs, const employeeData &rhs)
{
    return lhs.priority >= rhs.priority;
}

bool operator==(const employeeData &lhs, const employeeData &rhs)
{
    return lhs.priority == rhs.priority;
}

bool operator!=(const employeeData &lhs, const employeeData &rhs)
{
    return lhs.priority != rhs.priority;
}

void employeeData::operator+=(int plus)
{
    priority+= plus;
}

employeeData::~employeeData()
{

}

void employeeData::setPosition(const sf::Vector2f &pos)
{
    nameText.setPosition(pos);
}

sf::FloatRect employeeData::getGlobalBounds() const
{
    return nameText.getGlobalBounds();
}

void employeeData::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(nameText);
}

void employeeData::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(MouseEvents::isHover(nameText,window))
    {
        nameText.setFillColor(sf::Color::Blue);
    }
    else
    {
        nameText.setFillColor(sf::Color::Red);
    }
}

void employeeData::update()
{

}
