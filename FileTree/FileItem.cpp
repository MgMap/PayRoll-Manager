//
// Created by minau on 4/23/2023.
//

#include "FileItem.h"
#include "../Helper/Position.h"

FileItem::FileItem()
{
    file.setTexture(Textures::getTexture(FILES));
    folder.setTexture(Textures::getTexture(FOLDER));
    name.setFont(Fonts::getFont(BASLERVILLE));
    name.setFillColor(sf::Color::Black);
    //name.setCharacterSize(50);
    //rect.setSize({100,20});
    //rect.setFillColor(sf::Color::Black);
    //setSize({300,20});
    file.setPosition(500,500);
    folder.setPosition(500,500);
    file.setScale(0.05,0.05);
    folder.setScale(0.03,0.03);
    rect.setPosition(500,500);

}

FileItem::FileItem(std::string name)
{
    setName(name);
}



void FileItem::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if (checkState(IS_FILE))
    {
        if (MouseEvents::isHover(file, window))
        {
            file.setColor(sf::Color::Blue);
            name.setFillColor(sf::Color::Blue);
        }
        else
        {
            file.setColor(sf::Color::White);
            name.setFillColor(sf::Color::Black);
        }
    }
    if (checkState(IS_FOLDER))
    {
        if (MouseEvents::isHover(folder, window))
        {
            folder.setColor(sf::Color::Red);
            name.setFillColor(sf::Color::Red);
        }
        else
        {
            folder.setColor(sf::Color::White);
            name.setFillColor(sf::Color::Black);
        }
    }
    if (checkState(CLICKED))
    {
        setClickedColor();
    }
}

void FileItem::update()
{

}

void FileItem::setItem(stateEnum type)
{
    if (type == IS_FOLDER){
        enableState(IS_FOLDER);
        disableStates(IS_FILE);
    }
    else if (type == IS_FILE){
        enableState(IS_FILE);
        disableStates(IS_FOLDER);
    }
}

void FileItem::setSize(const sf::Vector2f &size)
{
    rect.setSize({size.x, static_cast<float>(name.getCharacterSize())});
}

void FileItem::setName(std::string name)
{
    this->name.setString(name);
    Position::right(file, this->name);//
    if (checkState(IS_FILE)){
        Position::right(file, this->name);
    }
    if (checkState(IS_FOLDER)){
        Position::right(folder, this->name);
    }
}

void FileItem::setPosition(sf::Vector2f pos)
{
    file.setPosition(pos);
    folder.setPosition(pos);

    if (checkState(IS_FILE))
    {
        Position::right(file, this->name);
    }
    if (checkState(IS_FOLDER)){
        Position::right(folder, this->name);
    }
}

sf::Vector2f FileItem::getPosition() const
{
    if(checkState(IS_FOLDER))
        return folder.getPosition();
    if(checkState(IS_FILE))
        return file.getPosition();
}

void FileItem::setClickedColor()
{
    folder.setColor((sf::Color::Red));
    name.setFillColor((sf::Color::Red));
}

void FileItem::setNormalColor()
{
    folder.setColor(sf::Color::White);
    name.setFillColor(sf::Color::Black);
}

sf::FloatRect FileItem::getGlobalBounds() const
{
    sf::FloatRect bounds;
    if (checkState(IS_FILE))
    {
        bounds = {file.getGlobalBounds().left,file.getGlobalBounds().top,
                  file.getGlobalBounds().width+name.getGlobalBounds().width,file.getGlobalBounds().height};
    }
    if (checkState(IS_FOLDER))
    {
        bounds = {folder.getGlobalBounds().left,folder.getGlobalBounds().top,
                  folder.getGlobalBounds().width+name.getGlobalBounds().width,folder.getGlobalBounds().height};
    }
    return bounds;
}

sf::FloatRect FileItem::getNameGB() const
{
    return name.getGlobalBounds();
}

std::string FileItem::getName()
{
    return name.getString();
}

void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    if (checkState(IS_FILE)){
        window.draw(file);
    }

    if (checkState(IS_FOLDER)){
        window.draw(folder);
    }

    window.draw(name);
    //window.draw(rect);
}