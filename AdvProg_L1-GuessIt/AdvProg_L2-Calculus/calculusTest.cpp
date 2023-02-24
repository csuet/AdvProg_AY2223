#include <iostream>
#include <cmath>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>


#include "calculus.h"

const double EPSILON = 0.001; // maximum difference between the expected result and returned result
const double PI_TEST = 3.14159265359;

struct TestStruct
{
    std::string testName;
    bool result;
    bool expected;
    std::string errorMsg;
};

bool isClose(double a, double b)
{
    return fabs(a - b) <= EPSILON;
}

void runTestLoop(TestStruct testCases[], int testSize){
    int i;
    for (i = 0; i< testSize; i++){
        std::cout << testCases[i].testName + ": ";
        if (testCases[i].result == testCases[i].expected)
        {
            std::cout << "PASSED \n";
        }
        else
        {
            std::cout << testCases[i].errorMsg;
            exit(1);
        }
    }
}

class Test: public CPPUNIT_NS::TestCase
{
  CPPUNIT_TEST_SUITE(Test);
  CPPUNIT_TEST(testMyCos);
  CPPUNIT_TEST(testMySin);
  CPPUNIT_TEST(testMySqrt);
  CPPUNIT_TEST(successTestExit);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp(void) {}
  void tearDown(void) {}

protected:

  void testMyCos(void){
      int testSize = 4;
      std::string sharedName = "[Cos test] ";
      TestStruct cosTestCases[testSize]  = 
      {
        {
            sharedName + "test normal 1", 
            isClose(myCos(0), cos(0)), 
            true, 
            "cos(0) should be close to 1.0 \n"
        },
        {
            sharedName + "test normal 2", 
            isClose(myCos(PI_TEST/4), cos(PI_TEST/4)), 
            true, 
            "cos(PI/4) should be close to" + std::to_string(cos(PI_TEST/4)) + " \n"
        },
        {
            sharedName + "test opposite angle", 
            isClose(myCos(-1 * PI_TEST/3), cos(PI_TEST/3)), 
            true, 
            "cos(-1 * PI/3) be should close to cos(PI/3)"
        },
        {
            sharedName + "test cos(60) and cos(30)", 
            isClose(myCos(PI_TEST/3), cos(PI_TEST/6)), 
            false, 
            "cos(PI/3) should not be close to cos(PI/6)\n"
        },
      };
      runTestLoop(cosTestCases, testSize);
    //   exit(0);
  }

  void testMySin(void){
      int testSize = 4;
      std::string sharedName = "[Sin test] ";
      TestStruct sinTestCases[testSize]  = 
      {
        {
            sharedName + "test normal 1", 
            isClose(mySin(0), sin(0)), 
            true, 
            "sin(0) should be close to 0.0 \n"
        },
        {
            sharedName + "test normal 2", 
            isClose(mySin(PI_TEST/4), sin(PI_TEST/4)), 
            true, 
            "sin(0) should be close to" + std::to_string(sin(PI_TEST/4)) +  " \n"
        },
        {
            sharedName + "supplementary angles", 
            isClose(mySin(PI_TEST - PI_TEST/3), sin(PI_TEST/3)), 
            true,
            "sin(PI - PI/3) should be close to sin(PI/3)\n"
        },
        {
            sharedName + "test sin(60) and sin(30)", 
            isClose(mySin(PI_TEST/3), sin(PI_TEST/6)), 
            false, 
            "sin(PI/3) should not be close to sin(PI/6)\n"
        },
      };
      runTestLoop(sinTestCases, testSize);
    //   exit(0);
  }

  void testMySqrt(void){
      int testSize = 4;
      std::string sharedName = "[Sqrt test] ";
      TestStruct sinTestCases[testSize]  = 
      {
        {
            sharedName + "test normal 1", 
            isClose(mySqrt(4), 2.0), 
            true, 
            "sqrt(4) should be 2 \n"
        },
        {
            sharedName + "test normal 2", 
            isClose(mySqrt(10), sqrt(10)),  
            true,
            "sqrt(10) should be close to " + std::to_string(sqrt(10)) +  " \n"
        },
        {
            sharedName + "test normal 3 ", 
            isClose(mySqrt(10), sqrt(11)),
            false,
            "sqrt(10) should not be close to sqrt(11). Maximum difference: " + std::to_string(EPSILON)+ "\n"
        },
        {
            sharedName + "test normal 4 ", 
            isClose(mySqrt(100), sqrt(100)),
            true,
            "sqrt(100) must be 10\n"
        },

      };
      runTestLoop(sinTestCases, testSize);
    //   exit(0);
  }


  void successTestExit(void){
    std::cout << "all tests passed! \n";
    exit(0);
  }

};


CPPUNIT_TEST_SUITE_REGISTRATION(Test);

int main()
{
  CPPUNIT_NS::TestResult controller;

  CPPUNIT_NS::TestResultCollector result;
  controller.addListener(&result);

  CPPUNIT_NS::BriefTestProgressListener progress;
  controller.addListener(&progress);

  CPPUNIT_NS::TestRunner runner;
  runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
  runner.run(controller);

  return result.wasSuccessful() ? 0 : 1;
}