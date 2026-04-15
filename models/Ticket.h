#pragma once

class Ticket {
public:
    int id;
    int vehicleId;
    int slotId;
    int entryTime;
    int exitTime;

    Ticket(int id, int vehicleId, int slotId, int entryTime)
        : id(id), vehicleId(vehicleId), slotId(slotId),
          entryTime(entryTime), exitTime(-1) {}

    void setExitTime(int time) { exitTime = time; }
};