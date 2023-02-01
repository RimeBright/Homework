#pragma once

class IntegerArray
{
private:
    int _len{};
    

public:
    
    int* data{};

    IntegerArray() = default;
    IntegerArray(int len);

    int getSize();

    int* copy();

    int find(int idx);

    void insert(int x, int newLen = 1);
    void remove(int newLen = 1);

    void changeSize(int x);

    ~IntegerArray();
    
};

//=============================

class BadLength
{
    private:
        int _len;
    public:
        BadLength(int len);
        void what();

};

//=============================


class BadRange
{
private:
    int _len;
public:
    BadRange(int len);
    void what();

};
