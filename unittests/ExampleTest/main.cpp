#include <iostream>
#include "QML_example.h"
#include <iostream>
#include "tests.h"


int main(int argc, char* argv[])
{
	QML_example::LibraryInfo::printInfo();

	std::cout << "Running "<< UnitTest::Test::getTests().size() << " tests...\n";
	UnitTest::Test::TestResults results;
	UnitTest::Test::runAllTests(results);
	UnitTest::Test::printResults(results);

	return results.getSuccess();
}