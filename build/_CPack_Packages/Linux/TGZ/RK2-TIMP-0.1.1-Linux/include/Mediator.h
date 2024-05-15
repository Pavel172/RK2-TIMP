#include <iostream>
#include <vector>
#include <string>

class Mediator;

class Colleague
{
public:
  Colleague(Mediator* const m, const unsigned int i) : mediator(m), id(i) {}
  virtual ~Colleague() {}

  unsigned int getID();

  virtual void send(std::string) = 0;
  virtual void receive(std::string) = 0;

protected:
  Mediator* mediator;
  unsigned int id;
};

class ConcreteColleague : public Colleague
{
public:
  ConcreteColleague(Mediator* const m, const unsigned int i) : Colleague(m, i) {}
  ~ConcreteColleague() {}

  void send(std::string msg);

  void receive(std::string msg);
};

class Mediator
{
public:
  virtual ~Mediator() {}

  virtual void add(Colleague* const c) = 0;
  virtual void distribute(Colleague* const sender, std::string msg) = 0;

protected:
  Mediator() {}
};

class ConcreteMediator : public Mediator
{
public:
  ~ConcreteMediator();

  void add(Colleague* const c);

  void distribute(Colleague* const sender, std::string msg);

private:
  std::vector<Colleague*> colleagues;
};
