//
// Created by minau on 4/27/2023.
//

#include "Word.h"
Word::Word()
{
    setFont(Fonts::getFont(OPEN_SANS ));
    setFillColor(sf::Color::Green);
    setCharacterSize(40);
}

Word::Word(std::string word)  : Word()
{
    this->word = word;
}

void Word::setPriority(int priority)
{
    this->priority = priority;
}

int Word::getPriority() const
{
    return priority;
}

void Word::setWord(const std::string &word)
{
    this->word = word;
    setString(word);
}

const std::string &Word::getWord() const
{
    return word;
}

bool operator<(const Word &lhs, const Word &rhs)
{
    return lhs.priority < rhs.priority;
}

bool operator>(const Word &lhs, const Word &rhs)
{
    return lhs.priority > rhs.priority;
}

bool operator<=(const Word &lhs, const Word &rhs)
{
    return lhs.priority <= rhs.priority;
}

bool operator>=(const Word &lhs, const Word &rhs)
{
    return lhs.priority >= rhs.priority;
}

bool operator!=(const Word &lhs, const Word &rhs)
{
    return lhs.priority != rhs.priority;
}

bool operator==(const Word &lhs, const Word &rhs)
{
    return lhs.priority == rhs.priority;
}

void Word::operator+=(int plus)
{
    priority+= plus;
}