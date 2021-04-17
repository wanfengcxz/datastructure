//
// Created by 晚风吹行舟 on 2021/4/17.
//

#include <iostream>

using namespace std;

namespace staticAllocation {

    const int MaxSize = 50;
    using T = int;

    struct SeqTable {

    private:
        int length;
        T data[MaxSize];
    public:

        SeqTable():length(0){

        }

        int getLength() {
            return this->length;
        }

        /**
         * insert
         * @param i insert location
         * @param value insert value
         * @return is insert success
         */
        bool insertElement(int i, T value);

        /**
         * delete
         * @param i delete location
         * @param e delete value
         * @return is delete success
         */
        bool deleteElement(int i, T &e);

        /**
         * locate given element
         * @param e given element
         * @return location
         */
        int locateElement(T e);

    };

    bool SeqTable::insertElement(int i, T value) {
        // is full ?
        if (length >= MaxSize) {
            return false;
        }
        // is i legal ?
        if (i < 1 || i > length + 1) {
            return false;
        }
        // move the data behind of i
        for (int j = length-1;j>=i-1;j--){
            data[j+1] = data[j];
        }
        // insert
        data[i-1] = value;
        this->length++;

        return true;
    }

    bool SeqTable::deleteElement(int i, T &e) {
        // is i legal ?
        if (i<1 || i>length){
            return false;
        }
        // storage i
        e = data[i-1];
        // move forward the data behind
        for (int j = i-1;j<length-1;j++){
            data[j+1] = data[j];
        }
        length--;
        return true;
    }

    int SeqTable::locateElement(T e) {
        for (int i = 0;i<length;i++){
            if (data[i] == e) {
                return i + 1;
            }
        }
        return 0;
    }

}

namespace dynamicAllocation {

    const int InitialSize = 2;
    using T = int;

    struct SeqTable{

    private:
        int length;
        int capacity;
        T *data;
        // expansion ratio
        double exp_ratio = 2.0;

    private:

        // expand
        void expansion(){
            // new capacity
            capacity = capacity*exp_ratio;
            // allocate a new piece of memory
            T * temp = new T[capacity];
            // copy
            memcpy(temp,data,length*sizeof(T));
            // release previous memory
            delete[] data;
            // assign
            data = temp;
        }

    public:

        SeqTable(){
            data = new T[InitialSize];
            length = 0;
            capacity = InitialSize;
        }

        ~SeqTable(){
            delete[] data;
        }

        int size(){
            return length;
        }

        bool insertElement(int i, T value);

        bool deleteElement(int i, T &e);

        int locateElement(T e);

    };



    bool SeqTable::insertElement(int i, T value) {
        // is full ?
        if (length == capacity){
            // expansion
            this->expansion();
        }
        // is i legal ?
        if (i<1 || i>length+1){
            return false;
        }
        // move element
        for (int j = length;j>i;j--){
            data[j] = data[j-1];
        }
        // assign
        data[i-1] = value;
        length++;

        return true;
    }

    bool SeqTable::deleteElement(int i, T &e) {
        // is i legal ?
        if (i<1 || i>length){
            return false;
        }
        // take out the value to be deleted
        e = data[i-1];
        // move element
        for (int j = i-1;j<length;j++){
            data[j] = data[j+1];
        }
        length--;
        return true;
    }

    int SeqTable::locateElement(T e) {
        for (int i = 0;i<length;i++){
            if (data[i] == e){
                return i+1;
            }
        }
        return 0;
    }
}
