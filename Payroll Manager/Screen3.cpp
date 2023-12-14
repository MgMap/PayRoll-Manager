//
// Created by minau on 4/26/2023.
//

#include "Screen3.h"

Screen3::Screen3() //Screen3("","","")
{
    nameBox.setLabel("Name: ");
    salaryBox.setLabel("Salary$: ");
    save.setString("save");
    edit.setString("edit");
    setupPositionmMenu();
}

Screen3::Screen3(const std::string &name, const std::string &position, const std::string &salary)
{
    setNameBox(name);
    nameBox.setLabel("Name: ");
    salaryBox.setLabel("Salary$: ");
    save.setString("save");
    edit.setString("edit");
    setPositionBox(position);
    setupPositionmMenu();
    setSalary(salary);
    setPosition({200,200});
}

void Screen3::setNameBox(const std::string &string)
{
    nameBox.setString(string);
    nameBox.setLabel("Name: ");
}

std::string Screen3::getName()
{
    return nameBox.getString();
}

void Screen3::setPositionBox(const std::string &string)
{
    positionBox.inputBox.changeItem(string);

}

std::string Screen3::getPositionBox()
{
    return positionBox.inputBox.getString();
}

void Screen3::setSalary(const std::string &string)
{
    salaryBox.setString(string);
    salaryBox.setLabel("Salary: ");
}

std::string Screen3::getSalary()
{
    return salaryBox.getString();
}

void Screen3::setPosition(const sf::Vector2f &pos)
{
   nameBox.setPosition(pos);
    Position::bottom(nameBox,salaryBox,50);
    Position::bottom(salaryBox,positionBox,50);
    save.setPosition({pos.x-100,pos.y+200});
    edit.setPosition({pos.x+350, pos.y+200});

}

sf::Vector2f Screen3::getPosition()
{
    return nameBox.getPosition();
}

Screen3::~Screen3()
{

}

void Screen3::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

    target.draw(positionBox);
    target.draw(salaryBox);
    target.draw(save);
    target.draw(edit);
    target.draw(nameBox);
}

void Screen3::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    edit.addEventHandler(window,event);
    save.addEventHandler(window,event);
    //edit.disableStates(CLICKED);
    if(MouseEvents::isClicked(edit,window))
    {
        edit.toggleState(CLICKED);
    }
    if(edit.checkState(CLICKED))
        {
            edit.setColor(sf::Color::Red);
            nameBox.addEventHandler(window, event);
            positionBox.addEventHandler(window, event);
            salaryBox.addEventHandler(window, event);
        }
    }


void Screen3::update()
{
    nameBox.update();
    positionBox.update();
    salaryBox.update();
}

void Screen3::setupPositionmMenu()
{
    //positionBox.addItem("CEO");
    positionBox.addItem("Product Manager");
    positionBox.addItem("Accountant");
    positionBox.addItem("General Manager");
    positionBox.addItem("Software Engineer");
    positionBox.addItem("Instructor");
    positionBox.addItem("Programmer");
    positionBox.addItem("Intern");
    positionBox.addItem("FIRED");
}
