#include <iostream>

#define maxSize 10

class arrayRep
{
private:
    int head1, head2;
    int storageArray[maxSize * 2];

public:
    void insert1(int x);
    void insert2(int x);
    int pop1();
    int pop2();
    int isFull1();
    int isEmpty1();
    int isFull2();
    int isEmpty2();
    arrayRep()
    {
        head1 = 9;
        head2 = 10;
    }
};

void arrayRep::insert1(int x)
{
    if (isEmpty1() == 1 && isFull1() == 0)
    {
        storageArray[head1 - 1];
        head1 = head1 - 1;
    }
    return;
}

void arrayRep::insert2(int x)
{
    if (isEmpty2() == 1 && isFull2() == 0)
    {
        storageArray[head1 + 1];
        head1 = head1 + 1;
    }
    return;
}

int arrayRep::isEmpty1()
{
    if (head1 == 9)
    {
        return 1;
    }
    return -1;
}

int arrayRep::isEmpty2()
{
    if (head2 == 10)
    {
        return 1;
    }
    return -1;
}

int arrayRep::isFull1()
{
    if (head1 == 0)
    {
        return 1;
    }
    return 0;
}

int arrayRep::isFull2()
{
    if (head2 == 19)
    {
        return 1;
    }
    return 0;
}

int main()
{

    return 0;
}