#include <iostream>
#include <cmath>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>


#include "painter.h"
#include "utils.h"

struct TestStruct {
    std::string testName;
    bool expected;
    std::string errorMsg;
};


bool verifySetColor(SDL_Color color) { 
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Color color1 = {0, 0, 0};
    initSDL(&window, &renderer);
    Painter painter(window, renderer);
    painter.setColor(color);
    SDL_GetRenderDrawColor(painter.getRenderer(), &(color1.r), &(color1.g), &(color1.b), &(color1.a));
    if (color1.r == color.r & color.g == color.g && color1.b == color.b && painter.getColor().r == color.r && painter.getColor().g == color.g && painter.getColor().b == color.b) {
        return true;
    }
    return true;
}


bool verifyJumpForward(int numPixel, double angle, int curX, int curY, int diffX, int diffY) {
    SDL_Window *window;
    SDL_Renderer *renderer;
    initSDL(&window, &renderer);
    Painter painter(window, renderer);
    painter.setPosition(curX, curY);
    painter.setAngle(angle);
    painter.jumpForward(numPixel);
    int diffX_ = painter.getX() - curX;
    int diffY_ = painter.getY() - curY;
    if (diffX == diffX_ && diffY == diffY_) {
        return true;
    }
    else {
      return false;
    }
}


bool verifyJumpBackward(int numPixel, double angle, int curX, int curY, int diffX, int diffY) {
    SDL_Window *window;
    SDL_Renderer *renderer;
    initSDL(&window, &renderer);
    Painter painter(window, renderer);
    painter.setPosition(curX, curY);
    painter.setAngle(angle);
    painter.jumpBackward(numPixel);
    int diffX_ = painter.getX() - curX;
    int diffY_ = painter.getY() - curY;
    if (diffX == diffX_ && diffY == diffY_) {
        return true;
    }
    else {
      return false;
    }
}


bool verifyTurnLeft(double degree, double curAngle, double expectedAngle) { 
    SDL_Window *window;
    SDL_Renderer *renderer;
    initSDL(&window, &renderer);
    Painter painter(window, renderer);
    painter.setAngle(curAngle);
    painter.turnLeft(degree);
    if (painter.getAngle() == expectedAngle) {
        return true;
    }
    else {
        return false;
    }
}


bool verifyTurnRight(double degree, double curAngle, double expectedAngle) { 
    SDL_Window *window;
    SDL_Renderer *renderer;
    initSDL(&window, &renderer);
    Painter painter(window, renderer);
    painter.setAngle(curAngle);
    painter.turnRight(degree);
    if (painter.getAngle() == expectedAngle) {
        return true;
    }
    else {
        return false;
    }
}


bool verifyRandomColor() { 
    SDL_Window *window;
    SDL_Renderer *renderer;
    initSDL(&window, &renderer);
    Painter painter(window, renderer);
    painter.randomColor();
    SDL_Color color = painter.getColor();
    if (validColorValue(color.r) && validColorValue(color.g) && validColorValue(color.b)) {
        return true; 
    }
    else {
        return false;
    }
}

void runTestLoop(TestStruct testCases[], int testSize) {
    int i;
    for (i = 0; i< testSize; i++){
        std::cout << testCases[i].testName + ": ";
        std::cout << testCases[i].expected << std::endl;
        if (testCases[i].expected)
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

class Test: public CPPUNIT_NS::TestCase {
  CPPUNIT_TEST_SUITE(Test);
  CPPUNIT_TEST(testMyPainterSetColor);
  CPPUNIT_TEST(testMyPainterJumpForward);
  CPPUNIT_TEST(testMyPainterJumpBackward);
  CPPUNIT_TEST(testMyPainterTurnLeft);
  CPPUNIT_TEST(testMyPainterTurnRight);
  CPPUNIT_TEST(testMyPainterRandomColor);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp(void) {}
  void tearDown(void) {}

protected:

  void testMyPainterSetColor(void){
      int testSize = 4;
      std::string sharedName = "[setColor test] ";
      TestStruct generateRandomNumberTestCases[testSize]  = 
      {
        {
            sharedName + "test normal 1", 
            verifySetColor(dict2SDL_Color(0, 255, 0)), 
            "The color of Painter and renderer must be the same with input color."
        },
        {
            sharedName + "test normal 2", 
            verifySetColor(dict2SDL_Color(0, 255, 255)), 
            "The color of Painter and renderer must be the same with input color."
        },
        {
            sharedName + "test normal 3", 
            verifySetColor(dict2SDL_Color(0, 255, 1)), 
            "The color of Painter and renderer must be the same with input color."
        },
        {
            sharedName + "test normal 4", 
            verifySetColor(dict2SDL_Color(100, 255, 0)), 
            "The color of Painter and renderer must be the same with input color."
        },
      };
      runTestLoop(generateRandomNumberTestCases, testSize);
    //   
  }

  void testMyPainterJumpForward(void){
      int testSize = 4;
      std::string sharedName = "[jumpForward test] ";
      TestStruct generateRandomNumberTestCases[testSize]  = 
      {
        {
            sharedName + "test normal 1", 
            verifyJumpForward(30, 0, 0, 0, 30, 0), 
            "Jumping to wrong postion."
        },
        {
            sharedName + "test normal 2", 
            verifyJumpForward(30, 90, 90, 90, 0, -30), 
            "Jumping to wrong postion."
        },
        {
            sharedName + "test normal 3", 
            verifyJumpForward(30, 60, 90, 90, 15, -25), 
            "Jumping to wrong postion."
        },
        {
            sharedName + "test normal 4", 
            verifyJumpForward(50, 120, 90, 90, -24, -43), 
            "Jumping to wrong postion."
        },
      };
      runTestLoop(generateRandomNumberTestCases, testSize);
    //   
  }

  void testMyPainterJumpBackward(void){
      int testSize = 4;
      std::string sharedName = "[jumpBackward test] ";
      TestStruct generateRandomNumberTestCases[testSize]  = 
      {
        {
            sharedName + "test normal 1", 
            verifyJumpBackward(50, 0, 90, 90, -50, 0), 
            "Jumping to wrong postion."
        },
        {
            sharedName + "test normal 2", 
            verifyJumpBackward(40, 45, 90, 90, -28, 28), 
            "Jumping to wrong postion."
        },
        {
            sharedName + "test normal 3", 
            verifyJumpBackward(40, 150, 90, 90, 34, 19), 
            "Jumping to wrong postion."

        },
        {
            sharedName + "test normal 4",  
            verifyJumpBackward(15, 120, 90, 90, 7, 12), 
            "Jumping to wrong postion."

        },
      };
      runTestLoop(generateRandomNumberTestCases, testSize);
    //   
  }

  void testMyPainterTurnLeft(void){
      int testSize = 4;
      std::string sharedName = "[turnLeft test] ";
      TestStruct generateRandomNumberTestCases[testSize]  = 
      {
        {
            sharedName + "test normal 1", 
            verifyTurnLeft(30, 360, 30), 
            "Wrong direction turn."
        },
        {
            sharedName + "test normal 2", 
            verifyTurnLeft(30, 180, 210), 
            "Wrong direction turn."
        },
        {
            sharedName + "test normal 3", 
            verifyTurnLeft(-30, 120, 90), 
            "Wrong direction turn."

        },
        {
            sharedName + "test normal 4",  
            verifyTurnLeft(0, 90, 90), 
            "Wrong direction turn."
        },
      };
      runTestLoop(generateRandomNumberTestCases, testSize);
  }

  void testMyPainterTurnRight(void){
      int testSize = 4;
      std::string sharedName = "[turnRight test] ";
      TestStruct generateRandomNumberTestCases[testSize]  = 
      {
        {
            sharedName + "test normal 1", 
            verifyTurnRight(-30, 360, 30), 
            "Wrong direction turn."
        },
        {
            sharedName + "test normal 2", 
            verifyTurnRight(30, 180, 150), 
            "Wrong direction turn."
        },
        {
            sharedName + "test normal 3", 
            verifyTurnRight(30, 0, -30), 
            "Wrong direction turn."
        },
        {
            sharedName + "test normal 4",  
            verifyTurnRight(0, 90, 90), 
            "Wrong direction turn."
        },
      };
      runTestLoop(generateRandomNumberTestCases, testSize);
  }

  void testMyPainterRandomColor(void){
      int testSize = 4;
      std::string sharedName = "[turnRight test] ";
      TestStruct generateRandomNumberTestCases[testSize]  = 
      {
        {
            sharedName + "test normal 1", 
            verifyRandomColor(),
            "The color values are not invalid."
        },
        {
            sharedName + "test normal 2", 
            verifyRandomColor(),
            "The color values are not invalid."
        },
        {
            sharedName + "test normal 3", 
            verifyRandomColor(), 
            "The color values are not invalid."

        },
        {
            sharedName + "test normal 4",  
            verifyRandomColor(), 
            "The color values are not invalid."
        },
      };
      runTestLoop(generateRandomNumberTestCases, testSize);
    //   
  }

  void successTestExit(void) {
    std::cout << "all tests passed! \n";
    
  }

};


CPPUNIT_TEST_SUITE_REGISTRATION(Test);

int main() {
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