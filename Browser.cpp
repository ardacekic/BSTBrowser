#include "Browser.h"

Browser::Browser() {
    windows.append(Window());
}

void Browser::newWindow() {
    windows.prepend(Window());
}

void Browser::closeWindow() {
    if(windows.isEmpty()){
        return;
    }
    else{
        while(!windows.getFirstNode()->data.isEmpty())//once tablar
            windows.getFirstNode()->data.closeTab();
            windows.removeNodeAtIndex(0);
    }
}

void Browser::switchToWindow(int index) {
    if(windows.isEmpty()){
        return;
    }
    if(index <= 0){
        return; //already head or invalid index
    }else{
        windows.moveToIndex(index,0); //will do the trick
    }
    // TODO
}

Window &Browser::getWindow(int index) {
    return windows.getNodeAtIndex(index) -> data;
}

void Browser::moveTab(Window &from, Window &to) {
    // TODO
    Tab p = from.getActiveTab();
    to.newTab(p);
    from.closeTab();
    if(from.isEmpty()){
        return;
    }
}

void Browser::mergeWindows(Window &window1, Window &window2) {
    // TODO
    while(!window2.isEmpty()){
        window2.changeActiveTabTo(0);
        Tab p = window2.getActiveTab();
        window2.closeTab();
        window1.newTab(p);
    }
}

void Browser::mergeAllWindows() {
    // TOD
    int size = windows.getSize();
    for(int i = 0; i<size-1; i++)
        mergeWindows(getWindow(0),getWindow(i+1));
}

void Browser::closeAllWindows() {
    if(windows.isEmpty()){
        return;
    }
    else{
        while(!windows.isEmpty())
            closeWindow();
    }
    // TODO
}

void Browser::closeEmptyWindows() {
    // TODO               

    if(windows.isEmpty()){
        return;
    }
    else{
        Node<Window> *w = windows.getFirstNode(); 
        while(w->next != windows.getFirstNode()){
            if(w->data.isEmpty()){
                windows.removeNode(w);
                w = windows.getFirstNode();
            }else{
                w = w->next;
            }
        }
        if(w->data.isEmpty()){
            windows.removeNode(w);
        }
    }
}

void Browser::print() {
    Node<Window> *head = windows.getFirstNode();
    if(head == NULL) {
        std::cout << "The browser is empty" << std::endl;
    } else {
        (head -> data).print();
        head = head -> next;
        while(head != windows.getFirstNode()) {
            (head -> data).print();
            head = head -> next;
        }
    }
}
