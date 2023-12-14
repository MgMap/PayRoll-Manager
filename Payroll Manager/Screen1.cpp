//
// Created by minau on 4/24/2023.
//

#include "Screen1.h"

Screen1::Screen1()
{
    enableState(SHOWN);
    text.setFont(Fonts::getFont(BASLERVILLE));
    text.setString("Welcome to PayRoll Manager");
    text.setPosition(750-text.getGlobalBounds().width/2, 200);
    text.setFillColor(sf::Color::Black);
    submit.setString("submit");
    submit.setPosition({500,500});
    newAccount.setString("Create New Account");
    newAccount.setPosition({800,500});
    username.setLabel("Username: ");
    username.setPosition({500,300});
    password.setLabel("Password: ");
    password.setPosition({500,400});
    fileReader("Payroll Manager/admin.txt");
}

Screen1::~Screen1()
{

}

void Screen1::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if(checkState(SHOWN))
    {
        target.draw(text);
        target.draw(username);
        target.draw(password);
        target.draw(submit);
        target.draw(newAccount);
    }
}

void Screen1::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(checkState(SHOWN))
    {
        username.addEventHandler(window, event);
        password.addEventHandler(window, event);
        submit.addEventHandler(window,event);

        if(!usernameStr.empty())
        {
            for(int i = 0; i < usernameStr.size();++i)
            {
                if(MouseEvents::isClicked(submit,window) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    if (username.getString() == usernameStr[i] && password.getString() == passwordStr[i])
                    {
                        disableStates(SHOWN);
                        enableState(HIDDEN);
                    }
                    else
                    {
                        std::cout << "User not Found";
                    }
                }
            }
        }
        createNewAccountHandler(window,event);
    }

}

void Screen1::createNewAccountHandler(sf::RenderWindow &window, sf::Event event)
{
    if(MouseEvents::isClicked(newAccount,window))
    {
        newAccount.toggleState(HIGHLIGHTED);
        if(newAccount.checkState(HIGHLIGHTED))
        {
            newAccount.setColor(sf::Color::Blue);
        }
        else
        {
            newAccount.setColor(sf::Color::Black);

        }
    }
    if(newAccount.checkState(HIGHLIGHTED) && MouseEvents::isClicked(submit,window))
    {

        saveUser(username.getString(),password.getString(),"Payroll Manager/admin.txt");
        fileReader("Payroll Manager/admin.txt");

    }
}

void Screen1::update()
{
    if(checkState(SHOWN))
    {
        username.update();
        password.update();
    }
}

void Screen1::fileReader(const std::string &filename)
{
    //testing
    /*usernameStr.push_back("Dave");
    passwordStr.push_back("1234");*/
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::stringstream ss(line);
            std::string token;

            getline(ss, token, ',');
            usernameStr.push_back(token);

            getline(ss, token, ',');
            passwordStr.push_back(token);
        }
        file.close();
    }
    else {
        std::cout << "Error opening file" << std::endl;
    }
}

void Screen1::saveUser(const std::string &user, const std::string &pass, const std::string &filename)
{
    std::ofstream outFile(filename, std::ios_base::app);
   // bool fileContainsData = (outFile.tellp() > 0);

    if (outFile.is_open())
    {
    // add a newline character before the first string if the file already contains data
        outFile <<std::endl;
        outFile << user <<","<< pass;


        outFile.close();
    std::cout << "Successfully saved ";
}
    else
        {
            std::cout << "Unable to open file " << filename << std::endl;
        }
}

std::string Screen1::getUserName()
{
    return username.getString();
}

void Screen1::setUserName(const std::string &string)
{
    username.setString(string);
}

std::string Screen1::getPassword()
{
    return std::__cxx11::string();
}

void Screen1::setPassword(const std::string &string)
{
    password.setString(string);
}

bool Screen1::checkUser(const string &user)
{
    return false;
}
