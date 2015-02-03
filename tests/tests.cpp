/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_Test1_init = false;
#include "test1.h"

static Test1 suite_Test1;

static CxxTest::List Tests_Test1 = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_Test1( "test1.h", 11, "Test1", suite_Test1, Tests_Test1 );

static class TestDescription_suite_Test1_testAddition : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Test1_testAddition() : CxxTest::RealTestDescription( Tests_Test1, suiteDescription_Test1, 14, "testAddition" ) {}
 void runTest() { suite_Test1.testAddition(); }
} testDescription_suite_Test1_testAddition;

static class TestDescription_suite_Test1_test_01_matrix_transpose : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Test1_test_01_matrix_transpose() : CxxTest::RealTestDescription( Tests_Test1, suiteDescription_Test1, 20, "test_01_matrix_transpose" ) {}
 void runTest() { suite_Test1.test_01_matrix_transpose(); }
} testDescription_suite_Test1_test_01_matrix_transpose;

static class TestDescription_suite_Test1_test_02_matrix_parse_from_string : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Test1_test_02_matrix_parse_from_string() : CxxTest::RealTestDescription( Tests_Test1, suiteDescription_Test1, 23, "test_02_matrix_parse_from_string" ) {}
 void runTest() { suite_Test1.test_02_matrix_parse_from_string(); }
} testDescription_suite_Test1_test_02_matrix_parse_from_string;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
