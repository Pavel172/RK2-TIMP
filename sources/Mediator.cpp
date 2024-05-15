#include "Mediator.h"
#include <iostream>

unsigned int Colleague::getID()
{
return id;
}

void ConcreteColleague::send(std::string msg)
{
  std::cout << "Message '" << msg << "' sent by Colleague " << id << std::endl;
  mediator->distribute(this, msg);
}

void ConcreteColleague::receive(std::string msg)
{
  std::cout << "Message '" << msg << "' received by Colleague " << id << std::endl;
}

ConcreteMediator::~ConcreteMediator()
{
  for (unsigned int i = 0; i < colleagues.size(); i++)
  {
    delete colleagues[i];
  }
  colleagues.clear();
}

void ConcreteMediator::add(Colleague* const c)
{
  colleagues.push_back(c);
}

void ConcreteMediator::distribute(Colleague* const sender, std::string msg)
{
  for (unsigned int i = 0; i < colleagues.size(); i++)
  {
    if (colleagues.at(i)->getID() != sender->getID())
    {
      colleagues.at(i)->receive(msg);
    }
  }
}
