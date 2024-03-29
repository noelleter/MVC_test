//
//  model.cpp
//  MVC_test
//
//  Created by 김노은 on 29/11/2019.
//  Copyright © 2019 Noeun-Kim. All rights reserved.
//

#pragma once
#include <string>
#include "Common.cpp"
using namespace std;

class Model {
public:
    Model(const string &data) {
        this->SetData(data);
    }
    Model() { } // default constructor
    string Data(){
        return this->data;
    }
    
    void SetData(const string &data) {
        this->data = data;
        if (this->event != nullptr) { // data change callback event
            this->event(data);
        }
    }
    //  register the event when data changes.
    void RegisterDataChangeHandler(DataChangeHandler handler) {
        this->event = handler;
    }
private:
    string data = "";
    DataChangeHandler event = nullptr;
};
