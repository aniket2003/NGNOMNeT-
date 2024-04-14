// UE.h
#ifndef __UE_H_
#define __UE_H_

// Define constants for message kinds
#define ROUTE_REPLY 1
#define DATA_PACKET 2


#include <omnetpp.h>
#include "RouteRequest_m.h"
#include "DataPacket_m.h"

using namespace omnetpp;

class UE : public cSimpleModule {
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    void sendRouteRequest();
    void sendDataPacket();
    // Add other necessary functions and variables
};

#endif /* __UE_H_ */
