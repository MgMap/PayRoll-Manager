//
// Created by minau on 4/26/2023.
//

#ifndef SFML_PROJECT_SCREEN3_H
#define SFML_PROJECT_SCREEN3_H
#include "../TextInput/TextBox.h"
#include "../Helper/GUIComponents.h"
#include "../Helper/MouseEvents.h"
#include "../DropDownMenu/DropDownMenu.h"
#include "../Helper/Position.h"
#include "../Helper/Button.h"
#include "DataReader.h"

class Screen3: public GUIComponents
{
private:
    TextBox nameBox;
    DropDownMenu positionBox;
    TextBox salaryBox;

    DataReader dataBank;

public:
    Button edit;
    Button save;
    Screen3();
    Screen3(const std::string &name, const std::string &position, const std::string &salary);
    void setNameBox(const std::string &string);
    std::string getName();

    void setupPositionmMenu();
    void setPositionBox(const std::string &string);
    std::string getPositionBox();

    void setSalary(const std::string &string);
    std::string getSalary();

    void setPosition(const sf::Vector2f &pos);
    sf::Vector2f getPosition();

    ~Screen3() override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;
};


#endif //SFML_PROJECT_SCREEN3_H
