#include <gtest/gtest.h>
#include "Mediator.h"

TEST(MediatorTest, TestMultipleColleagues)
{
    Mediator* mediator = new ConcreteMediator();

    Colleague* c1 = new ConcreteColleague(mediator, 1);
    Colleague* c2 = new ConcreteColleague(mediator, 2);
    Colleague* c3 = new ConcreteColleague(mediator, 3);

    mediator->add(c1);
    mediator->add(c2);
    mediator->add(c3);

    testing::internal::CaptureStdout();
    c1->send("Message 1");
    c3->send("Message 2");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Message 'Message 1' sent by Colleague 1\nMessage 'Message 1' received by Colleague 2\nMessage 'Message 1' received by Colleague 3\nMessage 'Message 2' sent by Colleague 3\nMessage 'Message 2' received by Colleague 1\nMessage 'Message 2' received by Colleague 2\n");

    delete mediator;
}

