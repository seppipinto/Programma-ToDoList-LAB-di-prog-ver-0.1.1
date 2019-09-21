//
// Created by seppi on 10/09/2019.
//

#ifndef LAB_TODOLIST_CATEGORY_H
#define LAB_TODOLIST_CATEGORY_H

#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <vector>
#include "Item.h"

class Category {

public:
    Category() = default;
    explicit Category(const std::string& _name) : name(_name){ }

    void addItemToCategory(const std::string& nitem)
    {
        std::shared_ptr<Item> item(new Item(nitem));
        list.push_back(item);
    }

    void remove(const std::string& item)
    {
        std::shared_ptr<Item> removeditem(new Item(item));
        list.erase((std::find_if(list.begin(), list.end(), [item](std::shared_ptr<Item> it) {return it->getData() == item; })));
    }


    void setItemDone(const std::string& doneItem){
        list.erase(std::find_if(list.begin(), list.end(), [doneItem](std::shared_ptr<Item> it) {return it->getData() == doneItem; }));
        std::shared_ptr<Item> item(new Item(doneItem, true));
        list.push_back(item);
    }

    void updateItem(const std::string& oldItem, const std::string& newItem){
        list.erase(std::find_if(list.begin(), list.end(), [oldItem](std::shared_ptr<Item> it) {return it->getData() == oldItem; }));
        std::shared_ptr<Item> item(new Item(newItem));
        list.push_back(item);
    }

    void displayCategory() const
    {
        for (const auto & item : list)
            std::cout << "- " << item->getData() << std::endl;
    }


private:
    std::string name;
    std::vector<std::shared_ptr<Item>> list;
};

#endif //LAB_TODOLIST_CATEGORY_H
