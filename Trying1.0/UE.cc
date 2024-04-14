// UE.cc
#include "UE.h"

void UE::initialize() {
    // Initialize UE module
    // Schedule sending route request
    scheduleAt(0, new cMessage("RouteRequest"));
}

void UE::handleMessage(cMessage *msg) {
    if (msg->isSelfMessage()) {
        // Self-message to send route request
        sendRouteRequest();
        delete msg;
    } else if (msg->getKind() == ROUTE_REPLY) {
        // Handle route reply
        // Extract route information and store it
        delete msg;
    } else if (msg->getKind() == DATA_PACKET) {
        // Handle incoming data packet
        // Forward or process data packet
        delete msg;
    }
}

void UE::sendRouteRequest() {
    // Create and send route request message
    RouteRequest *request = new RouteRequest("RouteRequest");
    request->setSourceUEID(getId());
//    request->setDestinationUEID( /* Set destination UE ID */ );
    request->setDestinationUEID(3);
    // Set other necessary fields
    send(request, "out");
}

void UE::sendDataPacket() {
    // Create and send data packet
    DataPacket *packet = new DataPacket("DataPacket");
    packet->setSourceUEID(getId());
//    packet->setDestinationUEID( /* Set destination UE ID */ );
    packet->setDestinationUEID(3);
//    packet->setSize( /* Set packet size */ );
    packet->setSize(5);
    // Set other necessary fields
    send(packet, "out");
}
