// eNB.h
#ifndef __ENB_H_
#define __ENB_H_

#include <omnetpp.h>
#include "RouteRequest_m.h"
#include "RouteReply_m.h"

using namespace omnetpp;

class eNB : public cSimpleModule {
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    void handleRouteRequest(RouteRequest *request);
    void handleRouteReply(RouteReply *reply);
    // Add other necessary functions and variables
};

#endif /* __ENB_H_ */
