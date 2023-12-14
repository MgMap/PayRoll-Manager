//
// Created by minau on 4/20/2023.
//

#ifndef SFML_PROJECT_TEXTURES_H
#define SFML_PROJECT_TEXTURES_H
#include <SFMl/Graphics.hpp>
#include <map>

enum textureEnum
{
    FILES,
    FOLDER,
    LAST_ENUM
};

class Textures
{
    private:
        static std::map<textureEnum, sf::Texture> map;
        static void load(textureEnum texture);
        static std::string getPath(textureEnum texture);
    public:
        static sf::Texture& getTexture(textureEnum texture);
    };



#endif //SFML_PROJECT_TEXTURES_H
