#ifndef PARENT_H
#define PARENT_H
#include <memory>
class Data_Detail {
public:
    int a;
    int b;
};

class Child_Record {
 public:
    Child_Record (){}
    Child_Record (Child_Record && out)
    {
        c = out.c;
        dd.a = out.dd.a;
        dd.b = out.dd.b;

        out.c = 0;
        out.dd.a = 0;
        out.dd.b =0;
    }
    Child_Record (const Child_Record & copy)
    {
        c = copy.c;
        dd.a = copy.dd.a;
        dd.b = copy.dd.b;
    }
    ~Child_Record ()
    {
    }
    private:
        int c;
        Data_Detail dd;
};

class Parent1 {

public:
    int load()
    {
        rows1.push_back(std::unique_ptr<Child_Record>(new Child_Record()));
        return 0;
    }
    std::unique_ptr<Child_Record> getSubSet(int index)
    {
        return std::move(rows1[0]/*fill out later*/);
    }
    void returnSubSet(std::unique_ptr<Child_Record> & returnRecord )
    {
        rows1.push_back(std::move(returnRecord)) ;
    }
private:
    std::vector< std::unique_ptr<Child_Record>> rows1;

};

class IParent2 {

public:
    IParent2(std::unique_ptr<Child_Record> input)
    {
        rows2.push_back(std::move(input));
    }

    virtual int proccess() = 0;

protected:
    std::vector< std::unique_ptr<Child_Record>> rows2;

};

class Parent2B : public IParent2
{
public:
    using IParent2::IParent2;

    virtual int proccess() override
    {
        return 0;
    }
};

#endif // PARENT_H
