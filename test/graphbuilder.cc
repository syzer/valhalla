#include "test.h"

#include "mjolnir/graphbuilder.h"

#include <sstream>
#include <string>
#include <thread>
#include <algorithm>
#include <memory>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/optional.hpp>

using namespace std;
using namespace valhalla::mjolnir;

namespace {


}

int main() {
  test::suite suite("graphbuilder");

  // Test setting and getting on random sizes of bit tables
  //suite.test(TEST_CASE(some_test));
  //TODO: sweet jesus add more tests of this class!

  return suite.tear_down();
}
