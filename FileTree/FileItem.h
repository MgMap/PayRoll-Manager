//
// Created by minau on 4/23/2023.
//

#ifndef SFML_PROJECT_FILEITEM_H
#define SFML_PROJECT_FILEITEM_H
#include <SFML/Graphics.hpp>
#include "../Helper/States.h"
#include "../Images/Textures.h"
#include "../Font/Fonts.h"
#include "../Helper/MouseEvents.h"
#include "../Helper/GUIComponents.h"
class FileItem : public GUIComponents
{
private:
    sf::Sprite file;
    sf::Sprite folder;
    sf::Text name;
    sf::RectangleShape rect;
public:
    FileItem();
    FileItem(std::string name);
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void setSize(const sf::Vector2f & size);
    void setItem(stateEnum type);
    void setName(std::string name);

    void setPosition(sf::Vector2f pos);
    sf::Vector2f getPosition() const;

    void setClickedColor();
    void setNormalColor();
    sf::FloatRect getGlobalBounds() const;
    sf::FloatRect getNameGB()const;

    std::string getName();
};


#endif //SFML_PROJECT_FILEITEM_H
