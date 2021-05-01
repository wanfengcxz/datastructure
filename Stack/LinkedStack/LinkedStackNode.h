//
// Created by 晚风吹行舟 on 2021/4/27.
//

template<typename T>
struct LinkedStackNode{

    T data;
    LinkedStackNode * next;

    LinkedStackNode(T data = 0):data(data), next(nullptr){

    }

};



