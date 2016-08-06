#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <parent.h>
#include <memory>
#include<iostream>
class Controller
{
public:
    Controller()
    {

    }
    void proccess()
    {
       P1.load();
       std::unique_ptr<IParent2> worker (new Parent2B(P1.getSubSet(2)));
       int result = worker->proccess();
       std::cout<<result<<"\n";
    }
private:
    Parent1 P1;
    //std::vector<std::unique_ptr<IParent2>> P2List;
};


#endif // CONTROLLER_H
