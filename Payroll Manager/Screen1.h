//
// Created by minau on 4/24/2023.
//

#ifndef SFML_PROJECT_SCREEN1_H
#define SFML_PROJECT_SCREEN1_H
#include "../TextInput/TextBox.h"
#include "../Helper/States.h"
#include "../Helper/EventHandler.h"
#include "../Helper/States.h"
#include "../Helper/GUIComponents.h"
#include "../Helper/Button.h"
#include <fstream>
#include <sstream>
#include "Screen2.h"

class Screen1: public GUIComponents
{
private:
    sf::Text text;
    TextBox username;
    TextBox password;

    std::vector<std::string> usernameStr;
    std::vector<std::string> passwordStr;

public:
    Button submit;
    Button newAccount;
    Screen1();
    ~Screen1() override;

    std::string getUserName();
    void setUserName(const std::string &string);

    std::string getPassword();
    void setPassword(const std::string &string);

    void fileReader(const std::string &filename);
    void saveUser(const std::string& user, const std::string &pass, const std::string &filename);
    bool checkUser(const std::string &user);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void createNewAccountHandler(sf::RenderWindow& window, sf::Event event);

    void update() override;
};


#endif //SFML_PROJECT_SCREEN1_H
