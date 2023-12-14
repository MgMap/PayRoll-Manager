//
// Created by minau on 4/20/2023.
//

#include "Textures.h"
std::map<textureEnum, sf::Texture> Textures::map;
void Textures::load(textureEnum texture)
{
    map[texture].loadFromFile(getPath(texture));
}

std::string Textures::getPath(textureEnum texture)
{
    switch(texture)
    {
        case FOLDER: return "Images/icons/folder.png";
        case FILES: return "Images/icons/file.png";
    }
}

sf::Texture &Textures::getTexture(textureEnum texture)
{
    load(texture);
    return map[texture];
}
