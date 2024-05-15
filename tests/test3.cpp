#include <gtest/gtest.h>
#include "Mediator.h"

TEST(MediatorTest, SendReceiveMessage) {
  Mediator* mediator = new ConcreteMediator();

  Colleague* c1 = new ConcreteColleague(mediator, 1);
  Colleague* c2 = new ConcreteColleague(mediator, 2);

  mediator->add(c1);
  mediator->add(c2);

  c1->send("Sending message");
  c2->send("Receiving message");

  delete mediator;
}
