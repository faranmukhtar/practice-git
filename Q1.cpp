// Task 1 - Faran Mukhtar  24k-0646
// His this is an update for git
#include<iostream>
using namespace std;

class DeviceManagement {
protected:
    string deviceID, devicetype;
    double Powerrating;
    bool status;
public:
    DeviceManagement(string id, string type, double power, bool s) {
        deviceID = id;
        devicetype = type;
        Powerrating = power;
        status = s;
    }
    virtual void turnon() {
        status = true;
        cout << deviceID << " turned ON.\n";
    }
    virtual void turnoff() {
        status = false;
        cout << deviceID << " turned OFF.\n";
    }
    virtual double calculatePowerUsage(int hours) = 0;
    string getID() { return deviceID; }
    string getType() { return devicetype; }
    bool getStatus() { return status; }
};
class Lights : public DeviceManagement {
public:
    Lights(string id, string type, double power, bool s) : DeviceManagement(id, type, power, s) {}
    double calculatePowerUsage(int hours) {
        return Powerrating * hours;
    }
};
class Fans : public DeviceManagement {
private:
    int speedfactor;
public:
    Fans(string id, string type, double power, bool s, int factor) : DeviceManagement(id, type, power, s), speedfactor(factor) {}
    double calculatePowerUsage(int hours) {
        return Powerrating * hours * speedfactor;
    }
};
class Airconditioners : public DeviceManagement {
private:
    int ctemp, dtemp;
public:
    Airconditioners(string id, string type, double power, bool s, int c, int d) : DeviceManagement(id, type, power, s), ctemp(c), dtemp(d) {}
    double calculatePowerUsage(int hours) {
        return Powerrating * hours * (1 - (double)(ctemp - dtemp) / 100);
    }
};
class SecuritySystems : public DeviceManagement {
private:
    int fixedpowerconsumption;
public:
    SecuritySystems(string id, string type, double power, bool s, int consumption) : DeviceManagement(id, type, power, s), fixedpowerconsumption(consumption) {}
    double calculatePowerUsage(int hours) {
        if (status == true) {
            return fixedpowerconsumption;
        } else {
            return 0;
        }
    }
};
class UserManagement {
protected:
    string UserID, UserRole;
    int AccessLevel;
public:
    UserManagement(string id, string role, int level) {
        UserID = id;
        UserRole = role;
        AccessLevel = level;
    }
    void viewAccessibleDevices(DeviceManagement* devices[], int size) {
        cout << "Accessible devices for " << UserID << ":\n";
        for (int i = 0; i < size; i++) {
            if (!(devices[i]->getType() == "Security Systems" && AccessLevel < 2)) {
                cout << devices[i]->getID() << " (" << devices[i]->getType() << ")\n";
            }
        }
    }
};
int main() {
    DeviceManagement* devices[4];
    devices[0] = new Lights("L01", "LED Light", 10, false);
    devices[1] = new Fans("F01", "Ceiling Fan", 75, false, 2);
    devices[2] = new Airconditioners("AC01", "Split AC", 1500, false, 30, 24);
    devices[3] = new SecuritySystems("S01", "Security Systems", 100, false, 1500);
    UserManagement user1("U001", "Regular User", 1);
    UserManagement user2("U002", "Admin", 2);
    for (int i = 0; i < 4; i++) {
        devices[i]->turnon();
    }
    cout << devices[0]->calculatePowerUsage(5) << endl;
    cout << devices[1]->calculatePowerUsage(3) << endl;
    cout << devices[2]->calculatePowerUsage(4) << endl;
    cout << devices[3]->calculatePowerUsage(24) << endl;
    user1.viewAccessibleDevices(devices, 4);
    user2.viewAccessibleDevices(devices, 4);
    for (int i = 0; i < 4; i++) {
        devices[i]->turnoff();
        delete devices[i];
    }
    return 0;
}
