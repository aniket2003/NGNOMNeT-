// eNB.cc
#include "eNB.h"
#include "RouteRequest_m.h"
#include "RouteReply_m.h"

void eNB::initialize() {
    // Initialize eNB module
}

void eNB::handleMessage(cMessage *msg) {
    if (msg->getKind() == 0) {
        // Handle route request
        handleRouteRequest(check_and_cast<RouteRequest *>(msg));
    } else if (msg->getKind() == 1) {
        // Handle route reply
        handleRouteReply(check_and_cast<RouteReply *>(msg));
    }
}

void eNB::handleRouteRequest(RouteRequest *request) {

    EV << "Request ENB: " << request <<"\n";

    // Handle route request from UE
    // Run Dijkstra algorithm to find shortest path
    // Send route reply back to UE
}

void eNB::handleRouteReply(RouteReply *reply) {
    // Handle route reply from UE
    // Extract route information and store it
}
