//
// Created by minau on 4/23/2023.
//

#include "FileTree.h"

std::vector<std::string> FileTree::split(std::string filepath)
{
    std::stringstream sstr(filepath);
    std::vector<std::string> v;
    while (sstr.good())
    {
        std::string subtr;
        getline(sstr, subtr, '/');
        v.push_back(subtr);
    }

    return v;
}

FileNode *FileTree::search(std::string s, FileNode *node)
{
    std::cout <<"SearchString: "<< s << std::endl;

    for (int i = 0; i < node->children.size(); ++i)
    {
        if (node->children[i]->data.getName() == s)
        {
            return node->children[i];
        }
    }

//    std::cout << "nully";
    return nullptr;
}

FileTree::FileTree()
{
    root = new FileNode;
    root->data.setItem(IS_FOLDER);
    root->data.setName("Directory");
    root->data.setPosition({500,500});
}

void FileTree::setPosition(sf::Vector2f pos)
{
    root->data.setPosition(pos);
}

void FileTree::setRootName(std::string name)
{
    root->data.setName(name);
}

void FileTree::push(std::string filepath, stateEnum type)
{
    std::vector<std::string> paths = split(filepath);
    FileNode* p = root;

    for (int i = 0; i < paths.size()-1; ++i)
    {
        if (p != nullptr)
        {
            for (int j = 0; j < p->children.size(); ++j)
            {
                if (p->children[j]->data.getName() == paths[i])
                {
                    p = p->children[j];
                    break;
                }
            }
        }
        else
            break;
    }
    if (p != nullptr){
        p->addChild(type, paths.back());
    } else
        std::cout << "Path not found" << std::endl;

}

void FileTree::treeClickedHandler()
{

}

void FileTree::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    //root->reposition(root);
    window.draw(*root);
}

void FileTree::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    root->addEventHandler(window,event,last_clicked);

}

void FileTree::update()
{

}

const std::string &FileTree::getLastClicked() const
{
    return last_clicked;
}

void FileTree::setLastClicked(const std::string &lastClicked)
{
    last_clicked = lastClicked;
}
