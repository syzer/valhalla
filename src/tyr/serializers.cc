#include <functional>
#include <string>
#include <stdexcept>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include <sstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "midgard/util.h"
#include "midgard/pointll.h"
#include "midgard/aabb2.h"
#include "midgard/logging.h"
#include "midgard/encoded.h"
#include "baldr/json.h"
#include "baldr/turn.h"
#include "baldr/rapidjson_utils.h"
#include "exception.h"
#include "odin/util.h"
#include "proto/directions_options.pb.h"
#include "tyr/serializers.h"


using namespace valhalla;
using namespace valhalla::tyr;
using namespace std;

namespace {

  namespace osrm_serializers {

/** TODO - make the OSRM serializer common so it can be used by matrix, route, locate, etc.
    // Serialize locations (called waypoints in OSRM). Waypoints are described here:
    //     http://project-osrm.org/docs/v5.5.1/api/#waypoint-object
    json::ArrayPtr waypoints(const std::list<valhalla::odin::TripDirections>& legs){
      int index = 0;
      auto waypoints = json::array({});
      for (auto leg = legs.begin(); leg != legs.end(); ++leg) {
        for (auto location = leg->location().begin() + index; location != leg->location().end(); ++location) {
          index = 1;

          // Create a waypoint to add to the array
          auto waypoint = json::map({});

          // Output location as a lon,lat array. Note this is the projected
          // lon,lat on the nearest road.
          PointLL input_ll(location->ll().lng(), location->ll().lat());
          PointLL proj_ll(location->projected_ll().lng(), location->projected_ll().lat());
          auto loc = json::array({});
          loc->emplace_back(json::fp_t{proj_ll.lng(), 6});
          loc->emplace_back(json::fp_t{proj_ll.lat(), 6});
          waypoint->emplace("location", loc);

          // Add street name. For now is just getting the name from the first
          // maneuver - this is not really correct.
          // TODO - get names from the edges in TripPath for the first edge of
          // the leg?
          waypoint->emplace("street", street_names(leg->maneuver(0)));

          // Add distance in meters from the input location to the nearest
          // point on the road used in the route
          float distance = input_ll.Distance(proj_ll);
          waypoint->emplace("distance", json::fp_t{distance, 1});

          // Add hint. Goal is for the hint returned from a locate request to be able
          // to quickly find the edge and point along the edge in a route request.
          // Defer this - not currently used in OSRM.
          waypoint->emplace("hint", std::string("TODO"));

          // Add the waypoint to the JSON array
          waypoints->emplace_back(waypoint);
        }
      }
      return waypoints;
    }
*/

  }

}
