//
// Created by minau on 4/30/2023.
//

#ifndef SFML_PROJECT_SCREEN2_H
#define SFML_PROJECT_SCREEN2_H
#include "../DropDownMenu/Item.h"
#include "dataSort.h"
#include "../TextInput/TextBox.h"
#include "../FileTree/FileTree.h"
#include "../Helper/Position.h"
#include "Screen3.h"

class Screen2: public GUIComponents
{
private:
    Item Directory;
    Item Search;
    Item AddNew;
    Item Logout;
    TextBox searchBox;
    dataSort dataSort;
    FileTree PositionTree;
    FileTree SalaryTree;
    DataReader dataBank;
    Screen3 sc3;
    int index=0;
    int index1= 0;
    std::string filename;

public:
    void init();

    void initTree(FileTree tree,FileTree tree2);

    Screen2();

    Screen2(const std::string &filename);

    const string &getFilename() const;

    void setFilename(const string &filename);

    void readFile(const std::string &filename);
    ~Screen2() override;

    void saveFile(const std::vector<employeeData> &data,const std::string &filename);

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void setPosition(const sf::Vector2f &pos);
    sf::Vector2f getPosition();

    void initDirectory(FileTree tree,FileTree tree2,const std::vector<employeeData> &data);

    void pushDirectory(FileTree tree,FileTree tree1,const employeeData &data);

    void setSearchPosition(const sf::Vector2f &pos);
    sf::Vector2f getSearchPosition();

    void setFileTreePosition(const sf::Vector2f &pos);
    sf::Vector2f getFileTreePosition();

    void logOutHandler(sf::RenderWindow &window, sf::Event event);
    void searchHandler(sf::RenderWindow &window, sf::Event event);
    void addNewHandler(sf::RenderWindow &window, sf::Event event);
    void directoryHandler(sf::RenderWindow &window, sf::Event event);


    const Item &getDirectory() const;

    void setDirectory(const Item &directory);

    const Item &getSearch() const;

    void setSearch(const Item &search);

    const Item &getAddNew() const;

    void setAddNew(const Item &addNew);

    const Item &getLogout() const;

    void setLogout(const Item &logout);

    const TextBox &getSearchBox() const;

    void setSearchBox(const TextBox &searchBox);

    //const dataSort &getDataSort() const;

    //void setDataSort(const dataSort &dataSort);

    const FileTree &getTree() const;

    void setTree(const FileTree &tree);

};


#endif //SFML_PROJECT_SCREEN2_H
