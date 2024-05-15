#include <gtest/gtest.h>
#include "Mediator.h"

TEST(MediatorTest, TestSendMessage)
{
  Mediator *mediator = new ConcreteMediator();
  
  Colleague *c1 = new ConcreteColleague( mediator, 1 );
  Colleague *c2 = new ConcreteColleague( mediator, 2 );

  mediator->add( c1 );
  mediator->add( c2 );

  testing::internal::CaptureStdout();
  c1->send( "Test message" );
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "Message 'Test message' sent by Colleague 1\nMessage 'Test message' received by Colleague 2\n");

  delete mediator;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
