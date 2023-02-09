#include <iostream>
#include <ctime>
#include "MotionSensor.h"
#include "GasSensor.h"
#include "SmokeSensor.h"
#include "Sensor.h"
#include "Component.h"
#include "Location.h"
#include "activation.h"
#include "main.h"
#include "EmergencyCenter.h"
#include "Alarm.h"
#include "Contact.h"
#include "mail.h"

using namespace std;

int main()
{

    /*
     ************************************************************ SCENARIO 2 - Louise ************************************************************
    */

    auto* instanceEmergencyCenter = EmergencyCenter::getInstance();

    auto residentialArea = make_shared<Location>("Residential Area");
    auto house1 = make_shared<Location>("House of John and Vicky");
    auto shed = make_shared<Location>("Shed of John");
    auto kitchen = make_shared<Location>("Kitchen of Vicky");
    auto house2 = make_shared<Location>("House of Dave");
    auto livingRoom = make_shared<Location>("Living room of Dave");
    auto house3 = make_shared<Location>("House of Kaitlin");
    auto lab = make_shared<Location>("Lab of Kaitlin");


    //TODO: change the share pointer to the specific sensor it is.
    //TODO: change the sensor classes to have a constructor that also includes the type of sensor

    /*
     * Initializing Sensors
     */
    auto smokeSensor1 = std::make_shared<SmokeSensor>("Smokey", "John's shed");
    auto motionSensor1 = std::make_shared<MotionSensor>("IcanCU", "John's shed");
    auto smokeSensor2 = std::make_shared<SmokeSensor>("Smokey", "Vicky's kitchen");
    auto motionSensor2 = std::make_shared<MotionSensor>("IcanCU", "Vicky's kitchen");
    auto gasSensor1 = std::make_shared<GasSensor>("BreatheLabs", "Dave's living room");
    auto smokeSensor3 = std::make_shared<SmokeSensor>("BurningInc", "Dave's living room");
    auto gasSensor2 = std::make_shared<GasSensor>("TN2S", "Kaitlin's house");
    auto motionSensor3 = std::make_shared<MotionSensor>("IcanCU", "Kaitlin's lab");

    /*
     * Configuring sensor actions
     */

    auto houseAlarm1 = std::make_shared<Alarm>("the " + house1->getName());
    auto messageFireDep = std::make_shared<Mail>("message", "fire department of the neighborhood");
    smokeSensor1->addStrategy(houseAlarm1);
    smokeSensor1->addStrategy(messageFireDep);
    smokeSensor2->addStrategy(houseAlarm1);
    smokeSensor2->addStrategy(messageFireDep);

    auto activateLight = std::make_shared<Activation>("light");
    auto activateAirConditioner = std::make_shared<Activation>("air conditioner");
    motionSensor1->addStrategy(activateLight);
    motionSensor1->addStrategy(activateAirConditioner);

    motionSensor2->setStartTime(22.0, 0.0);
    motionSensor2->setEndTime(7.0, 0.0);
    auto messageVicky = std::make_shared<Mail>("email", "vicky.cooke@gmail.com");
    motionSensor2->addStrategy(messageVicky);

    auto activateSprinklers = std::make_shared<Activation>("sprinkler system");
    auto houseAlarm2 = std::make_shared<Alarm>("the " + house2->getName());
    smokeSensor3->addStrategy(activateSprinklers);
    smokeSensor3->addStrategy(messageFireDep);
    smokeSensor3->addStrategy(houseAlarm2);

    auto houseAlarm3 = std::make_shared<Alarm>("the " + house3->getName());
    gasSensor2->addStrategy(houseAlarm1);
    gasSensor2->addStrategy(houseAlarm2);
    gasSensor2->addStrategy(houseAlarm3);

    auto emailKaitlin = std::make_shared<Mail>("email", "kaitlin.themadscientist@gmail.com");
    motionSensor3->setStartTime(4.0, 40.0);
    motionSensor3->setStartTime(9.0, 15.0);
    motionSensor3->addStrategy(emailKaitlin);




    /*
     * Building the heirarchy - adding locations and sensors to a locations
     */
    instanceEmergencyCenter->add(residentialArea);

    instanceEmergencyCenter->addChildToParent(residentialArea, house1);
    instanceEmergencyCenter->addChildToParent(house1, shed);
    instanceEmergencyCenter->addChildToParent(shed, smokeSensor1);
    instanceEmergencyCenter->addChildToParent(shed, motionSensor1);
    instanceEmergencyCenter->addChildToParent(house1, kitchen);
    instanceEmergencyCenter->addChildToParent(kitchen, smokeSensor2);
    instanceEmergencyCenter->addChildToParent(kitchen, motionSensor2);


    instanceEmergencyCenter->addChildToParent(residentialArea, house2);
    instanceEmergencyCenter->addChildToParent(house2, livingRoom);
    instanceEmergencyCenter->addChildToParent(livingRoom, gasSensor1);
    instanceEmergencyCenter->addChildToParent(livingRoom, smokeSensor3);

    instanceEmergencyCenter->addChildToParent(residentialArea, house3);
    instanceEmergencyCenter->addChildToParent(house3, gasSensor2);
    instanceEmergencyCenter->addChildToParent(house3, lab);
    instanceEmergencyCenter->addChildToParent(lab, motionSensor3);

    cout<< "------------------------ TEST 1 -----------------------" << endl;
    cout<< "------ Before ------" << endl;
    instanceEmergencyCenter->overviewByLocation("John's shed");

    //--- Start of code to be tested ---
    ++*smokeSensor1;
    //--- End of code to be tested ---

    cout<< "------ After ------" << endl;
    instanceEmergencyCenter->overviewByLocation("John's shed");

    cout<< "------------------------ TEST 2 -----------------------" << endl;
    cout<< "------ Before ------" << endl;
    instanceEmergencyCenter->overviewByLocationPointer(house1);


    cout<< "------ Test Output ------" << endl;
    //--- Start of code to be tested ---
    instanceEmergencyCenter->activateAllByLocationPointer(house1);
    //--- End of code to be tested ---

    cout<< "------ After ------" << endl;
    instanceEmergencyCenter->overviewByLocationPointer(house1);

    cout<< "------------------------ TEST 3 -----------------------" << endl;
    cout<< "------ Before ------" << endl;
    instanceEmergencyCenter->overviewByLocationPointer(residentialArea);


    cout<< "------ Test Output ------" << endl;
    //--- Start of code to be tested ---
    instanceEmergencyCenter->testAllByLocationPointer(residentialArea);
    //--- End of code to be tested ---

    cout<< "------ After ------" << endl;
    instanceEmergencyCenter->overviewByLocationPointer(residentialArea);

    cout<< "------------------------ TEST 4 -----------------------" << endl;
    cout<< "------ Before ------" << endl;
    instanceEmergencyCenter->overviewByLocationPointer(residentialArea);


    cout<< "------ Test Output ------" << endl;
    //--- Start of code to be tested ---
    instanceEmergencyCenter->activateAllComponents();
    //--- End of code to be tested ---

    cout<< "------ After ------" << endl;
    instanceEmergencyCenter->overviewByLocationPointer(residentialArea);

    cout<< "------------------------ TEST 5 -----------------------" << endl;
    cout<< "------ Before ------" << endl;
    instanceEmergencyCenter->overviewByLocationPointer(residentialArea);


    cout<< "------ Test Output ------" << endl;
    //--- Start of code to be tested ---
    instanceEmergencyCenter->testAllByLocationPointer(residentialArea);
    //--- End of code to be tested ---

    cout<< "------ After ------" << endl;
    instanceEmergencyCenter->overviewByLocationPointer(residentialArea);

    cout<< "------------------------ TEST 6 -----------------------" << endl;
    cout<< "------ Before ------" << endl;
    instanceEmergencyCenter->overviewByLocationPointer(residentialArea);


    cout<< "------ Test Output ------" << endl;
    //--- Start of code to be tested ---
    instanceEmergencyCenter->testAllByLocationPointer(house3);
    //--- End of code to be tested ---

    cout<< "------ After ------" << endl;
    instanceEmergencyCenter->overviewByLocationPointer(residentialArea);

    cout<< "------------------------ TEST 7 -----------------------" << endl;
    cout<< "------ Before ------" << endl;
    instanceEmergencyCenter->overviewByLocationPointer(residentialArea);


    cout<< "------ Test Output ------" << endl;
    //--- Start of code to be tested ---
    instanceEmergencyCenter->overviewSensorsInVector(instanceEmergencyCenter->orderById(instanceEmergencyCenter->getSensorList()));
    //--- End of code to be tested ---

    cout<< "------------------------ END OF TESTS -----------------------" << endl;


    cout << "end of program" << endl;
    return 0;
}
