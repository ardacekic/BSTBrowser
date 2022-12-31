#include "Window.h"
#include <stdio.h>
#include <iostream>
Window::Window() {
    this->activeTab = 0;
    tabs.append(Tab());
}

Tab Window::getActiveTab() {
    if(isEmpty()){
        return Tab();
    }
    else{
        return this->tabs.getNodeAtIndex(this->activeTab)->data;
    }
    // TODO
}

bool Window::isEmpty() const {
    if(this->tabs.isEmpty()){
        return true;
    }
    else{
        return false;
    }
    // TODO
}

void Window::newTab(const Tab &tab) {
    // TODO
    if(activeTab == -1){
        this->activeTab++;
        this->tabs.append(tab);
    }
    else{
        this->tabs.insertAfterNode(tab,this->tabs.getNodeAtIndex(activeTab));
        this->activeTab++;
    }
}

void Window::closeTab() {
    if(isEmpty()){
        this->activeTab = -1;
    }else{
        this->tabs.removeNodeAtIndex(activeTab);
        if(activeTab > tabs.getSize()-1)
            this->activeTab--;
    }
}

void Window::moveActiveTabTo(int index) {
    // TODO
    this->tabs.moveToIndex(this->activeTab,index);
    if(index >= this->tabs.getSize()){
        activeTab =  this->tabs.getSize()-1;
    }else{
        activeTab = index;
    }
}

void Window::changeActiveTabTo(int index) {
    // TODO
    if(index >= this->tabs.getSize()){
        return;
    }
    if(index < 0){
        return;
    }
    else{
        this->activeTab = index;
    }
}

void Window::addTab(Node<Tab> &tab) {
    if(this->tabs.isEmpty()){
        newTab(tab.data);
        changeActiveTabTo(0);
    }else{
        Node<Tab> *p = tabs.getLastNode();
        this->tabs.insertAfterNode(tab.data,p);
    }
}

void Window::print() {
    if(tabs.isEmpty()) std::cout << "Window is empty" << std::endl;
    else std::cout << "The active tab is tab " << activeTab << std::endl;
    tabs.print();
}
