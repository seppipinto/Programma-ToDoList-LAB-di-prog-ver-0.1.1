//
// Created by seppi on 10/09/2019.
//

#ifndef LAB_TODOLIST_ITEM_H
#define LAB_TODOLIST_ITEM_H

#include <iostream>
#include <string>

class Item {

public:
    explicit Item(std::string dat, bool done= false) : data(dat), done(done) {}

    std::string getData() const {
        if(done){
            return data + " -Done";}
        else
            return data;
    }

private:
    std::string data;
    bool done;
};

#endif //LAB_TODOLIST_ITEM_H
