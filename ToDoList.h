//
// Created by seppi on 10/09/2019.
//

#ifndef LAB_TODOLIST_TODOLIST_H
#define LAB_TODOLIST_TODOLIST_H

#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include "Item.h"
#include "Category.h"

class ToDoList {

public:

    template<typename... Args>
    void addItem(const std::string& item, Args&&... categorie) {
        std::vector<std::string> _categories{ categorie... };
        for (auto category : _categories) {
            if (categories.empty()) {
                Category newCategory(category);
                newCategory.addItemToCategory(item);
                categories[category] = newCategory;
            }
            else {
                //If a category was found add the item to that category
                if (categories.find(category) != categories.end()) {
                    categories[category].addItemToCategory(item);
                }
                    //otherwise create a category with that item on it
                else{
                    Category newCategory(category);
                    newCategory.addItemToCategory(item);
                    categories[category] = newCategory;
                }
            }
        }
    }

    void removeItem(const std::string& item, const std::string& category){
        (categories.find(category))->second.remove(item);
    }

    void setDone(const std::string& item, const std::string& category){
        (categories.find(category))->second.setItemDone(item);
    }

    void updateItem(const std::string& oldItem, const std::string& newItem){
        for (auto& category : categories) {
            category.second.updateItem(oldItem, newItem);
        }
    }

    template<typename... Args>
    void viewList(Args&&... arguments) const{
        std::vector < std::string > _categories{ arguments... };
        //If there are no parameters, print the whole list
        if (_categories.empty()){
            for (const auto& category_ : categories){
                std::cout << category_.first << ": "<< std::endl;
                category_.second.displayCategory();
                std::cout<< std::endl;
            }
        }
        else if (_categories.size() == 1) {
            std::cout << _categories[0] << std::endl;
            categories.at(_categories[0]).displayCategory();
        }
    }


private:
    std::unordered_map<std::string, Category> categories;
};

#endif //LAB_TODOLIST_TODOLIST_H
