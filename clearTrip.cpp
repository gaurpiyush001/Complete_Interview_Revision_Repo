#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include <stdexcept>

using namespace std;

// Utility struct for representing time slots
struct TimeSlot {
    int start, end;

    TimeSlot(int s, int e) : start(s), end(e) {
        if (start < 0 || end > 24 || start >= end)
            throw invalid_argument("Invalid time slot.");
    }

    bool overlaps(const TimeSlot& other) const {
        return !(end <= other.start || start >= other.end);
    }

    friend ostream& operator<<(ostream& os, const TimeSlot& ts) {
        os << "{" << ts.start << ":" << ts.end << "}";
        return os;
    }
};

// Class for ConferenceRoom
class ConferenceRoom {
public:
    string id;
    vector<TimeSlot> bookings;

    ConferenceRoom(string roomId) : id(move(roomId)) {}

    bool isAvailable(const TimeSlot& slot) const {
        for (const auto& bookedSlot : bookings) {
            if (bookedSlot.overlaps(slot)) return false;
        }
        return true;
    }

    void book(const TimeSlot& slot) {
        if (!isAvailable(slot))
            throw runtime_error("Time slot is already booked.");
        bookings.push_back(slot);
    }

    void cancel(const TimeSlot& slot) {
        for (auto it = bookings.begin(); it != bookings.end(); ++it) {
            if (it->start == slot.start && it->end == slot.end) {
                bookings.erase(it);
                return;
            }
        }
        throw runtime_error("Booking not found.");
    }

    friend ostream& operator<<(ostream& os, const ConferenceRoom& room) {
        os << room.id << " [";
        for (size_t i = 0; i < room.bookings.size(); ++i) {
            os << room.bookings[i];
            if (i < room.bookings.size() - 1) os << ", ";
        }
        os << "]";
        return os;
    }
};

// Class for Floor
class Floor {
public:
    int number;
    unordered_map<string, ConferenceRoom> rooms;

    Floor(int num) : number(num) {}

    void addRoom(const string& roomId) {
        if (rooms.count(roomId))
            throw runtime_error("Room already exists.");
        rooms.emplace(roomId, ConferenceRoom(roomId));
    }

    ConferenceRoom& getRoom(const string& roomId) {
        if (!rooms.count(roomId))
            throw runtime_error("Room not found.");
        return rooms[roomId];
    }

    friend ostream& operator<<(ostream& os, const Floor& floor) {
        for (const auto& [id, room] : floor.rooms) {
            os << room << "\n";
        }
        return os;
    }
};

// Class for Building
class Building {
public:
    string name;
    unordered_map<int, Floor> floors;

    Building(string buildingName) : name(move(buildingName)) {}

    void addFloor(int floorNum) {
        if (floors.count(floorNum))
            throw runtime_error("Floor already exists.");
        floors.emplace(floorNum, Floor(floorNum));
    }

    Floor& getFloor(int floorNum) {
        if (!floors.count(floorNum))
            throw runtime_error("Floor not found.");
        return floors[floorNum];
    }

    friend ostream& operator<<(ostream& os, const Building& building) {
        os << "Building " << building.name << "\n";
        for (const auto& [num, floor] : building.floors) {
            os << "  Floor " << num << ":\n" << floor;
        }
        return os;
    }
};

// Main management system
class ConferenceRoomSystem {
    unordered_map<string, Building> buildings;

public:
    void addBuilding(const string& buildingName) {
        if (buildings.count(buildingName))
            throw runtime_error("Building already exists.");
        buildings.emplace(buildingName, Building(buildingName));
        cout << "Added building " << buildingName << " into the system." << endl;
    }

    void addFloor(const string& buildingName, int floorNum) {
        getBuilding(buildingName).addFloor(floorNum);
        cout << "Added floor " << floorNum << " in building " << buildingName << "." << endl;
    }

    void addConferenceRoom(const string& buildingName, int floorNum, const string& roomId) {
        getBuilding(buildingName).getFloor(floorNum).addRoom(roomId);
        cout << "Added conference room " << roomId << " in floor " << floorNum << " of building " << buildingName << "." << endl;
    }

    void listRooms() const {
        for (const auto& [name, building] : buildings) {
            cout << building;
        }
    }

    void bookRoom(const string& buildingName, int floorNum, const string& roomId, const TimeSlot& slot) {
        getBuilding(buildingName).getFloor(floorNum).getRoom(roomId).book(slot);
        cout << "Booked room " << roomId << " for slot " << slot << "." << endl;
    }

    void cancelBooking(const string& buildingName, int floorNum, const string& roomId, const TimeSlot& slot) {
        getBuilding(buildingName).getFloor(floorNum).getRoom(roomId).cancel(slot);
        cout << "Cancelled booking for room " << roomId << " for slot " << slot << "." << endl;
    }

private:
    Building& getBuilding(const string& buildingName) {
        if (!buildings.count(buildingName))
            throw runtime_error("Building not found.");
        return buildings[buildingName];
    }
};

int main() {
    ConferenceRoomSystem system;

    system.addBuilding("b1");
    system.addFloor("b1", 1);
    system.addConferenceRoom("b1", 1, "c1");
    system.addConferenceRoom("b1", 1, "c2");

    system.listRooms();

    TimeSlot slot1(1, 5);
    TimeSlot slot2(6, 10);

    system.bookRoom("b1", 1, "c1", slot1);
    system.bookRoom("b1", 1, "c2", slot2);

    system.listRooms();

    system.cancelBooking("b1", 1, "c1", slot1);

    system.listRooms();

    return 0;
}
