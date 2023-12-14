//
// Created by minau on 4/30/2023.
//

#include "Screen2.h"


void Screen2::init()
{
    Directory.setString("Directory");
    Search.setString("Search");
    AddNew.setString("Add New");
    Logout.setString("Log Out");
    searchBox.setLabel("Search: ");
    Directory.setPosition({50,50});
    Position::right(Directory,Search);
    Position::right(Search,AddNew);
    Position::right(AddNew,Logout);

    sc3.setPosition({500,180});
    searchBox.setPosition({800,150});
    searchBox.setSize(15);
    dataSort.prioritize(searchBox.getString(),searchBox);

    initTree(this->PositionTree,this->SalaryTree);

   /* PositionTree.push("Salary",IS_FOLDER);
    PositionTree.push("Salary/0-5000", IS_FOLDER);
    PositionTree.push("Salary/5000-10000",IS_FOLDER);
    PositionTree.push("Salary/10000-20000", IS_FOLDER);
    PositionTree.push("Salary/20000-40000",IS_FOLDER);
    PositionTree.push("Salary/40000-60000",IS_FOLDER);
    PositionTree.push("Salary/60000-80000",IS_FOLDER);
    PositionTree.push("Salary/80000-100000",IS_FOLDER);
    PositionTree.push("Salary/100000++",IS_FOLDER);*/

}

void Screen2::initTree(FileTree tree,FileTree tree2)
{
    tree.setPosition({50,110});
    tree.setRootName("Positions");

   // tree.push("Positions", IS_FOLDER);
    //tree.push("Positions/CEO",IS_FOLDER);
    tree.push("Positions/Product Manager",IS_FOLDER);
    tree.push("Positions/Accountant",IS_FOLDER);
    tree.push("Positions/General Manager", IS_FOLDER);
    tree.push("Positions/Software Engineer", IS_FOLDER);
    tree.push("Positions/Instructor", IS_FOLDER);
    tree.push("Positions/Programmer",IS_FOLDER);
    tree.push("Positions/Intern",IS_FOLDER);

    tree2.setPosition({400,110});
    tree2.setRootName("Salary");
    //tree2.push("Salary",IS_FOLDER);
    tree2.push("Salary/0-5000", IS_FOLDER);
    tree2.push("Salary/5000-10000",IS_FOLDER);
    tree2.push("Salary/10000-20000", IS_FOLDER);
    tree2.push("Salary/20000-40000",IS_FOLDER);
    tree2.push("Salary/40000-60000",IS_FOLDER);
    tree2.push("Salary/60000-80000",IS_FOLDER);
    tree2.push("Salary/80000-100000",IS_FOLDER);
    tree2.push("Salary/100000++",IS_FOLDER);
}

void Screen2::initDirectory(FileTree tree,FileTree tree1,const std::vector<employeeData> &data)
{
    for(int i = 0; i < data.size();i++)
    {
        if(data[i].getPosition() == "CEO")
        {
            tree.push("Positions/CEO/" + data[i].getName(),IS_FILE);
        }
        if(data[i].getPosition() == "Product Manager")
        {
            tree.push("Positions/Product Manager/" + data[i].getName(),IS_FILE);
        }
        if(data[i].getPosition() == "Accountant")
        {
            tree.push("Positions/Accountant/" + data[i].getName(),IS_FILE);
        }
        if(data[i].getPosition() == "General Manager")
        {
            tree.push("Positions/General Manager/" + data[i].getName(),IS_FILE);
        }
        if(data[i].getPosition() == "Software Engineer")
        {
            tree.push("Positions/Software Engineer/" + data[i].getName(),IS_FILE);
        }
        if(data[i].getPosition() == "Instructor")
        {
            tree.push("Positions/Instructor/" + data[i].getName(),IS_FILE);
        }
        if(data[i].getPosition() == "Programmer")
        {
            tree.push("Positions/Programmer/" + data[i].getName(),IS_FILE);
        }
        if(data[i].getPosition() == "Intern")
        {
            tree.push("Positions/Intern/" + data[i].getName(),IS_FILE);
        }

    }

    for(int i = 0; i < data.size();i++)
    {
        int salary = stoi(data[i].getSalary());
        if( salary <= 5000 && salary > 0)
        {
            tree1.push("Salary/0-5000/" + data[i].getName(),IS_FILE);
        }
        if(salary <= 10000 && salary > 5000)
        {
            tree1.push("Salary/5000-10000/" + data[i].getName(),IS_FILE);
        }
        if(salary <= 20000 && salary > 10000)
        {
            tree1.push("Salary/10000-20000/" + data[i].getName(),IS_FILE);
        }
        if(salary <= 40000 && salary > 20000)
        {
            tree1.push("Salary/20000-40000/" + data[i].getName(),IS_FILE);
        }
        if(salary <= 60000 && salary > 40000)
        {
            tree1.push("Salary/40000-60000/" + data[i].getName(),IS_FILE);
        }
        if(salary <= 80000 && salary > 60000)
        {
            tree1.push("Salary/60000-80000/" + data[i].getName(),IS_FILE);
        }
        if(salary <= 100000 && salary > 80000)
        {
            tree1.push("Salary/80000-100000/" + data[i].getName(),IS_FILE);
        }
        if(salary > 100000)
        {
            tree1.push("Salary/100000++/" + data[i].getName(),IS_FILE);
        }

    }
}

void Screen2::pushDirectory(FileTree tree,FileTree tree1, const employeeData &data)
{
        if(data.getPosition() == "CEO")
        {
            tree.push("Positions/CEO/" + data.getName(),IS_FILE);
        }
        if(data.getPosition() == "Product Manager")
        {
            tree.push("Positions/Product Manager/" + data.getName(),IS_FILE);
        }
        if(data.getPosition() == "Accountant")
        {
            tree.push("Positions/Accountant/" + data.getName(),IS_FILE);
        }
        if(data.getPosition() == "General Manager")
        {
            tree.push("Positions/General Manager/" + data.getName(),IS_FILE);
        }
        if(data.getPosition() == "Software Engineer")
        {
            tree.push("Positions/Software Engineer/" + data.getName(),IS_FILE);
        }
        if(data.getPosition() == "Sale Representative")
        {
            tree.push("Positions/Sale Representative/" + data.getName(),IS_FILE);
        }
        if(data.getPosition() == "Programmer")
        {
            tree.push("Positions/Programmer/" + data.getName(),IS_FILE);
        }
        if(data.getPosition() == "Intern")
        {
            tree.push("Positions/Intern/" + data.getName(),IS_FILE);
        }

    int salary = stoi(data.getSalary());
    if( salary <= 5000 && salary > 0)
    {
        tree1.push("Salary/0-5000/" + data.getName(),IS_FILE);
    }
    if(salary <= 10000 && salary > 5000)
    {
        tree1.push("Salary/5000-10000/" + data.getName(),IS_FILE);
    }
    if(salary <= 20000 && salary > 10000)
    {
        tree1.push("Salary/10000-20000/" + data.getName(),IS_FILE);
    }
    if(salary <= 40000 && salary > 20000)
    {
        tree1.push("Salary/20000-40000/" + data.getName(),IS_FILE);
    }
    if(salary <= 60000 && salary > 40000)
    {
        tree1.push("Salary/40000-60000/" + data.getName(),IS_FILE);
    }
    if(salary <= 80000 && salary > 60000)
    {
        tree1.push("Salary/60000-80000/" + data.getName(),IS_FILE);
    }
    if(salary <= 100000 && salary > 80000)
    {
        tree1.push("Salary/80000-100000/" + data.getName(),IS_FILE);
    }
    if(salary > 100000)
    {
        tree1.push("Salary/100000++/" + data.getName(),IS_FILE);
    }
}

Screen2::Screen2()
{
init();
}

Screen2::Screen2(const string &filename)
{
    dataBank.readFile(filename);
    dataSort.readData(filename);
    init();
}

void Screen2::readFile(const string &filename)
{
    //dataBank.readFile(filename);
    dataSort.readData(filename);
    initDirectory(this->PositionTree,this->SalaryTree, dataSort.getDataBank());
}

void Screen2::setPosition(const sf::Vector2f &pos)
{

}

sf::Vector2f Screen2::getPosition()
{
    return sf::Vector2f();
}

void Screen2::setSearchPosition(const sf::Vector2f &pos)
{
    searchBox.setPosition(pos);
}

sf::Vector2f Screen2::getSearchPosition()
{
    return sf::Vector2f();
}

void Screen2::setFileTreePosition(const sf::Vector2f &pos)
{
    PositionTree.setPosition(pos);
}

sf::Vector2f Screen2::getFileTreePosition()
{

}

Screen2::~Screen2()
{

}

void Screen2::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(!checkState(DISABLED))
    {
        searchHandler(window,event);
        directoryHandler(window,event);
        addNewHandler(window,event);
        logOutHandler(window,event);
    }
}

void Screen2::logOutHandler(sf::RenderWindow &window, sf::Event event)
{
    Logout.addEventHandler(window, event);

    if(MouseEvents::isClicked(Logout,window))
    {
        disableStates(SHOWN);
        dataSort.clearData();
    }
}

void Screen2::searchHandler(sf::RenderWindow &window, sf::Event event)
{
    Search.addEventHandler(window, event);

    if (MouseEvents::isClicked(Search, window))
    {
        Search.toggleState(SHOWN);
    }
    if (Search.checkState(SHOWN))
    {
        searchBox.addEventHandler(window, event);
    }
    //if (searchBox.checkState(HIGHLIGHTED))
    {
        dataSort.prioritize(searchBox.getString(), searchBox);
        dataSort.addEventHandler(window, event);
        sc3.addEventHandler(window, event);

        std::vector<employeeData> data = dataSort.getDrawableData();
        std::vector<employeeData> mainData = dataSort.getDataBank();
        //int index = 0;
        for (int i = 0; i < data.size(); i++)
        {
            if (MouseEvents::isClicked(data[i], window))
            {
                Search.disableStates(SHOWN);
                sc3.enableState(SHOWN);
                dataSort.enableState(CLICKED);
                AddNew.disableStates(CLICKED);
                for (int j = 0; j < mainData.size();j++)
                {
                    //index++;
                    if(data[i].getName() == mainData[j].getName())
                    {
                        index = j;
                        std::cout << "index found" << index<<std::endl;
                        sc3.setNameBox(mainData[index].getName());
                        sc3.setPositionBox(mainData[index].getPosition());
                        sc3.setSalary(mainData[index].getSalary());
                    }
                }
            }

        }
        if(dataSort.checkState(CLICKED))
        {
            if (MouseEvents::isClicked(sc3.save, window))
            {
                std::cout << "saved at index " << index << std::endl;
                mainData[index].setName(sc3.getName());
                mainData[index].setPositions(sc3.getPositionBox());
                mainData[index].setSalary(sc3.getSalary());
                if(mainData[index].getPosition() == "FIRED")
                {
                    for(int i = index; i < mainData.size()-1;i++)
                    {
                        mainData[i] = mainData[i+1];
                    }
                    mainData.pop_back();
                }
                dataSort.setDataBank(mainData);
                dataSort.prioritize(searchBox.getString(), searchBox);
                saveFile(dataSort.getDataBank(),filename);
                FileTree tempTree,tempTree1;
                initTree(tempTree,tempTree1);
                initDirectory(tempTree,tempTree1,dataSort.getDataBank());
                this->PositionTree=tempTree;
                this->SalaryTree = tempTree1;
                dataSort.disableStates(CLICKED);
                sc3.disableStates(SHOWN);
            }
        }
    }
}

void Screen2::addNewHandler(sf::RenderWindow &window, sf::Event event)
{
    AddNew.addEventHandler(window, event);
    if(MouseEvents::isClicked(AddNew,window))
    {
        AddNew.toggleState(CLICKED);
        Search.disableStates(SHOWN);
        dataSort.disableStates(CLICKED);
        sc3.toggleState(SHOWN);
        sc3.setNameBox("");
        sc3.setPositionBox("");
        sc3.setSalary("");
    }
    if(AddNew.checkState(CLICKED))
    {
        AddNew.setFillColor(sf::Color::Blue);
        if(MouseEvents::isClicked(sc3.save,window))
        {

            employeeData data;
            data.setName(sc3.getName());
            data.setPositions(sc3.getPositionBox());
            data.setSalary(sc3.getSalary());
            std::vector<employeeData> mainData = dataSort.getDataBank();
            mainData.push_back(data);
            pushDirectory(this->PositionTree,this->SalaryTree, data);
            dataSort.setDataBank(mainData);
            saveFile(dataSort.getDataBank(),filename);
            //dataSort.prioritize(searchBox.getString(), searchBox);

            std::cout << "Pushed Back successfully" <<std::endl;
            AddNew.disableStates(CLICKED);
            sc3.disableStates(SHOWN);
        }
    }

}

void Screen2::directoryHandler(sf::RenderWindow &window, sf::Event event)
{

    Directory.addEventHandler(window, event);

    if (MouseEvents::isClicked(Directory, window))
    {
        Directory.toggleState(SHOWN);
    }
    if (Directory.checkState(SHOWN))
    {
        //for position tree
        PositionTree.addEventHandler(window, event);
        std::vector<employeeData> mainData = dataSort.getDataBank();

        if (!PositionTree.getLastClicked().empty())
        {
            Directory.disableStates(SHOWN);
            sc3.enableState(SHOWN);

            for (int j = 0; j < mainData.size(); j++)
            {
                //index++;
                if (PositionTree.getLastClicked() == mainData[j].getName())
                {
                    PositionTree.enableState(ENABLED);
                    AddNew.disableStates(CLICKED);
                    index1 = j;
                    std::cout << "index found" << index1 << std::endl;
                    sc3.setNameBox(mainData[index1].getName());
                    sc3.setPositionBox(mainData[index1].getPosition());
                    sc3.setSalary(mainData[index1].getSalary());
                    PositionTree.setLastClicked("");
                }

            }
        }
    }
    std::vector<employeeData> mainData = dataSort.getDataBank();
    if (PositionTree.checkState(ENABLED))
        {
            if (MouseEvents::isClicked(sc3.save, window))
            {
                sc3.disableStates(SHOWN);
                std::cout << "saved at index " << index1 << std::endl;
                mainData[index1].setName(sc3.getName());
                mainData[index1].setPositions(sc3.getPositionBox());
                mainData[index1].setSalary(sc3.getSalary());
                if(mainData[index1].getPosition() == "FIRED")
                {
                    for(int i = index1; i < mainData.size()-1;i++)
                    {
                        mainData[i] = mainData[i+1];
                    }
                    mainData.pop_back();
                }
                dataSort.setDataBank(mainData);
                dataSort.prioritize(searchBox.getString(), searchBox);
                saveFile(dataSort.getDataBank(), filename);
                FileTree tempTree,tempTree1;
                initTree(tempTree,tempTree1);
                initDirectory(tempTree,tempTree1,dataSort.getDataBank());
                this->PositionTree=tempTree;
                this->SalaryTree = tempTree1;
                PositionTree.disableStates(CLICKED);
                //create new filetree init and repopulate it and change the root*
            }
        }

    if (Directory.checkState(SHOWN))
    {

        std::vector<employeeData> mainData = dataSort.getDataBank();
        //for Salary Tree
        SalaryTree.addEventHandler(window, event);
        //std::vector<employeeData> mainData1 = dataSort.getDataBank();

        if (!SalaryTree.getLastClicked().empty())
        {
            Directory.disableStates(SHOWN);
            sc3.enableState(SHOWN);
            for (int j = 0; j < mainData.size(); j++)
            {
                //index++;
                if (SalaryTree.getLastClicked() == mainData[j].getName())
                {
                    SalaryTree.enableState(ENABLED);
                    AddNew.disableStates(CLICKED);
                    index1 = j;
                    std::cout << "index found" << index1 << std::endl;
                    sc3.setNameBox(mainData[index1].getName());
                    sc3.setPositionBox(mainData[index1].getPosition());
                    sc3.setSalary(mainData[index1].getSalary());
                    SalaryTree.setLastClicked("");
                }

            }
        }
    }
        if (SalaryTree.checkState(ENABLED))
        {
            if (MouseEvents::isClicked(sc3.save, window))
            {
                sc3.disableStates(SHOWN);

                std::cout << "saved at index " << index1 << std::endl;
                mainData[index1].setName(sc3.getName());
                mainData[index1].setPositions(sc3.getPositionBox());
                mainData[index1].setSalary(sc3.getSalary());
                if(mainData[index1].getPosition() == "FIRED")
                {
                    for(int i = index1; i < mainData.size()-1;i++)
                    {
                        mainData[i] = mainData[i+1];
                    }
                    mainData.pop_back();
                }
                dataSort.setDataBank(mainData);
                dataSort.prioritize(searchBox.getString(), searchBox);
                saveFile(dataSort.getDataBank(), filename);
                FileTree tempTree,tempTree1;
                initTree(tempTree,tempTree1);
                initDirectory(tempTree,tempTree1,dataSort.getDataBank());
                this->PositionTree = tempTree;
                this->SalaryTree=tempTree1;
                SalaryTree.disableStates(CLICKED);
                //create new filetree init and repopulate it and change the root*
            }
        }
    }

void Screen2::update()
{
    //if(checkState(DISABLED))
    {
        searchBox.update();
        sc3.update();
    }
}

void Screen2::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

    if(!checkState(DISABLED))
    {
        if(sc3.checkState(SHOWN))
            target.draw(sc3);
        if(Directory.checkState(SHOWN))
        {
            target.draw(PositionTree);
            target.draw(SalaryTree);
        }

        if(Search.checkState(SHOWN))
        target.draw(searchBox);

        target.draw(Directory);
        target.draw(Search);
        target.draw(AddNew);
        target.draw(Logout);

        if (searchBox.checkState(HIGHLIGHTED))
        {
            target.draw(dataSort);
        }
    }

}
const Item &Screen2::getDirectory() const
{
    return Directory;
}

void Screen2::setDirectory(const Item &directory)
{
    Directory = directory;
}

const Item &Screen2::getSearch() const
{
    return Search;
}

void Screen2::setSearch(const Item &search)
{
    Search = search;
}

const Item &Screen2::getAddNew() const
{
    return AddNew;
}

void Screen2::setAddNew(const Item &addNew)
{
    AddNew = addNew;
}

const Item &Screen2::getLogout() const
{
    return Logout;
}

void Screen2::setLogout(const Item &logout)
{
    Logout = logout;
}

const TextBox &Screen2::getSearchBox() const
{
    return searchBox;
}

void Screen2::setSearchBox(const TextBox &searchBox)
{
    Screen2::searchBox = searchBox;
}

/*const dataSort &Screen2::getDataSort() const
{
    return dataSort;
}*/

/*void Screen2::setDataSort(const dataSort &dataSort)
{
    Screen2::dataSort = dataSort;
}*/

const FileTree &Screen2::getTree() const
{
    return PositionTree;
}

void Screen2::setTree(const FileTree &tree)
{
    Screen2::PositionTree = tree;
}

void Screen2::saveFile(const vector<employeeData> &data, const string &filename)
{
    std::ofstream outFile(filename);
    if(outFile.is_open())
    {
        for(int i = 0; i <data.size();i++)
        {
            outFile << data[i].getName() <<"," <<data[i].getPosition()<<","<<data[i].getSalary();
            outFile <<std::endl;
        }
        std::cout << "Successfully Saved";
        outFile.close();
    }
    else
    {
        std::cout << "Unable to open file" << filename <<std::endl;
    }
}

const string &Screen2::getFilename() const
{
    return filename;
}

void Screen2::setFilename(const string &filename)
{
    Screen2::filename = filename;
}
