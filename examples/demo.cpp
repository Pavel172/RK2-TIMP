#include <Mediator.h>

int main()
{
  Mediator *mediator = new ConcreteMediator();
  
  Colleague *c1 = new ConcreteColleague( mediator, 1 );
  Colleague *c2 = new ConcreteColleague( mediator, 2 );
  Colleague *c3 = new ConcreteColleague( mediator, 3 );
  
  mediator->add( c1 );
  mediator->add( c2 );
  mediator->add( c3 );
  
  c1->send( "Hi!" );
  c3->send( "Hello!" );
  
  delete mediator;
  return 0;
}
