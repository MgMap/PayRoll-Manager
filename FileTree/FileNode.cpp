//
// Created by minau on 4/23/2023.
//

#include "FileNode.h"

void FileNode::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    reposition();

    window.draw(data);

    if (data.checkState(IS_FOLDER))
    {
        if (data.checkState(SHOWN))
        {
            for (int i = 0; i < children.size(); ++i)
            {
                window.draw(*children[i]);
            }
        }
    }
}

void FileNode::addEventHandler(sf::RenderWindow &window, sf::Event event, std::string &name)
{
    data.addEventHandler(window,event);

    if(data.checkState(IS_FILE))
    {
        if(MouseEvents::isClicked(data,window))
        {
            data.enableState(CLICKED);
            //data.enableState(SHOWN);
            if(data.checkState(CLICKED))
            {
                name = data.getName();
                data.disableStates(CLICKED);
            }
        }
        else
        {
            data.disableStates(CLICKED);
        }
    }
    if (data.checkState(IS_FOLDER))
    {
        if (MouseEvents::isClicked(data, window))
        {
            data.toggleState(SHOWN);

           // position();
        }
        if (data.checkState(SHOWN))
        {
            for (int i = 0; i < children.size(); ++i)
            {
                children[i]->addEventHandler(window,event,name);
            }
        }

            if(!data.checkState(SHOWN))
            {
                data.disableStates(SHOWN);
                data.setNormalColor();
                for (int i = 0; i < children.size(); ++i)
                {
                    children[i]->data.disableStates(SHOWN);
                }
            }
        }
    }


void FileNode::update()
{

}

void FileNode::addChild(stateEnum type, std::string name)
{
    FileNode* child = new FileNode;
    child->data.setItem(type);
    child->data.setName(name);
    children.push_back(child);

}

/*void FileNode::position() const
{
    if (!children.empty())
    {
        children[0]->data.setPosition({data.getNameGB().left, data.getNameGB().top+data.getNameGB().height});
        for (int i = 0; i < children.size()-1; ++i)
        {
            Position::bottom(children[i]->data, children[i+1]->data);
        }
    }
}*/

void FileNode::reposition() const
{
    float x = data.getPosition().x + 20;
    float y = data.getPosition().y;
    y= data.getGlobalBounds().top+ data.getGlobalBounds().height+5;

    if(data.checkState(SHOWN))
    {
        for(int i = 0; i < children.size(); ++i)
        {
            children[i]->setPosition({x,y});
           // children[i]->reposition();
            y+= children[i]->getGlobalBounds().height+5;
        }
    }
}

void FileNode::setPosition(sf::Vector2f pos)
{
    data.setPosition(pos);
    reposition();
}

sf::FloatRect FileNode::getGlobalBounds()
{
    sf::FloatRect bounds;
    if(data.checkState(SHOWN))
    {
        bounds = data.getGlobalBounds();
        for(int i = 0; i < children.size(); ++i)
        {
            bounds.height += children[i]->data.getGlobalBounds().height+5;
           //std::cout << bounds.height;
        }
    }
    else
    {
        bounds = data.getGlobalBounds();
    }
    return bounds;
}

FileItem FileNode::getData()
{
    return data;
}

void FileNode::addEventHandler(sf::RenderWindow &window, sf::Event event)
{

}
