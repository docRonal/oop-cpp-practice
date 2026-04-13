/*
Dokończyć (niczego nie zmieniając, jedynie dopisując) deklarację klas CContainer, CStack i CLimitedStack tak, żeby poprawnie działały w podanej funkcji main.
*/

#include <vector>

using namespace std;

class EmptyContainer
{
};

class CContainer
{
protected:
    vector<int> Data;

public:
    virtual bool push(int) = 0;
    virtual int pop() = 0;

    virtual size_t getSizeLimit() = 0;
    virtual ~CContainer() {}
};

class CStack
{
};

class CLimitedStack : public CContainer
{
private:
    static size_t SizeLimit;

public:
    static void setSizeLimit(size_t newLimit)
    {
        SizeLimit = newLimit;
    }
    size_t getSizeLimit() override
    {
        return SizeLimit;
    }
    int pop() override
    {
        if (!Data.empty())
        {
            int val = Data.back();
            Data.pop_back();
            return val;
        }
        return 0;
    }
    bool push(int val) override
    {
        if (Data.empty() || Data.size() < SizeLimit)
        {
            Data.push_back(val);
            return true;
        }
        return false;
    }
    ~CLimitedStack() override
    {
    }
};
