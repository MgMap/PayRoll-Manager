//
// Created by minau on 4/27/2023.
//

#ifndef SFML_PROJECT_WORD_H
#define SFML_PROJECT_WORD_H

#include <fstream>
#include <SFML/Graphics.hpp>
#include "../Font/Fonts.h"

class Word :public sf::Text
{
private:
    std::string word;
    int priority= 0;
    sf::Vector2f pos;
public:
    Word();
    Word(std::string str);
    void setPriority(int priority);
    int getPriority() const;
    void setWord(const std::string &word);
    const std::string &getWord() const;

    friend bool operator<(const Word& lhs, const Word& rhs);
    friend bool operator>(const Word& lhs, const Word& rhs);
    friend bool operator<=(const Word& lhs, const Word& rhs);
    friend bool operator>=(const Word& lhs, const Word& rhs);
    friend bool operator==(const Word& lhs, const Word& rhs);
    friend bool operator!=(const Word& lhs, const Word& rhs);

    void operator+=(int plus);

    friend std::ifstream& operator >> (std::ifstream& in, Word &words)
    {
        std::string str;
        in >> str;
        words.setString(str);
        return in;
    }
    friend std::ostream& operator <<(std::ostream& out, Word& words)
    {
        std::string str;
        str = words.getString();
        out << str;
        return out;
    }
};
#endif //SFML_PROJECT_WORD_H
